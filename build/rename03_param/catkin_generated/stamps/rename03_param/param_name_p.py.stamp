#! /usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from std_msgs.msg import String
if __name__ == "__main__":
    rospy.init_node("hello")
    """
    设置不同类型的参数
    """
    # 全局
    rospy.set_param("/radius_A",1)
    # 相对
    rospy.set_param("radius_B",2)
    # 私有
    rospy.set_param("~radius_C",3)