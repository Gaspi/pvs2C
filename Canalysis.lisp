;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                PVS to C translator
;;
;;     Author: Gaspard ferey
;;
;;  -> https://github.com/Gaspi/pvs2c.git
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; - Definition of the function declaration (Cfun-decl) class.
;; - Analysis and optimization of the C code (updates)
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(in-package :pvs)

;; --------------------------------------------------------------------
;;             Useful function mapping on Cinstr and Cexpr
;; --------------------------------------------------------------------

;; ------- Maps f to all expressions and returns the concatenation of all results --------
(defmethod map-Cexpr ((l list) f)
  (when (consp l) (append (map-Cexpr (car l) f) (map-Cexpr (cdr l) f))))
(defmethod map-Cexpr ((v C-var) f)       (funcall f v))
(defmethod map-Cexpr ((e Crecord-get) f) (append (funcall f e) (map-Cexpr (var e) f)))
(defmethod map-Cexpr ((e Carray-get) f)  (append (funcall f e) (map-Cexpr (list (var e) (arg e)) f)))
(defmethod map-Cexpr ((e Cfuncall) f)    (append (funcall f e) (map-Cexpr (args e) f)))
(defmethod map-Cexpr ((i Cfuncall-mp) f) (append (funcall f i) (map-Cexpr (func i) f)))
;; (defmethod map-Cexpr ((i Cdecl) f)       (append (funcall f i) (map-Cexpr (var i) f)))
;; (defmethod map-Cexpr ((i Cinit) f)       (append (funcall f i) (map-Cexpr (var i) f)))
;; (defmethod map-Cexpr ((i Cfree) f)       (append (funcall f i) (map-Cexpr (var i) f)))
(defmethod map-Cexpr ((i Cset) f)     (append (funcall f i) (map-Cexpr (list (var i)  (expr i)) f)))
(defmethod map-Cexpr ((i Ccopy) f)       (append (funcall f i) (map-Cexpr (list (varA i) (varB i)) f)))
(defmethod map-Cexpr ((i Carray-init) f) (append (funcall f i) (map-Cexpr (list (var i)  (body i)) f)))
(defmethod map-Cexpr ((i Crecord-init) f)(append (funcall f i) (map-Cexpr (var i) f)))
(defmethod map-Cexpr ((i Creturn) f)     (append (funcall f i) (map-Cexpr (var i) f)))
(defmethod map-Cexpr ((i Cif) f)
  (append (funcall f i)  (map-Cexpr (list (cond-part i) (then-part i) (else-part i)) f)))
(defmethod map-Cexpr (e f) (break "Mapvars encountered unknown C expression..."))

