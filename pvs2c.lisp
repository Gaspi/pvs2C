
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;   Author: Gaspard ferey
;; --------------------------------------------------------------------
;;   Draft clean translator modified
;; --------------------------------------------------------------------

(in-package :pvs)

;; Bad practice ???
(load "Ctypes")
(load "Cprimop")1


(defvar *livevars-table* nil)
(defvar *C-record-defns* nil)

;; Instructions to allocate memory for new variables
(defvar *C-instructions* nil)
(defun reset-instructions () (setf *C-instructions* nil))
(defun add-instructions (instructions)
  (setf *C-instructions* (append *C-instructions* instructions)))
(defun add-instruction (instruction)
  (setf *C-instructions* (append *C-instructions* (list instruction))))
(defun add-instructions-first (instructions)
  (setf *C-instructions* (append instructions *C-instructions*)))

;; Instructions to destruct previously allocated memory
(defvar *C-destructions* nil)
(defun reset-destructions () (setf *C-destructions* nil))
(defun add-destructions (destructions)
  (setf *C-destructions* (append *C-destructions* destructions)))
(defun add-destruction (destruction)
  (setf *C-destructions* (append *C-destructions* (list destruction))))


(defvar *C-definitions* nil)
(defun reset-definitions () (setf *C-definitions* nil))
(defun add-definition (definition)
  (setf *C-definitions* (append *C-definitions* (list definition))))


(defmacro pvs2C-error (msg &rest args)
  `(format t ,msg ,@args))

(defmacro pvsC_update (array index value)
  `(let ((update-op (if (and *destructive?* *livevars-table*)
			(format nil "pvsDestructiveUpdate")
			(format nil "pvsNonDestructiveUpdate"))))
       (format nil  "~a(~a, ~a, ~a)" update-op ,array ,index ,value)))

