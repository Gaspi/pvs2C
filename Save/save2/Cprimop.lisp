
(in-package :pvs)


(defparameter *C-primitives* '(Eq Neq TRUE FALSE pvsImplies pvsImplies == && && || 
 ! pvsWhen pvsIff pvsAdd pvsSub pvsTimes pvsDiv pvsNumberFieldPred < <= >
 >= pvsRealPred pvsIntegerPred pvsIntegerPred pvsRationalsPred pvsFloor pvsCeiling
 rem pvsNDiv isEven isOdd pvsCons hd tl isCons null isNull pvsRestrict
 length isMember pvsNth pvsAppend reverse))
(defparameter *pvsC-primitives-map*
  (pairlis *pvs2cl-primitives* *C-primitives*))
(defun pvs2C-primitive-op (name)
  (let ((entry (assoc name *pvsC-primitives-map* :test #'same-primitive?)))
    (when entry (cdr entry))))



(defun mk-C-funcall (fun args)
  (format nil "~a(~{~a~^, ~})" fun args))

;; Setting C variables to values
(defun set-C-pointer (function result args)
  (format nil "~a;"
	  (mk-C-funcall function (append (list result) args))))

(defun set-C-nonpointer (result expr)
  (if result
      (format nil "~a = ~a;" result expr)
    (format nil "~a" expr)))


(defun set-C-var (copy result expr)
  (if (pointer? result)
      (set-C-pointer copy result expr)
    (set-C-nonpointer result expr)))
(defun set-C-funres (function result args)
  (if (pointer? result)
      (set-C-pointer function result args)
    (set-C-nonpointer result (mk-C-funcall function args))))


(defgeneric pvs2C-add ())



;; How to define addition (depending on the type)
(defgeneric add-pointer (res a b))
(defmethod add-pointer ((res C-int) (a C-int) (b C-int)) "(\~a + \~a)")
(defmethod add-pointer (res a b) "add-unimpl(\~a, \~a + \~a)")








;; ------ Primitive constant (now only boolean) --------
(defun pvs2C*-primitive-cste (expr bindings livevars result)
  (let ((nop (pvs2C-primitive-op expr)))
    (if (boolean-primitive? nop)
	(pvs2C*-boolean-primitive nop result)
      (set-C-nonpointer "set" result nop))))

(defun boolean-primitive? (name)
  (member name '(TRUE FALSE)))
(defun pvs2C*-boolean-primitive (op result)
  (set-C-nonpointer result op))



;; --------- Primitive function call ----------------
(defun pvs2C*-primitive-app (expr bindings livevars result)
  (let* ((op (operator expr))
	 (nop (pvs2C-primitive-op op))
	 (type-args (mapcar #'pvs-type-2-C-type
			    (mapcar #'type (arguments expr))))
	 (type-res (when result (C-type result)))
	 (args (pvs2C (arguments expr) bindings livevars)))
    (cond ((equality-function? nop args)
	      (pvs2C*-equality-function args result))
	  ((comparison-function? nop)
	      (pvs2C*-comparison-function nop args result))
	  ((negation-function? nop args)
	     (pvs2C*-negation-function args result))
	  ((boolean-function? nop)
	    (pvs2C*-boolean-function nop args result))
	  ((eq nop 'Add) (pvs2C*-add args result))
	  (t
	    (format nil "~a;" (set-C-pointer nop result args))))))


(defun boolean-function? (name)
  (member name '(== && || ! pvsWhen pvsImplies pvsIff
		    pvsNumberFieldPred < <= > >= 
		    pvsRealPred pvsIntegerPred pvsIntegerPred
		    pvsRationalsPred isEven isOdd isCons isNull isMember )))
(defun pvs2C*-boolean-function (op args result)
  (set-C-nonpointer result
     (cond ((infix-primitive? op)
	      (pvs2C*-infix-primitive op args result))
	   ((comparison-function? op)
	      (pvs2C*-comparison-function op args result))
	   (t (mk-C-funcall op args)))))

(defun infix-primitive? (name)
  (member name '(== && ||)))
(defun pvs2C*-infix-primitive (op args result)
  (format nil (format nil "(~a~a~a ~a ~a)" "~{" "~a" "~^" op "~}")  args ))

;; ------------- Negation (1 argument - number / result number) ----------
(defun negation-function? (name args)
  (and (= (length args) 1) (eq name 'pvsSub)))
(defun pvs2C*-negation-function (args result)
  (if (pointer? result)
      (set-C-pointer "pvsNeg" result args)
    (set-C-nonpointer result (format nil "(-~a)" (car args)))))


;; -------------- Equality (2 arguments - could be anything / result int) ---------------
(defun equality-function? (name args)
  (and (= (length args) 2) (eq name 'Eq)))
(defun pvs2C*-equality-function (args result)
  (set-C-nonpointer result
		    (pvs2C-eq (C-type (car args))
			      (C-type (cadr args))
			      args)))
(defgeneric pvs2C-eq (typeA typeB args))
(defmethod pvs2C-eq ((typeA C-mpz) (typeB C-mpz) args)
  (format nil "(mpz_cmp(~a, ~a) == 0)" (car args) (cadr args)))
(defmethod pvs2C-eq ((typeA C-mpz) (typeB C-mpq) args)
  (format nil "(mpzq_cmp(~a, ~a) == 0)" (car args) (cadr args)))
(defmethod pvs2C-eq ((typeA C-mpq) (typeB C-mpz) args)
  (format nil "(mpqz_cmp(~a, ~a) == 0)" (car args) (cadr args)))
(defmethod pvs2C-eq ((typeA C-mpq) (typeB C-mpq) args)
  (format nil "(mpq_cmp(~a, ~a) == 0)" (car args) (cadr args)))
(defmethod pvs2C-eq ((typeA C-closure) (typeB C-closure) args)
  (format nil "closureEq(~a, ~a)" (car args) (cadr args)))
(defmethod pvs2C-eq ((typeA C-struct) (typeB C-struct) args)
  (format nil "~aEq(~a, ~a)" (slot-value typeA 'name) (car args) (cadr args)))
(defmethod pvs2C-eq ((typeA C-named-type) (typeB C-named-type) args)
  (format nil "~aEq(~a, ~a)" (slot-value typeA 'name) (car args) (cadr args)))
(defmethod pvs2C-eq ((typeA C-type) (typeB C-type) args)
  (format nil "(~a == ~a)" (car args) (cadr args)))


;; -------- Comparison (2 arguments - numbers / result int) ---------------
(defun comparison-function? (name)
  (member name '(< <= > >=)))
(defun pvs2C*-comparison-function (op args result)
  (set-C-nonpointer result
		    (format nil "( ~a(~a, ~a) ~a 0 )"
			    (pvs2C-comp (slot-value (car args)  'type)
					(slot-value (cadr args) 'type))
			    (car args)
			    (cadr args)
			    op)))
(defgeneric pvs2C-comp (typeA typeB))
(defmethod pvs2C-comp ((typeA C-mpz) (typeB C-mpz)) "mpz_cmp")
(defmethod pvs2C-comp ((typeA C-mpz) (typeB C-mpq)) "mpzq_cmp")
(defmethod pvs2C-comp ((typeA C-mpq) (typeB C-mpz)) "mpqz_cmp")
(defmethod pvs2C-comp ((typeA C-mpq) (typeB C-mpq)) "mpq_cmp")
(defmethod pvs2C-comp (typeA typeB) "compare")



;; Reminder of *pvs2cl-primitives*  :
; =  equalities
; /=  notequal
; TRUE  booleans
; FALSE  booleans
; IMPLIES  booleans
; =>  booleans
; <=>  booleans
; AND  booleans
; &  booleans
; OR  booleans
; NOT  booleans
; WHEN  booleans
; IFF  booleans
; +  number_fields
; -  number_fields
; *  number_fields
; /  number_fields
; number_field_pred  number_fields
; <  reals
; <=  reals
; >  reals
; >=  reals
; real_pred  reals
; integer_pred  integers
; integer?  integers
; rational_pred  rationals
; floor  floor_ceil
; ceiling  floor_ceil
; rem  modulo_arithmetic
; ndiv  modulo_arithmetic
; even?  integers
; odd?  integers
; cons  list_adt
; car  list_adt
; cdr  list_adt
; cons?  list_adt
; null  list_adt
; null?  list_adt
; restrict  restrict
; length  list_props
; member  list_props
; nth  list_props
; append  list_props
; reverse  list_props
