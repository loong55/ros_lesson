#! /usr/bin/env python
# -*- coding: utf-8 -*-
import rospy

"""
需求1：获取当前时刻 + 设置指定时刻
需求2：程序停顿执行5秒
需求3：已知程序开始时刻和运行时间，求运行结束时刻
需求4：定时器，每隔1秒钟，在控制台输出一段文本

"""
def doMsg(event):
    rospy.loginfo("+++++++++++")
    rospy.loginfo("调用回调函数的时刻:%.2f",event.current_real.to_sec())

if __name__ == "__main__":
    #-----------------------------------------------------------------------------------
    # 需求1：获取当前时刻 + 设置指定时刻
    rospy.init_node("hello_time")
    #获取时刻
    #获取now() 被调用的时刻，并封装成对象
    #即距离参考点 1970.01.01 00：00：00的时间，中国+8h
    now = rospy.Time.now()  
    rospy.loginfo("当前时刻：%.2f",now.to_sec())
    rospy.loginfo("当前时刻：%d",now.secs)
    # [INFO] [1724668296.301696]: 当前时刻：1724668296.30
    # [INFO] [1724668296.303739]: 当前时刻：1724668296    

    #设置时刻
    #将一个时间封装成Time对象，距离参考点过去了x秒
    time1 = rospy.Time(100.5) #秒
    time2 = rospy.Time(100,1e9) #秒，纳秒
    rospy.loginfo("当前时刻：%.2f",time1.to_sec())
    rospy.loginfo("当前时刻：%.2f",time2.to_sec())
    # [INFO] [1724672445.568729]: 当前时刻：100.50
    # [INFO] [1724672445.569474]: 当前时刻：101.00

    #从某个时间值(可以是变量)，获取时间对象
    time3 = rospy.Time.from_sec(210.12)
    rospy.loginfo("当前时刻：%.2f",time3.to_sec())
    # [INFO] [1724672548.787859]: 当前时刻：210.12

    #--------------------------------------------------------------------------------
    #需求2：程序停顿执行5秒
    rospy.loginfo("-----休眠前-----")
    # 1.封装一个持续时间对象（5秒）
    du = rospy.Duration(5,1e9)#秒，纳秒
    # 2.再将持续时间休眠
    #du.sleep()异常
    # rospy.sleep(du)
    rospy.loginfo("-----休眠后-----")
    # [INFO] [1724672912.190349]: -----休眠前-----
    # 等待6秒
    # [INFO] [1724672918.198098]: -----休眠后-----

    #-----------------------------------------------------------------------------
    #需求3：已知程序开始时刻和运行时间，求运行结束时刻
    #1.获取一个时刻t1
    t1 = rospy.Time.now()
    #2.设置一个持续时间du1
    du1 = rospy.Duration(5)
    #3.结束时刻 t2 = t1 + du1
    t2 = t1 + du1
    rospy.loginfo("开始时刻：%.2f",t1.to_sec())
    rospy.loginfo("结束时刻：%.2f",t2.to_sec())
    # [INFO] [1724673249.438090]: 开始时刻：1724673249.44
    # [INFO] [1724673249.438933]: 结束时刻：1724673254.44
    t3 = t1 - du1
    rospy.loginfo("时刻与时间减法：%.2f",t3.to_sec())
    #[INFO] [1724673618.295816]: 时刻与时间减法：1724673613.29
    # t4 = t1 + t2
    # rospy.loginfo("时刻与时刻加法：%.2f",t4.to_sec())#不行
    t5 = t1 - t2
    rospy.loginfo("时刻与时刻减法：%.2f",t5.to_sec())
    # [INFO] [1724673791.624368]: 时刻与时刻减法：-5.00
    du2 = du1 + du
    rospy.loginfo("时间与时间加法：%.2f",du2.to_sec())
    # [INFO] [1724673875.693536]: 时间与时间加法：11.00   
    du3 = du2 - du1
    rospy.loginfo("时间与时间减法：%.2f",du3.to_sec())
    # [INFO] [1724673934.050527]: 时间与时间减法：6.00

    #--------------------------------------------------------------------------------------
    """
    需求4：定时器，每隔1秒钟，在控制台输出一段文，类似于

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        rate.sleep() #休眠
        rospy.loginfo("+++++++++++++++")
    """
    """
    rospy.Timer(self, period, callback, oneshot=False, reset=False)
        @param period: desired period between callbacks
        @type  period: rospy.Duration
        @param callback: callback to be called
        @type  callback: function taking rospy.TimerEvent
        @param oneshot: if True, fire only once, otherwise fire continuously until shutdown is called [default: False]
        @type  oneshot: bool
        @param reset: if True, timer is reset when rostime moved backward. [default: False]
        @type  reset: bool
    """
    # timer = rospy.Timer(rospy.Duration(2),doMsg)#每隔两秒，运行一次doMsg函数
    # rospy.spin() #重要
    # # [INFO] [1724675054.027888]: +++++++++++
    # # [INFO] [1724675056.024945]: +++++++++++
    # # [INFO] [1724675058.027757]: +++++++++++

    # oneshot
    # timer = rospy.Timer(rospy.Duration(2),doMsg,True)#只运行一次doMsg
    # rospy.spin() #重要
    # # [INFO] [1724675263.437060]: +++++++++++

    #获取回调函数运行时刻
    timer = rospy.Timer(rospy.Duration(2),doMsg)#每隔两秒，运行一次doMsg函数
    rospy.spin() #重要
    # [INFO] [1724675836.166313]: +++++++++++
    # [INFO] [1724675836.167802]: 调用回调函数的时刻:1724675836.17
    # [INFO] [1724675838.166007]: +++++++++++
    # [INFO] [1724675838.167514]: 调用回调函数的时刻:1724675838.17
