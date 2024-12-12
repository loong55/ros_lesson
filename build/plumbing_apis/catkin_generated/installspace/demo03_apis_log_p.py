#!/usr/bin/env python2
#-*- coding:utf-8 -*-
import rospy

if __name__ == "__main__":
    #演示日志函数
    rospy.init_node("hello_log")

    rospy.logdebug("debug消息")
    rospy.loginfo("info消息")
    rospy.logwarn("warn消息")
    rospy.logerr("error消息")
    rospy.logfatal("fatal消息")