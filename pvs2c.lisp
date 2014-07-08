;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                PVS to C translator
;;
;;     Author: Gaspard ferey
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; This requires "Cutiles", "Cprimop.lisp" and "Ctypes.lisp" files all available at
;;               https://github.com/Gaspi/pvs2c.git
;;
;; To use:
;;  - Copy this file, Cprimop.lisp and Ctypes.lisp (3 files) in the folder containing
;;    the .pvs file (e.g. "foo.pvs") you're interested in translating to C.
;;  - Start PVS, open this .pvs file and typecheck it.
;;  - In the *pvs* buffer:
;;      (load "pvs2c")
;;      (generate-C-for-pvs-file "foo")
;;  - "foo.c" and "foo.h" were created.
;;
;;
;;  Main functions :
;;
;;    pvs2C expr bindings livevars type
;;      -> string representing a C-variable or expression of the
;;         given type and with the translation of expr as a value.
;;
;;    pvs2C* expr bindings livevars
;;      -> cons of a type amd a string representing a C-variable
;;         or expression of the given type and with the translation
;;         of expr as a value.
;;
;;    pvs2C2 expr bindings livevars type name [need-malloc]
;;      -> a list of instructions setting the C variable with the
;;         given name and type to the translation of expr.
;;         If need-malloc flag is t, also initialize the variable.
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;; Every Function has the resposnability to free it's array arguments !!!


;; TODO flattennning free variables
;; f(a , a(0), a )
;; -> x = GC( a )
;; -> y = GC( a )
;; -> z = y(0)
;; -> free(y)     ;; to last line <=> apply(y, 0)   (so y is freed)
;; -> f(a, x ,z)    ;; and everything is freed
;; 
;; 
;; Bump up the reference count by one so that no argument use a as a mutable variable
;; Move the free to just after the last occurence of the variable
;;
;; Every Function has the resposnability to free it's array arguments !!!
;; 
;; 
;; (lambda(x): a with [0 = x(0) ]  )( a with [0=0] )
;; -> x = GC( a )
;; -> y = a with [0=0]    ;; done non destructively
;; -> 
;; 


(in-package :pvs)

;; Bad practice ???
(load "Cutils")
(load "Ctypes")
(load "Cexpr")
(load "Cprimop")

(defvar *C-livevars-table* nil)
(defvar *C-record-defns* nil)


(defmacro C-reset (array)
  `(setq ,array nil))
(defmacro C-save (array)
  `(setq ,array (list ,array)))
(defmacro C-load (array)
  `(if (listp (car ,array))
       (let ((res (cdr ,array)))
	 (setq ,array (car ,array))
	 res)
     (break)))
(defmacro C-add (array args)
  `(setq ,array (append ,array
	    (if (listp ,args) ,args (list ,args)))))
(defmacro C-flush (array)
  `(let ((res ,array))
     (setq ,array nil)
     res))

;; Instructions to allocate memory for new variables
(defvar *C-instructions* nil)
(defun reset-instructions () (C-reset *C-instructions*))
(defun add-instructions (instructions)
  (C-add *C-instructions* instructions))
(defun add-instruction (instruction)
  (C-add *C-instructions* (list instruction)))
(defun add-instructions-first (instructions)
  (setq *C-instructions* (append instructions *C-instructions*)))

;; Instructions to destruct previously allocated memory
(defvar *C-destructions* nil)
(defun reset-destructions () (C-reset *C-destructions*))
(defun add-destructions (destructions)
  (C-add *C-destructions* destructions))
(defun add-destruction (destruction)
  (C-add *C-destructions* (list destruction)))

(defvar *C-definitions* nil)
(defun reset-definitions () (C-reset *C-definitions*))
(defun add-definition (definition)
  (setq *C-definitions* (append *C-definitions* (list definition))))


(defmacro pvs2C-error (msg &rest args)
  `(format t ,msg ,@args))


