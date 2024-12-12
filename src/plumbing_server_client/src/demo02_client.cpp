/*
    需求: 
        编写两个节点实现服务通信，客户端节点需要提交两个整数到服务器
        服务器需要解析客户端提交的数据，相加后，将结果响应回客户端，
        客户端再解析

    服务器实现:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 句柄
        4.创建 客户端 对象
        5.请求服务，接收响应

    实现动态参数提交：
        1.格式：rosrun xxx xxx 12 34
        2.节点执行时，获取命令中的参数，并组织n进 request
        共传入3个参数，程序名 12 34；故argc = 3;*argv[1]=12，*argv[2]=34
       
    问题：
        如果先启动客户端，没启动服务端，会请求异常
    解决：
        在ros中内部设置相关函数，这些函数可以让客户端挂起，等待服务端启动
*/
// 1.包含头文件
#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    // 调用时动态传值,如果通过 launch 的 args 传参，需要传递的参数个数 +3
    if (argc != 3)
    // if (argc != 5)//launch 传参(0-文件路径 1传入的参数 2传入的参数 3节点名称 4日志路径)
    {
        ROS_ERROR("请提交两个整数");
        return 1;//结束main函数
    }

    // 2.初始化 ROS 节点
    ros::init(argc,argv,"AddInts_Client");//客户端
    // 3.创建 ROS 句柄
    ros::NodeHandle nh;
    // 4.创建 客户端 对象
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("AddInts");
    //等待服务启动成功
    //方式1
    ros::service::waitForService("AddInts");
    //方式2
    // client.waitForExistence();
    // 5.组织请求数据
    //实例化AddInts类对象，里面封装了客户端的请求数据和服务端的响应数据
    plumbing_server_client::AddInts ai;
    ai.request.num1 = atoi(argv[1]);//将字符串地址转化为int型数据
    ai.request.num2 = atoi(argv[2]);
    // 6.发送请求,返回 bool 值，标记是否成功
    bool flag = client.call(ai);//ros自带函数
    // 7.处理响应
    if (flag)
    {
        ROS_INFO("请求正常处理,响应结果:%d",ai.response.sum);
    }
    else
    {
        ROS_ERROR("请求处理失败....");
        return 1;
    }

    return 0;
}