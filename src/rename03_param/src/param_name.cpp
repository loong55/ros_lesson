#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello");
    ros::NodeHandle nh;
    /* 
        使用 ros::param 设置不同类型参数
    */
    //全局
    ros::param::set("/radiusA",1);
    //相对
    ros::param::set("radiusB",2);
    //私有
    ros::param::set("~radiusC",3);

    return 0;
}
