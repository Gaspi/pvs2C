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
(defmethod unnamed? ((C-var C-var))
  (or (not (name C-var))
      (and (stringp (name C-var))
	   (string= (name C-var) "~a"))))


(defmethod define-name ((C-expr C-expr) name)
  (set-name C-expr name)
  (set-instr C-expr (define-name (instr C-expr) name))
  (set-destr C-expr (define-name (destr C-expr) name))
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
(defun gen-C-var (type prefix) (C-var type (gentemp prefix)))
(defmethod pointer? ((obj C-var)) (C-pointer? (type obj)))



;; ------- Accessor to a record type var :  var.e ------
(defcl Crecord-get (Cexpr) (var) (arg))
(defun Crecord-get (var arg)
  (make-instance 'Crecord-get :var var :arg arg :exprs (list var)))

;; ------- Accessor to an array type var :  var[e] ------
(defcl Carray-get (Cexpr) (var) (arg))
(defun Carray-get (var arg)
  (make-instance 'Carray-get :var var :arg arg :exprs (list var arg)))

;; -------- Function call : f(e1, ... , e2) ---------
(defcl Cfuncall (Cexpr) (fun) (args))
(defun Cfuncall (fun &optional args)
  (set-arguments
   (make-instance 'Cfuncall :fun (Cfun fun) :args nil :exprs nil)
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


;; ------- MPZ function call (instruction) : mpz_?(res, ...);  --------
(defcl Cfuncall-mp (Cinstr) (Cfunc))
(defun Cfuncall-mp (fun &optional args)
  (let ((fc (Cfuncall fun args)))
    (make-instance 'Cfuncall-mp :Cfunc fc :exprs (list fc))))
(defmethod set-arguments ((Cfuncall Cfuncall-mp) argts)
  (set-arguments (Cfunc Cfuncall) argts))


;; --------- Declaration of a variable : int* T; ----------------------
(defcl Cdecl (Cinstr) (var))
(defun Cdecl (var)
  (make-instance 'Cdecl :var var :exprs nil))

(defcl Cfree (Cinstr) (var))
(defun Cfree (var)
  (make-instance 'Cdecl :var var :exprs nil))



(defcl Cif (Cinstr) (var) (cond-part) (then-part) (else-part))
(defun Cif (var cond-part then-part else-part)
  (make-instance 'Cdecl
		 :var var
		 :cond-part cond-part
		 :then-part then-part
		 :else-part else-part
		 :exprs nil))


;; TODO
;; (defcl Calloc (Cinstr) (C-var))
;; (defcl Cif (Cinstr) (condition) (if-part) (then-part))





;; ---------- C allocation -------------
(defmethod C-alloc ((type C-struct))
  (loop for a in (args type)
	collect (define-name (C-alloc (cdr a)) (format nil "~~a.~a" (car a)))))
(defmethod C-alloc ((type C-mpz))
  (list "mpz_init(~a);"))
(defmethod C-alloc ((type C-mpq))
  (list "mpq_init(~a);"))
(defmethod C-alloc ((type C-type)) nil)

(defmethod C-alloc ((l list))
  (when (consp l) (append (C-alloc (car l)) (C-alloc (cdr l)))))

(defmethod C-alloc ((v C-var)) (list (Cdecl v)))


;; ----------- C variables memory deallocation -------------
(defgeneric C-free (arg))
(defmethod C-free ((type C-mpz))     (list "mpz_clear(~a);"))
(defmethod C-free ((type C-mpq))     (list "mpq_clear(~a);"))
(defmethod C-free ((type C-pointer-type))
  (append
   (when (C-pointer? (target type))
     (create-loop (C-free (target type)) "~~a[~a]" (size type)))
   (list "GC_free(~a);")))
(defmethod C-free ((type C-struct))
  (append (append-lists
	   (loop for e in (args type)
		 collect (C-free (C-var (cdr e) (format nil "~~a.~a" (cdr e))))))
	  (list "free(~a);")))
(defmethod C-free ((type C-pointer)) (list "free(~a);"))
(defmethod C-free ((type C-type))    nil)
(defmethod C-free ((v C-var))
  (list (Cfree v)))



;; TODO pvs2C et cie should return a C-var instead of type, name

;; --------------------------------------------------------------------
;;           CLOS representation of C functions
;; --------------------------------------------------------------------

(defcl Cfun () (name) (resol) (spec-op))
(defmethod Cfun ((f Cfun) &optional resol spec-op)
  (make-instance 'Cfun :name (name f) :resol (resol f) :spec-op (spec-op f)))
(defmethod Cfun (name &optional resol spec-op)
  (make-instance 'Cfun :name name :resol resol :spec-op spec-op))


;; --------- Generating functions ----------------
(defun mp-cmp (zq op)
  (Cfun (format nil "~a_cmp" zq) nil
	(format nil "(~a_cmp(~~{~~a~~^, ~~}) ~a 0)" zq op)))

(defun binop (op)
  (let ((bop (if (eql op '||) "||" op)))
    (Cfun (format nil "pvs_~a" bop) nil
	  (format nil "(~~{~~a~~^ ~a ~~})" bop))))

(defvar *pvs-cmp* (Cfun "pvsCmp"))
(defvar *pvs-neg* (Cfun "pvs-neg" nil "(-~{~a~})"))

(defvar *mpz_neg* (Cfun "mpz_neg"))
(defvar *mpq_neg* (Cfun "mpq_neg"))



(defvar *mpz_add* (Cfun "mpz_add"))
;; TODO define others...


;; --------------------------------------------------------------------
;;           Managing holes in expressions
;; --------------------------------------------------------------------


(defmethod define-name ((v C-var) name)
  (if (unnamed? v)
      (if (C-expr? name)
	  name
	(progn (setf (name v) name) v))
    v))

(defmethod define-name ((e Crecord-get) name)
  (setf (var e) (define-name (var e) name)) e)

(defmethod define-name ((e Carray-get) name)
  (setf (var e) (define-name (var e) name)) e)

(defmethod define-name ((e Cfuncall) name)
  (setf (args e) (define-name (args e) name)) e)

(defmethod define-name ((i Cfuncall-mp) name)
  (setf (Cfunc i) (define-name (Cfunc i) name)) i)

(defmethod define-name ((i Cdecl) name)
  (setf (var i) (define-name (var i) name)) i)

(defmethod define-name (e name) e)

;; --------------------------------------------------------------------
;;           C code generation
;; --------------------------------------------------------------------

(defmethod print-object ((obj C-expr) out) (format out "~a" (name obj)))

(defmethod print-object ((obj C-var) out) (format out "~a" (name obj)))

(defmethod print-object ((obj Carray-get) out)
  (format out "~a[~a]" (var obj) (arg obj)))

(defmethod print-object ((obj Crecord-get) out)
  (format out "~a.~a" (var obj) (arg obj)))

(defmethod print-object ((obj Cfun) out) (format out "~a" (name obj)))

(defmethod print-object ((obj Cfuncall) out)
  (with-slots (fun args) obj
    (format out
	    (if (spec-op fun) (spec-op fun)
	      (format nil "~a(~~{~~a~~^, ~~})" fun))
	    args)))

(defmethod print-object ((obj Cfuncall-mp) out)
  (format out "~a;" (Cfunc obj)))

(defmethod print-object ((obj Cdecl) out)
    (format out "~a ~a;" (type (var obj)) (var obj)))

(defmethod print-object ((obj Cfree) out)
  (with-slots (type name) (var obj)
    (format out (define-name (C-free type) name))))


;; Generate C lines of code here

(defmethod get-C-instructions ((instr Cif))
  (list ))

(defmethod get-C-instructions ((instr Cdecl))
  (with-slots (type name) (var obj)
    (cons (format nil "~a ~a;" type name)
	  (define-name (C-alloc type) name))))

(defmethod get-C-instructions ((instr Cfree))
  (with-slots (type name) (var obj)
    (define-name (C-free type) name)))


(defmethod get-C-instructions (instr)
  (list (format nil "~a" instr)))