(defvar *C-nondestructive-hash* (make-hash-table :test #'eq))
(defvar *C-destructive-hash* (make-hash-table :test #'eq))


;; Return a trivial Cexpr if possible
(defun getConstantName (expr bindings)
  (when (name-expr? expr)
    (let ((e (assoc (declaration expr) bindings :key #'declaration)))
      (when e (mk-Cexpr (pvs2C-type (type (car e))) (cdr e) nil nil)))))




; --- set and conversion functions need to be implemented correctly here ---


;; Returns a Cexpr
;; type is the list of the types
;; name is the list of the names
;; instr and destr are the concatenation of the instrs and destrs
(defmethod pvs2C ((expr list) bindings livevars &optional (exp-type (cons nil nil)))
  (if (consp expr)
      (let ((hd (pvs2C (car expr) bindings
		       (append (updateable-vars (cdr expr)) livevars)
		     (car exp-type)))
	    (tl (pvs2C (cdr expr) bindings
		       (append (updateable-vars (car expr)) livevars)
		       (cdr exp-type))))
	(mk-Cexpr (cons   (type  hd) (type  tl))
		  (cons   (name  hd) (name  tl))
		  (append (instr hd) (instr tl))
		  (append (destr hd) (destr tl))))
    (mk-Cexpr nil nil nil nil)))



;; If expressions
;; Return a Cexpr
;; type is given type
;; name is nil
;; destr contains the destructions for the condition
(defmethod pvs2C-if ((expr if-expr) bindings livevars exp-type)  ;result
  (let* ((condition (condition expr))
	 (then-part (then-part expr))
	 (else-part (else-part expr))
	 (newlivevars (append (updateable-vars then-part)
			      (append (updateable-vars else-part)
				      livevars)))
	 (C-cond-part (pvs2C condition bindings newlivevars *C-int*))
	 (C-then-part (pvs2C2 then-part bindings livevars exp-type "~a"))
	 (C-else-part (pvs2C2 else-part bindings livevars exp-type "~a"))
	 (instr (append
		 (instr C-cond-part)
		 (list (format nil "if(~a) {" (name C-cond-part)))
		 (indent (instr C-then-part))
		 (indent (destr C-then-part))
		 (list "} else {")
		 (indent (instr C-else-part))
		 (indent (destr C-else-part))
		 (list "}"))))
    (mk-Cexpr exp-type nil instr (destr C-cond-part))))

(defmethod pvs2C* ((expr if-expr) bindings livevars)
  (let* ((type (pvs2C-type expr)))    ;; TODO could be improved to find a smaller type
    (pvs2C-if expr bindings livevars type)))



;; --- Should be renamed "pvs2C-set" ---
;; Returns a Cexpr with type = type and name = name
(defmethod pvs2C2 ((expr list) bindings livevars type name &optional need-malloc)
  (if (consp expr)
      (let ((hd (pvs2C2 (car expr) bindings
			(append (updateable-vars (cdr expr)) livevars)
			(car type) (car name) need-malloc))
	    (tl (pvs2C2 (cdr expr) bindings
			(append (updateable-vars (car expr)) livevars)
			(cdr type) (cdr name) need-malloc)))
	(mk-Cexpr (cons   (type  hd) (type  tl))
		  (cons   (name  hd) (name  tl))
		  (append (instr hd) (instr tl))
		  (append (destr hd) (destr tl))))
    (mk-Cexpr nil nil nil nil)))



;; Record expressions are treated seperately
(defmethod pvs2C2 ((expr record-expr) bindings livevars type name &optional need-malloc)
  (let ((var (C-var type name))
	(formatted-fields
	 (loop for a in (assignments expr)
	       collect (let ((e (assoc (id (caar (arguments a))) (args type))))
			 (pvs2C2 (expression a) bindings livevars
				 (cdr e)
				 (format nil "~a.~a" name (car e)))))))
    (mk-Cexpr type name
	      (append (when need-malloc (C-alloc var))
		      (append-lists (mapcar #'instr formatted-fields)))
	      (append (C-free var)))))

(defmethod pvs2C ((expr record-expr) bindings livevars &optional (exp-type (pvs2C-type expr)))
  (pvs2C2 expr bindings livevars exp-type (gentemp "aux") t))





(defmethod pvs2C2 (expr bindings livevars type name &optional need-malloc)
  (let ((res-var (C-var type name))
	(e (if (C-base? type)
	       (pvs2C expr bindings livevars type)
	     (pvs2C* expr bindings livevars))))
    (if (and (unnamed? e) (type= (type e) type))  ;; Perfect case
	(progn (define-name e name)
	       (when need-malloc
		 (app-instr e (C-alloc res-var) t)
		 (app-destr e (C-free  res-var)))
	       e)
      (progn (when (unnamed? e)
	       (let ((n (gen-C-var (type e) "set")))
		 (define-name e n)
		 (set-instr e (append (C-alloc n) (instr e) (destr e)))
		 (set-destr e (C-free n))))
	     (set-var-to-Cexpr res-var e need-malloc)))))


(defmethod set-var-to-Cexpr ((var C-var) (e Cexpr) &optional need-malloc)
  (with-slots (type name) var
    (mk-Cexpr type name
	      (append
	       (instr e)
	       (when need-malloc (C-alloc var))
	       (get-typed-copy (type var) (name var)
			       (type e)   (name e))
	       (destr e))
	      (when need-malloc (C-free var)))))

    ;; (when need-malloc (add-destructions (C-free (C-var type name)))))))))


;; Return a Cexpr (  name : "if" name  ,  destr : only free(name)  )
(defmethod pvs2C ((expr if-expr) bindings livevars &optional (exp-type (pvs2C-type expr)))
  (let* ((type (smaller-type (pvs2C-type expr) exp-type))
	 (if-bloc (pvs2C-if expr bindings livevars type))
	 (if-name (gen-C-var type "if")))
    (define-name if-bloc if-name)
    (set-instr if-bloc
	       (append (C-alloc if-name)
		       (instr if-bloc)
		       (destr if-bloc)))
    (set-destr if-bloc (C-free if-name))
    (convert exp-type if-bloc)))


;; Returns a Cexpr
;; name is a variable of a simple expression
;; destr is only  free(name)
(defmethod pvs2C (expr bindings livevars &optional (exp-type (pvs2C-type expr)))
  (let ((cst-Cexpr (getConstantName expr bindings)))
    (if cst-Cexpr (convert exp-type cst-Cexpr)
      (let ((e (pvs2C* expr bindings livevars))) ;; Returns an instructions (ends with *)
	(if (unnamed? e)
	    (let ((n (gen-C-var (type e) "aux")))
	      (define-name e n)
	      (set-instr e (append (C-alloc n)
				   (instr e)
				   (destr e)))
	      (set-destr e (C-free n))
	      (convert exp-type e))
;;	  (if (not (destr e))  ; If it was a very simple expression
	  (convert exp-type e))))))
	    ;; (let ((n (gen-C-var exp-type "aux")))
	    ;;   (set-instr e (append (C-alloc n) ; probably empty
	    ;; 			   (list (format nil "~a = ~a;" n (cdr e)))
	    ;; 			   (destr e)))
	    ;;   (set-name e n)
	    ;;   (set-destr e (C-free n))
	    ;;   (convert exp-type e))))))))





(defstruct C-info
  id type-out type-arg definition analysis)

