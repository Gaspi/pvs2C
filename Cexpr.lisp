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
(defcl C-expr () (var) (instr) (destr))
(defun C-expr (var &optional instr destr)
  (make-instance 'C-expr :var var :instr instr :destr destr))
(defun mk-C-expr (type name &optional instr destr)
  (C-expr (C-var type name) instr destr))

(defmethod type ((e C-expr)) (type (var e)))
(defmethod name ((e C-expr)) (name (var e)))
;; (defmethod type ((e list))
;;   (when (consp e) (cons (type (car e)) (type (cdr e)))))
;; (defmethod name ((e list))
;;   (when (consp e) (cons (name (car e)) (name (cdr e)))))
(defmethod var ((e list))
  (when (consp e) (cons (var (car e)) (var (cdr e)))))


(defun set-var (C-expr var) (setf (var C-expr) var))
(defmethod set-type ((C-expr C-expr) (type C-type))
  (setf (type (var C-expr)) type))
(defmethod set-name ((C-expr C-expr) name)
  (setf (name (var C-expr)) name))
(defmethod set-instr ((C-expr C-expr) instr)
  (setf (instr C-expr) instr))
(defmethod set-destr ((C-expr C-expr) destr)
  (setf (destr C-expr) destr))

(defmethod app-instr ((C-expr C-expr) instr &optional first)
  (set-instr C-expr
	     (if first
		 (append instr (instr C-expr))
	       (append (instr C-expr) instr))))
(defmethod app-destr ((C-expr C-expr) destr &optional first)
  (set-destr C-expr
	     (if first
		 (append destr (destr C-expr))
	       (append (destr C-expr) destr))))

(defmethod unnamed? ((C-expr C-expr))
  (and (C-var? (var C-expr)) (unnamed? (var C-expr))))




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
(defcl C-var (Cexpr) (type) (name) (safe))
(defun C-var (type &optional name exprs safe)
  (make-instance 'C-var :type type
		 :name (if (listp name) name
			 (format nil "~a" name)) ;; names must be strings
		 :exprs exprs :safe safe))
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
(defun eq-C-var (x y)
  (and (C-var? x)
       (C-var? y)
       (stringp (name x))
       (stringp (name y))
       (string= (name x) (name y))))
(defun sign-var (C-var)
  (format nil "~a ~a" (type C-var) (name C-var)))
(defun safe-var (v) (C-var (type v) (name v) (exprs v) t))

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
    ;; (setf (exprs Cfuncall) (loop for a in args
    ;; 				 when (Cexpr? a) collect it))
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
(defcl Cset (Cinstr) (var) (expr))
(defun Cset (var expr)
  (make-instance 'Cset :var var :expr expr :exprs (list expr)))

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

(defcl Crecord-init (Cinstr) (var))
(defun Crecord-init (var)
  (make-instance 'Crecord-init :var var :exprs (list var)))



;; --------------- Return instruction ---------------
(defcl Creturn (Cinstr) (var))
(defun Creturn (var) (make-instance 'Creturn :var var))


;; ---- Creates a copy of varB and name it varA --------------
;; Uses the three flags need-bang, safe and arg-bang to know if
;;   A = B;
;;   A = copy(B);
;;   if GC = 1 then A = B else A = copy(B);
(defcl Ccopy (Cinstr) (varA) (varB) (safe))
(defun Ccopy (varA varB)
  (make-instance 'Ccopy :varA varA :varB varB :exprs (list varB)  :safe nil))



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

(defmethod define-name ((C-expr C-expr) name)
  (when (unnamed? C-expr)
    (rec-dn C-expr var)
    (rec-dn C-expr instr)
    (rec-dn C-expr destr))
  C-expr)

(defmethod define-name ((v C-var) name)
  (if (unnamed? v)
      (if (Cexpr? name) name
	(progn (setf (name v) (format nil "~a" name)) v))
    (progn (rec-dn v name) v)))

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

(defmethod define-name ((i Cinit) name)
  (rec-dn i var) i)

(defmethod define-name ((i Cfree) name)
  (rec-dn i var) i)

(defmethod define-name ((i Cset) name)
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

(defmethod define-name ((lst list) name)
  (when (consp lst)
    (cons (define-name (car lst) name)
	  (define-name (cdr lst) name))))

(defmethod define-name (e name) e)


;; --------------------------------------------------------------------
;;           C code generation
;; --------------------------------------------------------------------

(defmethod print-object ((obj C-var) out)
  (format out
	  (if (and *Cshow-safe* (safe obj)) "*~a*" "~a")
	  (if (name obj) (name obj) "~a")))

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



;; ------------ C lines of code are generated here ----------
(defmethod get-C-instructions ((instr Cdecl))
  (let ((var (var instr)))
    (list (format nil "~a ~a;" (type var) var))))

;; 
(defmethod get-C-instructions ((instr Cinit))
  (let* ((var (var instr))
	 (type (type var)))
    (cond ((C-mpz? type) (list (format nil "mpz_init(~a);" var)))
	  ((C-mpq? type) (list (format nil "mpq_init(~a);" var)))
	  ;; ((C-struct? type)
	  ;;  (get-C-instructions
	  ;;   (mapcar #'(lambda (x) (Cinit (Crecord-get var (car x))))
	  ;; 	    (args type))))
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
		     (list (format nil "GC_free(~a);" var)))))
	  (t nil))))

(defmethod get-C-instructions ((instr Cfuncall-mp))
  (list (format out "~a;" (Cfunc instr))))

(defmethod get-C-instructions ((instr Creturn))
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

(defmethod get-C-instructions ((instr Crecord-init))
  (let* ((var    (var instr))
	 (type   (type var)))
    (cons (format nil "~a = GC_malloc(1, sizeof( struct_~a ) );" var type)
	  (get-C-instructions (mapcar
			       #'(lambda (x) (Cinit (Crecord-get var (car x))))
			       (args type))))))

(defmethod get-C-instructions ((instr list))
  (when (consp instr)
    (append (get-C-instructions (car instr))
	    (get-C-instructions (cdr instr)))))

(defmethod get-C-instructions (instr)
  (list (format nil "Unknown instruction  : ~a" instr)))




;; --------------------------------------------------------------------
;;           C code generation for updates (Ccopy objects)
;; --------------------------------------------------------------------
(defmethod get-C-instructions ((instr Cset))
  (let* ((varA (var  instr)) (typeA (type varA))
	 (varB (expr instr)) (typeB (type varB)))
    (if (C-gmp? typeA)
	(mapcar #'(lambda (x) (format nil x varA varB)) (convertor typeA typeB))
      (list (format nil "~a = ~a;" varA
		    (format nil (convertor typeA typeB) varB))))))

(defmethod get-C-instructions ((instr Ccopy))
  (let* ((varA (varA instr))
	 (typeA (type varA))
	 (varB (varB instr))
	 (typeB (type varB)))
    (cond ((C-gmp? typeA)
	   (mapcar #'(lambda (x) (format nil x varA varB)) (convertor typeA typeB)))
	  ((C-pointer? typeA)
	   (get-bang-copy typeA varA typeB varB instr))
	  (t (list (format nil "~a = ~a;" varA
			   (format nil (convertor typeA typeB) varB)))))))

(defmethod get-bang-copy ((typeA C-array) nameA typeB nameB instr)
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

(defmethod get-bang-copy ((typeA C-struct) nameA typeB nameB instr)
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




;; --------------------------------------------------------------------
;;                 C code analysis
;; --------------------------------------------------------------------

(defvar *C-bang-vars* nil)
(defun is-bang (Cvar)
  (and (C-var? Cvar) (member Cvar *C-bang-vars* :test #'eq-C-var)))

;; vars are lists of var (name is-argument is-bang)
(defcl Cfun-decl () (all-vars) (bang-vars) (body))
(defun Cfun-decl (body args)
  (safety-analysis body)
  (make-instance 'Cfun-decl
		 :bang-vars (init-bang-args args)
		 :all-vars (get-set (get-all-vars (list args body)))
		 :body body))

(defmethod print-object ((obj Cfun-decl) out)
  (format out "{~%~{~a~%~}}" (get-C-instructions obj)))
(defmethod get-C-instructions ((e Cfun-decl))
  (let ((*C-bang-vars* (bang-vars e)))
    (indent (get-C-instructions (body e)))))


(defun init-bang-args (args)
  (when (consp args)
    (let ((hd (car args))
	  (tl (init-bang-args (cdr args))))
      (if (C-pointer? (type hd))
	  (cons (name hd) tl)
	tl))))

(defun unionvar (x y) (union x y :test #'eq-C-var))  
(defun get-set (l)
  (if (consp l)
      (unionvar (get-set (car l)) (get-set (cdr l)))
    (when l (list l))))




;; ------- Maps f to all expressions and returns the concatenation of all results --------
(defmethod map-Cexpr ((l list) f)
  (when (consp l) (append (map-Cexpr (car l) f) (map-Cexpr (cdr l) f))))
(defmethod map-Cexpr ((v C-var) f)       (funcall f v))
(defmethod map-Cexpr ((e Crecord-get) f) (append (funcall f e) (map-Cexpr (var e) f)))
(defmethod map-Cexpr ((e Carray-get) f)  (append (funcall f e) (map-Cexpr (list (var e) (arg e)) f)))
(defmethod map-Cexpr ((e Cfuncall) f)    (append (funcall f e) (map-Cexpr (args e) f)))
(defmethod map-Cexpr ((i Cfuncall-mp) f) (append (funcall f i) (map-Cexpr (func i) f)))
(defmethod map-Cexpr ((i Cdecl) f)       (append (funcall f i) (map-Cexpr (var i) f)))
(defmethod map-Cexpr ((i Cinit) f)       (append (funcall f i) (map-Cexpr (var i) f)))
(defmethod map-Cexpr ((i Cfree) f)       (append (funcall f i) (map-Cexpr (var i) f)))
(defmethod map-Cexpr ((i Cset) f)     (append (funcall f i) (map-Cexpr (list (var i)  (expr i)) f)))
(defmethod map-Cexpr ((i Ccopy) f)       (append (funcall f i) (map-Cexpr (list (varA i) (varB i)) f)))
(defmethod map-Cexpr ((i Carray-init) f) (append (funcall f i) (map-Cexpr (list (var i)  (body i)) f)))
(defmethod map-Cexpr ((i Crecord-init) f)(append (funcall f i) (map-Cexpr (var i) f)))
(defmethod map-Cexpr ((i Creturn) f)     (append (funcall f i) (map-Cexpr (var i) f)))
(defmethod map-Cexpr ((i Cif) f)
  (append (funcall f i)  (map-Cexpr (list (cond-part i) (then-part i) (else-part i)) f)))
(defmethod map-Cexpr (e f) (break "Mapvars encountered unknown C expression..."))

;; ------------------- Maps f only to instructions ----------------------
(defun map-Cinstr (body f)
  (map-Cexpr body #'(lambda (x) (when (Cinstr? x) (f x)))))

;; --------------- Gets all pointer-type variables -----------------
(defun get-all-vars (body)
  (map-Cexpr body #'(lambda (x) (when (and (C-var? x) (C-pointer? (type x))) (list x)))))


;; --------- This function flags all last occurence of a variable -----------
(defmethod safety-analysis ((l list))
  (when (consp l)
    (let* ((safe (safety-analysis (cdr l)))
	   (vars (get-all-vars (car l)))
	   (candidates (set-difference vars safe :test #'eq-C-var))
	   (set-cand (get-set candidates)))
      (loop for e in set-cand
	    do (let ((c (count e candidates :test #'eq-C-var)))
		 (if (= c 1) (replace-vars (car l) (name e) (safe-var e))
		   (if (= c 0) (break)))))
      (unionvar set-cand safe))))








;; --------------- Maps update function f to all C expressions ----------------
(defmethod upd-Cexpr ((v C-var) f) (funcall f v))
(defmethod upd-Cexpr ((l list) f)
  (when (consp l) (cons (upd-Cexpr (car l) f)
			(upd-Cexpr (cdr l) f))))
(defmethod upd-Cexpr ((e Carray-get) f)
  (setf (var  e) (upd-Cexpr (var  e) f))
  (setf (arg  e) (upd-Cexpr (arg  e) f))
  (funcall f e))
(defmethod upd-Cexpr ((e Crecord-get) f) (setf (var  e) (upd-Cexpr (var  e) f)) (funcall f e))
(defmethod upd-Cexpr ((e Cfuncall) f)    (setf (args e) (upd-Cexpr (args e) f)) (funcall f e))
(defmethod upd-Cexpr ((i Cfuncall-mp) f) (setf (func i) (upd-Cexpr (func i) f)) (funcall f e))
(defmethod upd-Cexpr ((i Cdecl) f)       (setf (var  i) (upd-Cexpr (var  i) f)) (funcall f i))
(defmethod upd-Cexpr ((i Cinit) f)       (setf (var  i) (upd-Cexpr (var  i) f)) (funcall f i))
(defmethod upd-Cexpr ((i Cfree) f)       (setf (var  i) (upd-Cexpr (var  i) f)) (funcall f i))
(defmethod upd-Cexpr ((i Cset) f)
  (setf (var  i) (upd-Cexpr (var  i) f))
  (setf (expr i) (upd-Cexpr (expr i) f))
  (funcall f i))
(defmethod upd-Cexpr ((i Ccopy) f)
  (setf (varA i) (upd-Cexpr (varA i) f))
  (setf (varB i) (upd-Cexpr (varB i) f))
  (funcall f i))
(defmethod upd-Cexpr ((i Carray-init) f)
  (setf (var  i) (upd-Cexpr (var  i) f))
  (setf (body i) (upd-Cexpr (body i) f))
  (funcall f i))
(defmethod upd-Cexpr ((i Crecord-init) f) (setf (var i) (upd-Cexpr (var i) f)) (funcall f i))
(defmethod upd-Cexpr ((i Creturn) f)      (setf (var i) (upd-Cexpr (var i) f)) (funcall f i))
(defmethod upd-Cexpr ((i Cif) f)
  (setf (cond-part i) (upd-Cexpr (cond-part i) f))
  (setf (then-part i) (upd-Cexpr (then-part i) f))
  (setf (else-part i) (upd-Cexpr (else-part i) f))
  (funcall f i))
(defmethod upd-Cexpr (e f) (break "Mapvars encountered unknown C expression..."))

;; --------------- Gets all pointer-type variables -----------------
(defun replace-vars (body name new-var)
  (upd-Cexpr body #'(lambda (x) (if (and (C-var? x) (string= (name x) name)) new-var x))))



;; ----- The main analysis loop. The recursive call should terminate... ------------
(defun C-analysis (op-decl)
  (let ((f  (C-info-definition (gethash op-decl *C-nondestructive-hash*)))
	(fd (C-info-definition (gethash op-decl *C-destructive-hash*))))
    nil))
    ;; (and (or (C-analysis* f)
    ;; 	     (C-analysis* fd))  ;; if both return nil  (no change)  then return nil (lazy and)
    ;; 	 (C-analysis op-decl)))) ;; else try again



;; ------------------ Here is the body of the analysis ---------------
(defun C-analysis* (f)
  nil)


;; TODO This function gets a replace rule (name, var) from an instruction
;; This is treated by:
;;  - Deleting the decl and init of name
;   - Deleting the current set or copy instruction
;;  - Deleting the free of var
;;  - Replacing occurences of name by var
;;  - Unsafing all variables !!!
;;  - Redo a safe analysis
(defun get-replace-rule (i)
  (cond ((and (Cset? i)
	      (Cvar? (var i))
	      (Cvar? (expr i))
	      (safe (expr i)))
	 (cons (name (var i)) (expr i)))
	((and (Ccopy? i)
	      (Cvar? (var i))
	      (Cvar? (expr i))
	      (safe (expr i)))
	 (cons (name (var i)) (expr i)))
	(t nil)))





