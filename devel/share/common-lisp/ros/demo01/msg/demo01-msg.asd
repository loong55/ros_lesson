
(cl:in-package :asdf)

(defsystem "demo01-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Person" :depends-on ("_package_Person"))
    (:file "_package_Person" :depends-on ("_package"))
  ))