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

(in-package :pvs)

;; Classes to represent C types
(defcl C-type ())
(defcl C-base    (C-type)) ;; represents int, long, ...
(defcl C-pointer (C-type) (bang))
(defcl C-gmp     (C-type))

(defcl C-number ())
(defcl C-integer (C-number) (range))

(defcl C-int (C-base C-integer))
(defcl C-uli (C-base C-integer))
(defcl C-mpz (C-gmp  C-integer))
(defcl C-mpq (C-gmp  C-number ))

(defcl C-pointer-type (C-pointer) (target) (size) (bang))
(defcl C-struct       (C-pointer) (name) (args))
(defcl C-closure      (C-pointer)) ;; To be implemented...
(defcl C-named-type   (C-pointer) (name)) ;; ???


;; A C variable is a type and a string to represent it
(defcl C-var () (name) (type))
(defun C-var (type name) (make-instance 'C-var :name name :type type))
(defmethod print-object ((obj C-var) out)
  (format out "~a" (name obj)))
(defun gen-C-var (type prefix) (C-var type (gentemp prefix)))


;; Some instances of the classes above (to avoid over-instanciating)
(defvar *C-type* (make-instance 'C-type))  ;; Type undefined
(defvar *C-int* (make-instance 'C-int :range *C-int-range*))
(defvar *C-uli* (make-instance 'C-uli :range *C-uli-range*))
(defvar *C-mpz* (make-instance 'C-mpz))
(defvar *C-mpq* (make-instance 'C-mpq))
(defvar *C-struct* (make-instance 'C-struct :name nil :args nil))



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
	  (if entry (make-instance 'C-struct :name (cadr entry) :args (cadddr entry))
	    (let* ((flds  (fields type))
		   (ids   (mapcar #'id flds))
		   (types (pvs2C-type (mapcar #'declared-type flds)))
		   (args (pairlis ids types))
		   (formatted-fields (loop for arg in args
					   collect (format nil "~a ~a;" (cdr arg) (car arg))))
		   (C-rectype-name (gentemp (format nil "~a" (id print-type))))
		   (C-rectype (format nil "struct ~a {~%~{  ~a~%~}};"
				      C-rectype-name formatted-fields)))
	      (push (list (declaration print-type) C-rectype-name C-rectype args)
		    *C-record-defns*)
	      (make-instance 'C-struct
			     :name C-rectype-name
			     :args args ))))
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
		       :bang nil
		       :size
		         (when (and (car range)
				    (cadr range)
				    (not (eq (car range) '*))
				    (not (eq (cadr range) '*)))
			   (1+ (- (cadr range) (car range))))))
    (make-instance 'C-closure)))

(defmethod bang-type ((type C-pointer-type))
  (setf (slot-value type 'bang) t)
  type)
(defmethod bang-type ((type C-type)) type)


(defmethod pvs2C-type ((type subtype) &optional tbindings)
  (cond ((subtype-of? type *boolean*) *C-int*)
	((subtype-of? type *integer*)
	 (let ((range (C-range type)))
	   (cond ((range-included range *C-int-range*) *C-int*)
		 ((range-included range *C-uli-range*) *C-uli*)
		 (t *C-mpz*))))
	 ((subtype-of? type *number*) *C-mpq*)
	 (t (pvs2C-type (find-supertype type)))))


(defun C-type-args (operator)
  (let ((dom-type (domain (type operator))))
    (if (tupletype? dom-type)
	(pvs2C-type (types dom-type))
      (list (pvs2C-type dom-type)))))


(defun is-expr-subtype? (expr type)
  (some #'(lambda (jty) (subtype-of? jty type))
	(get-PVS-types expr)))
(defun C-integer-type? (expr)
  (is-expr-subtype? expr *integer*))

(defun C-unsignedlong-type? (expr)
  (and (C-integer-type? expr)
       (range-included (C-range expr) *C-uli-range*)))
(defun C-int-type? (expr)
  (and (C-integer-type? expr)
       (range-included (C-range expr) *C-int-range*)))


(defmethod pvs2C-type ((e lambda-expr) &optional tbindings)
  (with-slots (type expression) e
  (if (C-updateable? type)
      (let ((range (subrange-index (domain type))))
	(make-instance 'C-pointer-type
		       :target (pvs2C-type expression)
		       :bang nil ;; Find here when this can be set to t
		       :size (1+ (- (cadr range) (car range)))))
    (make-instance 'C-closure))))

(defmethod pvs2C-type ((e expr) &optional tbindings)
  (if (C-integer-type? e)
      (let ((range (C-range e)))
	(cond ((range-included range *C-int-range*) *C-int*)
	      ((range-included range *C-uli-range*) *C-uli*)
	      (t *C-mpz*)))
    (pvs2C-type (type e))))

(defmethod pvs2C-type ((l list) &optional tbindings)
  (when (consp l)
    (cons (pvs2C-type (car l))
	  (pvs2C-type (cdr l)))))

(defmethod pvs2C-type ((type type-name) &optional tbindings)
  (if (eql (id type) 'boolean) *C-int*
    (pvs2C-type (type (car (resolutions type))))))
       ;; (or (call-next-method)
       ;; 	   (make-instance 'C-named-type
       ;; 			  :name (or (cdr (assoc type tbindings :test #'tc-eq))
       ;; 				    (id type)))))))

(defun get-PVS-types (expr)
  (let ((*generate-tccs* t))
    (cons (type expr) (judgement-types+ expr))))




(defmethod pointer? ((obj C-var)) (C-pointer? (type obj)))
(defmethod pointer? ((e expr)) (C-pointer? (pvs2C-type (type e))))



;; An expression to represent the memory size of a type
;; Deprecated
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

;;;; Arrays are never malloc this way :
;;;;   - arr = f(...);           ;; result of function containing malloc
;;;;   - arr = malloc( ...);     ;; copy from an other array
;;;;     for (int i...)
;;;;        arr[i] = ...;
;;;; !!!! Make sure there is no other way to create arrays !!!!
(defun array-malloc (type)
  (assert (C-pointer-type? type))
  (with-slots (target size) type
     (cons (format nil "~~a = GC_malloc(~a, sizeof(~a));" (size type) (target type))
	   (create-loop (C-alloc target) "~~a[~a]"size))))
	   
	   ;; (let ((body-alloc (C-alloc target)))
	   ;;   (when body-alloc
	   ;;     (let ((i (gentemp "i")))
	   ;; 	 (append
	   ;; 	  (list (format nil "for(int ~a = 0; ~a < ~a; ~a++) {" i i size i))
	   ;; 	  (indent (apply-argument body-alloc
	   ;; 				  (format nil "~~a[~a]" i)))
	   ;; 	  (list "}")))))))


;; TODO  create function loop
(defun create-loop (body arg size &optional (prefix "i"))
  (when body
       (let ((i (gentemp prefix)))
 	 (append
 	  (list (format nil "int ~a;" i)
		(format nil "for(~a = 0; ~a < ~a; ~a++) {" i i size i))
 	  (indent (apply-argument body (format nil arg i)))
 	  (list "}")))))


(defmethod C-alloc ((type C-struct))
  (append-lists
   (loop for a in (args type)
	collect (apply-argument (C-alloc (cdr a)) (format nil "~~a.~a" (car a))))))
(defmethod C-alloc ((type C-type)) nil)
(defmethod C-alloc ((v C-var))
  (with-slots (type name) v
    (cons (format nil "~a ~a;" type name)
	  (apply-argument (C-alloc type) name))))
(defmethod C-alloc ((l list))
  (when (consp l) (append (C-alloc (car l)) (C-alloc (cdr l)))))

;; C variables memory deallocation
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
  (apply-argument (C-free (type v)) (name v)))


;; TODO freeing an array should free all its elements first



;; -------- Converting a C expression to an other type --------


;; Getting a object of typeA representing nameB of typeB
(defun get-typed-copy (typeA nameA typeB nameB)
  (assert (and (C-type? typeA) (C-type? typeB)))
  (cond ((C-gmp? typeA)
	 (mapcar #'(lambda (x) (format nil x nameA nameB)) (convertor typeA typeB)))
	((and (C-pointer? typeA) (slot-value typeA 'bang)) ;; If we want a bang version
	 (get-bang-copy typeA nameA typeB nameB))
	((and (C-struct? typeA) (C-struct? typeB))
	 (append-lists
	  (loop for a in (args typeA)
		collect (get-typed-copy (cdr a) (format nil "~a.~a" nameA (car a))
					(cdr a) (format nil "~a.~a" nameB (car a))))))
	(t (list (format nil "~a = ~a;" nameA
			 (if (and (type= typeA typeB) (not (C-pointer-type? typeA)))
			     nameB
			   (format nil (convertor typeA typeB) nameB)))))))

;; Getting a bang version of the array (copy if needed)
(defmethod get-bang-copy ((typeA C-pointer-type) nameA (typeB C-pointer-type) nameB)
  (let* ((i (gentemp "i"))
	 (nameAi (format nil "~a[~a]" nameA i))
	 (nameBi (format nil "~a[~a]" nameB i))
	 (copy-bloc (append
		(apply-argument (array-malloc typeA) nameA)
		(list (format nil "int ~a;" i)
		      (format nil "for(~a = 0; ~a < ~a; ~a++) {" i i (size typeB) i))
		(indent (get-typed-copy (target typeA) nameAi (target typeB) nameBi))
		(list "}"))))
;;		(mapcar #'(lambda (x) (format nil "  ~a" x))
    ;;			(get-typed-copy (target typeA) nameAi (target typeB) nameBi))
    ;;		(list "}"))))
    (append
     (list (format nil "if ( GC_count( ~a ) == 1 )" nameB)
	   (format nil "  ~a = ~a;" nameA nameB)
	   (format nil "else {"))
     (indent copy-bloc)
     (list "}"))))

(defmethod get-bang-copy ((typeA C-struct) nameA (typeB C-struct) nameB)
  (get-typed-copy typeA nameA typeB nameB)) ;; Needs to be properly implemented...


;; Convert a (not unnamed) Cexpr to an other with different type
(defun convert (type e)
  (cond ((type= type (type e)) e)
	((C-base? type)
	 (set-name e (format nil (convertor type (type e)) (name e)))
	 (set-type e type)
	 e)
	(t
	 (let ((n (gen-C-var type "conv")))
	   (mk-Cexpr type n
		     (append (instr e)
			     (C-alloc n)
			     (get-typed-copy type n (type e) (name e))
			     (destr e))
		     (C-free n))))))

  
(defgeneric convertor (typeA typeB))
;; ---------- GMP library conversions ---------------
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
;; ---------- base types ------------------------
(defmethod convertor ((typeA C-int) (typeB C-uli)) "(int) ~a")
(defmethod convertor ((typeA C-uli) (typeB C-int)) "(unsigned long) ~a")
(defmethod convertor ((typeA C-uli) (typeB C-uli)) "~a")
(defmethod convertor ((typeA C-int) (typeB C-int)) "~a")
;; ---------- arrays pointer copy -----------------
(defmethod convertor ((typeA C-pointer-type) (typeB C-pointer-type))
  (format nil "(~a*) GC( ~~a )" (target typeA)))
;; ---------- other cases (basically unimplemented) --------------
(defmethod convertor (typeA typeB)
  (let ((func (if (type= typeA typeB)
		  (format nil "copy_~a" typeA)
		(format nil "~a_from_~a" typeA typeB))))
    (if (C-gmp? typeA)
	(list (format nil "~a(~~{~~a~~^, ~~});" func))
      (format nil "~a(~~a)" func))))



(defgeneric smaller-type (typeA typeB))
(defmethod smaller-type ((typeA C-mpq) typeB) typeB)
(defmethod smaller-type ((typeA C-mpz) (typeB C-mpq)) typeA)
(defmethod smaller-type ((typeA C-mpz) typeB) typeB)
(defmethod smaller-type ((typeA C-uli) (typeB C-gmp)) typeA)
(defmethod smaller-type ((typeA C-uli) typeB) typeB)
(defmethod smaller-type ((typeA C-int) typeB) typeA)


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



