
(defun test-cases ()
  (let ((tests (list "test" "draft")))
    (load "Cmain")
    (format t "~%Loading Cmain: done.~%")
    (loop for tst in tests
	  do (progn (tc tst)
		    (format t "~%Typechecking ~a: done.~%" tst)
		    (generate-C-for-pvs-file tst)))
    (format t "~%All tests: done.~%")))

(test-cases)
