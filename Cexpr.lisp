;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                PVS to C translator
;;
;;     Author: Gaspard ferey
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; This requires "pvs2c.lisp", "Cutils.lisp" and "Cprimop.lisp" files both available at
;;               https://github.com/Gaspi/pvs2c.git
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; Defining here a intermediate language between C and PVS

;; -------- Classe result of translating functions -------------------
(defcl C-expr () (type) (name) (instr) (destr))
(defun mk-C-expr (type name instr destr)
  (make-instance 'C-expr :type type
		        :name name
			:instr instr
			:destr destr))

(defun mk-simple-C-expr (type name)
  (mk-C-expr type name nil nil))
(defmethod get-C-var ((e C-expr))
  (C-var (type e) (name e)))



(defmethod set-type ((C-expr C-expr) (type C-type))
  (setf (type C-expr) type))
(defmethod set-name ((C-expr C-expr) name)
  (setf (name C-expr) name))
(defmethod set-instr ((C-expr C-expr) instr)
  (setf (instr C-expr) instr))
(defmethod set-destr ((C-expr C-expr) destr)
  (setf (destr C-expr) destr))

(defmethod app-instr ((C-expr C-expr) instr &optional first)
  (setf (instr C-expr)
	(if first
	    (append instr (instr C-expr))
	  (append (instr C-expr) instr))))
(defmethod app-destr ((C-expr C-expr) destr &optional first)
  (setf (destr C-expr)
	(if first
	    (append destr (destr C-expr))
	    (append (destr C-expr) destr))))


(defmethod unnamed? ((C-expr C-expr))
  (null (name C-expr)))



(defmethod define-name ((C-expr C-expr) name)
  (when (unnamed? C-expr)
    (set-name C-expr name)
    (set-instr C-expr (define-name (instr C-expr) name))
    (set-destr C-expr (define-name (destr C-expr) name)))
  C-expr)
(defmethod define-name ((lst list) name)
  (when (consp lst)
    (cons (define-name (car lst) name)
	  (define-name (cdr lst) name))))


;; (defmethod define-name (e name)
;;   (fill-hole e name))  ;; base case -> call to fill-hole


;; (defgeneric fill-hole (e name))
;; (defmethod fill-hole ((lst list) name)
;;   (when (consp lst)
;;     (cons (fill-hole (car lst) name)
;; 	  (fill-hole (cdr lst) name))))
;; (defmethod fill-hole ((str string) name)
;;   (format nil str name))




;; --------------------------------------------------------------------
;;           CLOS supertypes representation for fragments of C code
;; --------------------------------------------------------------------

