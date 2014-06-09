
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
	  ((sub-function? op args)
	     (pvs2C*-sub (car type-args) (cadr type-args) type-res args bindings livevars))
	  ((times-function? op args)
	     (pvs2C*-times (car type-args) (cadr type-args) type-res args bindings livevars))
	  ((div-function? op args)
	     (pvs2C*-div (car type-args) (cadr type-args) type-res args bindings livevars))
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
  (format nil (format nil "(~~{~~a~~^ ~a ~~})" (if (eq op '||) "||" op))
	          (pvs2C args bindings livevars (list *C-int* *C-int*))))


;; -------- Equality (2 arguments - could be anything / result int) --------
(defun equality-function? (name args)
  (and (eq name 'Eq) (= (length args) 2)))
(defun pvs2C*-equality (type-args args bindings livevars)
  (let* ((res (pvs2C-eq (car type-args) (cadr type-args)))
	 (C-args (pvs2C args bindings livevars (cdr res))))
    (cons *C-int* (format nil (car res) (car C-args) (cdr C-args)))))

(defgeneric pvs2C-eq (typeA typeB))
(defmethod pvs2C-eq ((typeA C-mpq) typeB)
  (list "(mpq_cmp(~a, ~a) == 0)" *C-mpq* *C-mpq*))
(defmethod pvs2C-eq (typeA (typeB C-mpq))
  (list "(mpq_cmp(~a, ~a) == 0)" *C-mpq* *C-mpq*))
(defmethod pvs2C-eq ((typeA C-mpz) typeB)
  (list "(mpz_cmp(~a, ~a) == 0)" *C-mpz* *C-mpz*))
(defmethod pvs2C-eq (typeA (typeB C-mpz))
  (list "(mpz_cmp(~a, ~a) == 0)" *C-mpz* *C-mpz*))
(defmethod pvs2C-eq ((typeA C-closure) typeB)
  (list "closureEq(~a, ~a)" typeA typeB))
(defmethod pvs2C-eq (typeA (typeB C-closure))
  (list "closureEq(~a, ~a)" typeA typeB))
(defmethod pvs2C-eq ((typeA C-struct) typeB)
  (list "aEq(~a, ~a)" typeA typeB))
(defmethod pvs2C-eq (typeA (typeB C-struct))
  (list "aEq(~a, ~a)" typeA typeB))
(defmethod pvs2C-eq ((typeA C-named-type) typeB)
  (list "aEq(~a, ~a)" typeA typeB))
(defmethod pvs2C-eq (typeA (typeB C-named-type))
  (list "aEq(~a, ~a)" typeA typeB))
(defmethod pvs2C-eq (typeA typeB)
  (list "(~a == ~a)" typeA typeB))



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
(defun pvs2C*-add (typeA typeB typeR args bindings livevars)
  (cond ((or (type= typeA *C-mpq*) (type= typeB *C-mpq*))
	   (cons *C-mpq* (list (set-C-pointer "mpq_add" "~a"
				    (pvs2C args bindings livevars (list *C-mpq* *C-mpq*))))))
	((or (type= typeA *C-mpz*) (type= typeB *C-mpz*) (type= typeR *C-mpz*))
	   (cond ((C-unsignedlong-type? (cadr args))
		    (cons *C-mpz* (list (set-C-pointer "mpz_add_ui" "~a"
					     (pvs2C args bindings livevars (list *C-mpz* *C-uli*))))))
		 ((C-unsignedlong-type? (car args))
		    (cons *C-mpz* (list (set-C-pointer "mpz_add_ui" "~a"
					     (pvs2C (reverse args) bindings livevars (list *C-mpz* *C-uli*))))))
		 ((cons *C-mpz* (list (set-C-pointer "mpz_add" "~a"
					   (pvs2C args bindings livevars (list *C-mpz* *C-mpz*))))))))
	((or (type= typeR *C-int*) (type= typeR *C-uli*))
	   (cons typeR (format nil "(~{~a~^ + ~})"
				 (pvs2C args bindings livevars (list typeA typeB)))))
	(t (cons *C-mpq* (list (set-C-pointer "mpq_add" "~a"
			    (pvs2C args bindings livevars (list *C-mpq* *C-mpq*))))))))


(defun sub-function? (op args)
  (and (eq op 'pvsSub) (eq (length args) 2)))
(defun pvs2C*-sub (typeA typeB typeR args bindings livevars)
  (cond ((or (type= typeA *C-mpq*) (type= typeB *C-mpq*))
	   (cons *C-mpq* (list (set-C-pointer "mpq_sub" "~a"
				    (pvs2C args bindings livevars (list *C-mpq* *C-mpq*))))))
	((or (type= typeA *C-mpz*) (type= typeB *C-mpz*))
	 (cond ((C-unsignedlong-type? (car args))
		   (cons *C-mpz*
			 (list (set-C-pointer "mpz_ui_sub" "~a"
				    (pvs2C args bindings livevars (list *C-uli* *C-mpz*))))))
	       ((C-unsignedlong-type? (cadr args))
		   (cons *C-mpz*
			 (list (set-C-pointer "mpz_sub_ui" "~a"
				    (pvs2C args bindings livevars (list *C-mpz* *C-uli*))))))
	       (t  (cons *C-mpz*
			 (list (set-C-pointer "mpz_sub" "~a"
				    (pvs2C args bindings livevars (list *C-mpz* *C-mpz*))))))))
	((or (type= typeR *C-int*) (type= typeR *C-uli*))
	   (cons typeR (format nil "(~{~a~^ + ~})"
				 (pvs2C args bindings livevars (list typeA typeB)))))
	(t (cons *C-mpq* (list (set-C-pointer "mpq_sub" "~a"
			    (pvs2C args bindings livevars (list *C-mpq* *C-mpq*))))))))



(defun times-function? (op args)
  (and (eq op 'pvsTimes) (eq (length args) 2)))
(defun pvs2C*-times (typeA typeB typeR args bindings livevars)
  (cond ((or (type= typeA *C-mpq*) (type= typeB *C-mpq*))
	   (cons *C-mpq* (list (set-C-pointer "mpq_mul" "~a"
				    (pvs2C args bindings livevars (list *C-mpq* *C-mpq*))))))
	((or (type= typeA *C-mpz*) (type= typeB *C-mpz*) (type= typeR *C-mpz*))
	   (cond ((C-unsignedlong-type? (cadr args))
		    (cons *C-mpz* (list (set-C-pointer "mpz_mul_ui" "~a"
					     (pvs2C args bindings livevars (list *C-mpz* *C-uli*))))))
		 ((C-unsignedlong-type? (car args))
		    (cons *C-mpz* (list (set-C-pointer "mpz_mul_ui" "~a"
					     (pvs2C (reverse args) bindings livevars (list *C-mpz* *C-uli*))))))
		 ((C-int-type? (cadr args))
		    (cons *C-mpz* (list (set-C-pointer "mpz_mul_si" "~a"
					     (pvs2C args bindings livevars (list *C-mpz* *C-int*))))))
		 ((C-int-type? (car args))
		    (cons *C-mpz* (list (set-C-pointer "mpz_mul_si" "~a"
					     (pvs2C (reverse args) bindings livevars (list *C-mpz* *C-int*))))))
		 ((cons *C-mpz* (list (set-C-pointer "mpz_mul" "~a"
					   (pvs2C args bindings livevars (list *C-mpz* *C-mpz*))))))))
	((or (type= typeR *C-int*) (type= typeR *C-uli*))
	   (cons typeR (format nil "(~{~a~^ * ~})"
				 (pvs2C args bindings livevars (list typeA typeB)))))
	(t (cons *C-mpq* (list (set-C-pointer "mpq_mul" "~a"
			    (pvs2C args bindings livevars (list *C-mpq* *C-mpq*))))))))


(defun div-function? (op args)
  (and (eq op 'pvsDiv) (eq (length args) 2)))
(defun pvs2C*-div (typeA typeB typeR args bindings livevars)
  (cond ((or (type= typeA *C-mpq*) (type= typeB *C-mpq*))
	   (cons *C-mpq* (list (set-C-pointer "mpq_div" "~a"
				    (pvs2C args bindings livevars (list *C-mpq* *C-mpq*))))))
	((and (or (type= typeA *C-mpz*) (type= typeB *C-mpz*)) (integer-type? typeR))
	 (cond ((C-unsignedlong-type? (car args))
		   (cons *C-mpz*
			 (list (set-C-pointer "mpz_divexact_ui" "~a"
				    (pvs2C (reverse args) bindings livevars (list *C-mpz* *C-uli*))))))
	       ((C-unsignedlong-type? (cadr args))
		   (cons *C-mpz*
			 (list (set-C-pointer "mpz_divexact_ui" "~a"
				    (pvs2C args bindings livevars (list *C-mpz* *C-uli*))))))
	       (t  (cons *C-mpz*
			 (list (set-C-pointer "mpz_divexact" "~a"
				    (pvs2C args bindings livevars (list *C-mpz* *C-mpz*))))))))
	((or (type= typeR *C-int*) (type= typeR *C-uli*))
	   (cons typeR (format nil "(~{~a~^ / ~})"
				 (pvs2C args bindings livevars (list typeA typeB)))))
	((and (integer-type? typeA) (integer-type? typeB))
	 (cons *C-mpq*
	       (append (pvs2C3 (car args)  bindings livevars *C-mpz* "mpq_numref(~a)")
		       (pvs2C3 (cadr args) bindings livevars *C-mpz* "mpq_denref(~a)")
		       (list "mpq_canonicalize(~a);"))))
	(t (cons *C-mpq* (list (set-C-pointer "mpq_div" "~a"
			    (pvs2C args bindings livevars (list *C-mpq* *C-mpq*))))))))







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