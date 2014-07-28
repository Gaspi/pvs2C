;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                PVS to C translator
;;
;;     Author: Gaspard ferey
;;
;;  -> https://github.com/Gaspi/pvs2c.git
;;  -> Please read  "main.lisp"
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; - Definition of the function declaration (Cfun-decl) class.
;; - Analysis and optimization of the C code (updates)
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(in-package :pvs)

;; --------------------------------------------------------------------
;;             Useful function mapping on C code
;; --------------------------------------------------------------------

;; ------- Maps f to all expressions and returns the concatenation of all results --------
(defmethod map-Ccode ((l list) f)
  (when (consp l) (append (map-Ccode (car l) f) (map-Ccode (cdr l) f))))
(defmethod map-Ccode ((v C-var)       f) (funcall f v))
(defmethod map-Ccode ((e Crecord-get) f) (append (funcall f e) (map-Ccode (var e) f)))
(defmethod map-Ccode ((e Carray-get)  f) (append (funcall f e) (map-Ccode (list (var e) (arg e)) f)))
(defmethod map-Ccode ((e Cfuncall)    f) (append (funcall f e) (map-Ccode (args e) f)))
(defmethod map-Ccode ((i Cfuncall-mp) f) (append (funcall f i) (map-Ccode (Cfunc i) f)))
(defmethod map-Ccode ((i Cdecl) f)       (append (funcall f i) (map-Ccode (var i) f)))
(defmethod map-Ccode ((i Cinit) f)       (append (funcall f i) (map-Ccode (var i) f)))
;; (defmethod map-Ccode ((i Cfree) f)       (append (funcall f i) (map-Ccode (var i) f)))
(defmethod map-Ccode ((i Cset) f)     (append (funcall f i) (map-Ccode (list (var i)  (expr i)) f)))
(defmethod map-Ccode ((i Ccopy) f)       (append (funcall f i) (map-Ccode (list (varA i) (varB i)) f)))
(defmethod map-Ccode ((i Carray-init) f) (append (funcall f i) (map-Ccode (list (var i)  (body i)) f)))
(defmethod map-Ccode ((i Crecord-init) f)(append (funcall f i) (map-Ccode (var i) f)))
(defmethod map-Ccode ((i Creturn) f)     (append (funcall f i) (map-Ccode (var i) f)))
(defmethod map-Ccode ((i Cif) f)
  (append (funcall f i)  (map-Ccode (list (cond-part i) (then-part i) (else-part i)) f)))
(defmethod map-Ccode ((e Ccode) f) nil)
(defmethod map-Ccode (e f) (break "Mapvars encountered unknown C expression..."))

