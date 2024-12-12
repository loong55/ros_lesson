#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"
//动态接收乌龟名字
std::string turtle_name;

void doPose(const turtlesim::Pose::ConstPtr& pose)
{
    //1.创建坐标发布对象
    static tf2_ros::TransformBroadcaster pub;   //static对象在程序运行期间会一直存在
    //2.组织被发布的数据
    //坐标对象
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";   //全局坐标
    ts.header.stamp = ros::Time::now(); 

    /*
    关键点2：动态传入
    */
    ts.child_frame_id = turtle_name;  //子坐标   

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

    //解析传入参数
    if (argc != 2)
    {
        ROS_ERROR("请传入正确参数");
    }
    else
    {
        turtle_name = argv[1];
        ROS_INFO("乌龟 %s 坐标发送",turtle_name.c_str());
    }
    
    ros::NodeHandle nh;
    // 3.创建订阅对象，订阅 /turtle1/pose
    ros::Subscriber sub;
    
    /*
    关键点1：订阅的话题名称，turtle1 或 turtle2 动态传入
    */
    sub = nh.subscribe(turtle_name + "/pose",100,doPose);
    // 4.回调函数处理订阅消息：将位姿信息转换成坐标相对关系，并发布（重点）
    // 5.spin()
    ros::spin();
    return 0;
}
