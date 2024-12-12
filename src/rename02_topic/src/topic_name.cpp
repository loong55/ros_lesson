#include "ros/ros.h"
#include "std_msgs/String.h"
/*
演示不同类型的话题名称设置
设置话题名称与命名空间
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"topic_name");
    // ros::NodeHandle nh;
    //设置不同类型的话题
    //1.全局--话题名称以“/”开头（也可以设置自己的命名空间），这种情况下和节点（命名空间和名字）无关系
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter",100);
    /*
    rosrun rename02_top topic_name __ns:=xxx

    rosnode list
    /xxx/topic_name

    rostopic list
    /chatter
    */

    // ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter",100);
    /*
    rosrun rename02_top topic_name __ns:=xxx

    rosnode list    
    /xxx/topic_name

    rostopic list   
    /yyy/chatter
    */

    //2.相对    非“/”开头
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",100);
    /*
    rosrun rename02_top topic_name __ns:=xxx

    rosnode list
    /xxx/topic_name

    rostopic list
    /xxx/chatter
    */
    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",100);
    /*
    rosrun rename02_top topic_name __ns:=xxx

    rosnode list
    /xxx/topic_name

    rostopic list
    /xxx/yyy/chatter
    */
    //3.私有  需要创建新的 ros::NodeHandle nh("~");话题名称在命名空间/节点 的下面

    ros::NodeHandle nh("~");
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",100);
    /*
    rosrun rename02_top topic_name __ns:=xxx

    rosnode list
    /xxx/topic_name

    rostopic list
    /xxx/topic_name/chatter
    */
    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",100);
    /*
    rosrun rename02_top topic_name __ns:=xxx

    rosnode list
    /xxx/topic_name

    rostopic list
    /xxx/topic_name/yyy/chatter
    */

    //有斜杠，用的全局，非私有，权限最高
    ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter",100);
    /*
    rosrun rename02_top topic_name __ns:=xxx
    
    rosnode list
    /xxx/topic_name

    rostopic list   
    /yyy/chatter
    */
    while (ros::ok())
    {

    }

    return 0;
}