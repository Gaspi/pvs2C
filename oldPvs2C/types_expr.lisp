
;; Types recognized by pvs2clean*





pvs2clean-primitive-op (name)

pvsclean_update (array index value)

clean_id (op)
clean_nondestructive_id (op)
clean_type (op)
clean_definition (op)
clean_analysis (op)
mk-clean-funcall (fun args)

pvs2clean (expr &optional context)

pvs2clean*

(expr number-expr)
(expr tuple-expr)
(expr record-expr)
(expr projection-application)
(expr field-application)
(expr list)
(expr application)
(expr name-expr)
(expr lambda-expr)
(expr if-expr)
(expr cases-expr)
(expr update-expr)



(defmethod pvs2clean-type

(type recordtype)
(type tupletype)
(type funtype)
(type subtype)
