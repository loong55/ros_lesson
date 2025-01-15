#include "ros/ros.h"
#include "actionlib/server/simple_action_server.h"
#include "demo01_action/AddIntsAction.h"
/*  
    需求:
        创建两个ROS节点，服务器和客户端，
        客户端可以向服务器发送目标数据N（一个整型数据）
        服务器会计算1到N之间所有整数的和，这是一个循环累加的过程，返回给客户端，
        这是基于请求响应模式的，
        又已知服务器从接收到请求到产生响应是一个耗时操作，每累加一次耗时0.1s，
        为了良好的用户体验，需要服务器在计算过程中，
        每累加一次，就给客户端响应一次百分比格式的执行进度，使用action实现。

    流程:
        1.包含头文件;
        2.初始化ROS节点;
        3.创建NodeHandle;
        4.创建action服务对象;
        5.处理请求,产生反馈与响应;
        6.spin().
*/

typedef actionlib::SimpleActionServer<demo01_action::AddIntsAction> Server;

 // 5.处理请求（1.解析提交的目标值；2.产生连续反馈；3.最终结果响应） ---回调函数
 // goal被用来获取客户端提交的目标值num，而server指针被用来发布进度反馈和最终结果
void cb(const demo01_action::AddIntsGoalConstPtr &goal,Server* server){
    //获取目标值
    int num = goal->num;
    ROS_INFO("客户端提交的目标值是:%d",num);
    //累加并响应连续反馈
    int result = 0;
    demo01_action::AddIntsFeedback feedback;//连续反馈对象
    ros::Rate rate(10);//通过频率设置休眠时间，1/10s
    for (int i = 1; i <= num; i++)
    {
        result += i;
        //组织连续数据并发布
        feedback.progress_bar = i / (double)num;
        server->publishFeedback(feedback);
        rate.sleep();
    }
    //设置最终结果
    demo01_action::AddIntsResult r;
    r.result = result;
    server->setSucceeded(r);
    ROS_INFO("最终结果:%d",r.result);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("action服务端实现");
    // 2.初始化ROS节点;
    ros::init(argc,argv,"AddInts_server");
    // 3.创建NodeHandle;
    ros::NodeHandle nh;
    // 4.创建action服务对象;
    /*SimpleActionServer(ros::NodeHandle n, //函数句柄
            std::string name,               //话题名称
            //回调函数，传入参数类型，产生不断的反馈
            boost::function<void (const demo01_action::AddIntsGoalConstPtr &)> execute_callback, 
            bool auto_start)                //自动启动选项
    */
    // actionlib::SimpleActionServer<demo01_action::AddIntsAction> server(....);
    //创建server对象，参数：函数句柄，绑定回调函数，是否自动启动服务
    /*绑定函数定义：
    &cb是回调函数的地址。
    _1是一个特殊的占位符，表示将动作目标（AddIntsGoalConstPtr）作为第一个参数传递给回调函数cb。
    &server是动作服务器对象的地址，作为第二个参数传递给回调函数cb。
    */
    Server server(nh,"addInts",boost::bind(&cb,_1,&server),false);
    server.start();//如果auto start为false，那么需要手动调用改函数，启动服务
    // 5.处理请求（1.解析提交的目标值；2.产生连续反馈；3.最终结果响应） ---回调函数

    // 6.spin().   
    ros::spin();
    return 0;
}