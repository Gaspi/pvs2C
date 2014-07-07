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

;; Defining here a intermediate language between C and PVS
;;

(defcl Cexpr () (type) (name) (instr) (destr))
(defun mk-Cexpr (type name instr destr)
  (make-instance 'Cexpr :type type
		        :name name
			:instr instr
			:destr destr))

(defun mk-simple-Cexpr (type name)
  (mk-Cexpr type name nil nil))

(defmethod print-object ((obj Cexpr) out) (format out "~a" (name obj)))

(defmethod set-type ((Cexpr Cexpr) (type C-type))
  (setf (type Cexpr) type))
(defmethod set-name ((Cexpr Cexpr) name)
  (setf (name Cexpr) name))
(defmethod set-instr ((Cexpr Cexpr) instr)
  (setf (instr Cexpr) instr))
(defmethod set-destr ((Cexpr Cexpr) destr)
  (setf (destr Cexpr) destr))

(defmethod app-instr ((Cexpr Cexpr) instr &optional first)
  (setf (instr Cexpr)
	(if first
	    (append instr (instr Cexpr))
	  (append (instr Cexpr) instr))))
(defmethod app-destr ((Cexpr Cexpr) destr &optional first)
  (setf (destr Cexpr)
	(if first
	    (append destr (destr Cexpr))
	    (append (destr Cexpr) destr))))


(defmethod unnamed? ((Cexpr Cexpr))
  (null (name Cexpr)))

(defmethod define-name ((Cexpr Cexpr) name)
  (set-name Cexpr name)
  (set-instr Cexpr (define-name (instr Cexpr) name))
  (set-destr Cexpr (define-name (destr Cexpr) name))
  Cexpr)

(defmethod define-name ((str string) name)
  (format nil str name))
(defmethod define-name ((lst list) name)
  (when (consp lst)
    (cons (define-name (car lst) name)
	  (define-name (cdr lst) name))))






;; (defcl Cvar () (name) (type))

;; (defcl Cexpr () (body) (type) (vars))
;; (defcl Cexpr-var (Cexpr) (var))



;;(defcl Cinstr ())

;; (defcl Calloc (Cinstr) (Cvar))

;; (defcl Cif (Cinstr) (condition) (if-part) (then-part))

