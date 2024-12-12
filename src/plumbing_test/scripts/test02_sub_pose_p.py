#! /usr/bin/env python
# -*- coding: utf-8 -*-
"""
订阅乌龟位姿，打印到终端
已知信息：
    1.话题名称：/turtle1/pose
    2.消息类型：turtlesim/Pose

实现流程：
    1.导包
    2.初始化节点
    3.创建订阅者对象
    4.回调函数 处理数据
    5.spin
"""

import rospy
from turtlesim.msg import Pose

def doPose(data):
    rospy.loginfo("乌龟坐标:x=%.2f, y=%.2f,theta=%.2f",data.x,data.y,data.theta)

if __name__ == "__main__":
    # 2.初始化节点
    rospy.init_node("sub_pose_p")
    # 3.创建订阅者对象
    sub = rospy.Subscriber("/turtle1/pose",Pose,doPose,queue_size=100)
    # 4.回调函数 处理数据
    # 5.spin
    rospy.spin()