;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                PVS to C translator
;;
;;     Author: Gaspard ferey
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; This requires "pvs2c.lisp" and "Cprimop.lisp" files both available at
;;               https://github.com/Gaspi/pvs2c.git
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(in-package :pvs)

;; Classes to represent C types
(defcl C-type ())
(defcl C-pointer (C-type))
(defcl C-number (C-type))
(defcl C-integer (C-number))
(defcl C-int (C-integer))
(defcl C-uli (C-integer))
(defcl C-mpz (C-integer C-pointer))
(defcl C-mpq (C-number C-pointer))
(defcl C-pointer-type (C-pointer) (target) (size))
(defcl C-struct (C-pointer) (name))
(defcl C-named-type (C-pointer) (name))
(defcl C-closure  (C-pointer))

;; Some instances of the classes above (to avoid over-instanciating)
(defvar *C-type* (make-instance 'C-type))
(defvar *C-int* (make-instance 'C-int))
(defvar *C-uli* (make-instance 'C-uli))
(defvar *C-mpz* (make-instance 'C-mpz))
(defvar *C-mpq* (make-instance 'C-mpq))

;; These constantas are C implementation dependent
(defvar *min-C-int* (- (expt 2 15)))
(defvar *max-C-int* (- (expt 2 15) 1))
(defvar *min-C-uli* 0)
(defvar *max-C-uli* (- (expt 2 32) 1))

;; Type equality  (mainly used to know if conversion is needed)
(defmethod type= ((typeA C-int) (typeB C-int)) t)
(defmethod type= ((typeA C-uli) (typeB C-uli)) t)
(defmethod type= ((typeA C-mpz) (typeB C-mpz)) t)
(defmethod type= ((typeA C-mpq) (typeB C-mpq)) t)
(defmethod type= ((typeA C-pointer-type) (typeB C-pointer-type))
  (and (type= (target typeA) (target typeB))
       (eq    (size   typeA) (size   typeB))))
(defmethod type= ((typeA C-struct) (typeB C-struct))
  (string= (name typeA) (name typeB)))
(defmethod type= ((typeA C-named-type) (typeB C-named-type))
  (string= (name typeA) (name typeB)))
(defmethod type= ((typeA C-closure) (typeB C-closure)) t)
(defmethod type= (typeA typeB) nil)

;; Type printing in C syntax
(defmethod print-object ((obj C-int) out) (format out "int"))
(defmethod print-object ((obj C-uli) out) (format out "unsigned long int"))
(defmethod print-object ((obj C-mpz) out) (format out "mpz_t"))
(defmethod print-object ((obj C-mpq) out) (format out "mpq_t"))
(defmethod print-object ((obj C-pointer-type) out) (format out "~a*" (slot-value obj 'target)))
(defmethod print-object ((obj C-struct) out) (format out "struct ~a" (slot-value obj 'name)))
(defmethod print-object ((obj C-named-type) out) (format out "~a" (slot-value obj 'name)))
(defmethod print-object ((obj C-closure) out) (format out "pvsClosure"))
(defmethod print-object ((obj C-type) out) (format out "[Abstract C type]"))

;; Translating PVS types to C types
(defmethod pvs2C-type ((type recordtype) &optional tbindings)
  (with-slots (print-type) type
    (if (type-name? print-type)
	(let ((entry (assoc (declaration print-type) *C-record-defns*)))
	  (if entry (make-instance 'C-struct :name (cadr entry))
	      (let* ((formatted-fields (loop for fld in (fields type)
				  collect
				  (format nil "~a ~a;" 
					  (pvs2C-type (type fld)) (id fld))))
		     (C-rectype-name (gentemp (format nil "pvs~a" (id print-type))))
		     (C-rectype (format nil "struct ~a {~%~{  ~a~%~}};"
					C-rectype-name formatted-fields)))
		(push (list (declaration print-type) C-rectype-name C-rectype)
		      *C-record-defns*)
		(make-instance 'C-struct :name C-rectype-name))))
	(pvs2C-error "~%Record type ~a must be declared." type))))

(defmethod pvs2C-type ((type tupletype) &optional tbindings)
  (make-instance 'C-named-type
		 :name (format nil "~{!~a~^_~}" (loop for elemtype in (types type)
				   collect (pvs2C-type elemtype)))))

(defmethod pvs2C-type ((type funtype) &optional tbindings)
  (if (C-updateable? type)
      (let ((range (subrange-index (domain type))))
	(make-instance 'C-pointer-type
		       :target (pvs2C-type (range type))
		       :size
		         (when (and (car range)
				    (cadr range)
				    (not (eq (car range) '*))
				    (not (eq (cadr range) '*)))
			   (1+ (- (cadr range) (car range))))))
    (make-instance 'C-closure)))

(defmethod pvs2C-type ((type subtype) &optional tbindings)
  (let ((range (subrange-index type)))
    (cond ((subtype-of? type *boolean*) *C-int*)
	  ((subtype-of? type *integer*)
	     (cond ((is-in-range? range *min-C-int* *max-C-int*) *C-int*)
		   ((is-in-range? range *min-C-uli* *max-C-uli*) *C-uli*)
		   (t *C-mpz*)))
	  ((subtype-of? type *number* ) *C-mpq*)
	  (t (pvs2C-type (find-supertype type))))))

(defmethod pvs2C-type ((type type-name) &optional tbindings)
  (with-slots (id) type
     (if (eq id 'boolean) *C-int*
       (make-instance 'C-named-type
		 :name (or (cdr (assoc type tbindings :test #'tc-eq))
			   (id type))))))


(defun C-type-args (operator)
  (let ((dom-type (domain (type operator))))
    (if (tupletype? dom-type)
	(pvs2C-type (types dom-type))
      (list (pvs2C-type dom-type)))))


(defun is-expr-subtype? (expr type)
  (some #'(lambda (jty) (subtype-of? jty type))
	(get-PVS-types expr)))

(defmethod get-bounds ((expr number-expr))
  (list (number expr) (number expr)))

(defmethod get-bounds ((expr expr))
  (get-inner-bounds-list (get-PVS-types expr) nil nil))

(defun get-inner-bounds-list (l inf sup)
  (if (consp l)
      (let ((range (subrange-index (car l))))
	(if range
	    (let ((ninf (car range))
		  (nsup (cadr range)))
	      (get-inner-bounds-list
	                  (cdr l)
			  (if inf (max inf ninf) ninf)
			  (if sup (min sup nsup) nsup)))
	  (get-inner-bounds-list (cdr l) inf sup)))
    (list inf sup)))

(defgeneric is-in-range? (e inf sup))
(defmethod is-in-range? ((interval list) inf sup)
  (and interval (car interval) (cadr interval)
       (<= inf (car interval))
       (<=     (cadr interval) sup)))
(defmethod is-in-range? ((t type-expr) inf sup)
  (is-in-range? (subrange-index t) inf sup))
(defmethod is-in-range? ((e expr) inf sup)
  (is-in-range? (get-bounds e) inf sup))

(defun C-integer-type? (expr)
  (is-expr-subtype? expr *integer*))
(defun C-unsignedlong-type? (expr)
  (and (C-integer-type? expr)
       (is-in-range? expr *min-C-uli* *max-C-uli*)))
(defun C-int-type? (expr)
  (and (C-integer-type? expr)
       (is-in-range? expr *min-C-int* *max-C-int*)))

(defmethod pvs2C-type ((e number-expr) &optional tbindings)
  (let ((n (number e)))
    (cond ((<= *min-C-int* n *max-C-int*) *C-int*)
	  ((<= 0 n *max-C-uli*) *C-uli*)
	  (t (pvs2C-type (type e))))))

(defmethod pvs2C-type ((e lambda-expr) &optional tbindings)
  (with-slots (type expression) e
  (if (C-updateable? type)
      (let ((range (subrange-index (domain type))))
	(make-instance 'C-pointer-type
		       :target (pvs2C-type expression)
		       :size (1+ (- (cadr range) (car range)))))
    (make-instance 'C-closure))))

(defmethod pvs2C-type ((e expr) &optional tbindings)
  (if (C-integer-type? e)
      (cond ((C-int-type? e) *C-int*)
	    ((C-unsignedlong-type? e) *C-uli*)
	    (t *C-mpz*))
    (pvs2C-type (type e))))


(defmethod pvs2C-type ((l list) &optional tbindings)
  (if (consp l)
      (cons (pvs2C-type (car l))
	    (pvs2C-type (cdr l)))
    nil))

(defun get-PVS-types (expr)
  (let ((*generate-tccs* t))
    (cons (type expr) (judgement-types+ expr))))




(defstruct C-var name type)
(defun C-var (type name) (make-C-var :name name :type type))
(defmethod print-object ((obj C-var) out)
  (format out "~a" (slot-value obj 'name)))
(defun var-type (arg) (slot-value arg 'type))
(defun var-name (arg) (slot-value arg 'name))
(defun gen-C-var (type prefix)
  (C-var type (gentemp prefix)))


(defmethod pointer? ((obj C-var)) (C-pointer? (var-type obj)))
(defmethod pointer? ((e expr)) (C-pointer? (pvs2C-type (type e))))



;; An expression to represent the memory size of a type
(defmethod m-size ((type C-pointer-type))
  (format nil "~a * sizeof(~a)" (size type) (target type)))
(defmethod m-size ((type C-type))
  (format nil "sizeof(~a)" type))


;; C variables memory allocation
(defgeneric C-alloc (arg))
(defmethod C-alloc ((type C-mpz))
  (list "mpz_init(~a);"))
(defmethod C-alloc ((type C-mpq))
  (list "mpq_init(~a);"))
(defmethod C-alloc ((type C-pointer-type))
  (with-slots (target size) type
    (cons (format nil "~~a = malloc( ~a );" (m-size type))
	  (when (C-pointer? target)
	    (let* ((i (gentemp "i"))
		   (name-i (format nil "~~a[~a]" i)))
	      (append
	       (list (format nil "for(int ~a = 0; ~a < ~a; ~a++) {" i i size i))
	       (mapcar #'(lambda (x) (format nil "  ~a" x))
		       (apply-argument (C-alloc target) name-i))
	       (list "}")))))))

(defmethod C-alloc ((type C-pointer))
  (list (format nil "~~a = malloc( ~a );" (m-size type))))

(defmethod C-alloc ((type C-type)) nil)
(defmethod C-alloc ((v C-var))
  (let ((type (var-type v))
	(name (slot-value v 'name)))
    (cons
     (format nil "~a ~a;" type name)
     (apply-argument (C-alloc type) name))))

;; C variables memory deallocation
(defgeneric C-free (arg))
(defmethod C-free ((type C-mpz))     (list "mpz_clear(~a);"))
(defmethod C-free ((type C-mpq))     (list "mpq_clear(~a);"))
(defmethod C-free ((type C-pointer)) (list "free(~a);"))
(defmethod C-free ((type C-type))    nil)
(defmethod C-free ((v C-var))
  (apply-argument (C-free (var-type v)) (var-name v)))




;; -------- Converting a C expression to an other type --------

;;; Add a case when the length is 1 (simple pointer)
;;;   Just do (get-typed-copy (target typeA) "nameA*" (target typeB) "nameB*"))
(defmethod get-typed-copy ( (typeA C-pointer-type) nameA (typeB C-pointer-type) nameB)
  (let* ((i (gentemp "i"))
	 (nameAi (format nil "~a[~a]" nameA i))
	 (nameBi (format nil "~a[~a]" nameB i)))
  (append
   (list (format nil "for(int ~a = 0; ~a < ~a; ~a++) {" i i (size typeB) i))
   (mapcar #'(lambda (x) (format nil "  ~a" x))
	   (get-typed-copy (target typeA) nameAi (target typeB) nameBi))
   (list "}"))))
(defmethod get-typed-copy ( (typeA C-pointer) nameA typeB nameB)
  (mapcar #'(lambda (x) (format nil x nameA nameB)) (convertor typeA typeB)))
(defmethod get-typed-copy (  typeA            nameA typeB nameB)
  (list (format nil "~a = ~a;" nameA
		(if (type= typeA typeB) nameB
		  (format nil (convertor typeA typeB) nameB)))))


(defgeneric convertor (typeA typeB))
(defmethod convertor ((typeA C-mpz) (typeB C-mpz)) (list "mpz_set(~a, ~a);"))
(defmethod convertor ((typeA C-mpz) (typeB C-mpq)) (list "mpq_get_num(~a, ~a);"))
(defmethod convertor ((typeA C-mpz) (typeB C-uli)) (list "mpz_set_ui(~a, ~a);"))
(defmethod convertor ((typeA C-mpz) (typeB C-int)) (list "mpz_set_si(~a, (long) ~a);"))
(defmethod convertor ((typeA C-mpq) (typeB C-mpq)) (list "mpq_set(~a, ~a);"
							 "mpq_canonicalize(~a);"))
(defmethod convertor ((typeA C-mpq) (typeB C-mpz)) (list "mpq_set_z(~a, ~a);"
							 "mpq_canonicalize(~a);"))
(defmethod convertor ((typeA C-mpq) (typeB C-uli)) (list "mpq_set_d(~a, (double) ~a );"
							 "mpq_canonicalize(~a);"))
(defmethod convertor ((typeA C-mpq) (typeB C-int)) (list "mpq_set_d(~a, (double) ~a );"
							 "mpq_canonicalize(~a);"))
(defmethod convertor ((typeA C-uli) (typeB C-mpz)) "mpz_get_ui(~a)")
(defmethod convertor ((typeA C-int) (typeB C-mpz)) "( (int) mpz_get_si(~a) )")
(defmethod convertor ((typeA C-uli) (typeB C-mpq)) "( (unsigned long) mpq_get_d(~a) )")
(defmethod convertor ((typeA C-int) (typeB C-mpq)) "( (int) mpq_get_d(~a) )")
(defmethod convertor ((typeA C-int) (typeB C-uli)) "(int) ~a")
(defmethod convertor ((typeA C-uli) (typeB C-int)) "(unsigned long) ~a")
(defmethod convertor (typeA typeB)
  (let ((func (if (type= typeA typeB)
		  (format nil "copy_~a" typeA)
		(format nil "~a_from_~a" typeA typeB))))
    (if (C-pointer? typeA)
	(list (format nil "~a(~~a, ~~a);" func))
      (format nil "~a(~~a)" func))))


(defgeneric smaller-type (typeA typeB))
(defmethod smaller-type ((typeA C-mpq) typeB) typeB)
(defmethod smaller-type ((typeA C-mpz) (typeB C-mpq)) *C-mpz*)
(defmethod smaller-type ((typeA C-mpz) typeB) typeB)
(defmethod smaller-type ((typeA C-int) typeB) C-int)
(defmethod smaller-type ((typeA C-uli) typeB) C-int)

(defmethod smaller-type ((typeA C-closure) (typeB C-closure))
  (make-instance 'C-closure))

(defmethod smaller-type (typeA typeB)
  (format t "!!! Warning !!! smaller-type called with unexpected type.")
  typeA)


;; ----------- Functions to convert environment to (*void)[] -------------------

;; Return arrays of instructions
(defun save-void (var-ind name-arr)
  (save-void* (pvs2C-type (type (car var-ind)))
	      (format nil "~a[~d]" name-arr (cdr var-ind))
	      (id (car var-ind))))

;; Return arrays of instructions
(defun load-void (var-ind name-arr)
  (load-void* (pvs2C-type (type (car var-ind)))
	      (format nil "~a[~d]" name-arr (cdr var-ind))
	      (id (car var-ind))))

(defmethod save-void* (type name id)
  (list (format nil "~a = ~a;" name id)))
(defmethod load-void* (type name id)
  (list (format nil "~a ~a = (~a) ~a;" type id type name)))







;; Defining here a intermediate language between C and PVS
;;

(defcl Cvar () (name) (type))

(defcl Cexpr () (body) (type) (vars))
;; (defcl Cexpr-var (Cexpr) (var))



(defcl Cinstr ())

(defcl Calloc (Cinstr) (Cvar))

(defcl Cif (Cinstr) (condition) (if-part) (then-part))



