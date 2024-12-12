#include "ros/ros.h"
#include "turtlesim/Pose.h"
/*
    订阅乌龟的位姿信息，并打印到终端
    已知信息：
        1.话题名称：/turtle1/pose
        2.消息类型：turtlesim/Pose
    
    实现流程：
        1.包含头文件
        2.初始化节点
        3.创建节点句柄
        4.创建订阅者对象
        5.回调函数处理订阅数据
        6.spin
*/
void doPose(const turtlesim::Pose::ConstPtr& p){
    ROS_INFO("乌龟的位姿信息：坐标：（%.2f,%.2f）,朝向：%.2f,线速度：%.2f,角速度：%.2f",
            p->x,p->y,p->theta,p->linear_velocity,p->angular_velocity);
};

int main(int argc,char *argv[])
{
    // 防止中文乱码
    setlocale(LC_ALL,"");
    // 2.初始化节点
    ros::init(argc,argv,"sub_pose");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建订阅者对象
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose",100,doPose);
    // 5.回调函数处理订阅数据
    // 6.spin
    ros::spin();
    return 0;
}