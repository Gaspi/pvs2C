;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                PVS to C translator
;;
;;     Author: Gaspard ferey
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



;; -------- C constants (implementation dependent) --------
(defvar *min-C-int* (- (expt 2 15)))
(defvar *max-C-int* (- (expt 2 15) 1))
(defvar *min-C-uli* 0)
(defvar *max-C-uli* (- (expt 2 32) 1))

(defvar *C-int-range* (C-range (cons *min-C-int* *max-C-int*)))
(defvar *C-uli-range* (C-range (cons *min-C-uli* *max-C-uli*)))


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
  (if (listp bloc)
      (mapcar #'(lambda (x) (format nil "  ~a" x))
	      bloc)
    (format nil "  ~a" bloc)))
