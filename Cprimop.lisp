;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                PVS to C translator
;;
;;     Author: Gaspard ferey
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; This requires "pvs2c.lisp", "Cutils.lisp" and "Ctypes.lisp" files both available at
;;               https://github.com/Gaspi/pvs2c.git
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; TODO:
;;    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(in-package :pvs)

(defparameter *C-primitives* '(Eq Neq 1 0 pvsImplies pvsImplies == && && || 
 ! pvsWhen pvsIff pvsAdd pvsSub pvsTimes pvsDiv pvsNumberFieldPred < <= >
 >= pvsRealPred pvsIntegerPred pvsIntegerPred pvsRationalsPred pvsFloor pvsCeiling
 rem pvsNDiv isEven isOdd pvsCons hd tl isCons null isNull pvsRestrict
 length isMember pvsNth pvsAppend reverse))
(defparameter *pvsC-primitives-map*
  (pairlis *pvs2cl-primitives* *C-primitives*))
(defun pvs2C-primitive-op (name)
  (let ((entry (assoc name *pvsC-primitives-map* :test #'same-primitive?)))
    (when entry (cdr entry))))


;; Deprecated
;; (defun mk-C-funcall (fun args)
;;   (Cfuncall fun  (if (listp args) args (list args))))


;; Calling a mpz function (first argument is result)
(defun set-C-pointer (function args)
  (Cfuncall-mp function (cons "~a" (if (listp args) args (list args)))))



;; ------ Primitive constant (now only boolean) --------
(defun pvs2C*-primitive-cste (expr bindings livevars)
  (let ((nop (pvs2C-primitive-op expr)))
    (if (boolean-primitive? nop)
	(pvs2C*-boolean-primitive nop)
      (mk-C-expr *C-type* nil  ;; If unimplemented ...
		(format nil "[set](~~a, ~a);" nop) nil))))

(defun boolean-primitive? (name)
  (member name '(1 0)))
(defun pvs2C*-boolean-primitive (op)
  (mk-C-expr *C-int* (format nil "~a" op) nil nil))


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
	     (break "Unknown primitive app")
	     (cons (pvs2C-type expr) ;; This is not even implemented correctly
		   (set-C-pointer op (pvs2C args bindings livevars type-args)))))))


(defun Cprocess (info args bindings livevars)
  (let* ((C-args (pvs2C args bindings livevars (cadr info)))
	 (func (caddr info))
	 (res (set-arguments func   ;; Here should be an instance of Cfuncall(-mpz)
			     (append (when (Cfuncall-mp? func) (list (C-var (car info))))
				     (name C-args)))))
    (set-type  C-args (car info))
    (set-name  C-args (unless (Cinstr? res) res))
    (app-instr C-args (when (Cinstr? res) res))
    C-args))


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
	 (Cprocess (list *C-int* type-args (Cfuncall op))
		   args bindings livevars))))