;; ------- Supertype : list of expressions in that expression --------
(defcl Cexpr () (exprs))
(defun Cexpr () (make-instance 'Cexpr :exprs nil))

;; TODO use that
(defmethod exprs ((l list)) (mapcar #'exprs l))


;; --------------------------------------------------------------------
;;               CLOS representation of C expressions      
;; --------------------------------------------------------------------

;; -------- A C variable : is a C type and a name (string or hole) ----
(defcl C-var (Cexpr) (type) (name))
(defun C-var (type &optional name exprs)
  (make-instance 'C-var :type type :name name :exprs exprs))
(defun C-var-list (types names)
  (when (consp types) (cons (C-var (car types) (car names))
			    (C-var-list (cdr types) (cdr names)))))
(defun gen-C-var (type prefix) (C-var type (gentemp (format nil "~a" prefix))))
(defmethod unnamed? ((C-var C-var))
  (or (not (name C-var))
      (and (stringp (name C-var))
	   (string= (name C-var) "~a"))))
;; Here are type functions that can be also applied to variables
(defmethod pointer? ((obj C-var)) (C-pointer? (type obj)))
(defmethod bang-type ((variable C-var))
  (C-var (bang-type (type variable)) (name variable)))


;; ------- Accessor to a record type var :  var.e ------
(defcl Crecord-get (Cexpr) (var) (arg) (type))
(defun Crecord-get (var arg)
  (make-instance 'Crecord-get :var var :arg arg
		 :type (cdr (assoc arg (args (type var))))
		 :exprs (list var)))

;; ------- Accessor to an array type var :  var[e] ------
(defcl Carray-get (Cexpr) (var) (arg) (type))
(defun Carray-get (var arg)
  (make-instance 'Carray-get :var var :arg arg
		 :type (target (type var))
		 :exprs (list var arg)))

;; -------- Function call : f(e1, ... , e2) ---------
;; May or may not have a valid type
(defcl Cfuncall (Cexpr) (fun) (args) (type))
(defun Cfuncall (fun &optional args type)
  (set-arguments
   (make-instance 'Cfuncall :fun (Cfun fun) :args nil :type type :exprs nil)
   args))
(defmethod set-arguments ((Cfuncall Cfuncall) argts)
  (let ((args (if (listp argts) argts (list argts))))
    (setf (args Cfuncall) args)
    (setf (exprs Cfuncall) (loop for a in args
				 when (Cexpr? a) collect it))
    Cfuncall))






;; --------------------------------------------------------------------
;;           CLOS representation of a full line of C code 
;; --------------------------------------------------------------------

;; --------------------- Supertype for instructions -------------------
(defcl Cinstr (Cexpr))

;; --------- Declaration of a variable : int* T; ----------------------
(defcl Cdecl (Cinstr) (var))
(defun Cdecl (var)
  (make-instance 'Cdecl :var var :exprs (list var)))

;; -------- Initialisation of a variable : mpz_init(a); ---------------
(defcl Cinit (Cinstr) (var))
(defun Cinit (var)
  (make-instance 'Cinit :var var :exprs (list var)))
;; This function should be used
(defun Calloc (v) (list (Cdecl v) (Cinit v)))


;; -------- Free a variable : GC_free(T);  mpz_clear(a); --------------
(defcl Cfree (Cinstr) (var))
(defun Cfree (var) (make-instance 'Cfree :var var :exprs nil))

;; -------- A = 2; ------------  Is not used...
(defcl Cassign (Cinstr) (var) (expr))
(defun Cassign (var expr)
  (make-instance 'Cassign :var var :expr expr :exprs (list expr)))

;; ------- MPZ function call (instruction) : mpz_?(res, ...);  --------
(defcl Cfuncall-mp (Cinstr) (Cfunc))
(defun Cfuncall-mp (fun &optional args)
  (let ((fc (Cfuncall fun args)))
    (make-instance 'Cfuncall-mp :Cfunc fc :exprs (list fc))))
(defmethod set-arguments ((Cfuncall Cfuncall-mp) argts)
  (set-arguments (Cfunc Cfuncall) argts))


;; -------- If instructions ------------------------------------------
(defcl Cif (Cinstr) (var) (cond-part) (then-part) (else-part))
(defun Cif (cond-part then-part else-part)
  (make-instance 'Cif :exprs (list cond-part then-part else-part)
		 :cond-part cond-part
		 :then-part then-part
		 :else-part else-part))


(defcl Carray-init (Cinstr) (var) (body) (i))
(defun Carray-init (var body i)
  (make-instance 'Carray-init
		 :var var :body body :i i :exprs (cons var body)))

;; --------------- Return instruction ---------------
(defcl Creturn (var))
(defun Creturn (var) (make-instance 'Creturn :var var))


;; ---- Creates a copy of varB and name it varA --------------
;; Uses the three flags need-bang, safe and arg-bang to know if
;;   A = B;
;;   A = copy(B);
;;   if GC = 1 then A = B else A = copy(B);
(defcl Ccopy (Cinstr) (varA) (varB) (safe) (arg-bang))
(defun Ccopy (varA varB)
  (make-instance 'Ccopy :varA varA :varB varB :exprs (list varB)
		 :safe nil :arg-bang nil))



;; Takes a C instruction (list) with a hole and return a list of string
(defun create-loop (body size &optional (prefix "i") (start 0))
  (let* ((i (gen-C-var *C-int* prefix))
	 (for-body (get-C-instructions (define-name body i))))
    (when for-body
      (append
       (list (format nil "int ~a;" i)
	     (format nil "for(~a = ~a; ~a < ~a; ~a++) {" i start i size i))
       (indent for-body)
       (list "}")))))








;; --------------------------------------------------------------------
;;           CLOS representation of C functions
;; --------------------------------------------------------------------

(defcl Cfun () (name) (spec-op) (destr))
(defmethod Cfun ((f Cfun) &optional spec-op destr)
  (make-instance 'Cfun :name (name f) :spec-op (spec-op f)
		       :destr (or destr (destr f))))
(defmethod Cfun (name &optional spec-op destr)
  (make-instance 'Cfun :name name :spec-op spec-op :destr destr))

(defmethod print-object ((obj Cfun) out)
  (with-slots (name destr) obj
   (format out "~a"
      (if (const-decl? name)
	  (C-info-id (gethash name
	      (if destr *C-destructive-hash* *C-nondestructive-hash*)))
	name))))

;; --------- Generating functions ----------------
(defun mp-cmp (zq op)
  (Cfun (format nil "~a_cmp" zq)
	(format nil "(~a_cmp(~~{~~a~~^, ~~}) ~a 0)" zq op)))

(defun binop (op)
  (let ((bop (if (eql op '||) "||" op)))
    (Cfun (format nil "pvs_~a" bop)
	  (format nil "(~~{~~a~~^ ~a ~~})" bop))))

(defvar *pvs-cmp* (Cfun "pvsCmp"))
(defvar *pvs-neg* (Cfun "pvs-neg" "(-~{~a~})"))


;; --------------------------------------------------------------------
;;           Managing holes in expressions
;; --------------------------------------------------------------------
(defmacro rec-dn (v arg)
  `(setf (,arg ,v) (define-name (,arg ,v) name)))

(defmethod define-name ((v C-var) name)
  (if (unnamed? v)
      (if (C-expr? name)
	  name
	(progn (setf (name v) name) v))
    (progn (setf (name v) (define-name (name v) name))
	   v)))

(defmethod define-name ((e Crecord-get) name)
  (rec-dn e var)
;;  (setf (var e) (define-name (var e) name))
  e)

(defmethod define-name ((e Carray-get) name)
  (rec-dn e var) (rec-dn e arg) e)

(defmethod define-name ((e Cfuncall) name)
  (rec-dn e args) e)

(defmethod define-name ((i Cfuncall-mp) name)
  (rec-dn i func) i)

(defmethod define-name ((i Cdecl) name)
  (rec-dn i var) i)

(defmethod define-name ((i Cfree) name)
  (rec-dn i var) i)

(defmethod define-name ((i Cassign) name)
  (rec-dn i var) (rec-dn i expr) i)

(defmethod define-name ((e Ccopy) name)
  (rec-dn e varA) (rec-dn e varB) e)

(defmethod define-name ((e Cif) name)
  (rec-dn e cond-part) (rec-dn e then-part) (rec-dn e else-part) e)

(defmethod define-name ((e Carray-init) name)
  (rec-dn e i) (rec-dn e var) (rec-dn e body) e)

;; Should never be called...
(defmethod define-name ((e Creturn) name) (rec-dn e var) e)

(defmethod define-name ((str string) name)
  (format nil str name))

(defmethod define-name (e name) e)


;; --------------------------------------------------------------------
;;           C code generation
;; --------------------------------------------------------------------

(defmethod print-object ((obj C-var) out)
  (if (name obj) (format out "~a" (name obj)) "~a"))

(defmethod print-object ((obj Carray-get) out)
  (format out "~a[~a]" (var obj) (arg obj)))

(defmethod print-object ((obj Crecord-get) out)
  (format out "~a->~a" (var obj) (arg obj)))



(defmethod print-object ((obj Cfuncall) out)
  (with-slots (fun args) obj
    (format out
	    (if (spec-op fun) (spec-op fun)
	      (format nil "~a(~~{~~a~~^, ~~})" fun))
	    args)))

;; ---- Default print function for Cinstr --------
(defmethod print-object ((obj Cinstr) out)
  (format out "~{~a~^~%~}" (get-C-instructions obj)))



;; ------- C lines of code are generated here --------
(defmethod get-C-instructions ((instr Cdecl))
  (let ((var (var instr)))
    (list (format nil "~a ~a;" (type var) var))))

;; 
(defmethod get-C-instructions ((instr Cinit))
  (let* ((var (var instr))
	 (type (type var)))
    (cond ((C-mpz? type) (list (format nil "mpz_init(~a);" var)))
	  ((C-mpq? type) (list (format nil "mpq_init(~a);" var)))
	  ((C-struct? type)
	   (get-C-instructions
	    (mapcar #'(lambda (x) (Cinit (Crecord-get var (car x))))
		    (args type))))
	  ;; Record type should actually have an empty init...
	  (t nil))))


;; ----------- C variables memory deallocation -------------
(defmethod get-C-instructions ((instr Cfree))
  (let* ((var (var instr))
	 (type (type var)))
    (cond ((C-mpz? type) (list (format nil "mpz_clear(~a);" var)))
	  ((C-mpq? type) (list (format nil "mpq_clear(~a);" var)))
	  ((C-pointer? type)
	   (let ((arg (if (C-struct? type)
			   (get-C-instructions
			    (mapcar #'(lambda (x) (Cfree (Crecord-get var (car x))))
				    (args type)))
			 (create-loop (Cfree (Carray-get var (C-var *C-int*)))
				      (size type)))))
	     (append (when arg (append (list (format nil "if( GC_count( ~a ) == 1 ) {" var))
				       (indent arg)
				       (list "}")))
		     (list (format nil "GC_free(~a)" var)))))
	  (t nil))))

(defmethod get-C-instructions ((instr Cassign))
  (list (format nil "~a = ~a;" (var instr) (expr instr))))

(defmethod get-C-instructions ((instr Cfuncall-mp))
  (list (format out "~a;" (Cfunc instr))))

(defmethod get-C-instructions ((instr return))
  (list (format nil "return ~a;" (var instr))))

(defmethod get-C-instructions ((instr Cif))
  (append (list (format nil "if (~a) {" (cond-part instr)))
	  (indent (get-C-instructions (then-part instr)))
	  (list "} else {")
	  (indent (get-C-instructions (else-part instr)))
	  (list "}")))

(defmethod get-C-instructions ((instr Carray-init))
  (with-slots (body i) instr
  (let* ((var (var instr))
	 (type (type var))
	 (l (size type)))
    (append (list (format nil "~a = GC_malloc(~a, sizeof(~a) );" var l (target type))
		  (format nil "int ~a;" i)
		  (format nil "for(~a = 0; ~a < ~a; ~a++) {" i i l i))
	    (indent (get-C-instructions (list (Cinit (Carray-get var i)) body)))
	    (list "}")))))

(defmethod get-C-instructions ((instr list))
  (when (consp instr)
    (append (get-C-instructions (car instr))
	    (get-C-instructions (cdr instr)))))

(defmethod get-C-instructions (instr)
  (list (format nil "Unknown instruction  : ~a" instr)))




;; --------------------------------------------------------------------
;;           C code generation for updates (Ccopy objects)
;; --------------------------------------------------------------------
(defmethod get-C-instructions ((instr Ccopy))
  (let* ((varA (varA instr))
	 (typeA (type varA))
	 (varB (varB instr))
	 (typeB (type varB)))
    (cond ((C-gmp? typeA)
	   (mapcar #'(lambda (x) (format nil x varA varB)) (convertor typeA typeB)))
	  ((and (C-pointer-type? typeA) (slot-value typeA 'bang)) ;; If we want a bang version
	   (get-bang-copy-array typeA varA typeB varB instr))
	  ((and (C-struct? typeA) (slot-value typeA 'bang)) ;; If we want a bang version
	   (get-bang-copy-struct typeA varA typeB varB instr))
	  (t (list (format nil "~a = ~a;" varA
			   (if (and (type= typeA typeB)
				    (not (C-pointer-type? typeA))
				    (not (C-struct? typeA)))
			       varB
			     (format nil (convertor typeA typeB) varB))))))))

(defun get-bang-copy-array (typeA nameA typeB nameB instr)
  (cond ((not (safe instr))    ;; If we can't reuse B because it appears later in the code
	 (append (list (format nil "~a = GC_malloc(~a, sizeof(~a) );"
			       nameA (size typeA) (target typeA)))
		 (create-loop (Ccopy (Carray-get (varA instr) (C-var *C-int*))
				     (Carray-get (varB instr) (C-var *C-int*)))
			      (size typeB))))
	((arg-bang instr) ;; If B never appears later and is of type bang
	 (list (format nil "~a = GC( ~a );" nameA nameB)))
	(t ;; If B never appears later but is not bang (a priori). We check the GC
	 (append
	  (list (format nil "if ( GC_count( ~a ) == 1 )" nameB)
		(format nil "  ~a = GC( ~a );" nameA nameB)
		(format nil "else {")
		(format nil "  ~a = GC_malloc(~a, sizeof(~a) );"
			nameA (size typeA) (target typeA)))
	  (indent (create-loop (Ccopy (Carray-get (varA instr) (C-var *C-int*))
				      (Carray-get (varB instr) (C-var *C-int*)))
			       (size typeB)))
	  (list "}")))))

(defun get-bang-copy-struct (typeA nameA typeB nameB instr)
  (cond ((not (safe instr))    ;; If we can't reuse B because it appears later in the code
	 (append (list (format nil "~a = GC_malloc(1, sizeof(~a));" nameA typeA))
		 (get-C-instructions
		  (loop for a in (args typeA)
			collect (Ccopy (Crecord-get (varA instr) (car a))
				       (Crecord-get (varB instr) (car a)))))))
	((arg-bang instr) ;; If B never appears later and is of type bang
	 (list (format nil "~a = GC( ~a );" nameA nameB)))
	(t ;; If B never appears later but is not bang (a priori). We check the GC
	 (append
	  (list (format nil "if ( GC_count( ~a ) == 1 )" nameB)
		(format nil "  ~a = GC( ~a );" nameA nameB)
		(format nil "else {")
		(format nil "~a = GC_malloc(1, sizeof(~a));" nameA typeA))
	  (indent (get-C-instructions
		   (loop for a in (args typeA)
			 collect (Ccopy (Crecord-get (varA instr) (car a))
					(Crecord-get (varB instr) (car a))))))
	  (list "}")))))
;; TODO in the malloc above, replace typeA by the real struct name (not the name of the pointer)








;; vars are lists of var (name is-argument is-bang)
(defcl Cfunction () (all-vars) (bang-args) (body))
(defun Cfunction (body args)
  (make-instance 'Cfunction
		 :bang-args (mapcar #'name args)
		 :all-vars (make-hash-table :test #'string=)
		 :body body))


;; TODO  define correctly the hashtables
;;    C-info-definition should probably contain a Cfunction object
;;    print-object of a Cfunction should replace the string
;;    C-info-type-arg should contain a list of var and should be sent to Cfunction

;; TODO pvs2C et cie should return a C-var instead of type, name
