
(defun test-cases (&rest tests)
  (load "main")
  (format t "~%Loading main: done.~%")
  (loop for tst in tests
	do (progn (tc tst)
		  (format t "~%Typechecking ~a: done.~%" tst)
		  (generate-C-for-pvs-file tst)))
  (format t "~%All tests: done.~%"))

(test-cases "test" "draft")