;; ------------ boolean operator (arguments int / result int ) ---------------
(defun infix-primitive? (name)
  (member name '(== && ||)))
(defun pvs2C*-infix-primitive (op args bindings livevars)
  (Cprocess (list *C-int* (list *C-int* *C-int*)
		  (Cfuncall (binop op)))
	    args bindings livevars))

;; -------- Equality (2 arguments - could be anything / result int) --------
(defun equality-function? (name args)
  (and (eq name 'Eq) (= (length args) 2)))
(defun pvs2C*-equality (type-args args bindings livevars)
  (Cprocess (cons *C-int* (pvs2C-eq (car type-args) (cadr type-args)))
	   args bindings livevars))
(defun pvs2C-eq (typeA typeB)
  (cond ((or (C-mpq? typeA) (C-mpq? typeB))
	 (list (list *C-mpq* *C-mpq*) (Cfuncall-mp (mp-cmp "mpq" '==))))
	((or (C-mpz? typeA) (C-mpz? typeB))
	 (list (list *C-mpz* *C-mpz*) (Cfuncall-mp (mp-cmp "mpz" '==))))
	((and (C-base? typeA) (C-base? typeB))
	 (list (list typeA typeB) (Cfuncall (binop '==))))
	(t
	 (list (list typeA typeB) (Cfuncall "pvsCmp")))))

;; -------- Comparison (2 arguments - numbers / result int) ---------------
(defun comparison-function? (name)
  (member name '(< <= > >=)))
(defun pvs2C*-comparison (op type-args args bindings livevars)
  (Cprocess (cons *C-int* (pvs2C-comp (car type-args) (cadr type-args) op))
	   args bindings livevars))
(defun pvs2C-comp (typeA typeB op)
  (cond ((or (C-mpq? typeA) (C-mpq? typeB))
	 (list (list *C-mpq* *C-mpq*) (Cfuncall (mp-cmp "mpq" op))))
	((or (C-mpz? typeA) (C-mpz? typeB))
	 (list (list *C-mpz* *C-mpz*) (Cfuncall (mp-cmp "mpz" op))))
	((and (C-base? typeA) (C-base? typeB))
	 (list (list typeA typeB) (Cfuncall (binop op))))
	(t
	 (list (list typeA typeB) (Cfuncall (mp-cmp "pvs" op))))))


;; ------------- Negation (1 argument - number / result number) ----------
(defun negation-function? (name args)
  (and (eq name 'pvsSub) (= (length args) 1)))
(defun pvs2C*-negation (type arg bindings livevars)
  (Cprocess (pvs2C-neg (car type))
	   arg bindings livevars))
(defun pvs2C-neg (type)
  (cond ((C-int? type)
	 (list *C-int* (list *C-int*) (Cfuncall *pvs-neg*)))
	((or (C-uli? type) (C-mpz? type))
	 (list *C-mpz* (list *C-mpz*) (Cfuncall-mp "mpz_neg")))
	((C-mpq?)
	 (list *C-mpq* (list *C-mpq*) (Cfuncall-mp "mpq_neg")))
	(t
	 (list type (list type) (Cfuncall "pvsNeg")))))



;; -------- Arithmetic (2 arguments - numbers / result number) ---------------

;; ---------- Addition ------------
(defun add-function? (op args)
  (and (eq op 'pvsAdd) (eq (length args) 2)))
(defun pvs2C*-add (typeA typeB typeR args bindings livevars)
  (let ((info (pvs2C-add typeR typeA typeB args)))
    (Cprocess (cdr info) (car info) bindings livevars)))
(defun pvs2C-add (typeR typeA typeB args)
  (cond ((or (C-mpq? typeA) (C-mpq? typeB))
	 (list args *C-mpq*
	       (list *C-mpq* *C-mpq*) (Cfuncall-mp "mpq_add")))
	((or (C-mpz? typeA) (C-mpz? typeA) (C-mpz? typeR))
	 (cond ((C-unsignedlong-type? (cadr args))
		(list args *C-mpz*
		      (list *C-mpz* *C-uli*) (Cfuncall-mp "mpz_add_ui")))
	       ((C-unsignedlong-type? (car args))
		(list (reverse args) *C-mpz*
		      (list *C-mpz* *C-uli*) (Cfuncall-mp "mpz_add_ui")))
	       (t
		(list args *C-mpz*
		      (list *C-mpz* *C-mpz*) (Cfuncall-mp "mpz_add")))))
	((or (C-int? typeR) (C-uli? typeR))
	 (list args typeR
	       (list typeA typeB) (Cfuncall (binop '+))))
	(t
	 (list args *C-mpq* (list *C-mpq* *C-mpq*) (Cfuncall-mp "mpq_add")))))


;; ---------- Substraction ------------
(defun sub-function? (op args)
  (and (eq op 'pvsSub) (eq (length args) 2)))
(defun pvs2C*-sub (typeA typeB typeR args bindings livevars)
  (Cprocess (pvs2C-sub typeR typeA typeB args)
	   args bindings livevars))
(defun pvs2C-sub (typeR typeA typeB args)
  (cond ((every #'C-base? (list typeA typeB typeR))
	 (list typeR (list typeA typeB) (Cfuncall (binop '-))))
	((and (C-integer? typeB) (C-unsignedlong-type? (car args)))
	 (list *C-mpz* (list *C-uli* *C-mpz*) (Cfuncall-mp "mpz_ui_sub")))
	((and (C-integer? typeA) (C-unsignedlong-type? (cadr args)))
	 (list *C-mpz* (list *C-mpz* *C-uli*) (Cfuncall-mp "mpz_sub_ui")))
	((and (C-integer? typeA) (C-integer? typeB))
	 (list *C-mpz* (list *C-mpz* *C-mpz*) (Cfuncall-mp "mpz_sub")))
	(t
	 (list *C-mpq* (list *C-mpq* *C-mpq*) (Cfuncall-mp "mpq_sub")))))


;; ---------- Multiplication ------------
(defun times-function? (op args)
  (and (eq op 'pvsTimes) (eq (length args) 2)))
(defun pvs2C*-times (typeA typeB typeR args bindings livevars)
  (let ((info (pvs2C-times typeR typeA typeB args)))
    (Cprocess (cdr info) (car info) bindings livevars)))
(defun pvs2C-times (typeR typeA typeB args)
  (cond ((or (C-mpq? typeA) (C-mpq? typeB))
	 (list args *C-mpq* (list *C-mpq* *C-mpq*) (Cfuncall-mp "mpq_mul")))
	((or (C-mpz? typeA) (C-mpz? typeB) (C-mpz? typeR))
	 (cond ((C-unsignedlong-type? (cadr args))
		(list args *C-mpz* (list *C-mpz* *C-uli*) (Cfuncall-mp "mpz_mul_ui")))
	       ((C-unsignedlong-type? (car args))
		(list (reverse args) *C-mpz* (list *C-mpz* *C-uli*) (Cfuncall-mp "mpz_mul_ui")))
	       ((C-int-type? (cadr args))
		(list args *C-mpz* (list *C-mpz* *C-int*) (Cfuncall-mp "mpz_mul_si")))
	       ((C-int-type? (car args))
		(list (reverse args) *C-mpz* (list *C-mpz* *C-int*) (Cfuncall-mp "mpz_mul_ui")))
	       (t
		(list args *C-mpz* (list *C-mpz* *C-mpz*) (Cfuncall-mp "mpz_mul")))))
	((C-base? typeR)
	 (list args typeR (list typeA typeB) (Cfuncall (binop '*))))
	(t
	 (list args *C-mpq* (list *C-mpq* *C-mpq*) (Cfuncall-mp "mpq_mul")))))


;; ---------- Division ------------
(defun div-function? (op args)
  (and (eq op 'pvsDiv) (eq (length args) 2)))
(defun pvs2C*-div (typeA typeB typeR args bindings livevars)
  (cond ((or (C-mpq? typeA) (C-mpq? typeB))
	 (Cprocess (list *C-mpq* (list *C-mpq* *C-mpq*) (Cfuncall-mp "mpq_div"))))
	((every #'C-base? (list typeA typeB typeR))
	 (Cprocess (list typeR (list typeA typeB) (Cfuncall (binop '/)))))
	((and (C-integer? typeA) (C-integer? typeR) (C-unsignedlong-type? (cadr args)))
	 (Cprocess (list *C-mpz* (list *C-mpz* *C-uli*) (Cfuncall-mp "mpz_divexact_ui"))))
	((every #'C-integer? (list typeA typeB typeR))
	 (Cprocess (list *C-mpz* (list *C-mpz* *C-mpz*) (Cfuncall-mp "mpz_divexact"))))
	((and (C-integer? typeA) (C-integer? typeB))
	 (let ((arg1 (pvs2C2 (car args)  bindings livevars
			     (Cfuncall "mpq_numref" (C-var *C-mpq*) *C-mpz*) nil))
	       (arg2 (pvs2C2 (cadr args) bindings livevars
			     (Cfuncall "mpq_denref" (C-var *C-mpq*) *C-mpz*) nil)))
	   (mk-C-expr *C-mpq* nil
;;		     (append (instr arg1) (instr arg2) (list "mpq_canonicalize(~a);"))
		     (append (instr arg1) (instr arg2)
			     (list (Cfuncall-mp "mpq_canonicalize" (list (C-var *C-mpq*)))))
		     (append (destr arg1) (destr arg2)))))
	(t (Cprocess (list *C-mpq* (list *C-mpq* *C-mpq*) (Cfuncall-mp "mpq_div"))))))

