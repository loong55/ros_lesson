#!/usr/bin/env python2
#-*- coding: utf-8 -*-
"""
    生成一只小乌龟
    准备工作:
        1.服务话题 /spawn
        2.服务消息类型 turtlesim/Spawn
        3.运行前先启动 turtlesim_node 节点

    实现流程:
        1.导包
          需要包含 turtlesim 包下资源，注意在 package.xml 配置
        2.初始化 ros 节点
        3.创建 service 客户端
        4.等待服务启动
        5.发送请求
        6.处理响应
"""
import rospy
from turtlesim.srv import *

if __name__ == "__main__":
    # 2.初始化 ros 节点
    rospy.init_node("set_turtle_p")
    # 3.创建 service 客户端
    client = rospy.ServiceProxy("/spawn",Spawn)
    # 4.等待服务启动
    client.wait_for_service()
    # 5.发送请求
    req = SpawnRequest()    #创建发布对象
    req.x = 2.0
    req.y = 2.0
    req.theta = -1.57
    req.name = "turtle3"
    # 6.处理响应
    try:
        response = client.call(req)
        rospy.loginfo("新龟生成：%s!",response.name)
    except Exception as e:
        rospy.logerr("服务调用失败！")