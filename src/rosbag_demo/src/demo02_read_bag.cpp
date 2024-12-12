/*  
    读取 bag 文件：
*/
#include "ros/ros.h"
#include "rosbag/bag.h"
#include "rosbag/view.h"    //解析bag数据
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"

int main(int argc, char *argv[])
{

    setlocale(LC_ALL,"");

    ros::init(argc,argv,"bag_read");
    ros::NodeHandle nh;

    //创建 bag 对象
    rosbag::Bag bag;
    //打开 bag 文件
    bag.open("test.bag",rosbag::BagMode::Read);
    //读数据
    for (auto &&m : rosbag::View(bag))
    {
        //解析
        std::string topic = m.getTopic();
        ros::Time time = m.getTime();
        std_msgs::StringPtr p = m.instantiate<std_msgs::String>();//取出消息里面的具体值
        if(p != nullptr){
            ROS_INFO("读取的数据:%s",p->data.c_str());
            ROS_INFO("话题:%s",topic.c_str());
            ROS_INFO("时间戳:%.2f",time.toSec());
        }
    }

    //关闭文件流
    bag.close();
    return 0;
}