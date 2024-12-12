#include "ros/ros.h"
/*
需求1：演示时间相关操作（获取当前时刻 + 设置指定时刻）
实现：
    1.准备（头文件，节点初始化，句柄创建）
    2.获取当前时刻
    3.设置指定时刻

需求2：程序停顿执行5秒
实现：
    1.创建持续时间对象
    2.休眠

需求3：已知程序开始时刻和运行时间，求运行结束时刻
实现：
    1.获取开始执行时刻
    2.模拟运行时间
    3.计算结束时刻
总结：
    1.时刻与时刻不能相减
    2.时刻与时间可相加减
    3.时间之间可以相加减

需求4：每隔1秒钟，在控制台输出一段文本
实现：
    1.策略1 ros::Rate(1)
    2.策略2 定时器
总结：
    创建: nh.creatTimer()
    参数1：时间间隔
    参数2：回调函数（时间时间 TimerEvent）
    参数3：是否只启动一次
    参数4：是否自动启动（当设置为false时，手动调用 timer.start()）
    定时器启动后：ros::spin()
*/

//定时器用的回调函数
void cb(const ros::TimerEvent& event){
    ROS_INFO("--------");
    ROS_INFO("函数被调用的时刻：%.2f",event.current_real.toSec());

}

int main(int argc, char  *argv[])
{
    // 1.准备（头文件，节点初始化，句柄创建）
    setlocale(LC_ALL,"");    
    ros::init(argc,argv,"hello_time");
    ros::NodeHandle nh;

    // 2.获取当前时刻
    ros::Time now = ros::Time::now();
    //now函数会将当前时刻封装并返回
    //当前时刻：now 被调用的那一刻
    //参考系：1970.01.01 00：00：00；中国：参考系+8h
    ROS_INFO("当前时刻：%.2f",now.toSec());//单位:秒,距离参考系的时间
    ROS_INFO("当前时刻：%d",now.sec);//单位:秒,距离参考系的时间

    // 3.设置指定时刻
    ros::Time t1(100,1e9);//距离参考系的时间，参数1：秒，参数2：纳秒,1e9=10^9
    ros::Time t2(100.66);
    ROS_INFO("t1 = %.2f",t1.toSec());
    ROS_INFO("t2 = %.2f",t2.toSec());

    // book@100ask:~/ws$ rosrun plumbing_apis  demo03_apis_time 
    // [ INFO] [1724583717.898397225]: 当前时刻：1724583717.90
    // [ INFO] [1724583717.899574252]: 当前时刻：1724583717
    // [ INFO] [1724583717.899631580]: t1 = 101.00
    // [ INFO] [1724583717.899685149]: t2 = 100.66

    ROS_INFO("------持续时间-----");
    ros::Time start = ros::Time::now();
    ROS_INFO("开始休眠:%.2f",start.toSec());
    ros::Duration du(4.5);//定时4.5秒
    du.sleep();//休眠4.5秒
    ros::Time end = ros::Time::now();
    ROS_INFO("结束休眠:%.2f",end.toSec());
    // [ INFO] [1724586367.960657222]: ------持续时间-----
    // [ INFO] [1724586367.960681601]: 开始休眠:1724586367.96
    // [ INFO] [1724586372.460918638]: 结束休眠:1724586372.46

    ROS_INFO("------时间运算-----");
    // 1.获取开始执行时刻
    ros::Time begin = ros::Time::now();
    // 2.模拟运行时间
    ros::Duration du1(5);//运行5秒钟
    // 3.计算结束时刻
    ros::Time stop = begin + du1;//也可以 “减法”
    ROS_INFO("开始时刻：%.2f",begin.toSec());
    ROS_INFO("结束时刻：%.2f",stop.toSec());
    // [ INFO] [1724586979.184085857]: 开始时刻：1724586979.18
    // [ INFO] [1724586979.184098739]: 结束时刻：1724586984.18

    //时刻与时刻运算
    //ros::Time sum = begin + stop;时刻没有+操作
    ros::Duration du2 = stop - begin;
    ROS_INFO("时刻相减：%.2f",du2.toSec());
    //[ INFO] [1724587326.316437257]: 时刻相减：5.00

    //持续时间之间的运算
    ros::Duration du3 = du1 + du2;
    ros::Duration du4 = du1 - du2;
    ROS_INFO("du1 + du2：%.2f",du3.toSec());
    ROS_INFO("du1 - du2：%.2f",du4.toSec());
    // [ INFO] [1724587504.250559469]: du1 + du2：10.00
    // [ INFO] [1724587504.250564680]: du1 - du2：0.00

    ROS_INFO("------定时器-----");
    /*
    Timer createTimer(Duration period,  //时间间隔 --- 1s
        const TimerCallback& callback,  //回调函数 --- 封装业务
        bool oneshot = false,           //是否只执行一次回调函数
        bool autostart = true)          //是否自动启动定时器
    */
    // ros::Timer timer = nh.createTimer(ros::Duration(1),cb);
    // ros::spin();//需要回旋
    // // [ INFO] [1724642727.858371742]: ------定时器-----
    // //间隔1秒输出横杠
    // // [ INFO] [1724642728.859643751]: --------
    // // [ INFO] [1724642729.858800596]: --------
    // // [ INFO] [1724642730.859296727]: --------

    //oneshot参数
    // ros::Timer timer = nh.createTimer(ros::Duration(1),cb,true);
    // ros::spin();//需要回旋
    // [ INFO] [1724643002.441836875]: --------

    //autostart参数
    ros::Timer timer = nh.createTimer(ros::Duration(1),cb,false,false);
    //不出现 ------
    timer.start();//手动启动定时器
    // [ INFO] [1724643261.505752254]: --------
    // [ INFO] [1724643262.505615668]: --------
    // [ INFO] [1724643263.506614365]: --------
    ros::spin();//需要回旋
    return 0;
}