#!/usr/bin/env python2
# -*- coding: utf-8 -*-
import rospy
from std_msgs.msg import String

def cb():
    rospy.loginfo("节点正在被关闭.....")

if __name__ == "__main__":
    #2.初始化 ROS 节点:命名(唯一)
    """
    作用：ros初始化

    参数：
        name: 节点名
        argv = None ------ 封装节点调用时传递的参数
        anonymous = False ------ 为节点生成随机后缀名，可以解决重名问题

    使用：
        1.argv的使用:可以按照ros中指定的语法格式传参，ros可以解析并加以使用           

        2.anonymous的使用
    """
    rospy.init_node("talker_p",anonymous=True)
    #3.实例化 发布者 对象
    """
    参数latch:
        bool值，默认值：False
    作用：
        如果设置为True,可以将发布的最后一条数据保存，当新的订阅对象连接时，将该数据发送出去
    使用：
        latch = True
    """
    pub = rospy.Publisher("chatter_p",String,queue_size=10,latch=True)
    #4.组织被发布的数据，并编写逻辑发布数据
    msg = String()  #创建 msg 对象
    msg_front = "hello 你好"
    count = 0  #计数器 
    # 设置循环频率
    rate = rospy.Rate(1)
    rospy.sleep(3)  #延迟3秒发送数据，防止订阅方接收不到
    while not rospy.is_shutdown():
        count += 1
        if count <= 3:
            #拼接字符串
            msg.data = msg_front + str(count)
            pub.publish(msg)
            rate.sleep()
            rospy.loginfo("写出的数据:%s",msg.data)
        else:
            #关闭节点
            rospy.on_shutdown(cb)
            rospy.signal_shutdown("提示信息：关闭节点")
            