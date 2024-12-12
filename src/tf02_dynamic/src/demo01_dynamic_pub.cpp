#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"
/*
发布方：订阅乌龟位姿信息，转换成相对于窗体的坐标关系，并发布
准备:
    话题：/turtle1/pose
    消息：/turtlesim/Pose
分析：订阅/turtle1/pose，获取乌龟在世界坐标系中的坐标
     将pose信息转换成坐标系相对信息并发布
流程：
    1.头文件
    2.设置编码，初始化，句柄
    3.创建订阅对象，订阅 /turtle1/pose
    4.回调函数处理订阅消息：将位姿信息转换成坐标相对关系，并发布（重点）
    5.spin()
*/
// 回调函数处理订阅消息：将位姿信息转换成坐标相对关系，并发布（重点）
void doPose(const turtlesim::Pose::ConstPtr& pose)
{
    //1.创建坐标发布对象
    static tf2_ros::TransformBroadcaster pub;   //static对象在程序运行期间会一直存在
    //2.组织被发布的数据
    //坐标对象
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";   //全局坐标
    ts.header.stamp = ros::Time::now(); 
    ts.child_frame_id = "turtle1";  //子坐标   
    //坐标偏移量
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0; //乌龟处于二维平面
    //坐标旋转量
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();
    //3.发布
    pub.sendTransform(ts);
}
int main(int argc, char *argv[])
{   
    // 2.设置编码，初始化，句柄
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dynamic_pub");
    ros::NodeHandle nh;
    // 3.创建订阅对象，订阅 /turtle1/pose
    ros::Subscriber sub;
    sub = nh.subscribe("/turtle1/pose",100,doPose);
    // 4.回调函数处理订阅消息：将位姿信息转换成坐标相对关系，并发布（重点）
    // 5.spin()
    ros::spin();
    return 0;
}
