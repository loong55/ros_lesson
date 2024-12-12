#! /usr/bin/env python
#-*- coding: utf-8 -*-
"""
订阅坐标系信息，生成一个相对于 子级坐标系的坐标点数据
转换成父级坐标系中的坐标点

流程：
    1.导包
    2.节点初始化
    3.创建订阅对象
    4.创建雷达坐标系中的坐标点
    5.将坐标点转换成车体坐标系中的坐标点
    6.spin
"""
    # 1.导包
import rospy
import tf2_ros  #创建订阅对象与坐标缓存器
from tf2_geometry_msgs import PointStamped  #坐标数据对象
if __name__ == "__main__":
    # 2.节点初始化
    rospy.init_node("dynamic_sub_p")
    # 3.创建订阅对象
    buffer = tf2_ros.Buffer()   #缓存坐标数据
    listener = tf2_ros.TransformListener(buffer)    #订阅者对象
    #创建订阅对象的同时，无需写话题名称，会自动接收坐标数据，存入buffer

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
    # 4.创建乌龟坐标系中的坐标点
        ps = PointStamped() 
        ps.header.frame_id = "turtle1"
        #订阅者时间戳置空，只让发布者时间戳生效，防止订阅延迟报错
        ps.header.stamp = rospy.Time(0.0)  
        ps.point.x = 2.0
        ps.point.y = 3.0
        ps.point.z = 5.0

    # 5.将坐标点转换成世界坐标系中的坐标点
        try:
            ps_out = buffer.transform(ps,"world")
            rospy.loginfo("转换结果：（%.2f,%.2f,%.2f）,参考坐标系：%s",
                        ps_out.point.x,
                        ps_out.point.y,
                        ps_out.point.z,
                        ps_out.header.frame_id
                        )
        except Exception as e:
            rospy.logerr("异常：%s",e)
    # 6.spin
        rate.sleep()