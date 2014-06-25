;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                PVS to C translator
;;
;;     Author: Gaspard ferey
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; This requires "pvs2c.lisp" and "Ctypes.lisp" files both available at
;;               https://github.com/Gaspi/pvs2c.git
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; TODO :
;;  times, add (neg?) a corriger comme sub et div (meilleure disjonction de cas)
;;  In Ctypes :
;;    C-interval-type (inf sup)
;;    *C-int*  is an instance of that with inf -2^15 and sup 2^15-1
;;    
;;    get-all-types expr/type  -> return all possible C type for the arg
;;    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

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
(defun set-C-pointer (function args)
  (let ((C-args (cons "~a" (if (listp args) args (list args)))))
    (list (format nil "~a;"
		  (mk-C-funcall function C-args)))))

(defmethod apply-argument ((instructions list) arg)
  (mapcar #'(lambda (x) (format nil x arg)) instructions))
(defmethod apply-argument (instructions arg)
  (format nil instructions arg))



;; ------ Primitive constant (now only boolean) --------
(defun pvs2C*-primitive-cste (expr bindings livevars)
  (let ((nop (pvs2C-primitive-op expr)))
    (if (boolean-primitive? nop)
	(pvs2C*-boolean-primitive nop)
      (mk-Cexpr *C-type* nil  ;; If unimplemented ...
		(format nil "[set](~~a, ~a);" nop) nil))))

(defun boolean-primitive? (name)
  (member name '(TRUE FALSE)))
(defun pvs2C*-boolean-primitive (op)
  (mk-Cexpr *C-int* (format nil "~a" op) nil nil))


;; --------- Primitive function call ----------------
(defun pvs2C*-primitive-app (expr bindings livevars)
  (let* ((op (pvs2C-primitive-op (operator expr)))
	 (args (arguments expr))
	 (type-args (pvs2C-type args))
	 (type-res  (pvs2C-type expr)))
    (cond ((equality-function? op args)
	     (pvs2C*-equality type-args args bindings livevars))
	  ((boolean-function? op)
	     (pvs2C*-boolean op type-args args bindings livevars))
	  ((negation-function? op args)
	     (pvs2C*-negation   type-args args bindings livevars))
	  ((add-function? op args)
	     (pvs2C*-add (car type-args) (cadr type-args) type-res args bindings livevars))
	  ((sub-function? op args)
	     (pvs2C*-sub (car type-args) (cadr type-args) type-res args bindings livevars))
	  ((times-function? op args)
	     (pvs2C*-times (car type-args) (cadr type-args) type-res args bindings livevars))
	  ((div-function? op args)
	     (pvs2C*-div (car type-args) (cadr type-args) type-res args bindings livevars))
	  (t
	     (cons (pvs2C-type expr)
		   (set-C-pointer op (pvs2C args bindings livevars type-args)))))))



(defun Cprocess (info args binding livevars)
  (let* ((args (pvs2C args bindings livevars (cadr info)))
	 (func (caddr args))
	 (instr (apply-argument func
				(append (when (listp func) (list "~a"))
					(name args)))))
    (set-type args (car info))
    (set-name args (unless (listp instr) instr))
    (set-instr args (append (instr args)
			    (when (listp instr) instr)))
    args))


;; ------------- Boolean functions (2 arguments - number or bool / result bool) ----------
(defun boolean-function? (name)
  (member name '(== && || ! pvsWhen pvsImplies pvsIff
		    pvsNumberFieldPred < <= > >= 
		    pvsRealPred pvsIntegerPred pvsIntegerPred
		    pvsRationalsPred isEven isOdd isCons isNull isMember )))
(defun pvs2C*-boolean (op type-args args bindings livevars)
  (cond ((infix-primitive? op)
	 (pvs2C*-infix-primitive op args bindings livevars))
	((comparison-function? op)
	 (pvs2C*-comparison op type-args args bindings livevars))
	(t
	 (mk-Cexpr *C-int*
		   (mk-C-funcall op (pvs2C args bindings livevars type-args))
		   nil nil))))


;; ------------ boolean operator (arguments int / result int ) ---------------
(defun infix-primitive? (name)
  (member name '(== && ||)))
(defun pvs2C*-infix-primitive (op args bindings livevars)
  (Cprocess (list *C-int*
		 (list *C-int* *C-int*)
		 (format nil "(~~{~~a~~^ ~a ~~})" (if (eq op '||) "||" op)))
	   args binding livevars))

;; -------- Equality (2 arguments - could be anything / result int) --------
(defun equality-function? (name args)
  (and (eq name 'Eq) (= (length args) 2)))
(defun pvs2C*-equality (type-args args bindings livevars)
  (Cprocess (cons *C-int* (pvs2C-eq (car type-args) (cadr type-args)))
	   args bindings livevars))
(defun pvs2C-eq (typeA typeB)
  (cond ((or (C-mpq? typeA) (C-mpq? typeB))
	 (list (list *C-mpq* *C-mpq*) "(mpq_cmp(~{~a~^, ~}) == 0)"))
	((or (C-mpz? typeA) (C-mpz? typeB))
	 (list (list *C-mpz* *C-mpz*) "(mpz_cmp(~{~a~^, ~}) == 0)"))
	((and (C-base? typeA) (C-base? typeB))
	 (list (list typeA typeB) "~{~a~^ == ~})"))
	(t
	 (list (list typeA typeB) "pvsCmp(~{~a~^, ~})"))))

;; -------- Comparison (2 arguments - numbers / result int) ---------------
(defun comparison-function? (name)
  (member name '(< <= > >=)))
(defun pvs2C*-comparison (op type-args args bindings livevars)
  (Cprocess (cons *C-int* (pvs2C-comp (car type-args) (cadr type-args) op))
	   args binding livevars))
(defun pvs2C-comp (typeA typeB op)
  (cond ((or (C-mpq? typeA) (C-mpq? typeB))
	 (list (list *C-mpq* *C-mpq*)
	       (format nil "(mpq_cmp(~~{~~a~~^, ~~}) ~a 0)" op)))
	((or (C-mpz? typeA) (C-mpz? typeB))
	 (list (list *C-mpz* *C-mpz*)
	       (format nil "(mpz_cmp(~~{~~a~~^, ~~}) ~a 0)" op)))
	((and (C-base? typeA) (C-base? typeB))
	 (list (list typeA typeB)
	       (format nil "(~~{~~a~~^ ~a ~~})" op)))
	(t
	 (list (list typeA typeB)
	       (format nil "(pvsCompare(~~{~~a~~^, ~~}) ~a 0)" op)))))



;; ------------- Negation (1 argument - number / result number) ----------
(defun negation-function? (name args)
  (and (eq name 'pvsSub) (= (length args) 1)))
(defun pvs2C*-negation (type arg binding livevars)
  (Cprocess (pvs2C-neg (car type))
	   arg binding livevars))
(defun pvs2C-neg (type)
  (cond ((C-int? type)
	 (list *C-int* (list *C-int*) "(-~{~a~})"))
	((or (C-uli? type) (C-mpz? type))
	 (list *C-mpz* (list *C-mpz*) (list "mpz_neg(~{~a~^, ~})")))
	((C-mpq?)
	 (list *C-mpq* (list *C-mpq*) (list "mpq_neg(~{~a~^, ~})")))
	(t
	 (list type (list type) (list "pvsNeg(~{~a~^, ~})")))))



;; -------- Arithmetic (2 arguments - numbers / result number) ---------------
(defun add-function? (op args)
  (and (eq op 'pvsAdd) (eq (length args) 2)))
(defun pvs2C*-add (typeA typeB typeR args bindings livevars)
  (let ((info (pvs2C-add typeR typeA typeB args)))
    (Cprocess (cdr info) (car info) bindings livevars)))
(defun pvs2C-add (typeR typeA typeB args)
  (cond ((or (C-mpq? typeA) (C-mpq typeB))
	 (list args *C-mpq*
	       (list *C-mpq* *C-mpq*)
	       (list "mpq_add(~{~a~^, ~});")))
	((or (C-mpz? typeA) (C-mpz? typeA) (C-mpz? typeR))
	 (cond ((C-unsignedlong-type? (cadr args))
		(list args *C-mpz*
		      (list *C-mpz* *C-uli*)
		      (list "mpz_add_ui(~{~a~^, ~});")))
	       ((C-unsignedlong-type? (car args))
		(list (reverse args) *C-mpz*
		      (list *C-mpz* *C-uli*)
		      (list "mpz_add_ui(~{~a~^, ~});")))
	       (t
		(list args *C-mpz*
		      (list *C-mpz* *C-mpz*)
		      (list "mpz_add(~{~a~^, ~});")))))
	((or (C-int? typeR) (C-uli? typeR))
	 (list args typeR
	       (list typeA typeB)
	       (format nil "(~{~a~^ + ~})")))
	(t
	 (list args *C-mpq*
	       (list *C-mpq* *C-mpq*)
	       (list "mpq_add(~{~a~^, ~});")))))


(defun sub-function? (op args)
  (and (eq op 'pvsSub) (eq (length args) 2)))
(defun pvs2C*-sub (typeA typeB typeR args binding livevars)
  (Cprocess (pvs2C-sub typeR typeA typeB args)
	   args binding livevars))
(defun pvs2C-sub (typeR typeA typeB args)
  (cond ((every #'C-base? (list typeA typeB typeR))
	 (list typeR (list typeA typeB) "(~{~a~^ + ~})"))
	((and (C-integer? typeB) (C-unsignedlong-type? (car args)))
	 (list *C-mpz* (list *C-uli* *C-mpz*)
	       (list "mpz_ui_sub(~{~a~^, ~});")))
	((and (C-integer? typeA) (C-unsignedlong-type? (cadr args)))
	 (list *C-mpz* (list *C-mpz* *C-uli*)
	       (list "mpz_sub_ui(~{~a~^, ~});")))
	((and (C-integer? typeA) (C-integer? typeB))
	 (list *C-mpz* (list *C-mpz* *C-mpz*)
	       (list "mpz_sub(~{~a~^, ~});")))
	(t
	 (list *C-mpq* (list *C-mpq* *C-mpq*)
	       (list "mpq_sub(~{~a~^, ~});")))))



(defun times-function? (op args)
  (and (eq op 'pvsTimes) (eq (length args) 2)))
(defun pvs2C*-times (typeA typeB typeR args binding livevars)
  (let ((info (pvs2C-times typeR typeA typeB args)))
    (Cprocess (cdr info) (car info) binding livevars)))
(defun pvs2C-times (typeR typeA typeB args)
  (cond ((or (C-mpq? typeA) (C-mpq? typeB))
	 (list args *C-mpq* (list *C-mpq* *C-mpq*)
	       (list "mpq_mul(~{~a~^, ~});")))
	((or (C-mpz? typeA) (C-mpz? typeB) (C-mpz? typeR))
	 (cond ((C-unsignedlong-type? (cadr args))
		(list args *C-mpz* (list *C-mpz* *C-uli*)
		      (list "mpz_mul_ui(~{~a~^, ~});")))
	       ((C-unsignedlong-type? (car args))
		(list (reverse args) *C-mpz* (list *C-mpz* *C-uli*)
		      (list "mpz_mul_ui(~{~a~^, ~});")))
	       ((C-int-type? (cadr args))
		(list args *C-mpz* (list *C-mpz* *C-int*)
		      (list "mpz_mul_si(~{~a~^, ~});")))
	       ((C-int-type? (car args))
		(list (reverse args) *C-mpz* (list *C-mpz* *C-int*)
		      (list "mpz_mul_ui(~{~a~^, ~});")))
	       (t
		(list args *C-mpz* (list *C-mpz* *C-mpz*)
		      (list "mpz_mul(~{~a~^, ~});")))))
	((C-base? typeR)
	 (list args typeR (list typeA typeB) "(~{~a~^ * ~})"))
	(t
	 (list args *C-mpq* (list *C-mpq* *C-mpq*)
	       (list "mpq_mul(~{~a~^, ~});")))))


(defun div-function? (op args)
  (and (eq op 'pvsDiv) (eq (length args) 2)))
(defun pvs2C*-div (typeA typeB typeR args binding livevars)
  (cond ((or (C-mpq? typeA) (C-mpq? typeB))
	 (Cprocess (list *C-mpq* (list *C-mpq* *C-mpq*)
			(list "mpq_div(~{~a~^, ~});"))))
	((every #'C-base? (list typeA typeB typeR))
	 (Cprocess (list typeR (list typeA typeB) "(~{~a~^ / ~})")))
	((and (C-integer? typeA) (C-integer? typeR) (C-unsignedlong-type? (cadr args)))
	 (Cprocess (list *C-mpz* (list *C-mpz* *C-uli*)
			(list "mpz_divexact_ui(~{~a~^, ~});"))))
	((every #'C-integer? (list typeA typeB typeR))
	 (Cprocess (list *C-mpz* (list *C-mpz* *C-mpz*)
			(list "mpz_divexact(~{~a~^, ~});"))))
	((and (C-integer? typeA) (C-integer? typeB))
	 (let ((arg1 (pvs2C2 (car args)  bindings livevars *C-mpz* "mpq_numref(~a)" nil))
	       (arg2 (pvs2C2 (cadr args) bindings livevars *C-mpz* "mpq_denref(~a)" nil)))
	   (mk-Cexpr *C-mpq* nil
		     (append (instr arg1) (instr arg2) (list "mpq_canonicalize(~a);"))
		     (append (destr arg1) (destr arg2)))))
	(t (Cprocess (list *C-mpq* (list *C-mpq* *C-mpq*)
			  (list "mpz_div(~{~a~^, ~});"))))))

