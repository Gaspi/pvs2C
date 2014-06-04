;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;PVS to C Translator (version 0, Jan 20, 2006)
;;Authors: Ronny Wichers Schreur and Natarajan Shankar
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;Globals: *C-record-defns* records C record type definitions
;;         *C-primitives* is a list of C names for PVS primitives
;;         *pvsC-primitives-map* is an alist mapping PVS primitives to
;;                   C versions
;;         *C-nondestructive-hash* records translations hashed by PVS decl
;;         *C-destructive-hash* records destructive translation
;;         *livevars-table* (shadowed) maintains update analysis
;;Top level function is pvs2C(expr, context) which initializes globals and
;; calls pvs2C*.  The main cases are applications, which lead to
;;pvs-defn-application and update-expr which branches according to destructive and
;;non-destructive updates.  Unfinished work includes modules and datatypes. 

;; --------------------------------------------------------------------
;; PVS
;; Copyright (C) 2006, SRI International.  All Rights Reserved.

;; This program is free software; you can redistribute it and/or
;; modify it under the terms of the GNU General Public License
;; as published by the Free Software Foundation; either version 2
;; of the License, or (at your option) any later version.

;; This program is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with this program; if not, write to the Free Software
;; Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
;; --------------------------------------------------------------------


(in-package :pvs)

(defvar *livevars-table* nil)

(defvar *definitions-stream* (make-string-output-stream))
(defvar        *main-stream* (make-string-output-stream))


(defun parse-tc (expr)
  (let ((*current-context*
      (if *current-context* *current-context* *prelude-context*)))
    (typecheck* (xt-expr (parse-expr expr)) nil nil nil)))


