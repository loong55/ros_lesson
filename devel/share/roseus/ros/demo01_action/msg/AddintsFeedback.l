;; Auto-generated. Do not edit!


(when (boundp 'demo01_action::AddintsFeedback)
  (if (not (find-package "DEMO01_ACTION"))
    (make-package "DEMO01_ACTION"))
  (shadow 'AddintsFeedback (find-package "DEMO01_ACTION")))
(unless (find-package "DEMO01_ACTION::ADDINTSFEEDBACK")
  (make-package "DEMO01_ACTION::ADDINTSFEEDBACK"))

(in-package "ROS")
;;//! \htmlinclude AddintsFeedback.msg.html


(defclass demo01_action::AddintsFeedback
  :super ros::object
  :slots (_progerss_bar ))

(defmethod demo01_action::AddintsFeedback
  (:init
   (&key
    ((:progerss_bar __progerss_bar) 0.0)
    )
   (send-super :init)
   (setq _progerss_bar (float __progerss_bar))
   self)
  (:progerss_bar
   (&optional __progerss_bar)
   (if __progerss_bar (setq _progerss_bar __progerss_bar)) _progerss_bar)
  (:serialization-length
   ()
   (+
    ;; float64 _progerss_bar
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _progerss_bar
       (sys::poke _progerss_bar (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _progerss_bar
     (setq _progerss_bar (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get demo01_action::AddintsFeedback :md5sum-) "02110171e2018aaea07999b32009b866")
(setf (get demo01_action::AddintsFeedback :datatype-) "demo01_action/AddintsFeedback")
(setf (get demo01_action::AddintsFeedback :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
# 3.连续反馈变量
float64 progerss_bar


")



(provide :demo01_action/AddintsFeedback "02110171e2018aaea07999b32009b866")


