#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello");
    ros::NodeHandle nh;
    /* 
        使用 NodeHandle 设置不同类型参数
    */
    //全局
    nh.setParam("/radius_nh_A",4);
    //相对
    nh.setParam("radius_nh_B",5);
    //私有
    ros::NodeHandle nh_private("~");
    nh_private.setParam("radius_nh_C",6);

    return 0;
}
