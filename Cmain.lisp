;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                PVS to C translator
;;
;;     Author: Gaspard ferey
;;
;;  -> https://github.com/Gaspi/pvs2c.git
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; The whole project is available on Github at the following address
;;         https://github.com/Gaspi/pvs2c.git
;;
;; To make this work, you need:
;;   - The following files:
;;       Cmain.lisp (this file)
;;       Cutils.lisp
;;       Ctypes.lisp
;;       Cexpr.lisp
;;       Canalysis.lisp
;;       Cprimop.lisp
;;       pvs2c.lisp
;;       GC.c
;;   - The GNU GMP library installed
;;
;;
;; To use:
;;  - Copy all the files above (8 files) in the folder containing
;;    the .pvs file (e.g. "foo.pvs") you're interested in
;;    translating to C.
;;  - Start PVS, open this .pvs file and typecheck it.
;;  - Switch to the *pvs* buffer and execute:
;;      (load "pvs2c")
;;      (generate-C-for-pvs-file "foo")
;;  - "foo.c" and "foo.h" were created.
;;  - (optionnal) Compile with:
;;        gcc -o foo foo.c GC.c -lgmp
;;  - (optionnal) Execute with:
;;        ./foo
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



(in-package :pvs)

;; ------------------- Loading the other files ---------------------
;; (pushnew "/amd/pfs/export/u2/homes/ferey/Docuemts/pvs2c" *pvs-directories* :test #'string=)
;; (lf "Cutils.lisp")
;; (lf "Ctypes.lisp")
;; (lf "Cexpr.lisp")
;; (lf "Canalysis.lisp")
;; (lf "Cprimop.lisp")
;; (lf "pvs2c.lisp")
(load "Cutils")
(load "Ctypes")
(load "Cexpr")
(load "Canalysis")
(load "Cprimop")
(load "pvs2c")
