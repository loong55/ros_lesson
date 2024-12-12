#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"     //创建订阅方对象
#include "tf2_ros/buffer.h"     //缓存数据到buffer中
#include "geometry_msgs/PointStamped.h"     //坐标点数据
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"    //tf2坐标消息
/*
订阅方：订阅发布的坐标相对关系，传入一个坐标点，调用tf实现转换

流程：
    1.包含头文件
    2.编码、初始化、NodeHandle（必须）
    3.创建订阅对象：负责订阅坐标系相对关系
    4.组织一个坐标点数据
    5.转换算法，调用tf内置实现
    6.输出
*/
int main(int argc, char *argv[])
{
    // 2.编码、初始化、NodeHandle（必须）
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"static_sub");
    ros::NodeHandle nh;
    // 3.创建订阅对象：负责订阅坐标系相对关系
    //3-1 创建一个buffer缓存
    tf2_ros::Buffer buffer;
    //3-2创建订阅对象，将订阅数据存入buffer
    tf2_ros::TransformListener listener(buffer);
    // 4.组织一个坐标点数据(雷达检测的物体坐标)
    geometry_msgs::PointStamped ps;
    ps.header.frame_id = "laser";
    ps.header.stamp = ros::Time::now();
    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;
    
    // 5.转换算法，调用tf内置实现
    ros::Rate rate(10);
    while (ros::ok())
    {
        //核心代码  将ps转换成相对于base_link的坐标点
        geometry_msgs::PointStamped ps_out;

        try
        {
            //转换后的坐标点信息，需要头文件tf2_geometry_msgs/tf2_geometry_msgs.h
            ps_out = buffer.transform(ps,"base_link");//参数1：输入坐标点，参数2；转换后的坐标系

            // 6.输出
            ROS_INFO("转换后的坐标值：（%.2f,%.2f,%.2f）,参考坐标系：%s",
                        ps_out.point.x,
                        ps_out.point.y,
                        ps_out.point.z,
                        ps_out.header.frame_id.c_str());
        }
        catch(const std::exception& e)
        {
            // std::cerr << e.what() << '\n';
            ROS_INFO("异常消息：%s",e.what());
        }
        rate.sleep();
        ros::spinOnce();
    }
    
    return 0;
}
