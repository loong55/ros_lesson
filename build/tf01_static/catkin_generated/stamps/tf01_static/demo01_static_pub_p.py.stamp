#! /usr/bin/env python
#-*- coding: utf-8 -*-
import rospy
import tf.transformations
import tf2_ros  #创建发布对象
import tf  #将欧拉角转化为四元数
from geometry_msgs.msg import TransformStamped  #消息类型
"""
发布方：发布两个坐标系相对关系（底盘 base_link  雷达 laser）
流程：
    1.导包
    2.初始化节点
    3.创建发布对象
    4.组织被发布对象
    5.发布数据
    6.spin()
"""
if __name__ == "__main__":
    # 2.初始化节点
    rospy.init_node("static_pub_p")

    # 3.创建发布对象
    pub = tf2_ros.StaticTransformBroadcaster()

    # 4.组织被发布对象（写消息数据）
    ts = TransformStamped()
    # header
    ts.header.stamp = rospy.Time.now()
    ts.header.frame_id = "base_link"
    # child frame id
    ts.child_frame_id = "radar"

    #坐标系相对信息
    #偏移量
    ts.transform.translation.x = 0.2
    ts.transform.translation.y = 0.0
    ts.transform.translation.z = 0.5
    #旋转量
    qtn = tf.transformations.quaternion_from_euler(0,0,0)
    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.y = qtn[1]
    ts.transform.rotation.z = qtn[2]
    ts.transform.rotation.w = qtn[3]

    # 5.发布数据
    pub.sendTransform(ts)

    # 6.spin()
    rospy.spin()