(defvar *C-nondestructive-hash* (make-hash-table :test #'eq))
(defvar *C-destructive-hash* (make-hash-table :test #'eq))



(defun getConstantName (expr bindings)
  (when (name-expr? expr)
      (cdr (assoc (declaration expr) bindings :key #'declaration))))


(defun apply-argument (instructions arg)
  (mapcar #'(lambda (x) (format nil x arg)) instructions))


(defmethod pvs2C ((expr list) bindings livevars exp-type)
  (pvs2C-list expr bindings livevars nil exp-type))

(defun pvs2C-list (l bindings livevars exp-type accum)
  (if (consp l)
      (let ((carExpr (pvs2C (car l) bindings
			(append (updateable-vars (cdr l)) livevars)
			(car exp-type)))
	    (newAccu (append *C-destructions* accum)))
	(reset-destructions)
	(cons carExpr
	      (pvs2C-list (cdr l) bindings                        ;;need car's freevars
		     (append (updateable-vars (car l))  ;;f(A, A WITH ..)
			     livevars) (cdr exp-type) newAccu)))
    (progn
      (add-destructions accum)
      nil)))



;;;; ---------  Needs refactoring using pvs2C2  !!!
(defmethod pvs2C-if ((expr if-expr) bindings livevars exp-type need-malloc)  ;result
  (cond ((branch? expr)   ;; What is this condition ? Does it mean (not-trivillay-false?)  ?
     (let* ((condition (condition expr))
        (then-part (then-part expr))
        (else-part (else-part expr))
        (newlivevars (append (updateable-vars then-part)
                 (append (updateable-vars else-part)
                     livevars)))
        (C-condition (pvs2C condition bindings newlivevars C-int))
        (previous-instr *C-instructions*)
        (previous-destr *C-destructions*))
       (reset-instructions)
       (reset-destructions)
       (let ((C-then-part (pvs2C* then-part bindings livevars result))
         (C-then-instructions *C-instructions*)
         (C-then-destructions *C-destructions*))
     (reset-instructions)
     (reset-destructions)
     (let ((C-else-part (pvs2C* else-part bindings livevars result))
           (C-else-instructions *C-instructions*)
           (C-else-destructions *C-destructions*))
       (reset-instructions)
       (reset-destructions)
       (add-instructions previous-instr)
       (add-destructions previous-destr)
       (if need-malloc
	   (progn (add-instructions (C-alloc result))
		  (add-destructions (C-free  result))))
       (add-instruction (format nil "if(~a) {" C-condition))
       (add-instructions (mapcar
                  #'(lambda (x) (format nil "  ~a" x))
                  C-then-instructions))
       (add-instruction (format nil "  ~a" C-then-part))
       (add-instructions (mapcar
                  #'(lambda (x) (format nil "  ~a" x))
                  C-then-destructions))
       (add-instruction "} else {")
       (add-instructions (mapcar
                  #'(lambda (x) (format nil "  ~a" x))
                  C-else-instructions))
       (add-instruction (format nil "  ~a" C-else-part))
       (add-instructions (mapcar
                  #'(lambda (x) (format nil "  ~a" x))
                  C-else-destructions))
       (add-instruction "}")
       ))))
     (t (call-next-method))))


(defmethod pvs2C* ((expr if-expr) bindings livevars)
  (let* ((type (pvs-type-2-C-type expr))
	 (if-bloc (pvs2C-if expr bindings livevars type nil)))
    (cons type
	  (if (pointer? type) if-bloc
	    (let ((if-name (gentemp "if")))
	      (add-instructions (apply-argument if-bloc if-name))
	      if-name)))))

(defmethod pvs2C ((expr if-expr) bindings livevars exp-type)
  (let* ((type (pvs-type-2-C-type expr))
	 (if-bloc (pvs2C-if expr bindings livevars type t))
	 (if-name (gentemp "if")))
    (add-instructions (apply-argument if-bloc if-name))
    (convert exp-type type if-name)))



(defun pvs2C2 (expr bindings livevars type name)
  (if (not (pointer? type))
      (let ((e (pvs2C expr bindings livevars type)))
	(add-instruction (format nil "~a = ~a;" name e))
	(add-instructions *C-destructions*)
	(reset-destructions))
    (let* ((e (pvs2C* expr bindings livevars))
	   (type-e (car e)))
      (if (eq type-e type)
	  (progn
	    (add-instructions (apply-argument (cdr e) name))
	    (add-instructions *C-destructions*)
	    (reset-destructions))
	(if (pointer? type-e)
	    (let ((n (gen-C-var typeA "set")))
	      (add-instructions (C-alloc n))
	      (add-instructions (apply-argument (cdr e) n))
	      (add-instructions *C-destructions*)
	      (reset-destructions)
	      (add-instruction (set type name type-e n))
	      (add-instructions (C-free n)))
	  (progn
	      (add-instruction (set type name type-e (cdr e)))
	      (add-instructions *C-destructions*)
	      (reset-destructions)))))))


(defmethod pvs2C (expr bindings livevars exp-type)
  (let ((name (getConstantName expr bindings)))
    (if name
	(convert exp-type (pvs-type-2-C-type expr) name)
      (let* ((l (length *C-destructions*))
	     (e (pvs2C* expr bindings livevars)) ;; Returns an instructions (ends with *)
	     (type (car e)))
	(if (pointer? type)
	    (let ((n (gen-C-var type "aux")))
	      (add-instructions (C-alloc n))
	      (add-instructions (apply-argument (cdr e) n))
	      (add-instructions *C-destructions*)
	      (reset-destructions)
	      (add-destructions (C-free n))
	      (convert exp-type type n))
	  (if (eq l (length *C-destructions*)) ; If it's a very simple expression
	      (convert exp-type type (cdr e))
	    (let* ((type (C-type e))
		   (n (gen-C-var type "aux")))
		(add-instructions (C-alloc n)) ;; probably empty
		(add-instruction (format nil "~a ~a = ~a;" type n (cdr e)))
		(add-instructions *C-destructions*)
		(reset-destructions)
		(add-destructions (C-free n)) ; probably empty
		(convert exp-type (C-type e) n))))))))



; --- set and conversion functions need to be implemented correctly here ---

(defun convert (typeA typeB e)
  (if (eq typeA typeB)
      e
    (let ((n (gen-C-var typeA "conv")))
      (add-instructions (C-alloc n))
      (add-destructions (C-free n))
      (add-instruction (set typeA n typeB e))
      n)))

(defun set (typeA nameA typeB nameB)
  (if (pointer? typeA)
      (format nil "~a(~a, ~a);" (convertor typeA typeB) nameA nameB)
    (if (eq typeA typeB)
	(format nil "~a = ~a;" nameA nameB)
      (format nil "~a = ~a(~a);" nameA (convertor typeA typeB) nameB))))

(defun convertor (typeA typeB)
  (if (eq typeA typeB)
      (format nil "copy_~a" typeA)
    (format nil "~a_from_~a" typeA typeB)))



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


(defmethod pvs2C* ((expr number-expr) bindings livevars)
  (declare (ignore bindings livevars))
  (let ((type (pvs-type-2-C-type expr)))
    (cons type
       (if (pointer? type)
	   (let (op (cond ((eq (type-of type) 'C-mpz) "mpz_set_str")
			  ((eq (type-of type) 'C-mpq) "mpq_set_str")
			  (t "setUnknown")))
	     (list (format nil "~a(~~a, \"~a\");" op (number expr))))
	 (format nil "~a" (number expr))))))

(defmacro pvs2C_tuple (args)
  `(format nil "(~{~a~^, ~})" ,args))

;; Should be modified to create a different tuple according to the type of the args
(defmethod pvs2C* ((expr tuple-expr) bindings livevars)
  (let* ((elts (exprs expr))
	 (args (pvs2C elts bindings livevars
		      (mapcar #'pvs-type-2-C-type elts))))
    (mk-C-funcall "createTuple" (cons "~a" args))))

(defmethod pvs2C* ((expr record-expr) bindings livevars)
  (let* ((sorted-assignments (sort-assignments (assignments expr)))
	 (formatted-fields
	  (loop for entry in sorted-assignments
		collect (format nil "~~a.~a = ~a;"
			  (caar (arguments entry))
			  (pvs2C (expression entry)
				 bindings livevars)))))
    (cons (pvs-type-2-C-type expr)
	  (format nil "struct record ~~a;" formatted-fields))))

(defun matchlist (index length dummy)
  (if (eql index 0)
	(if (eql length 0)
	    (list dummy)
	    (cons dummy (enlist (1- length))))
      (cons '_ (matchlist (1- index)(1- length) dummy))))

(defun enlist (n)
  (if (eql n 0)
      nil
      (cons '_ (enlist (1- n)))))

(defmethod pvs2C* ((expr projection-application) bindings livevars)
  (let* ((ll (length (exprs expr)))
	 (dummy (gentemp "DDD"))
	 (match-list (pvs2C_tuple (matchlist (index expr) ll dummy)))
	 (expr-list (pvs2C expr bindings livevars)))
    `(let ,match-list = ,expr-list in ,dummy)))
	


(defmethod pvs2C*  ((expr field-application) bindings livevars)
  (let* ((clarg (pvs2C (argument expr) bindings livevars ))
	 (id (id expr))
	 (e (format nil "~a.~a" clarg id))
	 (type (pvs-type-2-C-type expr)))
    (cons type
	  (if (pointer? type)
	      (set type "~a" type e)
	    e))))

;; When is this function called ??  (not working)
(defmethod pvs2C* ((expr list) bindings livevars)
  (if (consp expr)
      (cons (pvs2C (car expr) bindings
		   (append (updateable-vars (cdr expr)) livevars) )
	    (pvs2C (cdr expr) bindings  ;;need car's freevars
		   (append (updateable-vars (car expr)) ;;f(A, A WITH ..)
			   livevars)))
    nil))

(defun pair3lis (l1 l2 l3)
  (if (consp l1)
      (cons (list (car l1) (car l2) (car l3)) (pair3lis (cdr l1) (cdr l2) (cdr l3)))))

(defmethod pvs2C* ((expr application) bindings livevars)
  (with-slots (operator argument) expr
    (if (constant? operator)
      (if (pvs2cl-primitive? operator)
	    (pvs2C*-primitive-app expr bindings livevars)
	  (if (datatype-constant? operator)
	      (cons (pvs-type-2-C-type (range (type operator)))
		    (mk-C-funcall (pvs2C-resolution operator)
				  (pvs2C (arguments expr) bindings livevars)))
	    (pvs2C-defn-application expr bindings livevars)))
      (if (lambda? operator)
	  (let* ((bind-decls (bindings operator))
		 (bind-ids (pvs2cl-make-bindings bind-decls bindings))
		 (newbind (append (pairlis bind-decls bind-ids) bindings))
		 (type-args (C-type-args operator))
		 (C-arg (pvs2C (if (tuple-expr? argument)
				   (exprs argument)
				   (list argument))
			       bindings
			       (append (updateable-free-formal-vars operator) livevars)
			       type-args)))
	    (add-instructions (mapcar
			       #'(lambda (x) (format nil "~a ~a = ~a;"
						     (car x)
						     (cadr x)
						     (caddr x)))
			       (pair3lis type-args (bindings operator) C-arg))) ; process name
	    (pvs2C* (expression operator) newbind nil))
	 (let ((type (pvs-type-2-C-type (range (type operator))))
	       (C-arg (pvs2C argument bindings
			     (append (updateable-free-formal-vars operator) livevars) ))
	       (C-op (pvs2C operator bindings
			    (append (updateable-vars argument) livevars) )))
	   (cons type
		 (if (C-updateable? (type operator))
		     (if (pointer? type)
			 (format nil "pvsSelect(~~a, ~a, ~a);" C-op C-arg)
		       (format nil "pvsSelect(~a, ~a);" C-op C-arg))
		   (if (pointer? type)
		       (set-C-pointer C-op "~a" C-arg)
		     (mk-C-funcall C-op C-arg)))))))))


(defun constant-formals (module)
  (loop for x in (formals module)
	when (formal-const-decl? x)
	collect (make-constant-from-decl x)))

(defun pvs2C-defn-application (expr bindings livevars)
  (with-slots (operator argument) expr
    (pvs2C-resolution operator)
    (let* ((actuals (expr-actuals (module-instance operator)))
	   (op-decl (declaration operator))
	   (args (arguments expr))
	   (C-args (pvs2C (append actuals args) bindings livevars )))
      (if *destructive?*
	  (let* ((ret-type (pvs-type-2-C-type (range (type operator))))
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
	    (cons ret-type (list
			    (if (pointer? ret-type)
				(set-C-pointer id-op "~a" C-args)
			      (mk-C-funcall id-op C-args))))))
      (cons ret-type (list
		      (if (pointer? ret-type)
			  (set-C-pointer (C_id operator) "~a" C-args)
			(mk-C-funcall (C_id operator) C-args)))))))

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
	 (cl-type-out (pvs-type-2-C-type range-type))
	 (pointer-out (pointer? cl-type-out))
	 (result-var (C-var cl-type-out "result"))
	 (cl-body (pvs2C2 body id-map nil cl-type-out "result"))
	 (cl-type-arg (format nil "~{~a~^, ~}"
	      (append (when pointer-out (list (format nil "~a result" cl-type-out)))
		      (loop for var in formals
			    collect (format nil "~a ~a"
					    (pvs-type-2-C-type (type var))
					    (cdr (assoc var id-map)) )))))
	 (hash-entry (gethash op-decl *C-nondestructive-hash*)))
    (format t "~%Defining (nondestructively) ~a with ~%type ~a -> ~a ~%as ~a" (id op-decl) cl-type-arg cl-type-out cl-body)
    (setf (C-info-type-out hash-entry) (if pointer-out "void" cl-type-out)
	  (C-info-type-arg hash-entry) cl-type-arg
	  (C-info-definition hash-entry)
	      (format nil "~{  ~a~%~}  ~a~%~{  ~a~%~}~:[  return result;~%~;~]"
		      *C-instructions* cl-body *C-destructions* pointer-out))
    (reset-instructions)
    (reset-destructions)
      ))

(defun pvs2C-resolution-destructive (op-decl formals body range-type)
  (let* ((*destructive?* t)
	 (*output-vars* nil)
	 (bind-ids (pvs2cl-make-bindings formals nil))
	 (id-map (pairlis formals bind-ids))
	 (cl-type-out (pvs-type-2-C-type range-type))
	 (pointer-out (pointer? cl-type-out))
	 (result-var (C-var cl-type-out "result"))
	 (cl-body (pvs2C2 body id-map nil cl-type-out "result"))
	 (cl-type-arg (format nil "~{~a~^, ~}"
	      (append (when pointer-out (list (format nil "~a result" cl-type-out)))
		      (loop for var in formals
			collect (format nil "~a ~a"
					(pvs-type-2-C-type (type var))
					(cdr (assoc var id-map)))))))
	 (hash-entry (gethash op-decl *C-destructive-hash*))
	 (old-output-vars (C-info-analysis hash-entry)))
    (format t "~%Defining (destructively) ~a with ~%type ~a -> ~a ~%as ~a" (id op-decl) cl-type-arg cl-type-out cl-body)
    (unless pointer-out (add-instructions-first (C-alloc result-var)))
    (setf (C-info-type-out hash-entry) (if pointer-out "void" cl-type-out)
	  (C-info-type-arg hash-entry) cl-type-arg
	  (C-info-definition hash-entry)
	      (format nil "~{  ~a~%~}  ~a~%~{  ~a~%~}~:[  return result;~%~;~]"
		      *C-instructions* cl-body *C-destructions* pointer-out)
	  (C-info-analysis hash-entry) *output-vars*)
    (reset-instructions)
    (reset-destructions)
    (unless (equalp old-output-vars *output-vars*)
      (pvs2C-resolution-destructive op-decl formals body range-type))))


(defmethod pvs2C* ((expr name-expr) bindings livevars)
  (let* ((type-e (pvs-type-2-C-type expr))
	 (decl (declaration expr))
	 (bnd (assoc decl bindings :key #'declaration))
	 (prim (pvs2cl-primitive? expr)))
    (assert (not (and bnd (const-decl? decl))))
    (cond (bnd  (cons type-e (cdr bnd)))
	  (prim (pvs2C*-primitive-cste expr bindings livevars))
	  ((const-decl? decl)
	        (pvs2C*-constant expr decl bindings livevars))
	  (t
	        (let ((undef (undefined expr "Hit untranslateable expression ~a")))
		  `(funcall ',undef))))))

(defun pvs2C*-constant (expr op-decl bindings livevars)
  (let* ((type-e (pvs-type-2-C-type expr))
	 (defns (def-axiom op-decl))
	 (defn (when defns (args2 (car (last (def-axiom op-decl))))))
	 (def-formals (when (lambda-expr? defn)
			(bindings defn))))
    (pvs2C-resolution expr)
    (if def-formals 
	(let ((eta-expansion
	       (make!-lambda-expr def-formals
		    (make!-application* expr
		       (loop for bd in def-formals
			     collect (mk-name-expr bd))))))
	  (pvs2C* eta-expansion bindings livevars))
	(let* ((actuals (expr-actuals (module-instance expr)))
	       (C-actuals (pvs2C actuals bindings livevars)))
	  (cons type-e
		(if (pointer? type-e)
		    (list (set-C-pointer (C_nondestructive_id expr) "~a" C-actuals))
		  (mk-C-funcall (C_nondestructive_id expr) C-actuals)))))))









;; ---------------  Refactoring point ---------------------








(defun range-arr (max &key (min 0) (step 1))
   (loop for n from min below max by step
      collect n))

(defun pvs2C-lambda (bind-decls expr bindings) ;;removed livevars
  (let ((previous-instr *C-instructions*))
    (reset-instructions)
    (let* ((*destructive?* nil)
	   (bind-ids (pvs2cl-make-bindings bind-decls bindings))
	   (cl-body (pvs2C expr
			    (append (pairlis bind-decls bind-ids)
				    bindings)
			    nil))
	   (name (gentemp "fun"))
	   (range-type (pvs-type-2-C-type (type expr)))
	   (fv (free-variables expr))
	   (nb-args (length fv))
	   (var-ind (pairlis fv (range-arr nb-args)))
	   (param-def (mapcar #'(lambda (x) (format nil "~a ~a = (~a)args[~a];"
						     (pvs-type-2-C-type (type (car x)))
						     (id (car x))
						     (pvs-type-2-C-type (type (car x)))
						     (cdr x)))
			       var-ind))
	   (def-instructions *C-instructions*))
      (reset-instructions)
      (add-instructions previous-instr)
      (add-definition (format nil "~a ~a(void *args) {~%~{  ~a~%~}~{  ~a~%~}  return ~a;~%}"
			      range-type name param-def def-instructions  cl-body))
      (add-instruction (format nil "void args[~d];" nb-args))
      (let ((assign (loop for x in bindings when (assoc (cdr x) var-ind
							:test #'(lambda (x y) (eq x (id y)) )) collect it)))
	(add-instructions (mapcar #'(lambda (x)
				      (format nil "args[~d] = ~a;" (cdr x) (id (car x))))
				  assign))
	(cons (make-instance 'C-closure)
	      (list (format nil "makeClosure(~~a, ~a, args);" name)))))))



(defmethod pvs2C* ((expr lambda-expr) bindings livevars)
  (declare (ignore livevars))
  (let ((type (type expr))
	(C-expr (pvs2C-lambda (bindings expr)
			      (expression expr)
			      bindings)))
    (if (and (C-updateable? type) (funtype? type))
	(format nil "(Function ~a ~a);" (array-bound type) C-expr)    ;; not working
      C-expr)))



(defmethod pvs2C* ((expr cases-expr) bindings livevars)
  (format nil "case ~a of ~{~%~a~}"
    (pvs2C (expression expr) bindings livevars)
    (pvs2C-cases (selections expr) (else-part expr) bindings livevars)))

(defun pvs2C-cases (selections else-part bindings livevars)
  (let ((selections-C
	 (loop for entry in selections
	       collect
	       (let* ((bind-decls (args entry))
		      (bind-ids (pvs2cl-make-bindings bind-decls bindings)))
		 (format nil "~a ~{~a ~} -> ~a"
			 (pvs2C (constructor entry) bindings livevars)
			 bind-ids
			 (pvs2C (expression entry)
				     (append (pairlis bind-decls bind-ids) bindings)
				     livevars))))))
    (if else-part
	(format nil "~a ~% _ -> ~a"
	  selections-C
	  (pvs2C (expression else-part) bindings livevars))
	selections-C)))

(defmethod pvs2C* ((expr update-expr) bindings livevars)
  (if (C-updateable? (type (expression expr)))
      (if (and *destructive?*
	       (not (some #'maplet? (assignments expr))))
	  (let* ((expression (expression expr))
		 (assignments (assignments expr))
		 (*livevars-table* 
		  (no-livevars? expression livevars assignments))
		 )
	    ;;very unrefined: uses all
	    ;;freevars of eventually updated expression.
	    (cond (*livevars-table* ;; check-assign-types
		   (push-output-vars (car *livevars-table*)
				     (cdr *livevars-table*))
		   (pvs2C-update expr bindings livevars))
		  (t
		   (when (and *eval-verbose* (not *livevars-table*))
		     (format t "~%Update ~s translated nondestructively. Live variables ~s present"
			       expr livevars))
		   (pvs2C-update expr bindings livevars))))
	  (pvs2C-update expr bindings livevars))
      (cons (pvs-type-2-C-type expr)
	    (pvs2C (translate-update-to-if! expr) bindings livevars))))

(defun pvs2C-update (expr bindings livevars)
  (with-slots (type expression assignments) expr
    (let* ((assign-exprs (mapcar #'expression assignments))
	   (exprvar (gentemp "E"))
	   (C-expr (pvs2C expression bindings
				(append (updateable-free-formal-vars
					 assign-exprs)
					;;assign-args can be ignored
					livevars) )))
      (cons (pvs-type-2-C-type type)
	    (format nil "~a"
		    (pvs2C-update* (type expression)
				   C-expr exprvar
				   (mapcar #'arguments assignments)
				   assign-exprs
				   bindings
				   (append (updateable-vars expression)
					   livevars)
				   (list (list (pvs-type-2-C-type type) exprvar C-expr))))))))

(defun pvs2C-assign-rhs (assignments bindings livevars)
  (when (consp assignments)
      (let ((C-assign-expr (pvs2C (expression (car assignments))
					   bindings
					   (append (updateable-vars
						    (arguments (car assignments)))
						   (append (updateable-vars (cdr assignments))
					   livevars)) ))
	    (*lhs-args* nil))
	(cons C-assign-expr
	      (pvs2C-assign-rhs (cdr assignments) bindings
				    (append (updateable-free-formal-vars
					     (expression (car assignments)))
					    livevars))))))



;;recursion over updates in an update expression
(defun pvs2C-update* (type expr exprvar assign-args assign-exprs bindings livevars accum)
  (if (consp assign-args)
      (let* ((*lhs-args* nil)
	     (assign-exprvar (gentemp "R"))
	     (C-assign-expr
	      (pvs2C (car assign-exprs)
			  bindings
			  (append (updateable-vars (cdr assign-exprs))
				  (append (updateable-vars (cdr assign-args))
					  livevars)) ))
	     (newexprvar (gentemp "N"))
	     (new-accum (pvs2C-update-nd-type
		       type exprvar newexprvar
		       (car assign-args)
		       assign-exprvar
		       bindings
		       (append (updateable-free-formal-vars (car assign-exprs))
			       (append (updateable-vars (cdr assign-exprs))
				       (append (updateable-vars (cdr assign-args))
					       livevars)))
		       accum))
	     (lhs-bindings (nreverse *lhs-args*))
	     (cdr-C-output
	      (pvs2C-update*
	       type expr
	       newexprvar
	       (cdr assign-args)(cdr assign-exprs) bindings
	       (append (updateable-free-formal-vars (car assign-exprs))
		       livevars) 
		       new-accum )))
	(add-instructions-first (list (format nil "~a ~a = ~a;"
					(pvs-type-2-C-type (type (car assign-exprs)))
					assign-exprvar C-assign-expr)))
	(add-instructions-first (mapcar #'(lambda (x) (format nil "~{~a ~a = ~a;~}" x)) lhs-bindings))
	cdr-C-output)
    (progn 
        (add-instructions (mapcar #'(lambda (x) (format nil "~{~a ~a = ~a;~}" x)) (nreverse accum)))
;;        (format nil "~:{~a ~a = ~a~%~}~a" (nreverse accum) exprvar)
	exprvar)))
     	  


;;recursion over nested update arguments in a single update.
(defun pvs2C-update-nd-type (type expr newexprvar args assign-expr
					   bindings livevars accum)
  (if (consp args)
      (pvs2C-update-nd-type* type expr newexprvar (car args) (cdr args) assign-expr
			      bindings livevars accum)
      (cons (list (pvs-type-2-C-type type) newexprvar assign-expr) accum)))

(defmethod pvs2C-update-nd-type* ((type funtype) expr newexprvar arg1 restargs
				   assign-expr bindings livevars accum)
  (let* ((arg1var (gentemp "L"))
	 (C-arg1 (pvs2C  (car arg1) bindings
				 (append (updateable-vars restargs)
					 livevars) )))
    (push (list (pvs-type-2-C-type (type (car arg1))) arg1var C-arg1) *lhs-args*)
    (if (consp restargs)
	(let* (
	       (exprvar (gentemp "E"))
	       (exprval (format nil "pvsSelect(~a, ~a)" expr arg1var))
	       (newexprvar2 (gentemp "N"))
	       (newaccum
		(pvs2C-update-nd-type 
		 (range type) exprvar newexprvar2
		 restargs assign-expr bindings livevars
		 (cons (list (pvs-type-2-C-type type) exprvar exprval) accum))))
	  (cons (list (pvs-type-2-C-type type) newexprvar (pvsC_update expr arg1var newexprvar2))
		newaccum)
	  )
	(cons (list (pvs-type-2-C-type type) newexprvar (pvsC_update expr arg1var assign-expr))
	      accum))))



(defmethod pvs2C-update-nd-type* ((type recordtype) expr newexprvar arg1 restargs
				   assign-expr bindings livevars accum)
  (let ((id (id (car arg1))))
	(if (consp restargs)
	    (let* (
		   (exprvar (gentemp "E"))
		   (new-expr (format nil "~a.~a" expr id))
		   (field-type (type (find id (fields type) :key #'id) ))
		   (newexprvar2 (gentemp "N"))
		   (newaccum (pvs2C-update-nd-type field-type exprvar newexprvar2
						       restargs assign-expr bindings
						       livevars
						       (cons (list (pvs-type-2-C-type type) exprvar new-expr) accum))))
	      (cons (list (pvs-type-2-C-type type) newexprvar (format nil "{~a & ~a = ~a}" expr id newexprvar2)) newaccum))
	    (cons (listn (pvs-type-2-C-type type) ewexprvar (format nil "{~a & ~a = ~a}" expr id assign-expr))
		  accum))))

(defmethod pvs2C-update-nd-type* ((type subtype) expr newexprvar arg1 restargs
				   assign-expr bindings livevars accum)
  (pvs2C-update-nd-type* (find-supertype type) expr newexprvar arg1 restargs
			  assign-expr bindings livevars accum))




;;C-updateable? is used to check if the type of an updated expression
;;is possibly destructively. 

(defmethod C-updateable? ((texpr tupletype))
  (C-updateable? (types texpr)))

;;this is the only case where C-updateable? can be false, because
;;the given function type is not an array.  
(defmethod C-updateable? ((texpr funtype)) ;;add enum types, subrange.
  (and (or (simple-below? (domain texpr))(simple-upto? (domain texpr)))
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

(defmethod C-updateable? ((texpr t))
  t) ;;It is okay to say  C-updateable? for uninterpreted
;;or actuals since these will not be updated destructively or otherwise.
  
(defun pvs2C-theory (theory)
  (reset-instructions)
  (reset-destructions)
  (let* ((theory (get-theory theory))
	 (*current-theory* theory)
	 (*current-context* (context theory)))
    (cond ((datatype? theory)
	   (pvs2C-datatype theory)
	   ;;(pvs2C-theory (adt-theory theory))
	   ;;(let ((map-theory (adt-map-theory theory))
	   ;;   (reduce-theory (adt-reduce-theory theory)))
	   ;;   (when map-theory (pvs2C-theory (adt-map-theory theory)))
	   ;;   (when reduce-theory (pvs2C-theory (adt-reduce-theory theory))))
	   )
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
			       (progn
				 (pvs2C-declaration decl))))
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
      (break "What to di with constant formals?")))

(defun pvs2C-constructors (constrs datatype tvars)
  (pvs2C-constructors* constrs datatype tvars))

(defun pvs2C-constructors* (constrs datatype tvars)
  (when constrs
    (cons (pvs2C-constructor (car constrs) datatype tvars)
	  (pvs2C-constructors* (cdr constrs) datatype tvars))))

;;; Maps to ConstructorDef
(defun pvs2C-constructor (constr datatype tvars)
  (format nil "~a~{ ~a~}" (id constr)
	  (mapcar #'(lambda (arg) (pvs-type-2-C-type (type arg) tvars))
	    (arguments constr))))

(defun clear-C-hash ()
  (clrhash *C-nondestructive-hash*)
  (clrhash *C-destructive-hash*))

(defun generate-C-for-pvs-file (filename &optional force?)
  (setq *C-record-defns* nil)
  (clrhash *C-nondestructive-hash*)
  (clrhash *C-destructive-hash*)
  (reset-destructions)
  (reset-definitions)
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
      (format output  "/*~%C file generated from ~a.pvs" filename)
      (format output  "~%Make sure to link GMP and PVS.c in compilation:")
      (format output  "~%    gcc -o ~a ~a.c PVS.c -lgmp" filename filename)
      (format output  "~%    ./~a~%*/" filename)
      (format outputH "// C file generated from ~a.pvs" filename)
      (format output  "~2%#include<stdio.h>")
      (format output   "~%#include \"PVS.h\"")
      (format output   "~%#include \"~a.h\"" filename)
      (format output   "~2%#define TRUE 1")
      (format output   "~%#define FALSE 0")
      (format output "~2%int main(void) {")
      (format output  "~%  printf(\"Executing ~a ...\\n\");" filename)
      (format output  "~%  return 0;~%}")
      (format output "~{~2%~a~}" *C-definitions*)
      (dolist (theory theories)
	(dolist (decl (theory theory))
	  (let ((ndes-info (gethash decl *C-nondestructive-hash*))
		(des-info (gethash decl *C-destructive-hash*)))
	    (when ndes-info
	      (let ((id (C-info-id ndes-info)))
		;; First the signature
		(format output  "~2%~a ~a(~a) {"
			(C-info-type-out ndes-info)
			id
			(C-info-type-arg ndes-info))
		(format outputH "~2%~a ~a(~a);"
			(C-info-type-out ndes-info)
			id
			(C-info-type-arg ndes-info))
		;; Then the defn
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





;; Old code

;(defun line-split (string)
;  (loop for start = 0 then (1+ finish)
;        for finish = (position #\Newline string :start start)
;        collecting (subseq string start finish)
;        until (null finish)))
