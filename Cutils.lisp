;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                PVS to C translator
;;
;;     Author: Gaspard ferey
;;
;;  -> https://github.com/Gaspi/pvs2c.git
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; This requires "pvs2c.lisp", "Cprimop.lisp" and "Ctypes.lisp" files all available at
;;               https://github.com/Gaspi/pvs2c.git
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(in-package :pvs)


;; ------- Simple arithmetic on Z bar : { -, numbers, + } ---------
(defun <=zb (a b)
  (or (eql a '-)
      (eql b '+)
      (and (not (eql a '+))
	   (not (eql b '-))
	   (<= a b))))
(defun sign-zb (a)
  (if (eql a 0) 0 (if (<=zb a 0) -1 1)))
(defun min-zb (a b) (if (<=zb a b) a b))
(defun max-zb (a b) (if (<=zb a b) b a))
(defun add-zb (a b) (if (eql '- (min-zb a b)) '-
		    (if (eql '+ (max-zb a b)) '+ (+ a b))))
(defun neg-zb (a) (if (eql a '-) '+
		  (if (eql a '+) '- (- a))))
(defun sub-zb (a b) (add-zb a (neg-zb b)))
(defun mul-zb (a b)
  (let ((sign (* (sign-zb a) (sign-zb b))))
    (cond ((eql sign 0) 0)
	  ((not (and (numberp a)(numberp b)))
	   (if (> sign 0) '+ '-))
	  (t (* a b)))))


;; --------------- Classe to describe a range ----------------
(defcl C-range () (inf) (sup))
(defmethod C-range ((l list))
  (if (consp l)
      (make-instance 'C-range
		     :inf (if (and (car l) (not (eql (car l) '*)))
			      (car l) '-)
		     :sup (if (consp (cdr l))
			      (if (and (cadr l) (not (eql (cadr l) '*)))
				  (cadr l) '+)
			    (if (and (cdr l) (not (eql (cdr l) '*)))
				(cdr l) '+)))
    (make-instance 'C-range :inf '- :sup '+)))

(defun inter-range (ranges)
  (C-range (when (consp ranges)
	     (let ((tl (inter-range (cdr ranges))))
	       (cons (max-zb (inf (car ranges)) (inf tl))
		     (min-zb (sup (car ranges)) (sup tl)))))))

(defun range-included (rangeA rangeB)
  (and (<=zb (inf rangeB) (inf rangeA))
       (<=zb (sup rangeA) (sup rangeB))))



;; ------- C range computations ------------------
(defmethod C-range ((type type-expr))
  (C-range (when (subtype-of? type *integer*)
	     (subrange-index type))))
;; TODO add new C-range function for subrange (cf mail Sam) ...

(defmethod C-range ((expr number-expr))
  (C-range (cons (number expr) (number expr))))
;; Intersection of all bounds given by judgement-types
(defmethod C-range ((expr expr))
  (inter-range (mapcar #'C-range (get-PVS-types expr))))

(defmethod C-range ((expr application))
  (inter-range (list (C-range (type expr))
		     (C-range
   (when (pvs2cl-primitive? (operator expr))
     (let* ((op (pvs2C-primitive-op (operator expr)))
	    (args (mapcar #'C-range (arguments expr))))
       (cond ((negation-function? op args)
	      (cons (neg-zb (sup (car args)))
		    (neg-zb (inf (car args)))))
	     ((= (length args) 2)
	      (let ((i1 (inf (car  args)))
		    (s1 (sup (car  args)))
		    (i2 (inf (cadr args)))
		    (s2 (sup (cadr args))))
		(cond ((eql op 'pvsAdd)
		       (cons (add-zb i1 i2) (add-zb s1 s2)))
		      ((eql op 'pvsSub)
		       (cons (sub-zb i1 s2) (sub-zb s1 i2)))
		      ((eql op 'pvsTimes)
		       (cons (min-zb (min-zb (mul-zb i1 i2)
					     (mul-zb i1 s2))
				     (min-zb (mul-zb s1 i2)
					     (mul-zb s1 s2)))
			     (max-zb (max-zb (mul-zb i1 i2)
					     (mul-zb i1 s2))
				     (max-zb (mul-zb s1 i2)
					     (mul-zb s1 s2)))))
		      (t nil))))
	     (t nil))))))))



;; -------- Simple indentation function ---------
(defun indent (bloc)
  (if (listp bloc) (mapcar #'indent bloc)
    (format nil "  ~a" bloc)))



;; There is probably a Common Lisp function to do that...
(defun append-lists (l)
  (when (consp l) (append (car l) (append-lists (cdr l)))))

(defun range-arr (max &key (min 0) (step 1))
   (loop for n from min below max by step
      collect n))










;; ---------- Draft / old functions ---------------------


(defun C_type (op)
  (let ((hashentry (gethash (declaration op) (C-hashtable))))
    (when hashentry (format nil "~a -> ~a"
	 (C-info-type-arg hashentry)
	 (C-info-type-out hashentry)))))

(defun C_definition (op)
  (let ((hashentry (gethash (declaration op) (C-hashtable))))
    (when hashentry (C-info-definition hashentry))))







(defmacro C-reset (array)
  `(setq ,array nil))
(defmacro C-save (array)
  `(setq ,array (list ,array)))
(defmacro C-load (array)
  `(if (listp (car ,array))
       (let ((res (cdr ,array)))
	 (setq ,array (car ,array))
	 res)
     (break)))
(defmacro C-add (array args)
  `(setq ,array (append ,array
	    (if (listp ,args) ,args (list ,args)))))
(defmacro C-flush (array)
  `(let ((res ,array))
     (setq ,array nil)
     res))




;; Instructions to allocate memory for new variables
(defvar *C-instructions* nil)
(defun reset-instructions () (C-reset *C-instructions*))
(defun add-instructions (instructions)
  (C-add *C-instructions* instructions))
(defun add-instruction (instruction)
  (C-add *C-instructions* (list instruction)))
(defun add-instructions-first (instructions)
  (setq *C-instructions* (append instructions *C-instructions*)))

;; Instructions to destruct previously allocated memory
(defvar *C-destructions* nil)
(defun reset-destructions () (C-reset *C-destructions*))
(defun add-destructions (destructions)
  (C-add *C-destructions* destructions))
(defun add-destruction (destruction)
  (C-add *C-destructions* (list destruction)))


;; -------------Debugging functions and variables ---------------
(defvar *Cshow-safe* t)
(defvar *Cshow-bang* t)

;; Not working well
(defvar *Csimple-names* nil)
(defun gen-name (id destr)
  (if *Csimple-names* (format nil "~a~:[~;_d~]" id destr)
    (gentemp (format nil "pvs_~a~:[~;_d~]" id destr))))

(defvar *Cdebug* t)
(defun debug (str) (when *Cdebug*) (format t "~%Debug: ~a" str))




;; (defun pvs2C-resolution-nondestructive (op-decl formals body range-type)
;;   (let* ((*destructive?* nil)
;; 	 (bind-ids (pvs2cl-make-bindings formals nil))
;; 	 (id-map (pairlis formals bind-ids))
;; 	 (C-type-out (pvs2C-type range-type))
;; 	 (return-void (C-gmp? C-type-out))
;; 	 (result-var (C-var C-type-out "result"))
;; 	 (C-args (loop for var in formals
;; 		       collect (C-var (pvs2C-type (type var))
;; 				      (cdr (assoc var id-map)))))
;; 	 (C-type-arg (append (when return-void (list (C-var C-type-out "result")))
;; 			     C-args))
;; 	 (hash-entry (gethash op-decl *C-nondestructive-hash*))
;; 	 (C-body (pvs2C2 body id-map nil result-var (not return-void))))
;;              ;; If we don't return void, we need to malloc the result
;;     (debug (format nil "Defining (nondestructively) ~a with type~%   ~a -> ~a"
;; 		   (id op-decl) (mapcar #'type C-type-arg) C-type-out))
;;     (when *eval-verbose* (format t "~%as :~%~{~a~%~}" (instr C-body)))
;;     (setf (C-info-type-out hash-entry) (if return-void "void" C-type-out)
;; 	  (C-info-type-arg hash-entry) C-type-arg
;; 	  (C-info-C-code   hash-entry) C-body
;; 	  (C-info-definition hash-entry)
;; 	  (Cfun-decl (append (instr C-body)
;; 			     (if return-void (destr C-body) (list (Creturn result-var))))
;; 		     C-args nil))))

;; (defun pvs2C-resolution-destructive (op-decl formals body range-type)
;;   (let* ((*destructive?* t)
;; 	 (bind-ids (pvs2cl-make-bindings formals nil))
;; 	 (id-map (pairlis formals bind-ids))
;; 	 (C-type-out (pvs2C-type range-type))
;; 	 (return-void (C-gmp? C-type-out))
;; 	 (result-var (C-var C-type-out "result"))
;; 	 (C-args (loop for var in formals
;; 		       collect (C-var (pvs2C-type (type var))
;; 				      (cdr (assoc var id-map)))))
;; 	 (C-type-arg (append (when return-void (list (C-var C-type-out "result")))
;; 			     C-args))
;; 	 (hash-entry (gethash op-decl *C-destructive-hash*))
;; 	 (old-output-vars (C-info-analysis hash-entry))
;; 	 (C-body (pvs2C2 body id-map nil result-var (not return-void))))
;;              ;; If we don't return void, we need to malloc the result
;;     (debug (format nil "Defining (destructively) ~a with type~%   ~a -> ~a"
;; 		   (id op-decl) (mapcar #'type C-type-arg) C-type-out))
;;     (when *eval-verbose* (format t "~%as :~%~{~a~%~}" (instr C-body)))
;;     (setf (C-info-type-out hash-entry) (if return-void "void" C-type-out)
;; 	  (C-info-type-arg hash-entry) C-type-arg
;; 	  (C-info-C-code   hash-entry) C-body
;; 	  (C-info-definition hash-entry)
;; 	  (Cfun-decl (append (instr C-body)
;; 			     (if return-void (destr C-body) (list (Creturn result-var))))
;; 		     C-args t))))






