#!/usr/bin/env python2
# -*- coding: utf-8 -*-
import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("hello")
    """
    实现不同类型的话题设置
    """
    # 1.全局    话题名称以 / 开头
    # pub = rospy.Publisher("/chatter",String,queue_size=10)
    '''
    rosrun rename02_topic topic_name_p.py __ns:=xxx

    rosnode list
    /xxx/hello

    rostopic list
    /chatter
    '''
    # 2.相对    话题名称无前缀
    # pub = rospy.Publisher("chatter",String,queue_size=10)
    """
    rosrun rename02_topic topic_name_p.py __ns:=xxx

    rosnode list
    /xxx/hello

    rostopic list
    /xxx/chatter
    """
    # 3.私有    话题名称以 ~ 开头
    pub = rospy.Publisher("~chatter",String,queue_size=10)
    """
    rosrun rename02_topic topic_name_p.py __ns:=xxx

    rosnode list
    /xxx/hello

    rostopic list
    /xxx/hello/chatter
    """

    while not rospy.is_shutdown():
        pass
