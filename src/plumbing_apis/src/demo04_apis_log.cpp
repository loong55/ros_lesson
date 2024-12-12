#include "ros/ros.h"
/*
ros 中日志：
    演示不同级别日志的基本使用
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello_log");
    ros::NodeHandle nh;

    //日志输出
    ROS_DEBUG("调试信息");//不会打印在控制台
    ROS_INFO("一般信息");
    ROS_WARN("警告信息");
    ROS_ERROR("错误信息");
    ROS_FATAL("严重错误");
    // [ INFO] [1724646209.954417074]: 一般信息
    // [ WARN] [1724646209.955213578]: 警告信息
    // [ERROR] [1724646209.955239990]: 错误信息
    // [FATAL] [1724646209.955249620]: 严重错误


    return 0;
}
