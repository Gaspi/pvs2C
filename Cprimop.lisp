
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
  (if (listp args)
      (format nil "~a(~{~a~^, ~})" fun args)
    (format nil "~a(~a)" fun args)))

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


(defun apply-argument (instructions arg)
  (mapcar #'(lambda (x) (format nil x arg)) instructions))


;; How to define addition (depending on the type)
(defgeneric add-pointer (res a b))
(defmethod add-pointer ((res C-int) (a C-int) (b C-int)) "(\~a + \~a)")
(defmethod add-pointer (res a b) "add-unimpl(\~a, \~a + \~a)")








;; ------ Primitive constant (now only boolean) --------
(defun pvs2C*-primitive-cste (expr bindings livevars)
  (let ((nop (pvs2C-primitive-op expr)))
    (if (boolean-primitive? nop)
	(pvs2C*-boolean-primitive nop)
      (cons *C-type*
	    (list (set-C-nonpointer "set" "~a" nop))))))

(defun boolean-primitive? (name)
  (member name '(TRUE FALSE)))
(defun pvs2C*-boolean-primitive (op)
  (cons *C-int* (format nil "~a" op)))



;; --------- Primitive function call ----------------
(defun pvs2C*-primitive-app (expr bindings livevars)
  (let* ((op (pvs2C-primitive-op (operator expr)))
	 (args (arguments expr))
	 (type-args (pvs-type-2-C-type args))
	 (type-res  (pvs-type-2-C-type expr)))
    (cond ((equality-function? op args)
	     (pvs2C*-equality type-args args bindings livevars))
	  ((boolean-function? op)
	     (pvs2C*-boolean op type-args args bindings livevars))
	  ((negation-function? op args)
	     (pvs2C*-negation (car type-args) (car args) bindings livevars))
	  ((add-function? op args)
	     (pvs2C*-add (car type-args) (cadr type-args) type-res args bindings livevars))
	  (t
	     (cons (pvs-type-2-C-type expr)
		   (list (set-C-pointer op "~a" (pvs2C args bindings livevars type-args))))))))


;; ------------- Boolean functions (2 arguments - number or bool / result bool) ----------
(defun boolean-function? (name)
  (member name '(== && || ! pvsWhen pvsImplies pvsIff
		    pvsNumberFieldPred < <= > >= 
		    pvsRealPred pvsIntegerPred pvsIntegerPred
		    pvsRationalsPred isEven isOdd isCons isNull isMember )))
(defun pvs2C*-boolean (op type-args args bindings livevars)
  (cons *C-int*
	(cond ((infix-primitive? op)
	        (pvs2C*-infix-primitive op args bindings livevars))
	      ((comparison-function? op)
	        (pvs2C*-comparison op type-args args bindings livevars))
	      (t
	        (mk-C-funcall op (pvs2C args bindings livevars type-args) )))))

(defun infix-primitive? (name)
  (member name '(== && ||)))
(defun pvs2C*-infix-primitive (op args bindings livevars)
  (format nil (format nil "(~~{~~a~~^ ~a ~~})" op)
	          (pvs2C args bindings livevars (list *C-int* *C-int*))))


;; -------- Equality (2 arguments - could be anything / result int) --------
(defun equality-function? (name args)
  (and (eq name 'Eq) (= (length args) 2)))
(defun pvs2C*-equality (type-args args bindings livevars)
  (cons *C-int*
	(pvs2C-eq (car type-args) (cadr type-args)
		  (car args) (cadr args)
		  bindings livevars)))

(defgeneric pvs2C-eq (typeA typeB argA argB bindings livevars))

(defmethod pvs2C-eq ((typeA C-mpq) typeB argA argB bindings livevars)
  (format nil "(mpq_cmp(~a, ~a) == 0)"
	  (pvs2C argA bindings livevars *C-mpq*)
	  (pvs2C argB bindings livevars *C-mpq*)))
(defmethod pvs2C-eq (typeA (typeB C-mpq) argA argB bindings livevars)
  (format nil "(mpq_cmp(~a, ~a) == 0)"
	  (pvs2C argA bindings livevars *C-mpq*)
	  (pvs2C argB bindings livevars *C-mpq*)))

(defmethod pvs2C-eq ((typeA C-mpz) typeB argA argB bindings livevars)
  (format nil "(mpz_cmp(~a, ~a) == 0)"
	  (pvs2C argA bindings livevars *C-mpz*)
	  (pvs2C argB bindings livevars *C-mpz*)))
(defmethod pvs2C-eq (typeA (typeB C-mpz) argA argB bindings livevars)
  (format nil "(mpz_cmp(~a, ~a) == 0)"
	  (pvs2C argA bindings livevars *C-mpz*)
	  (pvs2C argB bindings livevars *C-mpz*)))

(defmethod pvs2C-eq ((typeA C-closure) typeB argA argB bindings livevars)
  (format nil "closureEq(~a, ~a)"
	  (pvs2C argA bindings livevars typeA)
	  (pvs2C argB bindings livevars typeB)))
(defmethod pvs2C-eq (typeA (typeB C-closure) argA argB bindings livevars)
  (format nil "closureEq(~a, ~a)"
	  (pvs2C argA bindings livevars typeA)
	  (pvs2C argB bindings livevars typeB)))

(defmethod pvs2C-eq ((typeA C-struct) typeB argA argB bindings livevars)
  (format nil "aEq(~a, ~a)"
	  (pvs2C argA bindings livevars typeA)
	  (pvs2C argB bindings livevars typeB)))
(defmethod pvs2C-eq (typeA (typeB C-struct) argA argB bindings livevars)
  (format nil "aEq(~a, ~a)"
	  (pvs2C argA bindings livevars typeA)
	  (pvs2C argB bindings livevars typeB)))
(defmethod pvs2C-eq ((typeA C-named-type) typeB argA argB bindings livevars)
  (format nil "aEq(~a, ~a)"
	  (pvs2C argA bindings livevars typeA)
	  (pvs2C argB bindings livevars typeB)))
(defmethod pvs2C-eq (typeA (typeB C-named-type) argA argB bindings livevars)
  (format nil "aEq(~a, ~a)"
	  (pvs2C argA bindings livevars typeA)
	  (pvs2C argB bindings livevars typeB)))

(defmethod pvs2C-eq (typeA typeB argA argB bindings livevars)
  (format nil "(~a == ~a)"
	  (pvs2C argA bindings livevars typeA)
	  (pvs2C argB bindings livevars typeB)))



;; -------- Comparison (2 arguments - numbers / result int) ---------------
(defun comparison-function? (name)
  (member name '(< <= > >=)))
(defun pvs2C*-comparison (op type-args args bindings livevars)
  (let* ((aux (pvs2C-comp (car type-args) (cadr type-args) op))
	 (args (pvs2C args bindings livevars (cdr aux))))
    (format nil (car aux) (car args) (cadr args))))

(defgeneric pvs2C-comp (typeA typeB op))
(defmethod pvs2C-comp ((typeA C-mpq) typeB op)
  (cons (format nil "(mpq_cmp(~~a, ~~a) ~a 0)" op)
	(list *C-mpq* *C-mpq*)))
(defmethod pvs2C-comp (typeA (typeB C-mpq) op)
  (cons (format nil "(mpq_cmp(~~a, ~~a) ~a 0)" op)
	(list *C-mpq* *C-mpq*)))
(defmethod pvs2C-comp ((typeA C-mpz) typeB op)
  (cons (format nil "(mpz_cmp(~~a, ~~a) ~a 0)" op)
	(list *C-mpz* *C-mpz*)))
(defmethod pvs2C-comp (typeA (typeB C-mpz) op)
  (cons (format nil "(mpz_cmp(~~a, ~~a) ~a 0)" op)
	(list *C-mpz* *C-mpz*)))
(defmethod pvs2C-comp ((typeA C-int) (typeB C-int) op)
  (cons (format nil "(~~a ~a ~~a)" op)
	(list *C-int* *C-int*)))
(defmethod pvs2C-comp ((typeA C-uli) (typeB C-uli) op)
  (cons (format nil "(~~a ~a ~~a)" op)
	(list *C-uli* *C-uli*)))
(defmethod pvs2C-comp (typeA typeB op)
  (cons (format nil "(pvsCompare(~~a, ~~a) ~a 0)" op)
	(list typeA typeB)))




;; ------------- Negation (1 argument - number / result number) ----------
(defun negation-function? (name args)
  (and (eq name 'pvsSub) (= (length args) 1)))
(defmethod pvs2C*-negation ((type-arg C-int) arg bindings livevars)
  (cons *C-int* (format nil "(-~a)" (pvs2C arg bindings livevars *C-int*))))
(defmethod pvs2C*-negation ((type-arg C-uli) arg bindings livevars)
  (cons *C-mpz*
	(list (set-C-pointer "mpz_neg" "~a" (pvs2C arg bindings livevars *C-mpz*)))))
(defmethod pvs2C*-negation ((type-arg C-mpz) arg bindings livevars)
  (cons *C-mpz*
	(list (set-C-pointer "mpz_neg" "~a" (pvs2C arg bindings livevars *C-mpz*)))))
(defmethod pvs2C*-negation ((type-arg C-mpq) arg bindings livevars)
  (cons *C-mpq*
	(list (set-C-pointer "mpq_neg" "~a" (pvs2C arg bindings livevars *C-mpq*)))))
(defmethod pvs2C*-negation (type-arg arg bindings livevars)
  (cons type-arg
	(list (set-C-pointer "pvsNeg" "~a" (pvs2C arg bindings livevars type-arg)))))




;; -------- Arithmetic (2 arguments - numbers / result number) ---------------

(defun add-function? (op args)
  (and (eq op 'pvsAdd) (eq (length args) 2)))

(defgeneric pvs2C*-add (typeA typeB typeR args bindings livevars))
(defmethod pvs2C*-add ((typeA C-mpq) typeB typeR args bindings livevars)
  (cons *C-mpq* (list (set-C-pointer "mpq_add" "~a"
			   (pvs2C args bindings livevars (list *C-mpq* *C-mpq*))))))
(defmethod pvs2C*-add (typeA (typeB C-mpq) typeR args bindings livevars)
  (cons *C-mpq* (list (set-C-pointer "mpq_add" "~a"
			   (pvs2C args bindings livevars (list *C-mpq* *C-mpq*))))))
(defmethod pvs2C*-add ((typeA C-mpz) typeB typeR args bindings livevars)
  (if (C-unsignedlong-type? (cadr args))
      (cons *C-mpz* (list (set-C-pointer "mpq_add_ui" "~a"
			       (pvs2C args bindings livevars (list *C-mpz* *C-uli*)))))
    (cons *C-mpz* (list (set-C-pointer "mpq_add" "~a"
			     (pvs2C args bindings livevars (list *C-mpz* *C-mpz*)))))))
(defmethod pvs2C*-add (typeA (typeB C-mpz) typeR args bindings livevars)
  (if (C-unsignedlong-type? (car args))
      (cons *C-mpz* (list (set-C-pointer "mpq_add_ui" "~a"
			       (pvs2C (reverse args) bindings livevars (list *C-mpz* *C-uli*)))))
    (cons *C-mpz* (list (set-C-pointer "mpq_add" "~a"
			     (pvs2C args bindings livevars (list *C-mpz* *C-mpz*)))))))
(defmethod pvs2C*-add (typeA typeB (typeR C-int) args bindings livevars)
  (cons *C-int* (format nil "(~{~a~^ + ~})"
			(pvs2C args bindings livevars (list typeA typeB)))))
(defmethod pvs2C*-add (typeA typeB (typeR C-uli) args bindings livevars)
  (cons *C-uli* (format nil "(~{~a~^ + ~})"
			(pvs2C args bindings livevars (list typeA typeB)))))
(defmethod pvs2C*-add (typeA typeB typeR args bindings livevars)
  (cons *C-type* (list (set-C-pointer "pvsAdd" "~a"
			    (pvs2C args bindings livevars (list typeA typeB))))))










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