(defmacro C-hashtable ()
  `(if *destructive?* *C-destructive-hash* *C-nondestructive-hash*))

(defun C_id (op)
  (let ((hashentry (gethash (declaration op) (C-hashtable))))
    (when hashentry (C-info-id hashentry))))

(defun C_nondestructive_id (op)
  (let ((hashentry (gethash (declaration op) *C-nondestructive-hash*)))
    (when hashentry (C-info-id hashentry))))

(defun C_type (op)
  (let ((hashentry (gethash (declaration op) (C-hashtable))))
    (when hashentry (format nil "~a -> ~a"
	 (C-info-type-arg hashentry)
	 (C-info-type-out hashentry)))))

(defun C_definition (op)
  (let ((hashentry (gethash (declaration op) (C-hashtable))))
    (when hashentry (C-info-definition hashentry))))

(defun C_analysis (op)
  (let ((hashentry (gethash (declaration op) (C-hashtable))))
    (when hashentry (C-info-analysis hashentry))))


;; number-expr is a non negative integer
(defmethod pvs2C* ((expr number-expr) bindings livevars)
  (declare (ignore bindings livevars))
  (let ((type (pvs2C-type expr)))
    (if (C-gmp? type)
	(mk-Cexpr type nil
		  (list (format nil  "mpz_set_str(~~a, \"~a\")" (number expr)))
		  nil)
      (mk-Cexpr type (format nil "~a" (number expr)) nil nil))))


;; -------------------------- Unsafe code down ----------------------------

;; Should be modified to create a different tuple according to the type of the args
(defmethod pvs2C* ((expr tuple-expr) bindings livevars)
  (let* ((elts (exprs expr))
	 (args (pvs2C elts bindings livevars
		      (mapcar #'pvs2C-type elts))))
    (set-name args
	      (mk-C-funcall "createTuple" (cons "~a" (name args))))
    args))

(defmacro pvs2C_tuple (args)
  `(format nil "(~{~a~^, ~})" ,args))

