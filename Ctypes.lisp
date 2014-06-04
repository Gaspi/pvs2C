
(in-package :pvs)


;; structure to represent the C variables
(defclass C-type () ())
(defclass C-int (C-type) ())
(defclass C-mpz (C-type) ())
(defclass C-mpq (C-type) ())
(defclass C-pointer (C-type) ((target :type C-type  :initarg :target)))
(defclass C-struct (C-type) ((name :initarg :name)))
(defclass C-named-type (C-type) ((name :initarg :name)))
(defclass C-closure  (C-type) ())

(defmethod print-object ((obj C-int) out) (format out "int"  ))
(defmethod print-object ((obj C-mpz) out) (format out "mpz_t"))
(defmethod print-object ((obj C-mpq) out) (format out "mpq_t"))
(defmethod print-object ((obj C-pointer) out) (format out "~a*" (slot-value obj 'target)))
(defmethod print-object ((obj C-struct) out) (format out "struct ~a" (slot-value obj 'name)))
(defmethod print-object ((obj C-named-type) out) (format out "~a" (slot-value obj 'name)))
(defmethod print-object ((obj C-closure) out) (format out "pvsClosure"))
(defmethod print-object ((obj C-type) out) (format out "[Abstract C type]"))

(defgeneric pointer? (type))
(defmethod pointer? ((type C-int)) nil)
(defmethod pointer? ((type C-type)) t)


(defmethod pvs-type-2-C-type ((type recordtype) &optional tbindings)
  (with-slots (print-type) type
    (if (type-name? print-type)
	(let ((entry (assoc (declaration print-type) *C-record-defns*)))
	  (if entry (cadr entry) ;return the C-rectype-name
	      (let* ((formatted-fields (loop for fld in (fields type)
				  collect
				  (format nil "~a ~a;" 
					  (pvs-type-2-C-type (type fld)) (id fld))))
		     (C-rectype-name (gentemp (format nil "pvs~a" (id print-type))))
		     (C-rectype (format nil "struct ~a {~%~{  ~a~%~}};"
					C-rectype-name formatted-fields)))
		(push (list (declaration print-type) C-rectype-name C-rectype)
		      *C-record-defns*)
		(make-instance 'C-struct :name C-rectype-name))))
	(pvs2C-error "~%Record type ~a must be declared." type))))

(defmethod pvs-type-2-C-type ((type tupletype) &optional tbindings)
  (make-instance 'C-named-type
		 :name (format nil "~{!~a~^_~}" (loop for elemtype in (types type)
				   collect (pvs-type-2-C-type elemtype)))))

(defmethod pvs-type-2-C-type ((type funtype) &optional tbindings)
  (if (C-updateable? type)
      (make-instance 'C-pointer :target (pvs-type-2-C-type (range type)))
    (make-instance 'C-closure)))

(defmethod pvs-type-2-C-type ((type subtype) &optional tbindings)
  (cond ((subtype-of? type *integer*) (make-instance 'C-mpz) )
	((subtype-of? type *number* ) (make-instance 'C-mpq) )
	((subtype-of? type *boolean*) (make-instance 'C-int) )
	(t (pvs-type-2-C-type (find-supertype type)))))

(defmethod pvs-type-2-C-type ((type type-name) &optional tbindings)
  (with-slots (id) type
     (if (eq id 'boolean)
       (make-instance 'C-int)
       (make-instance 'C-named-type
		 :name (or (cdr (assoc type tbindings :test #'tc-eq))
			   (id type))))))

(defmethod pvs-type-2-C-type ((e number-expr) &optional tbindings)
  (if (< (abs (number e)) (expt 2 15))
      (make-instance 'C-int)
    (pvs-type-2-C-type (type e))))

(defmethod pvs-type-2-C-type ((type expr) &optional tbindings)
  (pvs-type-2-C-type (type type)))



(defstruct C-var name type)
(defun get-C-var (type name)
  (make-C-var :name name :type type))
(defun C-var (type name) (make-C-var :name name :type type))
(defmethod print-object ((obj C-var) out)
  (format out "~a" (slot-value obj 'name)))

(defmethod pointer? ((obj C-var)) (pointer? (C-type obj)))
(defmethod pointer? ((e expr)) (pointer? (pvs-type-2-C-type (type e))))
(defmethod pointer? (arg) nil)

(defmethod C-type ((arg C-var)) (slot-value arg 'type))

(defgeneric gen-C-var (expr prefix))
(defmethod gen-C-var ((expr C-type) prefix)
  (C-var expr (gentemp prefix)))
(defmethod gen-C-var ((expr expr) prefix)
  (let* ((type (type expr))
	 (name (gentemp prefix))
	 (C-type
	  (if (subtype-of? type *number*)
	      (if (C-integer-type? expr)
		  (make-instance 'C-mpz)
		(make-instance 'C-mpq))
	    (pvs-type-2-C-type type))))
    (C-var C-type name)))


(defun C-integer-type? (expr)
  (let ((*generate-tccs* t))
    (some #'(lambda (jty) (subtype-of? jty *integer*))
        (judgement-types+ expr))))


(defgeneric malloc (type name))
(defmethod malloc ((type C-mpz) name)
   (list (format nil "mpz_init(~a);" name)))
(defmethod malloc ((type C-mpq) name)
   (list (format nil "mpq_init(~a);" name)))
(defmethod malloc ((type C-pointer) name)
   (list (format nil "~a = malloc( sizeof(~a) );" name (slot-value type 'target))))
(defmethod malloc ((type C-type) name) nil)

(defun C-alloc (v)
  (let ((type (slot-value v 'type))
	(name (slot-value v 'name)))
    (append (list (format nil "~a ~a;" type name))
	    (malloc type name))))



(defgeneric free (type name))
(defmethod free ((type C-int) name) nil)
(defmethod free ((type C-mpz) name)
  (list (format nil "mpz_clear(~a);" name)))
(defmethod free ((type C-mpq) name)
  (list (format nil "mpq_clear(~a);" name)))
(defmethod free ((type C-type) name)
  (list (format nil "free(~a);" name)))

(defun C-free (v)
  (free (slot-value v 'type) (slot-value v 'name)))


(defun C-type-args (operator)
  (let ((dom-type (domain (type operator))))
    (if (tupletype? dom-type)
	(mapcar #'pvs-type-2-C-type (types dom-type))
      (list pvs-type-2-C-type dom-type))))







;; Old functions


;(defun malloc (type name) ;; other versions should be defined (for BigInt, Rationnal, etc)
;  (cond ((subtype-of? type *integer*) (list
;				       (format nil "mpz_t ~a;" name)
;				       (format nil "mpz_init(~a);" name)))
;	((subtype-of? type *number*) (list
;				      (format nil "mpq_t ~a;" name)
;				      (format nil "mpq_init(~a);" name)))
;	 (t (list (format nil "~a ~a = malloc( sizeof(~a) );"
;			  (pvs2C-type type) name (pvs2C-type type))))))
;
;(defun free (type name) ;; other versions should be defined (for BigInt, Rationnal, etc)
;  (cond ((subtype-of? type *integer*) (list
;				       (format nil "mpz_clear(~a);" name)))
;	((subtype-of? type *number*) (list
;				      (format nil "mpq_clear(~a);" name)))
;	 (t (list (format nil "free(~a);" name)))))
