/*设置乌龟GUI背景色*/
#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"set_bgcol");

    // //1.用ros内置函数设置参数
    // ros::param::set("/turtlesim/background_r",0);
    // ros::param::set("/turtlesim/background_g",0);
    // ros::param::set("/turtlesim/background_b",0);

    //2.用句柄设置参数
    ros::NodeHandle nh("turtlesim");//添加命名空间后，后续不用输入
    nh.setParam("background_r",255);
    nh.setParam("background_g",255);
    nh.setParam("background_b",255);

    return 0;
}
