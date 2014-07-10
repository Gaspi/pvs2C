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


;; -------- Classe result of translating functions -------------------
(defcl C-expr () (type) (name) (instr) (destr))
(defun mk-C-expr (type name instr destr)
  (make-instance 'C-expr :type type
		        :name name
			:instr instr
			:destr destr))

(defun mk-simple-C-expr (type name)
  (mk-C-expr type name nil nil))

(defmethod print-object ((obj C-expr) out) (format out "~a" (name obj)))

(defmethod set-type ((C-expr C-expr) (type C-type))
  (setf (type C-expr) type))
(defmethod set-name ((C-expr C-expr) name)
  (setf (name C-expr) name))
(defmethod set-instr ((C-expr C-expr) instr)
  (setf (instr C-expr) instr))
(defmethod set-destr ((C-expr C-expr) destr)
  (setf (destr C-expr) destr))

(defmethod app-instr ((C-expr C-expr) instr &optional first)
  (setf (instr C-expr)
	(if first
	    (append instr (instr C-expr))
	  (append (instr C-expr) instr))))
(defmethod app-destr ((C-expr C-expr) destr &optional first)
  (setf (destr C-expr)
	(if first
	    (append destr (destr C-expr))
	    (append (destr C-expr) destr))))


(defmethod unnamed? ((C-expr C-expr))
  (null (name C-expr)))

(defmethod define-name ((C-expr C-expr) name)
  (set-name C-expr name)
  (set-instr C-expr (define-name (instr C-expr) name))
  (set-destr C-expr (define-name (destr C-expr) name))
  C-expr)

(defmethod define-name ((str string) name)
  (format nil str name))
(defmethod define-name ((lst list) name)
  (when (consp lst)
    (cons (define-name (car lst) name)
	  (define-name (cdr lst) name))))



;; ------------ CLOS representation of a fragment of C code -----------
(defcl Cexpr () (list-var))
(defun mk-Cexpr () (make-instance 'Cexpr :list-var nil))

;; A C variable is a type and a string to represent it
(defcl C-var (Cexpr) (name) (type))
(defun C-var (type name &optional list-var)
  (make-instance 'C-var :name name :type type :list-var list-var))
(defmethod print-object ((obj C-var) out)
  (format out "~a" (name obj)))
(defun gen-C-var (type prefix)
  (let ((res (C-var type (gentemp prefix))))
    (setf (list-var res) (list res))
    res))



;; ------------ CLOS representation of a full line of C code ----------
(defcl Cinstr ())

;; Should not be used
(defcl Caux (Cinstr) (body))
(defun mk-Caux (body) (make-instance 'Caux :body body))



;; (defcl Cvar () (name) (type))

;; (defcl C-expr () (body) (type) (vars))
;; (defcl C-expr-var (C-expr) (var))



;;(defcl Cinstr ())

;; (defcl Calloc (Cinstr) (Cvar))

;; (defcl Cif (Cinstr) (condition) (if-part) (then-part))

