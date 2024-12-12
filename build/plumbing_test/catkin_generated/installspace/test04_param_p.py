#!/usr/bin/env python2
#-*- coding: utf-8 -*-

'''
设置乌龟gui背景色
'''
import rospy

if __name__ == "__main__":
    rospy.init_node("set_bgCol")
    rospy.set_param("/turtlesim/background_r",100)
    rospy.set_param("/turtlesim/background_g",100)
    rospy.set_param("/turtlesim/background_b",100)
