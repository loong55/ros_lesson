/*
    生成一只小乌龟
    准备工作:
        1.服务话题 /spawn
        2.服务消息类型 turtlesim/Spawn
        3.运行前先启动 turtlesim_node 节点

    实现流程:
        1.包含头文件
          需要包含 turtlesim 包下资源，注意在 package.xml 配置
        2.初始化 ros 节点
        3.创建 ros 句柄
        4.创建 service 客户端
        5.等待服务启动
        6.发送请求
        7.处理响应
*/
#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化 ros 节点
    ros::init(argc,argv,"turtle2");
    // 3.创建 ros 句柄
    ros::NodeHandle nh;
    // 4.创建 service 客户端
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    // 5.等待服务启动
    ros::service::waitForService("/spawn");
    // 6.发送请求
    turtlesim::Spawn spawn;//创建数据载体
    spawn.request.x = 1.0;
    spawn.request.y = 1.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "turtle2";
    //客户端向服务端发送数据，响应成功返回true,服务端响应数据存入spawn
    bool flag = client.call(spawn);
    // 7.处理响应
    if (flag)
    {
        ROS_INFO("有新龟诞生：%s!",spawn.response.name.c_str());
    }
    else
    {
        ROS_INFO("龟龟出生失败！");
    }
    
    return 0;
}