(defmethod pvs2C* ((expr projection-application) bindings livevars)
  (let* ((ll (length (exprs expr)))
	 (dummy (gentemp "DDD"))
	 (match-list (pvs2C_tuple (matchlist (index expr) ll dummy)))
	 (expr-list (pvs2C expr bindings livevars)))
    `(let ,match-list = ,expr-list in ,dummy)))


;; When is this function called ??  (not working)
(defmethod pvs2C* ((expr list) bindings livevars)
  (if (consp expr)
      (cons (pvs2C (car expr) bindings
		   (append (updateable-vars (cdr expr)) livevars) )
	    (pvs2C (cdr expr) bindings  ;;need car's freevars
		   (append (updateable-vars (car expr)) ;;f(A, A WITH ..)
			   livevars)))
    nil))

;; -------------------------- Unsafe code up ----------------------------



(defmethod pvs2C*  ((expr field-application) bindings livevars)
  (let* ((clarg (pvs2C (argument expr) bindings livevars))
	 (id (id expr))
	 (type (pvs2C-type expr)))
    (set-name clarg (format nil "~a.~a" (name clarg) id))
    (set-type clarg type)
    clarg))


;; pairlis with three lists
(defun pair3lis (l1 l2 l3)
  (when (consp l1)
    (cons (list (car l1) (car l2) (car l3))
	  (pair3lis (cdr l1) (cdr l2) (cdr l3)))))

(defun mk-Cexpr-funcall (type op args)
  (set-type args type)
  (if (C-gmp? type)
      (progn
	(app-instr args (set-C-pointer op (name args)))
	(set-name args nil))
    (set-name args (mk-C-funcall op (name args))))
  args)

(defmethod pvs2C* ((expr application) bindings livevars)
  (with-slots (operator argument) expr
    (if (constant? operator)
      (if (pvs2cl-primitive? operator)
	    (pvs2C*-primitive-app expr bindings livevars)
	  (if (datatype-constant? operator)
	      (mk-Cexpr-funcall (pvs2C-type (range (type operator)))
				(pvs2C-resolution operator)
				(pvs2C (arguments expr)
				       bindings
				       livevars))
	    (pvs2C-defn-application expr bindings livevars)))
      (if (lambda? operator)
	  (let* ((bind-decls (bindings operator))
		 (bind-ids (pvs2cl-make-bindings bind-decls bindings))
		 (newbind (append (pairlis bind-decls bind-ids) bindings))
		 (type-args (C-type-args operator))
		 (C-arg (pvs2C2 (if (tuple-expr? argument)
				    (exprs argument)
				  (list argument))
				bindings
				(append (updateable-free-formal-vars operator) livevars)
				type-args
				(mapcar #'id (bindings operator)) t))
		 (C-expr (pvs2C* (expression operator) newbind nil)))
	    (app-instr C-expr (instr C-arg) t)
	    (app-destr C-expr (destr C-arg))
	    C-expr)
	(let* ((type-op (pvs2C-type (type operator)))
	       (type (pvs2C-type (range (type operator))))
	       (C-arg (pvs2C argument bindings
			     (append (updateable-free-formal-vars operator) livevars)))
	       (C-op (pvs2C operator bindings
			    (append (updateable-vars argument) livevars)
			    type-op)))
	  (if (C-pointer-type? type-op) ;; if the operator is an array
	      (mk-Cexpr (target type-op)
			(format nil "~a[~a]" (name C-op) (name C-arg))
			(append (instr C-op) (instr C-arg))
			(append (destr C-op) (destr C-arg)))
	    (if (C-gmp? type)
		(mk-Cexpr type nil
			  (append (instr C-op) (instr C-arg)
				  (set-C-pointer C-op C-arg))
			  (append (destr C-op) (destr C-arg)))
	      (mk-Cexpr type
			(mk-C-funcall C-op C-arg)
			(append (instr C-op) (instr C-arg))
			(append (destr C-op) (destr C-arg))))))))))


(defun pvs2C-defn-application (expr bindings livevars)
  (with-slots (operator argument) expr
    (pvs2C-resolution operator)
    (let* ((actuals (expr-actuals (module-instance operator)))
	   (op-decl (declaration operator))
	   (args (arguments expr))
	   (type-args (C-type-args op-decl))
	   (ret-type (pvs2C-type (range (type op-decl))))
	   (C-args (pvs2C (append actuals args) bindings livevars type-args)))
      (if *destructive?*
	  (let* ((ret-type (pvs2C-type (range (type operator))))
		 (defns (def-axiom op-decl))
		 (defn (when defns (args2 (car (last (def-axiom op-decl))))))
		 (def-formals (when (lambda-expr? defn)
				(bindings defn)))
		 (module-formals (unless (eq (module op-decl) (current-theory))
				   (constant-formals (module op-decl))))
		 (alist (append (pairlis module-formals actuals)
				(when def-formals
				  (pairlis def-formals args))))
		 (analysis (C_analysis operator))
		 (check (check-output-vars analysis alist livevars))
		 (id-op (if check (C_id operator)
			          (C_nondestructive_id operator))))
	    (mk-Cexpr-funcall ret-type id-op C-args))
	(mk-Cexpr-funcall ret-type (C_id operator) C-args)))))

(defun pvs2C-resolution (op)
  (let* ((op-decl (declaration op)))
    (pvs2C-declaration op-decl)))

(defun pvs2C-declaration (op-decl)
  (let ((nd-hashentry (gethash op-decl *C-nondestructive-hash*))
	;(d-hashentry (gethash op-decl *C-destructive-hash*))
	;enough to check one hash-table. 
	)
    (when (null nd-hashentry)
      (let ((op-id (gentemp (format nil "pvs_~a" (id op-decl))))
	    (op-d-id (gentemp (format nil "pvs_d_~a" (id op-decl)))))
      (setf (gethash op-decl *C-nondestructive-hash*)
	    (make-C-info :id op-id))
      (setf (gethash op-decl *C-destructive-hash*)
	    (make-C-info :id op-d-id))
      (let* ((defns (def-axiom op-decl))
	     (defn (when defns (args2 (car (last (def-axiom op-decl))))))
	     (def-formals (when (lambda-expr? defn)
			    (bindings defn)))
	     (def-body (if (lambda-expr? defn) (expression defn) defn))
	     (module-formals (constant-formals (module op-decl)))
	     (range-type (if def-formals (range (type op-decl))
			     (type op-decl))))
	(pvs2C-resolution-nondestructive op-decl (append module-formals def-formals)
					     def-body range-type)
	(pvs2C-resolution-destructive op-decl (append module-formals def-formals)
					  def-body range-type))))))

(defun pvs2C-resolution-nondestructive (op-decl formals body range-type)
  (let* ((*destructive?* nil)
	 (bind-ids (pvs2cl-make-bindings formals nil))
	 (id-map (pairlis formals bind-ids))
	 (cl-type-out (pvs2C-type range-type))
	 (return-void (C-gmp? cl-type-out))
;;	 (pointer-out (C-pointer? cl-type-out))
	 (result-var (C-var cl-type-out "result"))
	 (cl-type-arg (format nil "~{~a~^, ~}"
	      (append (when return-void (list (format nil "~a result" cl-type-out)))
		      (loop for var in formals
			    collect (format nil "~a ~a"
					    (pvs2C-type (type var))
					    (cdr (assoc var id-map)) )))))
	 (hash-entry (gethash op-decl *C-nondestructive-hash*))
	 (C-body (pvs2C2 body id-map nil cl-type-out "result" (not return-void))))
             ;; If we don't return void, we need to malloc the result
    (format t "~%Defining (nondestructively) ~a with type~%   ~a -> ~a"
	    (id op-decl) cl-type-arg cl-type-out)
    (when *eval-verbose* (format t "~%as :~%~{~a~%~}" (instr C-body)))
;;    (unless return-void (add-instructions-first (C-alloc result-var)))
    (setf (C-info-type-out hash-entry) (if return-void "void" cl-type-out)
	  (C-info-type-arg hash-entry) cl-type-arg
	  (C-info-definition hash-entry)
	       (format nil "~{  ~a~%~}~{  ~a~%~}~:[  return result;~%~;~]"
		       (instr C-body)
		       (when return-void (destr C-body))
		       return-void))
      ))

(defun pvs2C-resolution-destructive (op-decl formals body range-type)
  (let* ((*destructive?* t)
	 (*output-vars* nil)
	 (bind-ids (pvs2cl-make-bindings formals nil))
	 (id-map (pairlis formals bind-ids))
	 (cl-type-out (pvs2C-type range-type))
	 (return-void (C-gmp? cl-type-out))
;;	 (pointer-out (C-pointer? cl-type-out))
	 (result-var (C-var cl-type-out "result"))
	 (cl-type-arg (format nil "~{~a~^, ~}"
	      (append (when return-void (list (format nil "~a result" cl-type-out)))
		      (loop for var in formals
		       collect (format nil "~a ~a"
				       (pvs2C-type (type var))
				       (cdr (assoc var id-map)))))))
	 (hash-entry (gethash op-decl *C-destructive-hash*))
	 (old-output-vars (C-info-analysis hash-entry))
	 (C-body (pvs2C2 body id-map nil cl-type-out "result" (not return-void))))
             ;; If we don't return void, we need to malloc the result
    (format t "~%Defining (destructively) ~a with type~%   ~a -> ~a"
	    (id op-decl) cl-type-arg cl-type-out)
    (when *eval-verbose* (format t "~%as :~%~{~a~%~}" (instr C-body)))
;;    (unless return-void (add-instructions-first (C-alloc result-var)))
    (setf (C-info-type-out hash-entry) (if return-void "void" cl-type-out)
	  (C-info-type-arg hash-entry) cl-type-arg
	  (C-info-definition hash-entry)
	      (format nil "~{  ~a~%~}~{  ~a~%~}~:[  return result;~%~;~]"
		       (instr C-body)
		       (when return-void (destr C-body))
		       return-void)
	   (C-info-analysis hash-entry) *output-vars*)
    (unless (equalp old-output-vars *output-vars*)
      (pvs2C-resolution-destructive op-decl formals body range-type))))


(defmethod pvs2C* ((expr name-expr) bindings livevars)
  (let* ((type-e (pvs2C-type expr))
	 (decl (declaration expr))
	 (bnd (assoc decl bindings :key #'declaration))
	 (prim (pvs2cl-primitive? expr)))
    (assert (not (and bnd (const-decl? decl))))
    (cond (bnd
	   (mk-Cexpr type-e (cdr bnd) nil nil))
	  (prim (pvs2C*-primitive-cste expr bindings livevars))
	  ((const-decl? decl)
	        (pvs2C*-constant expr decl bindings livevars))
	  (t
	        (let ((undef (undefined expr "Hit untranslateable expression ~a")))
		  `(funcall ',undef))))))

(defun pvs2C*-constant (expr op-decl bindings livevars)
  (let* ((defns (def-axiom op-decl))
	 (defn (when defns (args2 (car (last (def-axiom op-decl))))))
	 (def-formals (when (lambda-expr? defn)
			(bindings defn))))
    (pvs2C-resolution expr)
    (if def-formals  ;; I don't understand this...
	(let ((eta-expansion
	       (make!-lambda-expr def-formals
		    (make!-application* expr
		       (loop for bd in def-formals
			     collect (mk-name-expr bd))))))
	  (pvs2C* eta-expansion bindings livevars))
      (let ((actuals (expr-actuals (module-instance expr))))
	(mk-Cexpr-funcall (pvs2C-type (type expr))
			  (C_nondestructive_id expr)
			  (pvs2C actuals bindings livevars))))))


(defmethod pvs2C* ((expr lambda-expr) bindings livevars)
  (declare (ignore livevars))
  (with-slots (type expression) expr
    (let ((bind-decls (bindings expr)))
      (if (and (C-updateable? type) (funtype? type))  ;; If it could be represented as an array
	  (let* ((Ctype (pvs2C-type type)) ;; Should we use the type of the range-expr ?
;;	         (range-type (pvs2C-type expression))  ;; Should we built Ctype from that ?
		 (range-type (target Ctype))
		 (i (gentemp "i"))
		 (new-bind (append (pairlis bind-decls ;; bind-decls must have length 1
					    (list i))
				   bindings))
		 (body (pvs2C2 expression
			       new-bind
			       nil  ;;removed livevars (why ?)
			       range-type
			       (format nil "~~a[~a]" i)
			       nil)))
	    (mk-Cexpr Ctype nil
		      (append
		       (array-malloc Ctype)
		       (list (format nil "int ~a;" i)
			     (format nil "for(~a = 0; ~a < ~a; ~a++) {"
				     i i (array-bound type) i))
		       (indent (instr body))
		       (list "}"))
		      (when (destr body)
			(append
			 (list (format nil "for(~a = 0; ~a < ~a;;; ~a++) {"
				       i i (array-bound type) i))
			 (indent (destr body))
			 (list "}")))))
	(pvs2C-lambda bind-decls expression bindings)))))

;; (list (format nil "if ( GC_count( ~~a ) == 1) {")
;;       (format nil "  ~~a = GC( ~a );" )
;;       ....


;; Creates a closure (not working now...)
(defun pvs2C-lambda (bind-decls expr bindings) ;;removed livevars
  (let* ((*destructive?* nil)
	 (range-type (pvs2C-type (type expr)))
	 (bind-ids (pvs2cl-make-bindings bind-decls bindings))
	 (new-bind (append (pairlis bind-decls bind-ids) bindings))
	 (C-body (pvs2C expr
			 new-bind
			 nil range-type))
	 (name (gentemp "fun"))
	 (fv (freevars expr))
	 (nb-args (length fv))
	 (var-ind (pairlis fv (range-arr nb-args)))
	 (param-def (append-lists (mapcar #'(lambda (x) (load-void x "env"))
					  var-ind)))
	 (assign (loop for x in bindings
		       when (assoc (cdr x) var-ind :test #'(lambda (x y) (eq x (id y)) ))
		       collect it))
	 ;; Carefull !! eq x (id y) is not enough, (duplication variable id)
	 (env-name (gentemp "env")))
    (add-definition (format nil "~a ~a(void *env) {~%~{  ~a~%~}  return ~a;~%}"
			    range-type name
			    (append param-def (instr C-body) (destr C-body))
			    (name C-body)))
    (mk-Cexpr (make-instance 'C-closure)
	      nil
	      (append (list (format nil "void ~a[~d];" env-name nb-args))
		      (append-lists (mapcar
				     #'(lambda (x) (save-void x env-name))
				     assign))
		      (list (format nil "makeClosure(~~a, ~a, ~a);" name env-name)))
	      nil)))








;; Doesn't work  / Should look like if-expr
(defmethod pvs2C* ((expr cases-expr) bindings livevars)
  (let ((type (pvs2C-type expr)))
    (mk-Cexpr type nil
	      (append (list (format nil "switch( ~a ) {"
				    (pvs2C (expression expr) bindings livevars type)))
		  (pvs2C-cases (selections expr) (else-part expr) bindings livevars)
		  (list "}")))))

;; Doesn't work / Should look like if-expr
(defun pvs2C-cases (selections else-part bindings livevars)
  (let ((selections-C
	 (loop for entry in selections
	       collect
	       (let* ((bind-decls (args entry))
		      (bind-ids (pvs2cl-make-bindings bind-decls bindings)))
		 (format nil "  case ~a ~{~a ~} : ~a; break;"
			 (pvs2C (constructor entry) bindings livevars)
			 bind-ids
			 (pvs2C (expression entry)
				(append (pairlis bind-decls bind-ids) bindings)
				livevars)))))))
  (append selections-C
	  (when else-part
	    (list (format nil "  default: ~a"
			  (pvs2C (expression else-part) bindings livevars))))
	  (list "}")))



(defmethod pvs2C* ((expr update-expr) bindings livevars)
  (with-slots (expression assignments) expr
  (if (C-updateable? (type expression))
      (progn
	(when (and *destructive?* (not (some #'maplet? assignments)))
	  (let* ((*C-livevars-table* 
		  (no-livevars? expression livevars assignments)))
	    ;;very unrefined: uses all freevars of eventually updated expression.
	    (cond (*C-livevars-table* ;; check-assign-types
		   (push-output-vars (car *C-livevars-table*)
				     (cdr *C-livevars-table*)))
		  ((and *eval-verbose* (not *C-livevars-table*))
		   (format t "~%Update ~s translated nondestructively. Live variables ~s present"
			   expr livevars)))))
	(pvs2C-update expr bindings livevars))
    (pvs2C (translate-update-to-if! expr) bindings livevars)))) ;; When does that happen ?



(defun pvs2C-update (expr bindings livevars)
  (with-slots (type expression assignments) expr
    (let* ((C-type (pvs2C-type type))
	   (assign-exprs (mapcar #'expression assignments))
	   (C-expr (pvs2C2 expression bindings
			   (append (updateable-free-formal-vars
				    assign-exprs) ;;assign-args can be ignored
				   livevars)
			   (bang-type C-type) "~a" nil))
	   (C-update (pvs2C-update* (type expression)
				   (mapcar #'arguments assignments)
				   assign-exprs
				   bindings
				   (append (updateable-vars expression)
					   livevars))))
      (set-name C-expr nil) ;; type is already C-type
      (set-instr C-expr
		 (append (instr C-update)  ;; Defining update key / value
			 (instr C-expr)    ;; Getting an updateable array
			 (name C-update)   ;; Performing the update (destructively)
			 (destr C-update)));; Destroying
      C-expr)))  ;; destr of C-expr is still to be destroyed


;;recursion over updates in an update expression
(defun pvs2C-update* (type assign-args assign-exprs bindings livevars)
  (if (consp assign-args)
    (let ((C-car (pvs2C-update-nd-type
	        type "~a"
		(car assign-args )
		(car assign-exprs)
		bindings
		(append (append (updateable-vars (cdr assign-exprs))
				(updateable-vars (cdr assign-args ))
				livevars))))
	  (C-cdr (pvs2C-update* type
			   (cdr assign-args)
			   (cdr assign-exprs)
			   bindings
			   (append (updateable-free-formal-vars (car assign-exprs))
				   livevars))))
      (set-name  C-cdr (append (name  C-car) (name  C-cdr)))
      (app-instr C-cdr (instr C-car) t)
      (app-destr C-cdr (destr C-car) t)
      C-cdr)
    (mk-Cexpr nil nil nil nil)))


;; ---- Recursion over nested update arguments in a single update ----
(defun pvs2C-update-nd-type (type exprvar args assign-expr bindings livevars)
  (if (consp args)
      (pvs2C-update-nd-type* type exprvar (car args) (cdr args) assign-expr
			      bindings livevars)
    (break))) ;; Should never happen... (a priori)
;; (let ((C-type (pvs2C-type type)))
;;   (get-typed-copy C-type exprvar
;; 		  C-type (pvs2C assign-expr bindings livevars C-type)))))

(defmethod pvs2C-update-nd-type* ((type funtype) expr arg1 restargs
				   assign-expr bindings livevars)
  (let* ((arg1var (gentemp "L"))
	 (Ctype (pvs2C-type type))
	 (C-dom-type )
	 (C-arg1 (pvs2C2 (car arg1) bindings
			 (append (updateable-vars restargs)
				 (updateable-free-formal-vars assign-expr)
				 livevars)
			 (pvs2C-type (domain type)) arg1var t)))
    (if (consp restargs)
	(let* ((C-range-type (pvs2C-type (range type)))
	       (exprvar (gen-C-var C-range-type "E"))
	       (C-expr (pvs2C-update-nd-type (range type) exprvar
					     restargs assign-expr
					     bindings livevars)))
	  (mk-Cexpr nil
		    (append (C-alloc exprvar)
			    (get-typed-copy (bang-type C-range-type) exprvar
					    C-range-type (format nil "~a[~a]" expr arg1var))
			    (name C-expr))
		    (append (instr C-expr) (instr C-arg1) )
		    (append (destr C-arg1) (destr C-expr))))
      (let* ((res (gentemp "res"))
	     (C-expr (pvs2C2 assign-expr bindings livevars
			    (target Ctype) res t)))
	(mk-Cexpr nil (get-typed-copy (target Ctype) (format nil "~a[~a]" expr arg1var)
				      (target Ctype) res)
		  (append (instr C-arg1) (instr C-expr))
		  (append (destr C-arg1) (destr C-expr)))))))


(defmethod pvs2C-update-nd-type* ((type recordtype) expr arg1 restargs
				   assign-expr bindings livevars)
  (let* ((id (id (car arg1)))
	 (field-type (type (find id (fields type) :key #'id) ))
	 (C-target-type (pvs2C-type field-type)))
    (if (consp restargs)
	(let ((exprvar (gentemp "E"))
	      (C-expr (pvs2C-update-nd-type field-type exprvar restargs assign-expr
				      bindings livevars)))
	  (set-name C-expr
		     (append (get-typed-copy (bang-type C-target-type) exprvar
					     C-target-type (format nil "~a.~a" expr id))
			     (name C-expr)))
	  Cexpr)
      (let* ((res (gentemp "res"))
	     (C-expr (pvs2C2 assign-expr bindings livevars
			     C-target-type res t)))
	(mk-Cexpr nil (get-typed-copy C-target-type (format nil "~a.~a" expr id)
				      C-target-type res)
		  (instr C-expr)
		  (destr C-expr))))))


(defmethod pvs2C-update-nd-type* ((type subtype) expr arg1 restargs
				   assign-expr bindings livevars)
  (pvs2C-update-nd-type* (find-supertype type) expr arg1 restargs
			  assign-expr bindings livevars))


;; Function to get and set arrays

;; Dead code...
(defun updateable-set (type array index value)
  (if (and *destructive?* *C-livevars-table*) ;; Destructive update
      (list (format nil "~a[~a] = ~a; +++" array index value))
;;      (get-typed-copy (target type)
;;		      (format nil "~a[~a]" array index)
;;		      (target type) value)
    (get-typed-copy (target type)
		    (format nil "~a[~a]" array index)
		    (target type)
		    value)))
;;    (list (format nil "pvsNonDestructiveUpdate2(~a, ~a, ~a);" array index value))))
;; Should depend on the type ...


;; Get array[index] to modify it's fields later
;; Dead code...
(defmethod updateable-get ((type C-pointer-type) result array index)
  (list (format nil "~a ~a;" (target type) result)
	(format nil "if ( GC_count( ~a[~a] ) == 1 )" array index)
	(format nil "  ~a = ~a[~a];" result array index)
	
	(format nil "~a ~a = ~a[~a];" (target type) result array index)))

;;Dead code...
(defmethod pvs2C*-updateable-get ((type C-pointer-type) array index)
  (cons (target type)
	(if (C-pointer? (target type))
	    (list (format nil "~~a = ~a[~a];" array index))
	  (format nil "~a[~a]" array index))))


;;C-updateable? is used to check if the type of an updated expression
;;is possibly destructively. 

(defmethod C-updateable? ((texpr tupletype))
  (C-updateable? (types texpr)))

;;this is the only case where C-updateable? can be false, because
;;the given function type is not an array.  
(defmethod C-updateable? ((texpr funtype)) ;;add enum types, subrange.
  (and (or (simple-below? (domain texpr))
	   (simple-upto? (domain texpr)))
       (C-updateable? (range texpr))))

(defmethod C-updateable? ((texpr recordtype))
  (C-updateable? (mapcar #'type (fields texpr))))

(defmethod C-updateable? ((texpr subtype))
  (C-updateable? (find-supertype texpr)))

(defmethod C-updateable? ((texpr list))
  (or (null texpr)
      (and (C-updateable? (car texpr))
	   (C-updateable? (cdr texpr)))))

;;This is subsumed by fall-through case.
;(defmethod C-updateable? ((texpr type-name))
;  (not (or (eq texpr *boolean*)
;	   (eq texpr *number*))))

;(defmethod C-updateable? ((texpr actual))
;  (C-updateable? (type-value texpr)))

(defmethod C-updateable? ((texpr t)) t)
;; It is okay to say  C-updateable? for uninterpreted
;; or actuals since these will not be updated destructively or otherwise.



(defun pvs2C-theory (theory)
  (let* ((theory (get-theory theory))
	 (*current-theory* theory)
	 (*current-context* (context theory)))
    (cond ((datatype? theory)
	   (pvs2C-datatype theory))
	   ;;(pvs2C-theory (adt-theory theory))
	   ;;(let ((map-theory (adt-map-theory theory))
	   ;;   (reduce-theory (adt-reduce-theory theory)))
	   ;;   (when map-theory (pvs2C-theory (adt-map-theory theory)))
	   ;;   (when reduce-theory (pvs2C-theory (adt-reduce-theory theory))))
	  (t (loop for decl in (theory theory)
		   do (cond ((type-eq-decl? decl)
			     (let ((dt (find-supertype (type-value decl))))
			       (when (adt-type-name? dt)
				 (pvs2C-constructors (constructors dt) dt))))
			    ((datatype? decl)
			     (let ((adt (adt-type-name decl)))
			       (pvs2C-constructors (constructors adt) adt)))
			    ((const-decl? decl)
			     (unless (eval-info decl)
			       (pvs2C-declaration decl)))
			    (t nil)))))))

;;; maps to AlgebraicTypeDef
(defun pvs2C-datatype (dt)
  (let* ((typevars (mapcar #'(lambda (fm)
			       (pvs2C-datatype-formal fm dt))
		     (formals dt)))
	 (constructors (pvs2C-constructors
			(constructors dt) dt
			(mapcar #'cons (formals dt) typevars))))
    (format nil "::~a~{ ~a~} = ~{~a~^ | ~}"
      (id dt) typevars constructors)))

(defun pvs2C-datatype-formal (formal dt)
  (if (formal-type-decl? formal)
      (let ((id-str (string (id formal))))
	(if (lower-case-p (char id-str 0))
	    (id formal)
	    (make-new-variable (string-downcase id-str :end 1) dt)))
      (break "What to do with constant formals?")))

(defun pvs2C-constructors (constrs datatype tvars)
  (pvs2C-constructors* constrs datatype tvars))

(defun pvs2C-constructors* (constrs datatype tvars)
  (when constrs
    (cons (pvs2C-constructor (car constrs) datatype tvars)
	  (pvs2C-constructors* (cdr constrs) datatype tvars))))

;;; Maps to ConstructorDef
(defun pvs2C-constructor (constr datatype tvars)
  (format nil "~a~{ ~a~}" (id constr)
	  (mapcar #'(lambda (arg) (pvs2C-type (type arg) tvars))
	    (arguments constr))))

(defun clear-C-hash ()
  (clrhash *C-nondestructive-hash*)
  (clrhash *C-destructive-hash*))

(defun generate-C-for-pvs-file (filename &optional force?)
  (setq *C-record-defns* nil)
  (clrhash *C-nondestructive-hash*)
  (clrhash *C-destructive-hash*)
  (let ((theories (cdr (gethash filename *pvs-files*))))
    ;; Sets the hash-tables
    (dolist (theory theories)
      (pvs2C-theory theory))
    (with-open-file (outputH (format nil "~a.h" filename)
			    :direction :output
			    :if-exists :supersede
			    :if-does-not-exist :create)
    (with-open-file (output (format nil "~a.c" filename)
			    :direction :output
			    :if-exists :supersede
			    :if-does-not-exist :create)
      (format output "~{~a~%~}" (apply-argument (list
	    "// ---------------------------------------------"
	    "//        C file generated from ~a.pvs"
	    "// ---------------------------------------------"
	    "//   Make sure to link GC.c and GMP in compilation:"
	    "//      gcc -o ~a ~:*~a.c GC/GC.c -lgmp"
	    "//      ./~a"
	    "// ---------------------------------------------"
	    "~%#include<stdio.h>"
	    "#include<gmp.h>"
	    "#include \"GC.h\""
	    "#include \"~a.h\""
	    "~%#define TRUE 1"
	    "#define FALSE 0"
	    "~%int main(void) {"
	    "  printf(\"Executing ~a ...\\n\");"
	    "  return 0;~%}") filename))
      (format output "~{~2%~a~}" *C-definitions*)
      (format outputH "// C file generated from ~a.pvs" filename)

      (dolist (rec-def *C-record-defns*)
	(format output "~a~%" (caddr rec-def)))
      (dolist (theory theories)
	(dolist (decl (theory theory))
	  (let ((ndes-info (gethash decl *C-nondestructive-hash*))
		(des-info (gethash decl *C-destructive-hash*)))
	    (when ndes-info
	      (let ((id (C-info-id ndes-info)))
		;; First the signature
		(format outputH "~2%~a ~a(~a);"
			(C-info-type-out ndes-info)
			id
			(C-info-type-arg ndes-info))
		;; Then the defn
		(format output  "~2%~a ~a(~a) {"
			(C-info-type-out ndes-info)
			id
			(C-info-type-arg ndes-info))
		(format output "~%~a}"  (C-info-definition des-info))))
	    (when des-info
	      (let ((id (C-info-id des-info)))
		;; First the signature
		(format output  "~2%~a ~a(~a) {"
			(C-info-type-out des-info)
			id
			(C-info-type-arg des-info))
		(format outputH "~2%~a ~a(~a);"
			(C-info-type-out des-info)
			id
			(C-info-type-arg des-info))
		;; Then the defn
		(format output "~%~a}"  (C-info-definition des-info)))))))))))




;; TODO handle the duplication of variable
;; f(x:int) = let x = 2 in x
;; x#0 generated  -> x_0 for isntance


;; Useless functions ?/

(defun pvs2C-assign-rhs (assignments bindings livevars)
  (when (consp assignments)
    (let* ((e (expression (car assignments)))
	   (C-assign-expr (pvs2C e
				 bindings
				 (append (updateable-vars
					  (arguments (car assignments)))
					 (append (updateable-vars (cdr assignments))
						 livevars))))
	   (*lhs-args* nil))
      (cons C-assign-expr
	    (pvs2C-assign-rhs (cdr assignments) bindings
			      (append (updateable-free-formal-vars e)
				      livevars))))))




(defmacro debug (array str)
  `(when (eq ',array '*C-destructions*)
       (break (format nil "~a ~a : ~a~%" ',str ',array ,array))))


;; Deprecated
(defmacro pvsC_update (array index value)
  `(let ((update-op (if (and *destructive?* *C-livevars-table*)
			(format nil "pvsDestructiveUpdate")
			(format nil "pvsNonDestructiveUpdate"))))
       (format nil  "~a(~a, ~a, ~a);" update-op ,array ,index ,value)))




;; To add in the .el files

;; (defpvs pvs-C-file find-file (filename)
;;   "Generates the C code for a given file and displays it in a buffer"
;;   (interactive (pvs-complete-file-name "Generate C for file: "))
;;   (unless (interactive-p) (pvs-collect-theories))
;;   (pvs-bury-output)
;;   (message "Generating C for file...")
;;   (pvs-send-and-wait (format "(generate-C-for-pvs-file \"%s\")"
;; 			 filename) nil nil 'dont-care)
;;   (let ((buf (pvs-find-C-file filename)))
;;     (when buf
;;       (message "")
;;       (save-excursion
;; 	(set-buffer buf)
;; 	(setq pvs-context-sensitive t)
;; 	(lisp-mode)))))

;; (defun pvs-find-C-file (filename)
;;   (let ((buf (get-buffer (format "%s.c" filename))))
;;     (when buf
;;       (kill-buffer buf)))(format 
;;   (let ((C-file (format "%s%s.c" pvs-current-directory filename)))
;;     (when (file-exists-p C-file)
;;       (find-file-read-only-other-window C-file))))