;; ------------------- Maps f only to instructions ----------------------
(defun map-Cinstr (body f)
  (map-Ccode body #'(lambda (x) (when (Cinstr? x) (funcall f x)))))

;; --------------- Maps update function f to all C expressions ----------------
(defmethod upd-Ccode ((v C-var) f) (funcall f v))
(defmethod upd-Ccode ((l list) f)
  (when (consp l)
    (let ((hd (upd-Ccode (car l) f))
	  (tl (upd-Ccode (cdr l) f)))
      (if hd (cons hd tl) tl))))
(defmethod upd-Ccode ((e Carray-get) f)
  (setf (var  e) (upd-Ccode (var  e) f))
  (setf (arg  e) (upd-Ccode (arg  e) f))
  (funcall f e))
(defmethod upd-Ccode ((e Crecord-get) f) (setf (var  e) (upd-Ccode (var  e) f)) (funcall f e))
(defmethod upd-Ccode ((e Cfuncall) f)    (setf (args e) (upd-Ccode (args e) f)) (funcall f e))
(defmethod upd-Ccode ((i Cfuncall-mp) f) (setf (Cfunc i)(upd-Ccode (Cfunc i)f)) (funcall f i))
(defmethod upd-Ccode ((i Cdecl) f)       (setf (var  i) (upd-Ccode (var  i) f)) (funcall f i))
(defmethod upd-Ccode ((i Cinit) f)       (setf (var  i) (upd-Ccode (var  i) f)) (funcall f i))
(defmethod upd-Ccode ((i Cfree) f)       (setf (var  i) (upd-Ccode (var  i) f)) (funcall f i))
(defmethod upd-Ccode ((i Cset) f)
  (setf (var  i) (upd-Ccode (var  i) f))
  (setf (expr i) (upd-Ccode (expr i) f))
  (funcall f i))
(defmethod upd-Ccode ((i Ccopy) f)
  (setf (varA i) (upd-Ccode (varA i) f))
  (setf (varB i) (upd-Ccode (varB i) f))
  (funcall f i))
(defmethod upd-Ccode ((i Carray-init) f)
  (setf (var  i) (upd-Ccode (var  i) f))
  (setf (body i) (upd-Ccode (body i) f))
  (funcall f i))
(defmethod upd-Ccode ((i Crecord-init) f) (setf (var i) (upd-Ccode (var i) f)) (funcall f i))
(defmethod upd-Ccode ((i Creturn) f)      (setf (var i) (upd-Ccode (var i) f)) (funcall f i))
(defmethod upd-Ccode ((i Cif) f)
  (setf (cond-part i) (upd-Ccode (cond-part i) f))
  (setf (then-part i) (upd-Ccode (then-part i) f))
  (setf (else-part i) (upd-Ccode (else-part i) f))
  (funcall f i))
(defmethod upd-Ccode (e f) (break "Mapvars encountered unknown C expression..."))

;;  ------------------ Maps f only to instructions ----------------------
(defun upd-Cinstr (body f)
  (upd-Ccode body #'(lambda (x) (if (Cinstr? x) (funcall f x) x))))



;; --------------------------------------------------------------------
;;                 C function declarations
;; --------------------------------------------------------------------

(defcl Cfun-decl () (id) (type-out) (args) (all-vars) (flags) (body))
(defun Cfun-decl (id type-out body args)
  (make-instance 'Cfun-decl
		 :id id :type-out type-out :args args
		 :flags (init-flags args)
		 :all-vars (get-set (get-all-vars (list args body)))
		 :body body))

;; ----- Return all pointer arguments in f -----------
(defmethod pointer-args ((f Cfun-decl))
  (pointer-args (args f)))
(defmethod pointer-args ((l list))
  (when (consp l)
    (let ((hd (car l))
	  (tl (pointer-args (cdr l))))
      (if (pointer? hd)
	  (cons hd tl) tl))))

;; -------- Printing a function declaration -------------
(defun print-signature (f out)
  (assert (Cfun-decl? f))
  (let ((*Ccurr-f* f))
    (format out "~2%~a ~a(~a);" (type-out f) (id f) (sign-var (args f)))))
(defun print-definition (f out)
  (assert (Cfun-decl? f))
  (let ((*Ccurr-f* f))
    (format out  "~2%~:[~;!~]~a ~a(~a) {~%~{~a~%~}}"
	    (and *Cshow-bang* (bang-return? f))
	    (type-out f)
	    (id f)
	    (sign-var (args f))
	    (get-C-instructions f))))
(defmethod print-object ((obj Cfun-decl) out)
  (print-definition obj out))
(defmethod get-C-instructions ((f Cfun-decl))
  (indent (get-C-instructions (body f))))






;; --------------------------------------------------------------------
;;                 Variables and flags management
;; --------------------------------------------------------------------

;; ------- Current function declaration beeing analysed --------
(defvar *Ccurr-f* nil)

;; ----- Is Cvar an argument or a local variable in the current function ? ----
(defun is-arg? (Cvar &optional (f *Ccurr-f*))
  (member Cvar (args f) :test #'eq-C-var))
(defun is-local? (Cvar &optional (f *Ccurr-f*))
  (not (is-arg? Cvar f)))

;; ---------------- Return variable and type --------------
(defun get-return-var (f)
  (let ((ret (car (last (body f)))))
    (when (Creturn? ret) (var ret)))) ;; The last instruction should be Creturn
(defmethod bang-return? ((f Cfun-decl)) (bang? (get-return-var f) f))
(defmethod bang-return? ((f const-decl))
  (bang-return? (C-info-definition (gethash f (C-hashtable)))))
(defmethod bang-return? ((f null)) nil)  ;; allows to call (bang-return? nil)


;; ------------ Class to represent the flags state of a variable ----------
(defcl Cflags () (bang) (dupl) (arg) (treated))
(defun Cflags (&optional bang arg)
  (make-instance 'Cflags :bang bang :dupl nil :arg arg :treated arg))
(defmethod bang    (Cvar) nil)
(defmethod dupl    (Cvar) nil)
(defmethod treated (Cvar) nil)

;; --- Initializes the flags assoc list with the arguments of a function --
(defun init-flags (args)
  (when (consp args)
    (let ((hd (car args))
	  (tl (init-flags (cdr args))))
      (if (pointer? hd)
	  (acons (name hd) (Cflags *destructive?* t) tl)
	tl))))

;; ---------- Return the Cflags associated to the Cvar ----------
(defun get-flags (Cvar &optional (f *Ccurr-f*))
  (when (and f (pointer? Cvar))
    (let ((e (assoc Cvar (flags f) :test #'eq-C-var)))
      (if e (cdr e)
	(let ((new-e (Cflags)))  ;; Create a default Cflags
	  (setf (flags f) (acons (name Cvar) new-e (flags f)))
	  new-e)))))


;; ------- Return nil if the variable is currently considered not bang ---
(defmethod bang? ((fc Cfuncall) &optional (f *Ccurr-f*))
  (bang-return? (get-definition fc)))
(defmethod bang? (Cvar &optional (f *Ccurr-f*)) (bang (get-flags Cvar f)))



;; --------- Is it legal to flag this var ? (local & not treated yet) ---------
(defmethod add-bang? ((e Cflags)) (not (or (arg e) (treated e))))
(defmethod add-bang? (Cvar) (when Cvar (add-bang? (get-flags Cvar))))
(defmethod add-bang ((e Cflags))
  (when (add-bang? e)
    (setf (bang    e) t)
    (setf (treated e) t)))  ;; This flag guarantees variables are never flagged bang twice
(defmethod add-bang (Cvar) (when Cvar (add-bang (get-flags Cvar))))

;; --------- Is it legal to unflag this var ? ---------
(defmethod rem-bang? ((e Cflags)) (bang e))
(defmethod rem-bang? (Cvar)       (when Cvar (rem-bang? (get-flags Cvar))))
;; ------ Unflags the var(s). Return nil if no removal was legal ----------
(defmethod rem-bang ((e Cflags))  (when (rem-bang? e) (setf (bang e) nil) t))
(defmethod rem-bang ((l list))
  (when (consp l)
    (let ((hd (rem-bang (car l)))
	  (tl (rem-bang (cdr l))))
      (or hd tl))))
(defmethod rem-bang (Cvar) (rem-bang (get-flags Cvar)))


;; -------- Is a variable or a simple expresion dupl ? ------------
(defmethod dupl? ((e Crecord-get) &optional (f *Ccurr-f*)) (dupl? (var e) f))
(defmethod dupl? ((e Carray-get)  &optional (f *Ccurr-f*)) (dupl? (var e) f))
(defmethod dupl? (Cvar            &optional (f *Ccurr-f*))
  (when Cvar (dupl (get-flags Cvar f))))

;; ----------- The dupl flag can't be removed ----------------------
(defmethod set-dupl ((e Cflags))
  (when (not (dupl e)) (setf (dupl e) t)))
(defmethod set-dupl ((e Carray-get))  (set-dupl (var e)))
(defmethod set-dupl ((e Crecord-get)) (set-dupl (var e)))
(defmethod set-dupl ((e Cfuncall))    (set-dupl (get-dupl-args e)))
(defmethod set-dupl ((l list))
  (when (consp l)
    (let ((hd (set-dupl (car l)))
	  (tl (set-dupl (cdr l))))
      (or hd tl))))
(defmethod set-dupl (Cvar) (set-dupl (get-flags Cvar)))





;; --------------------------------------------------------------------
;;                 C code analysis
;; --------------------------------------------------------------------

;; ------- Operations on sets of variables ---------------
(defun unionvar (x y) (union x y :test #'eq-C-var))  
(defun get-set (l)
  (if (consp l)
      (unionvar (get-set (car l)) (get-set (cdr l)))
    (when l (list l))))

;; --------------- Gets all pointer-type variables -----------------
(defun get-all-vars (body)
  (map-Ccode body #'(lambda (x) (when (pointer? x) (list x)))))




;; ---------- Replace all pointer-type variables according to assoc list ----------
(defun replace-variables (body alist)
  (upd-Ccode body
	     #'(lambda (x) (or (cdr (assoc x alist :test #'eq-C-var)) x))))

;; ----- The main analysis loop. The recursive call should terminate... ------------
(defun C-analysis (op-decl)
  (let ((f  (C-info-definition (gethash op-decl *C-nondestructive-hash*)))
	(fd (C-info-definition (gethash op-decl *C-destructive-hash*))))
    (and (or (C-analysis* f)
    	     (C-analysis* fd)         ;; if both return nil  (no change)
	     (C-last-analysis f)) ;; then perform a last analysis and return nil
    	 (C-analysis op-decl)))) ;; else try again


;; ------------------ Here is the body of the analysis ---------------
(defun C-analysis* (f)
  (with-slots (body) f
  (let ((*Ccurr-f* f))
    (unsafe-all-pointers body)
    (init-analysis f)
    ;; (break)
    (when *C-replace-analysis*
      (or (C-analysis-destr-funcall body)
	  (C-analysis-dupl-funcall body)
	  (C-analysis-replace-rule f body)
	  (C-analysis-new-notbang body)
	  (C-analysis-new-bang    body)
	  (C-analysis-dupl body)
	  (C-analysis-set-to-copy body)
	  )))))



;; ------ This function unflags "safe" in all occurence of variables -----
(defun unsafe-all-pointers (l)
  (upd-Ccode l #'(lambda (x) (if (and (pointer? x) (safe x))
				 (C-var (type x) (name x) nil) x))))

;; --------- This function flags "safe" all last occurence of a variable -----------
(defun safety-analysis (l)
  (when (consp l)
    (let* ((safe (safety-analysis (cdr l)))
	   (vars (get-all-vars (car l)))
	   (candidates (set-difference vars safe :test #'eq-C-var))
	   (set-cand (get-set candidates))
	   (repl (pairlis set-cand
			  (mapcar #'(lambda (x)
				      (if (= (count x candidates :test #'eq-C-var) 1)
					  (safe-var x) x))
				  set-cand))))
      (replace-variables (car l) repl)
      (unionvar set-cand safe))))

;; --------- This function put all safe flags, unbang safe (unused) arguments,
;; --------- and flag the return variable as dupl
(defun init-analysis (f)
  (assert (Cfun-decl? f))
  (let* ((used   (safety-analysis (body f)))
	 (unused (set-difference (pointer-args f) used :test #'eq-C-var)))
    (rem-bang unused)
    (setf (args f)
	  (mapcar #'(lambda (x) (if (member x unused :test #'eq-C-var) (safe-var x) x))
		  (args f)))
    (set-dupl (get-return-var f))))



;; ------ Analysis to find variables that can be replaced by an other -----------
(defun C-analysis-replace-rule (f body)
  (let ((rr (get-replace-rule body)))
    (when rr
      (setf (body f)
	    (upd-Cinstr body
			#'(lambda (x)
			    (unless (or (and (or (Cdecl? x) (Cinit? x))
					     (string= (name (var x)) (cadr rr)))
					(eq x (car rr))
					(and (Cfree? x)
					     (eq-C-var (var x) (cddr rr))))
			      x))))
      (replace-variables body (list (cdr rr)))
      t))) ;; We return t to restart the analysis loop

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
	      (C-var? (expr i))
	      (type= (type (var i)) (type (expr i)))
	      (safe (expr i)))
	 (cons i (cons (name (var i)) (safe-var (expr i) nil))))
	((and (Ccopy? i)
	      (C-var? (varA i))
	      (C-var? (varB i))
	      (bang?  (varB i))
	      (safe   (varB i)))
	 (cons i (cons (name (varA i)) (safe-var (varB i) nil))))
	(t nil)))


;; --------- Analysis to remove bang flags ---------------
(defun C-analysis-new-notbang (body)
  (let ((new-nb (map-Ccode body #'get-new-bang-unflag)))
    (rem-bang new-nb)))
(defmethod get-new-bang-unflag ((e Carray-get))
  (when (and (bang? (var e)) (safe (var e))) (list (var e))))
(defmethod get-new-bang-unflag ((e Crecord-get))
  (when (and (bang? (var e)) (safe (var e))) (list (var e))))
(defmethod get-new-bang-unflag (other) nil)



;; --------- Analysis to add new bang flags ---------------
(defun C-analysis-new-bang (body)
  (let ((new-b (get-new-bang-flag body)))
    (when (add-bang? new-b) (add-bang new-b) t)))
;; TODO find other cases when new array are created (bang)
(defmethod get-new-bang-flag ((i list))
  (when (consp i) (or (get-new-bang-flag (car i))
		      (get-new-bang-flag (cdr i)))))
(defmethod get-new-bang-flag ((i Ccopy))
  (let ((var (varA i))) (when (add-bang? var) var)))
(defmethod get-new-bang-flag ((i Carray-init))
  (let ((var (var i)))  (when (add-bang? var) var)))
(defmethod get-new-bang-flag ((i Crecord-init))
  (let ((var (var i)))  (when (add-bang? var) var)))
(defmethod get-new-bang-flag ((i Cset))
  (let ((e (expr i)))
    (when (and (safe e) (bang? e) (add-bang? (var i))) (var i))))
(defmethod get-new-bang-flag ((i Cinstr)) nil)



;; ------ Quick analysis to replace bang-unsafe Cset to Ccopy ---------------
;; ----- To be done at the very end for the least number of new copies ------
(defun C-analysis-set-to-copy (body)
  (null ;; This analysis doesn't require a restart of all analysis
   (upd-Cinstr body #'(lambda (x)
		       (if (and (Cset? x)
				(bang? (expr x))   ;; This means (expr x) is a C-var
				(not (safe (expr x))))
			   (Ccopy (var x) (expr x))
			 x)))))

;; ------ Analysis to propagate dupl flags -------
(defun C-analysis-dupl (body)
  (map-Cinstr (reverse body) #'C-analysis-dupl*))

(defmethod C-analysis-dupl* ((i Cset))
  (when (dupl? (var i))
    (and (set-dupl (expr i)) (list t))))
(defmethod C-analysis-dupl* ((i Cinstr)) nil)





;; We try to change a funcall non-destr (default) into a funcall destr
;; Conditions :
;;  - Arguments bang are variables safe and bang
;;  - Arguments dupl are variables safe or not bang
;; Consequences:
;;  -> flag destr in funcall set to t
;;  -> if result is dupl, all variables passed as dupl arguments are flagged dupl

;; ---- Gets all arguments expressions corresponding to arguments flagged bang -----
(defun get-bang-args (fc &optional destr)
  (assert (Cfuncall? fc))
  (let ((def (if destr (get-definition fc t)
	               (get-definition fc))))
    (when def (get-bang-args* (args fc) (args def) def))))
(defun get-bang-args* (l names def)
  (when (consp l)
    (let ((tl (get-bang-args* (cdr l) (cdr names) def)))
      (if (bang? (car names) def)
	  (cons (car l) tl)
	tl))))

;; ---- Gets all arguments expressions corresponding to arguments flagged dupl -----
(defun get-dupl-args (fc)
  (assert (Cfuncall? fc))
  (let ((def (get-definition fc)))
    (when def (get-dupl-args* (args fc) (args def) def))))
(defun get-dupl-args* (l names def)
  (when (consp l)
    (let ((tl (get-dupl-args* (cdr l) (cdr names) def)))
      (if (dupl? (car names) def) (cons (car l) tl) tl))))


(defun C-analysis-destr-funcall (body)
  (map-Ccode body #'destr-funcall))
(defun destr-funcall (fc)
  (when (and (Cfuncall? fc)               ;; fc is a call...
	     (const-decl? (name (fun fc)));; ... to a PVS function ...
	     (not (destr (fun fc)))      ;; ... non destructive version
	     (all-safe-and-bang (get-bang-args fc t)))
;;    (break)
    (setf (destr (fun fc)) t)
    (list t)))

(defun all-safe-and-bang (l)
  (or (null l)
      (and (safe  (car l))
	   (bang? (car l))
	   (all-safe-and-bang (cdr l)))))


(defun C-analysis-dupl-funcall (body)
;;  (break "po")
  (map-Ccode body #'dupl-funcall))
(defun dupl-funcall (fc)
  (when (and (Cfuncall? fc)
	     (get-definition fc))    ;; useless ?
    (let ((rb
	   (loop for e in (get-dupl-args fc)
		 when (and (bang? e) (not (safe e)) (C-var? e))
		 collect e)))
;;      (break)
      (when (rem-bang rb)
	(list t)))))


(defun C-last-analysis (f) )