(defun add-definition (str &rest args)
  (apply 'format *definitions-stream* str args)
  (format *definitions-stream* "~%"))

(defun add-main (str &rest args)
  (apply 'format *main-stream* str args)
  (format *main-stream* "~%"))

(defun output-c ()
  (format t "%% ----- Definitions -----~%")
  (format t (get-output-stream-string *definitions-stream*))
  (format t "%% ----- Body -----~%")
  (format t (get-output-stream-string *main-stream*)))
  

;; This function should return a valid name for a variable used nowhere else
;; A prefixe is given
(defvar *name-counter* 0)
(defun unused-name (&optional (prefix "_"))
  (let ((*name-counter* (+ 1 *name-counter*)))
    (format nil "~a~a" prefix *name-counter*) ))



(defparameter *C-primitives* '(== != 1 0 pvsImplies pvsImplies
				   == && && || 
 ! pvsWhen pvsIff pvsAdd pvsSub pvsTimes pvsDiv pvsNumberFieldPred pvsLe pvsLeq pvsGe
 pvsGeq pvsRealPred pvsIntegerPred pvsIntegerPred pvsRationalsPred pvsFloor pvsCeiling
 rem pvsNDiv pvsEven? pvsOdd? pvsCons hd tl isCons null isNull pvsRestrict
 length isMember pvsNth pvsAppend reverse))

(defparameter *pvsC-primitives-map*
  (pairlis *pvs2cl-primitives* *C-primitives*))

(defun pvs2C-primitive-op (name)
  (let ((entry (assoc name *pvsC-primitives-map* :test #'same-primitive?)))
    (when entry (cdr entry))))


(defparameter *C-primitives-infix* '(t t nil nil nil nil t t t t
    nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
    nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil))
(defparameter *pvsC-primitives-infix-map*
  (pairlis *pvs2cl-primitives* *C-primitives-infix*))
(defun pvs2C-primitive-infix? (name)
  (let ((entry (assoc name *pvsC-primitives-infix-map* :test #'same-primitive?)))
    (when entry (cdr entry))))

(defparameter *C-primitives-nopar* '(nil nil t t nil nil nil nil nil nil
    t nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
    nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil))
(defparameter *pvsC-primitives-nopar-map*
  (pairlis *pvs2cl-primitives* *C-primitives-nopar*))
(defun pvs2C-primitive-nopar? (name)
  (let ((entry (assoc name *pvsC-primitives-nopar-map* :test #'same-primitive?)))
    (when entry (cdr entry))))





(defvar *C-record-defns* nil)


(defmacro pvs2C-error (msg &rest args)
  `(format t ,msg ,@args))

(defmacro pvsC_update (array index value)
  `(let ((update-op (if (and *destructive?* *livevars-table*)
			(format nil "pvsDestructiveUpdate")
			(format nil "pvsNonDestructiveUpdate"))))
       (format nil  "~a ~a ~a ~a" update-op ,array ,index ,value)))

(defvar *C-nondestructive-hash* (make-hash-table :test #'eq))
(defvar *C-destructive-hash* (make-hash-table :test #'eq))

(defstruct C-info
  id type definition analysis)

(defmacro C-hashtable ()
  `(if *destructive?* *C-destructive-hash* *C-nondestructive-hash*))

(defun C_id (op)
  (let ((hashentry (gethash (declaration op) (C-hashtable))))
    (when hashentry (C-info-id hashentry))))

(defun C_nondestructive_id (op)
  (let ((hashentry (gethash (declaration op) *C-nondestructive-hash*)))
    (when hashentry (C-info-id hashentry))))

(defun C_type (op)
  (let ((hashentry (gethash (declaration op) (C-hashtable))))
    (when hashentry (C-info-type hashentry))))

(defun C_definition (op)
  (let ((hashentry (gethash (declaration op) (C-hashtable))))
    (when hashentry (C-info-definition hashentry))))

(defun C_analysis (op)
  (let ((hashentry (gethash (declaration op) (C-hashtable))))
    (when hashentry (C-info-analysis hashentry))))

(defun mk-C-funcall (fun args)
  (format nil "~a(~{~a~^ ~})" fun args))

(defun pvs2C (expr &optional context)
  (let* ((*current-context*
	 (if context context *current-context*))
	(*current-theory* (theory *current-context*))
	(*generate-tccs* 'none))
    (pvs2C* expr nil nil)))


(defmethod pvs2C* ((expr number-expr) bindings livevars)
  (declare (ignore bindings livevars))
  (let ((n (number expr)))
    (if (< (abs n) 2147483648) n
      (let ((varname (unused-name "bint")))
        (add-definition "~a = newBigInt(\"~a\");" varname n)
        varname))))


(defmacro pvs2C_tuple (args)
  `(format nil "(~{~a~^, ~})" ,args))

(defmethod pvs2C* ((expr tuple-expr) bindings livevars)
  (let ((args (pvs2C* (exprs expr) bindings livevars)))
    (pvs2C_tuple args)))

(defmethod pvs2C* ((expr record-expr) bindings livevars)
  (let* ((sorted-assignments (sort-assignments (assignments expr)))
	 (formatted-fields
	  (loop for entry in sorted-assignments
		collect (format nil "~a = ~a"
			  (caar (arguments entry))
			  (pvs2C* (expression entry)
			  bindings livevars)))))
    (format nil "{~{~a~^, ~}}" formatted-fields)))
    
(defun matchlist (index length dummy)
  (if (eql index 0)
	(if (eql length 0)
	    (list dummy)
	    (cons dummy (enlist (1- length))))
      (cons '_ (matchlist (1- index)(1- length) dummy))))

(defun enlist (n)
  (if (eql n 0)
      nil
      (cons '_ (enlist (1- n)))))

(defmethod pvs2C* ((expr projection-application) bindings livevars)
  (let* ((ll (length (exprs expr)))
	 (dummy (gentemp "DDD"))
	 (match-list (pvs2C_tuple (matchlist (index expr) ll dummy)))
	 (expr-list (pvs2C* expr bindings livevars)))
    `(let ,match-list = ,expr-list in ,dummy)))
	


(defmethod pvs2C*  ((expr field-application) bindings livevars)
  (let* ((clarg (pvs2C* (argument expr) bindings livevars))
	 (id (id expr)))
    (format nil "~a.~a" clarg id)))

(defmethod pvs2C* ((expr list) bindings livevars)
  (if (consp expr)
      (cons (pvs2C* (car expr) bindings
			(append (updateable-vars (cdr expr)) livevars))
	    (pvs2C* (cdr expr) bindings  ;;need car's freevars
			(append (updateable-vars (car expr)) ;;f(A, A WITH ..)
				livevars)))
      nil))



(defmethod pvs2C* ((expr application) bindings livevars)
  (with-slots (operator argument) expr
    (if (constant? operator)
	(if (pvs2cl-primitive? operator)
	    (pvs2C-primitive-app expr bindings livevars)
	    (if (datatype-constant? operator)
		(mk-funapp (pvs2C-resolution operator)
			   (pvs2C* (arguments expr) bindings livevars))
		(pvs2C-defn-application  expr bindings livevars)))
	(let ((C-op (pvs2C* operator bindings
				    (append (updateable-vars
					     argument)
					    livevars)))
	      (C-arg (pvs2C* argument bindings
				     (append
				      (updateable-free-formal-vars operator)
				      livevars))))
	  (if (C-updateable? (type operator))
	    (format nil "pvsSelect(~a, ~a, ~a)" C-op C-arg "???")
		(mk-C-funcall C-op (list C-arg)))))))


(defun pvs2C-primitive-app (expr bindings livevars)
  (let* (( o   (operator expr)  )
         (args (pvs2C* (arguments expr) bindings livevars) )
         (prim (pvs2C-primitive-op o)  ))
    (if (pvs2C-primitive-infix? o)
      (format nil (format nil "(~a~a~a)" "~{~a~^ " prim " ~}") args)
      (if (pvs2C-primitive-nopar? o)
        (format nil "~a~{ ~a~}" prim args)
        (format nil "~a(~{~a~^, ~})" prim args)))))


(defun constant-formals (module)
  (loop for x in (formals module)
			 when (formal-const-decl? x)
			 collect (make-constant-from-decl x)))

(defun pvs2C-defn-application (expr bindings livevars)
  (with-slots (operator argument) expr
    (pvs2C-resolution operator)
    (let* ((actuals (expr-actuals (module-instance operator)))
	   (op-decl (declaration operator))
	   (args (arguments expr))
	   (C-args (pvs2C* (append actuals args) bindings livevars)))
      (if *destructive?*
	(let* ((defns (def-axiom op-decl))
	   (defn (when defns (args2 (car (last (def-axiom op-decl))))))
	   (def-formals (when (lambda-expr? defn)
			  (bindings defn)))
	   (module-formals (constant-formals (module op-decl)))
	   (alist (append (pairlis module-formals actuals)
			  (pairlis def-formals args)))
	   (analysis (C_analysis operator))
	   (check (check-output-vars analysis alist livevars)))
	  (format nil "(~a ~{ ~a~})" (if check (C_id operator)
				       (C_nondestructive_id operator))
			    C-args)
	      )
	(format nil "(~a ~{ ~a~})" (C_id operator) C-args)))));;this should be
;;C_nondestructive_id?

(defun pvs2C-resolution (op)
  (let* ((op-decl (declaration op)))
    (pvs2C-declaration op-decl)))

(defun pvs2C-declaration (op-decl)
  (let ((nd-hashentry (gethash op-decl *C-nondestructive-hash*))
	;(d-hashentry (gethash op-decl *C-destructive-hash*))
	;enough to check one hash-table. 
	)
    (when (null nd-hashentry)
      (let ((op-id (gentemp (format nil "pvs_~a" (id op-decl))))
	    (op-d-id (gentemp (format nil "pvs_d_~a" (id op-decl)))))
      (setf (gethash op-decl *C-nondestructive-hash*)
	    (make-C-info :id op-id))
      (setf (gethash op-decl *C-destructive-hash*)
	    (make-C-info :id op-d-id))
      (let* ((defns (def-axiom op-decl))
	     (defn (when defns (args2 (car (last (def-axiom op-decl))))))
	     (def-formals (when (lambda-expr? defn)
			    (bindings defn)))
	     (def-body (if (lambda-expr? defn) (expression defn) defn))
	     (module-formals (constant-formals (module op-decl)))
	     (range-type (if def-formals (range (type op-decl))
			     (type op-decl))))
	(pvs2C-resolution-nondestructive op-decl (append module-formals def-formals)
					     def-body range-type)
	(pvs2C-resolution-destructive op-decl (append module-formals def-formals)
					  def-body range-type))))))

(defun pvs2C-resolution-nondestructive (op-decl formals body range-type)
  (let* ((*destructive?* nil)
	 (bind-ids (pvs2cl-make-bindings formals nil))
	 (cl-body (pvs2C* body
			   (pairlis formals bind-ids)
			   nil))
	 (cl-type (format nil "~{~a ~} -> ~a"
		  (loop for var in formals
			collect (format nil "!~a" (pvs2C-type (type var))))
		  (pvs2C-type range-type)))
	 (cl-defn (format nil "~a ~{~a ~} -> ~a" "\\ " bind-ids cl-body))
	 (hash-entry (gethash op-decl *C-nondestructive-hash*)))
    (format t "~%Defining (nondestructively) ~a with ~%type ~a ~%as ~a" (id op-decl) cl-type cl-defn)
    (setf (C-info-type hash-entry)
	  cl-type
	  (C-info-definition hash-entry)
	  cl-defn
	  )))

(defun pvs2C-resolution-destructive (op-decl formals body range-type)
  (let* ((*destructive?* t)
	 (*output-vars* nil)
	 (bind-ids (pvs2cl-make-bindings formals nil))
	 (cl-body (pvs2C* body
			   (pairlis formals bind-ids)
			   nil))
	 (cl-type (format nil "~{~a ~} -> ~a"
		  (loop for var in formals
			collect (if (assoc (declaration var) *output-vars*
					   :key #'declaration)
				    (format nil "!*~a" (pvs2C-type (type var)))
				    (format nil "!~a" (pvs2C-type (type var)))))
		  (pvs2C-type range-type)))
	 (cl-defn  (format nil "~a ~{~a ~} -> ~a" "\\ " bind-ids cl-body))
	 (hash-entry (gethash op-decl *C-destructive-hash*))
	 (old-output-vars (C-info-analysis hash-entry)))
        (format t "~%Defining (destructively) ~a with ~%type ~a ~%as ~a" (id op-decl) cl-type cl-defn)
    (setf (C-info-type hash-entry)
	  cl-type
	  (C-info-definition hash-entry)
	  cl-defn
	  (C-info-analysis hash-entry)
	  *output-vars*)
    (unless (equalp old-output-vars *output-vars*)
      (pvs2C-resolution-destructive op-decl formals body range-type))))



	  
(defmethod pvs2C* ((expr name-expr) bindings livevars)
  (let* ((decl (declaration expr))
	 (bnd (assoc  decl bindings :key #'declaration)))
    (assert (not (and bnd (const-decl? decl))))
    (if bnd
	(cdr bnd)
	(if (const-decl? decl)
	    (pvs2C-constant expr decl bindings livevars)
	    (let ((undef (undefined expr "Hit untranslateable expression ~a")))
	      `(funcall ',undef))))))

(defun pvs2C-constant (expr op-decl bindings livevars)
  (let* ((defns (def-axiom op-decl))
	 (defn (when defns (args2 (car (last (def-axiom op-decl))))))
	 (def-formals (when (lambda-expr? defn)
			(bindings defn))))
    (pvs2C-resolution expr)
    (if def-formals 
	(let ((eta-expansion
		   (mk-lambda-expr def-formals
		     (mk-application expr
		       (loop for bd in def-formals
			     collect (change-class (copy bd) 'name-expr))))))
	  (pvs2C* eta-expansion bindings livevars))
	(let* ((actuals (expr-actuals (module-instance expr)))
	       (C-actuals (pvs2C* actuals bindings livevars)))
	(format nil "(~a ~{ ~a~})" (C_nondestructive_id expr)
		C-actuals)))))



(defun pvs2C-lambda (bind-decls expr bindings) ;;removed livevars
  (let* ((*destructive?* nil)
	 (bind-ids (pvs2cl-make-bindings bind-decls bindings))
	 (cl-body (pvs2C* expr
			   (append (pairlis bind-decls bind-ids)
				   bindings)
			   nil))
	  (name (unused-name)))
	(add-definition "~a(~{~a~^ ~}) = ~a" name bind-ids cl-body)
    name))

(defmethod pvs2C* ((expr lambda-expr) bindings livevars)
  (declare (ignore livevars))
  (let ((type (type expr))
	(C-expr (pvs2C-lambda (bindings expr) (expression expr) bindings)))
    (if (and (C-updateable? type)
	     (funtype? type))
	(format nil "(Function ~a ~a)" (array-bound type) C-expr)
	C-expr)))


(defmethod pvs2C* ((expr if-expr) bindings livevars)
  (cond ((branch? expr)
	 (let ((condition (condition expr))
	       (then-part (then-part expr))
	       (else-part (else-part expr)))
	 `(if ,(pvs2C* condition bindings
			   (append (updateable-vars then-part)
				   (append (updateable-vars else-part)
					   livevars)))
	      ,(pvs2C* (then-part expr) bindings livevars)
	      ,(pvs2C* (else-part expr) bindings livevars))))
	(t (call-next-method))))

(defmethod pvs2C* ((expr cases-expr) bindings livevars)
  (format nil "case ~a of ~{~%~a~}"
    (pvs2C* (expression expr) bindings livevars)
    (pvs2C-cases (selections expr)(else-part expr) bindings livevars)))

(defun pvs2C-cases (selections else-part bindings livevars)
  (let ((selections-C
	 (loop for entry in selections
	       collect
	       (let* ((bind-decls (args entry))
		      (bind-ids (pvs2cl-make-bindings bind-decls bindings)))
		 (format nil "~a ~{~a ~} -> ~a"
			 (pvs2C* (constructor entry) bindings livevars)
			 bind-ids
			 (pvs2C* (expression entry)
				     (append (pairlis bind-decls bind-ids) bindings)
				     livevars))))))
    (if else-part
	(format nil "~a ~% _ -> ~a"
	  selections-C
	  (pvs2C* (expression else-part) bindings livevars))
	selections-C)))

(defmethod pvs2C* ((expr update-expr) bindings livevars)
  (if (C-updateable? (type (expression expr)))
      (if (and *destructive?*
	       (not (some #'maplet? (assignments expr))))
	  (let* ((expression (expression expr))
		 (assignments (assignments expr))
		 (*livevars-table* 
		  (no-livevars? expression livevars assignments))
		 )
	    ;;very unrefined: uses all
	    ;;freevars of eventually updated expression.
	    (cond (*livevars-table* ;; check-assign-types
		   (push-output-vars (car *livevars-table*)
				     (cdr *livevars-table*))
		   (pvs2C-update expr
				  bindings livevars))
		  (t
		   (when (and *eval-verbose* (not *livevars-table*))
		     (format t "~%Update ~s translated nondestructively.
 Live variables ~s present" expr livevars))
		   (pvs2C-update  expr
						    bindings livevars))))
	  (pvs2C-update expr bindings livevars))
      (pvs2C* (translate-update-to-if! expr)
		  bindings livevars)))

(defun pvs2C-update
    (expr bindings livevars)
  (with-slots (type expression assignments) expr
    (let* ((assign-exprs (mapcar #'expression assignments))
	   (exprvar (gentemp "E"))
	   (C-expr (pvs2C* expression bindings
				(append (updateable-free-formal-vars
					 assign-exprs)
					;;assign-args can be ignored
					livevars))))
      (format nil "#! ~a"
    (pvs2C-update* (type expression)
				   C-expr exprvar
				   (mapcar #'arguments assignments)
				   assign-exprs
				   bindings
				   (append (updateable-vars expression)
					   livevars)
				   (list (list exprvar C-expr)))))))

(defun pvs2C-assign-rhs (assignments bindings livevars)
  (when (consp assignments)
      (let ((C-assign-expr (pvs2C* (expression (car assignments))
					   bindings
					   (append (updateable-vars
						    (arguments (car assignments)))
						   (append (updateable-vars (cdr assignments))
					   livevars))))
	    (*lhs-args* nil))
	(cons C-assign-expr
	      (pvs2C-assign-rhs (cdr assignments) bindings
				    (append (updateable-free-formal-vars
					     (expression (car assignments)))
					    livevars))))))

				   

;;recursion over updates in an update expression
(defun pvs2C-update*
    (type expr exprvar
	  assign-args assign-exprs bindings livevars accum)
  (if (consp assign-args)
      (let* ((*lhs-args* nil)
	     (assign-exprvar (gentemp "R"))
	     (C-assign-expr
	      (pvs2C* (car assign-exprs)
			  bindings
			  (append (updateable-vars (cdr assign-exprs))
				  (append (updateable-vars (cdr assign-args))
					  livevars))))
	     (newexprvar (gentemp "N"))
	     (new-accum (pvs2C-update-nd-type
		       type exprvar newexprvar
		       (car assign-args)
		       assign-exprvar
		       bindings
		       (append (updateable-free-formal-vars (car assign-exprs))
			       (append (updateable-vars (cdr assign-exprs))
				       (append (updateable-vars (cdr assign-args))
					       livevars)))
		       accum))
	     (lhs-bindings (nreverse *lhs-args*))
	     (cdr-C-output
	      (pvs2C-update*
	       type expr
	       newexprvar
	       (cdr assign-args)(cdr assign-exprs) bindings
	       (append (updateable-free-formal-vars (car assign-exprs))
		       livevars) 
		       new-accum )))
	(format nil "~a = ~a ~%~:{~a = ~a~%~} ~a"
	  assign-exprvar C-assign-expr
		lhs-bindings
		 cdr-C-output))
      (format nil "~:{~a = ~a~%~} = ~a" (nreverse accum) exprvar)))
     	  


;;recursion over nested update arguments in a single update.
(defun pvs2C-update-nd-type (type expr newexprvar args assign-expr
					   bindings livevars accum)
  (if (consp args)
      (pvs2C-update-nd-type* type expr newexprvar (car args) (cdr args) assign-expr
			      bindings livevars accum)
      (cons (list newexprvar assign-expr) accum)))

(defmethod pvs2C-update-nd-type* ((type funtype) expr newexprvar arg1 restargs
				   assign-expr bindings livevars accum)
  (let* ((arg1var (gentemp "L"))
	 (C-arg1 (pvs2C*  (car arg1) bindings
				 (append (updateable-vars restargs)
					 livevars))))
    (push (list arg1var C-arg1) *lhs-args*)
    (if (consp restargs)
	(let* (
	       (exprvar (gentemp "E"))
	       (exprval (format nil "pvsSelect ~a ~a" expr arg1var))
	       (newexprvar2 (gentemp "N"))
	       (newaccum
		(pvs2C-update-nd-type 
		 (range type) exprvar newexprvar2
		 restargs assign-expr bindings livevars
		 (cons (list exprvar exprval) accum))))
	  (cons (list newexprvar (pvsC_update expr arg1var newexprvar2))
		newaccum)
	  )
	(cons (list newexprvar (pvsC_update expr arg1var assign-expr))
	      accum))))



(defmethod pvs2C-update-nd-type* ((type recordtype) expr newexprvar arg1 restargs
				   assign-expr bindings livevars accum)
  (let ((id (id (car arg1))))
	(if (consp restargs)
	    (let* (
		   (exprvar (gentemp "E"))
		   (new-expr (format nil "~a.~a" expr id))
		   (field-type (type (find id (fields type) :key #'id) ))
		   (newexprvar2 (gentemp "N"))
		   (newaccum (pvs2C-update-nd-type field-type exprvar newexprvar2
						       restargs assign-expr bindings
						       livevars
						       (cons (list exprvar new-expr) accum))))
	      (cons (list newexprvar (format nil "{~a & ~a = ~a}" expr id newexprvar2)) newaccum))
	    (cons (list newexprvar (format nil "{~a & ~a = ~a}" expr id assign-expr))
		  accum))))

(defmethod pvs2C-update-nd-type* ((type subtype)  expr newexprvar arg1 restargs
				   assign-expr bindings livevars accum)
  (pvs2C-update-nd-type* (find-supertype type) expr newexprvar arg1 restargs
			  assign-expr bindings livevars accum))

(defmethod pvs2C-type ((type recordtype))
  (with-slots (print-type) type
    (if (type-name? print-type)
	(let ((entry (assoc (declaration print-type) *C-record-defns*)))
	  (if entry (cadr entry) ;return the C-rectype-name
	      (let* ((formatted-fields (loop for fld in (fields type)
				  collect
				  (format nil "~a :: !~a" (id fld)
						(pvs2C-type (type fld)))))
		    (C-rectype (format nil "{ ~{~a~^, ~} }" formatted-fields))
		    (C-rectype-name (gentemp (format nil "pvs~a" (id print-type)))))
		(push (list (declaration print-type) C-rectype-name C-rectype)
		      *C-record-defns*)
		C-rectype-name)))
	(pvs2C-error "~%Record type ~a must be declared." type))))

(defmethod pvs2C-type ((type tupletype))
  (format nil "(~{!~a~^, ~})" (loop for elemtype in (types type)
				   collect (pvs2C-type elemtype))))

(defmethod pvs2C-type ((type funtype))
  (if (C-updateable? type)
      (format nil "(PvsArray ~a)" (pvs2C-type (range type)))
      (format nil "(~a -> ~a)"
	(pvs2C-type (domain type))
	(pvs2C-type (range type)))))

(defmethod pvs2C-type ((type subtype))
  (let ((fs (find-supertype type)))
    (if (and (eq fs *number*)
	     (subtype-of? type *integer*))
	(format nil "BigInt");;Generates nonsense if type is not subtype of int.
	(pvs2C-type (find-supertype type)))))


;;C-updateable? is used to check if the type of an updated expression
;;is possibly destructively. 

(defmethod C-updateable? ((texpr tupletype))
  (C-updateable? (types texpr)))

;;this is the only case where C-updateable? can be false, because
;;the given function type is not an array.  
(defmethod C-updateable? ((texpr funtype)) ;;add enum types, subrange.
  (and (or (simple-below? (domain texpr))(simple-upto? (domain texpr)))
       (C-updateable? (range texpr))))

(defmethod C-updateable? ((texpr recordtype))
  (C-updateable? (mapcar #'type (fields texpr))))

(defmethod C-updateable? ((texpr subtype))
  (C-updateable? (find-supertype texpr)))

(defmethod C-updateable? ((texpr list))
  (or (null texpr)
      (and (C-updateable? (car texpr))
	   (C-updateable? (cdr texpr)))))

;;This is subsumed by fall-through case.
;(defmethod C-updateable? ((texpr type-name))
;  (not (or (eq texpr *boolean*)
;	   (eq texpr *number*))))



;(defmethod C-updateable? ((texpr actual))
;  (C-updateable? (type-value texpr)))

(defmethod C-updateable? ((texpr t))
  t) ;;It is okay to say  C-updateable? for uninterpreted
;;or actuals since these will not be updated destructively or otherwise.
  
(defun pvs2C-theory (theory)
  (let* ((theory (get-theory theory))
	 (*current-theory* theory)
	 (*current-context* (context theory)))
    (cond ((datatype? theory)
	   (let ((adt (adt-type-name theory)))
	     (pvs2C-constructors (constructors adt) adt))
	   (pvs2C-theory (adt-theory theory))
	   (let ((map-theory (adt-map-theory theory))
		 (reduce-theory (adt-reduce-theory theory)))
	     (when map-theory (pvs2C-theory (adt-map-theory theory)))
	     (when reduce-theory (pvs2C-theory (adt-reduce-theory theory))))) 
	  (t (loop for decl in (theory theory)
		   do (cond ((type-eq-decl? decl)
			     (let ((dt (find-supertype (type-value decl))))
			       (when (adt-type-name? dt)
				 (pvs2C-constructors (constructors dt) dt))))
			    ((datatype? decl)
			     (let ((adt (adt-type-name decl)))
			       (pvs2C-constructors (constructors adt) adt)))
			    ((const-decl? decl)
			     (unless (eval-info decl)
			       (progn
				 (pvs2C-declaration decl))))
			    (t nil)))))))

(defun clear-C-hash ()
  (clrhash *C-nondestructive-hash*)
  (clrhash *C-destructive-hash*))