;; ------------------- Maps f only to instructions ----------------------
(defun map-Cinstr (body f)
  (map-Cexpr body #'(lambda (x) (when (Cinstr? x) (funcall f x)))))

;; --------------- Maps update function f to all C expressions ----------------
(defmethod upd-Cexpr ((v C-var) f) (funcall f v))
(defmethod upd-Cexpr ((l list) f)
  (when (consp l)
    (let ((hd (upd-Cexpr (car l) f))
	  (tl (upd-Cexpr (cdr l) f)))
      (if hd (cons hd tl) tl))))
(defmethod upd-Cexpr ((e Carray-get) f)
  (setf (var  e) (upd-Cexpr (var  e) f))
  (setf (arg  e) (upd-Cexpr (arg  e) f))
  (funcall f e))
(defmethod upd-Cexpr ((e Crecord-get) f) (setf (var  e) (upd-Cexpr (var  e) f)) (funcall f e))
(defmethod upd-Cexpr ((e Cfuncall) f)    (setf (args e) (upd-Cexpr (args e) f)) (funcall f e))
(defmethod upd-Cexpr ((i Cfuncall-mp) f) (setf (func i) (upd-Cexpr (func i) f)) (funcall f e))
(defmethod upd-Cexpr ((i Cdecl) f)       (setf (var  i) (upd-Cexpr (var  i) f)) (funcall f i))
(defmethod upd-Cexpr ((i Cinit) f)       (setf (var  i) (upd-Cexpr (var  i) f)) (funcall f i))
(defmethod upd-Cexpr ((i Cfree) f)       (setf (var  i) (upd-Cexpr (var  i) f)) (funcall f i))
(defmethod upd-Cexpr ((i Cset) f)
  (setf (var  i) (upd-Cexpr (var  i) f))
  (setf (expr i) (upd-Cexpr (expr i) f))
  (funcall f i))
(defmethod upd-Cexpr ((i Ccopy) f)
  (setf (varA i) (upd-Cexpr (varA i) f))
  (setf (varB i) (upd-Cexpr (varB i) f))
  (funcall f i))
(defmethod upd-Cexpr ((i Carray-init) f)
  (setf (var  i) (upd-Cexpr (var  i) f))
  (setf (body i) (upd-Cexpr (body i) f))
  (funcall f i))
(defmethod upd-Cexpr ((i Crecord-init) f) (setf (var i) (upd-Cexpr (var i) f)) (funcall f i))
(defmethod upd-Cexpr ((i Creturn) f)      (setf (var i) (upd-Cexpr (var i) f)) (funcall f i))
(defmethod upd-Cexpr ((i Cif) f)
  (setf (cond-part i) (upd-Cexpr (cond-part i) f))
  (setf (then-part i) (upd-Cexpr (then-part i) f))
  (setf (else-part i) (upd-Cexpr (else-part i) f))
  (funcall f i))
(defmethod upd-Cexpr (e f) (break "Mapvars encountered unknown C expression..."))

;;  ------------------ Maps f only to instructions ----------------------
(defun upd-Cinstr (body f)
  (upd-Cexpr body #'(lambda (x) (if (Cinstr? x) (funcall f x) x))))





;; --------------------------------------------------------------------
;;                 Bang flags management
;; --------------------------------------------------------------------
(defvar *C-bang-vars* nil)
(defun bang? (Cvar)
  (when (C-var? Cvar)
    (let ((e (assoc Cvar *C-bang-vars* :test #'eq-C-var)))
      (when e (cdr e)))))

;; --- Initializes the bang-vars assoc list with the arguments of a function --
(defun init-bang-args (args)
  (when (consp args)
    (let ((hd (car args))
	  (tl (init-bang-args (cdr args))))
      (if (C-pointer? (type hd))
	  (acons (name hd) *destructive?*  tl)
	tl))))

;; --- Flags the var as bang (unless it is already flagged not bang) ---
(defun add-bang (f var)
  (let* ((b (bang-vars f)))
    (unless (assoc Cvar b :test #'eq-C-var)
      (setf (bang-vars f) (acons var t (bang-vars f))))))

;; -- ------------- Unflags the var as bang ---------------
(defun rem-bang (f var)
  (setf (bang-vars f) (acons var nil (bang-vars f))))



;; --------------------------------------------------------------------
;;                 C code analysis
;; --------------------------------------------------------------------

(defcl Cfun-decl () (id) (type-out) (args) (all-vars) (bang-vars) (body))
(defun Cfun-decl (id type-out body args)
  (make-instance 'Cfun-decl
		 :id id :type-out type-out :args args
		 :bang-vars (init-bang-args args)
		 :all-vars (get-set (get-all-vars (list args body)))
		 :body body))

;; -------- Printing a function declaration -------------
(defun print-signature (f out)
  (let ((*C-bang-vars* (bang-vars f)))
    (format out "~2%~a ~a(~a);" (type-out f) (id f) (sign-var (args f)))))
(defun print-definition (f out)
  (let ((*C-bang-vars* (bang-vars f)))
    (format out  "~2%~a ~a(~a) ~a" (type-out f) (id f) (sign-var (args f)) f)))
(defmethod print-object ((obj Cfun-decl) out)
  (format out "{~%~{~a~%~}}" (get-C-instructions obj)))
(defmethod get-C-instructions ((e Cfun-decl))
  (let ((*C-bang-vars* (bang-vars e)))
    (indent (get-C-instructions (body e)))))


(defun unionvar (x y) (union x y :test #'eq-C-var))  
(defun get-set (l)
  (if (consp l)
      (unionvar (get-set (car l)) (get-set (cdr l)))
    (when l (list l))))


;; --------------- Gets all pointer-type variables -----------------
(defun get-all-vars (body)
  (map-Cexpr body #'(lambda (x) (when (and (C-var? x) (C-pointer? (type x))) (list x)))))


;; --------- This function flags "safe" all last occurence of a variable -----------
(defun safety-analysis (l)
  (when (consp l)
    (let* ((safe (safety-analysis (cdr l)))
	   (vars (get-all-vars (car l)))
	   (candidates (set-difference vars safe :test #'eq-C-var))
	   (set-cand (get-set candidates)))
      (loop for e in set-cand
	    do (let ((c (count e candidates :test #'eq-C-var)))
		 (if (= c 1) (replace-vars (car l) (name e) (safe-var e))
		   (if (= c 0) (break)))))
      (unionvar set-cand safe))))

;; --------- This function unflags "safe" in all variables -----------
(defun unsafe-all (l)
  (upd-Cexpr l #'(lambda (x) (if (and (C-var? x) (safe x))
				 (C-var (type x) (name x) nil) x))))

;; ---------- Replace all pointer-type variables with given name by new-var----------
(defun replace-vars (body name new-var)
  (upd-Cexpr body #'(lambda (x) (if (and (C-var? x) (string= (name x) name)) new-var x))))

;; ---------- Replace all pointer-type variables with given name by new-var----------
;; (defun delete-instrs (body testf)
;;   (upd-Cexpr body #'(lambda (x) (unless (and (Cinstr? x) (testf x)) x))))


;; ----- The main analysis loop. The recursive call should terminate... ------------
(defun C-analysis (op-decl)
  (let ((f  (C-info-definition (gethash op-decl *C-nondestructive-hash*)))
	(fd (C-info-definition (gethash op-decl *C-destructive-hash*))))
    (and (or (C-analysis* f)
    	     (C-analysis* fd))  ;; if both return nil  (no change)  then return nil
    	 (C-analysis op-decl)))) ;; else try again


;; ------------------ Here is the body of the analysis ---------------
(defun C-analysis* (f)
  (with-slots (body) f
  (let ((*C-bang-vars* (bang-vars f)))
    (unsafe-all body)
    (safety-analysis body)

    (upd-Cinstr body #'(lambda (x)
			 (if (and (Cset? x)
				  (bang? (expr x))   ;; This means (expr x) is a C-var
				  (not (safe (expr x))))
			     (Ccopy (var x) (expr x))
			   x)))
    (let ((rr (get-replace-rule body)))
      (if rr
	  (progn
	    (setf (body f)
		  (upd-Cinstr body
			      #'(lambda (x)
				  (unless (or (and (or (Cdecl? x) (Cinit? x))
						   (string= (name (var x)) (cadr rr)))
					      (eq x (car rr))
					      (and (Cfree? x)
						   (eq-C-var (var x) (cddr rr))))
				    x))))
	    (replace-vars body (cadr rr) (cddr rr))
	    t) ;; We return t to restart the analysis loop
	nil
	)))))


;; TODO This function gets a replace rule (i . (name . var)) from an instruction
;; This is treated by:
;;  - Deleting the decl and init of name
;   - Deleting the current set or copy instruction
;;  - Deleting the free of var
;;  - Replacing occurences of name by var
;;  - Unsafing all variables !!!
;;  - Redo a safe analysis
(defmethod get-replace-rule ((i list))
  (when (consp i) (or (get-replace-rule (car i))
		      (get-replace-rule (cdr i)))))

(defmethod get-replace-rule ((i Cinstr))
  (cond ((and (Cset? i)
	      (C-var? (var i))
	      (safe (expr i)))
	 (cons i (cons (name (var i)) (expr i))))
	((and (Ccopy? i)
	      (C-var? (varA i))
	      (C-var? (varB i))
	      (bang? (varB i))
	      (safe   (varB i)))
	 (cons i (cons (name (varA i)) (varB i))))
	(t nil)))





