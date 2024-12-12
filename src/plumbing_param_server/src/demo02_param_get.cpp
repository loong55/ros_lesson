/*
    参数服务器操作之查询_C++实现:
    在 roscpp 中提供了两套 API 实现参数操作
    ros::NodeHandle

        param(键,默认值) 
            存在，返回键对应的值，否则返回默认值

        getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached键,存储结果的变量)--从缓存中提取，提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1：被搜索的键，参数2：结果)
            搜索键，参数2存储搜索结果的变量，如果键存在则键名被存入参数2，否则参数2为空

    ros::param ----- 与 NodeHandle 类似
*/

#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");//防止中文乱码
    ros::init(argc,argv,"get_param");//初始化节点（节点名称）

    //NodeHandle--------------------------------------------------------
    
    ros::NodeHandle nh;
    
    // param 函数
    int res1 = nh.param("nh_int",100); // 键存在
    int res2 = nh.param("nh_int2",100); // 键不存在
    ROS_INFO("param获取结果:%d,%d",res1,res2);
    //param获取结果:10000,100


    // getParam 函数
    int nh_int_value;
    double nh_double_value;
    bool nh_bool_value;
    std::string nh_string_value;
    std::vector<std::string> stus;
    std::map<std::string, std::string> friends;

    nh.getParam("nh_int",nh_int_value);
    nh.getParam("nh_double",nh_double_value);
    nh.getParam("nh_bool",nh_bool_value);
    nh.getParam("nh_string",nh_string_value);
    nh.getParam("nh_vector",stus);
    nh.getParam("nh_map",friends);

    ROS_INFO("getParam获取的结果:%d,%.2f,%s,%d",
            nh_int_value,
            nh_double_value,
            nh_string_value.c_str(),
            nh_bool_value
            );//10000,3.14,hello NodeHandle,1
    for (auto &&stu : stus)//遍历stus，每次循环给stu赋值一次
    {
        ROS_INFO("stus 元素:%s",stu.c_str());//用c风格字符串形式输出        
    }
    /*
    [ INFO] [1724151841.944857405]: stus 元素:zhangsan
    [ INFO] [1724151841.944888085]: stus 元素:李四
    [ INFO] [1724151841.944892990]: stus 元素:王五
    [ INFO] [1724151841.944902557]: stus 元素:孙大脑袋
    */

    for (auto &&f : friends)
    {
        ROS_INFO("map 元素:%s = %s",f.first.c_str(), f.second.c_str());
    }
    /*
    [ INFO] [1724151841.944908374]: map 元素:guo = huang
    [ INFO] [1724151841.944913013]: map 元素:yuang = xiao
    */

    // getParamCached()
    nh.getParamCached("nh_int",nh_int_value);
    ROS_INFO("通过缓存获取数据:%d",nh_int_value);
    //通过缓存获取数据:10000

    //getParamNames()
    std::vector<std::string> param_names1;
    nh.getParamNames(param_names1);//将参数服务器中的键名存入param_names1
    for (auto &&name : param_names1)
    {
        ROS_INFO("名称解析name = %s",name.c_str());        
    }
    /*
    [ INFO] [1724151841.946669765]: 名称解析name = /param_double
    [ INFO] [1724151841.946717951]: 名称解析name = /param_int
    [ INFO] [1724151841.946790520]: 名称解析name = /rosversion
    [ INFO] [1724151841.946802605]: 名称解析name = /run_id
    [ INFO] [1724151841.946808835]: 名称解析name = /param_bool
    [ INFO] [1724151841.946815695]: 名称解析name = /nh_int
    [ INFO] [1724151841.946854004]: 名称解析name = /param_vector
    [ INFO] [1724151841.946895464]: 名称解析name = /nh_map/guo
    [ INFO] [1724151841.946919449]: 名称解析name = /nh_map/yuang
    [ INFO] [1724151841.946926770]: 名称解析name = /nh_vector
    [ INFO] [1724151841.946932185]: 名称解析name = /nh_bool
    [ INFO] [1724151841.946937718]: 名称解析name = /nh_string
    [ INFO] [1724151841.946979257]: 名称解析name = /param_map/guo
    [ INFO] [1724151841.947019639]: 名称解析name = /param_map/yuang
    [ INFO] [1724151841.947056720]: 名称解析name = /rosdistro
    [ INFO] [1724151841.947083354]: 名称解析name = /nh_double
    [ INFO] [1724151841.947089215]: 名称解析name = /param_string
    */
    ROS_INFO("----------------------------");

    //hasParam()，键名是否存在？
    ROS_INFO("存在 nh_int 吗? %d",nh.hasParam("nh_int"));
    ROS_INFO("存在 nh_intttt 吗? %d",nh.hasParam("nh_intttt"));
    // [ INFO] [1724151841.948633801]: 存在 nh_int 吗? 1
    // [ INFO] [1724151841.949115054]: 存在 nh_intttt 吗? 0

    //searchParam("键名",键的值)
    std::string key;
    nh.searchParam("nh_int",key);
    ROS_INFO("搜索键:%s",key.c_str());//搜索键:/nh_int
    
    //param--------------------------------------------------------
    /*
    ROS_INFO("++++++++++++++++++++++++++++++++++++++++");
    int res3 = ros::param::param("param_int",20); //存在
    int res4 = ros::param::param("param_int2",20); // 不存在返回默认
    ROS_INFO("param获取结果:%d,%d",res3,res4);

    // getParam 函数
    int param_int_value;
    double param_double_value;
    bool param_bool_value;
    std::string param_string_value;
    std::vector<std::string> param_stus;
    std::map<std::string, std::string> param_friends;

    ros::param::get("param_int",param_int_value);
    ros::param::get("param_double",param_double_value);
    ros::param::get("param_bool",param_bool_value);
    ros::param::get("param_string",param_string_value);
    ros::param::get("param_vector",param_stus);
    ros::param::get("param_map",param_friends);

    ROS_INFO("getParam获取的结果:%d,%.2f,%s,%d",
            param_int_value,
            param_double_value,
            param_string_value.c_str(),
            param_bool_value
            );
    for (auto &&stu : param_stus)
    {
        ROS_INFO("stus 元素:%s",stu.c_str());        
    }

    for (auto &&f : param_friends)
    {
        ROS_INFO("map 元素:%s = %s",f.first.c_str(), f.second.c_str());
    }

    // getParamCached()
    ros::param::getCached("param_int",param_int_value);
    ROS_INFO("通过缓存获取数据:%d",param_int_value);

    //getParamNames()
    std::vector<std::string> param_names2;
    ros::param::getParamNames(param_names2);
    for (auto &&name : param_names2)
    {
        ROS_INFO("名称解析name = %s",name.c_str());        
    }
    ROS_INFO("----------------------------");

    ROS_INFO("存在 param_int 吗? %d",ros::param::has("param_int"));
    ROS_INFO("存在 param_intttt 吗? %d",ros::param::has("param_intttt"));

    std::string key;
    ros::param::search("param_int",key);
    ROS_INFO("搜索键:%s",key.c_str());
    */

    return 0;
}