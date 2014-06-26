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



;; --------------- Classe to describe a range ----------------
(defcl C-range () (inf) (sup))
(defmethod C-range ((l list))
  (if (consp l)
      (make-instance 'C-range
		     :inf (when (not (eql (car l) '*)) (car l))
		     :sup (if (consp (cdr l))
			      (when (not (eql (cadr l) '*)) (cadr l))
			    (cdr l)))
    (make-instance 'C-range :inf nil :sup nil)))

(defun inter-range (range)
  (C-range
   (when (consp range)
     (let ((hd (car range))
	   (tl (inter-range (cdr range))))
       (cons
	(cond ((and (inf hd) (inf tl))
	       (max (inf hd) (inf tl)))
	      ((inf hd) (inf hd))
	      ((inf tl) (inf tl))
		(t nil))
	(cond ((and (sup hd) (sup tl))
	       (min (sup hd) (sup tl)))
	      ((sup hd) (sup hd))
	      ((sup tl) (sup tl))
	      (t nil)))))))

(defun range-included (rangeA rangeB)
  (let ((inter (inter-range (list rangeA rangeB))))
    (and (eql (inf inter) (inf rangeA))
	 (eql (sup inter) (sup rangeA)))))



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

;; TODO add new C-range function for add, mul, ...

;; TODO implement a search for the smallest type
;; using bounds on integer expr :
;;  number-expr x -> bounds = (x x)
;;  (add, mul, sub, etc)
;;  (nil x) for half a bound


(defmethod C-range ((expr application))
  (inter-range (list (C-range (type expr))
		     (C-range
   (when (pvs2cl-primitive? (operator expr))
     (let* ((op (pvs2C-primitive-op (operator expr)))
	    (args (mapcar #'C-range (arguments expr))))
       (cond ((negation-function? op args)
	      (cons (when (sup (car args)) (- (sup (car args))))
		    (when (inf (car args)) (- (inf (car args))))))
	     ((add-function? op args)
	      (cons (when (and (inf (car args)) (inf (cadr args)))
		            (+ (inf (car args)) (inf (cadr args))))
		    (when (and (sup (car args)) (sup (cadr args)))
		            (+ (sup (car args)) (sup (cadr args))))))
	     ((sub-function? op args)
	      (cons (when (and (inf (car args)) (sup (cadr args)))
		            (- (inf (car args)) (sup (cadr args))))
		    (when (and (sup (car args)) (inf (cadr args)))
		            (- (sup (car args)) (inf (cadr args))))))
	     (t nil))))))))
      


;; -------- Simple indentation function ---------
(defun indent (bloc)
  (if (listp bloc)
      (mapcar #'(lambda (x) (format nil "  ~a" x))
	      bloc)
    (format nil "  ~a" bloc)))
