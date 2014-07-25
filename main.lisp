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
;;       main.lisp (this file)
;;       Cutils.lisp
;;       Ctypes.lisp
;;       Ccode.lisp
;;       Canalysis.lisp
;;       Cprimop.lisp
;;       pvs2c.lisp
;;       GC.c
;;   - The GNU GMP library installed
;;      -> https://gmplib.org/
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


;; ------------------Debugging functions and variables ---------------
;; Default values
(defvar *Cshow-safe* nil)
(defvar *Cshow-bang* nil)
(defvar *Cshow-dupl* nil)

(defvar *Cdebug* nil)
(defvar *Csimple-names* nil)
(defvar *C-analysis* t)
(defvar *C-replace-analysis* t)


;; Change only for debugging...
(setq *Cshow-safe* t)
(setq *Cshow-bang* t)
(setq *Cshow-dupl* t)
(setq *Cdebug* t)
(setq *Csimple-names* nil)
(setq *C-analysis* t)
(setq *C-replace-analysis* t)



;; ------------------------ Loading the files ---------------------
;; (pushnew "/amd/pfs/export/u2/homes/ferey/Documents/pvs2c" *pvs-directories* :test #'string=)
;; (lf "Cutils.lisp")
;; (lf "Ctypes.lisp")
;; (lf "Ccode.lisp")
;; (lf "Canalysis.lisp")
;; (lf "Cprimop.lisp")
;; (lf "pvs2c.lisp")
(load "Cutils")
(load "Ctypes")
(load "Ccode")
(load "Canalysis")
(load "Cprimop")
(load "pvs2c")
