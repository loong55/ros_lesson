/*
需求:
    需求1.换算出turtle1 相对于turtle2 的关系
    需求2：计算角速度和线速度并发布
实现流程:
    1.包含头文件
    2.初始化 ros 节点
    3.创建 ros 句柄
    4.创建 TF 订阅对象
    5.解析订阅信息中获取 son1 坐标系原点在 son2 中的坐标
      解析 son1 中的点相对于 son2 的坐标
    6.spin
*/
//1.包含头文件
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[])
{   setlocale(LC_ALL,"");
    // 2.初始化 ros 节点
    ros::init(argc,argv,"sub_frames");
    // 3.创建 ros 句柄
    ros::NodeHandle nh;
    // 4.创建 TF 订阅对象
    tf2_ros::Buffer buffer; 
    tf2_ros::TransformListener listener(buffer);

    //A.创建发布对象
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",100);

    // 5.解析订阅信息中获取 son1 坐标系原点在 son2 中的坐标
    ros::Rate r(1);
    while (ros::ok())
    {
        try
        {
            //解析 turtle1 中的点相对于 turtle2 的坐标
            /*
            buffer.lookupTransform("参数1","参数2",参数3)
            A 相对于 B 的坐标系关系
            参数1：目标坐标系 B
            参数2：源坐标系   A
            参数3：ros::Time(0) 取时间间隔最短的两个坐标关系帧，计算相对关系
            返回值：geometry_msgs::TransformStamped  两坐标系的相对关系
            */
            geometry_msgs::TransformStamped tfs = buffer.lookupTransform("turtle2","turtle1",ros::Time(0));
            // ROS_INFO("Son1 相对于 Son2 的坐标关系:父坐标系ID=%s",tfs.header.frame_id.c_str());//turtle2
            // ROS_INFO("Son1 相对于 Son2 的坐标关系:子坐标系ID=%s",tfs.child_frame_id.c_str());//turtle1
            // ROS_INFO("Son1 相对于 Son2 的坐标关系:x=%.2f,y=%.2f,z=%.2f",
            //         tfs.transform.translation.x,
            //         tfs.transform.translation.y,
            //         tfs.transform.translation.z
            //         );

            //B.计算并组织速度消息
            geometry_msgs::Twist twist;
            /*
            组织速度，只需要设置线速度的X和角速度Z
            X = 系数 *（x^2+y^2）^0.5
            Z = 系数 * arctan(y/x)
            */
            twist.linear.x = 1 * sqrt(pow(tfs.transform.translation.x,2) + pow(tfs.transform.translation.y,2));
            twist.angular.z = 1 * atan2(tfs.transform.translation.y,tfs.transform.translation.x);
            //C.发布
            pub.publish(twist);
        }
        catch(const std::exception& e)
        {
            // std::cerr << e.what() << '\n';
            ROS_INFO("异常信息:%s",e.what());
        }

        r.sleep();
        // 6.spin
        ros::spinOnce();
    }
    return 0;
}