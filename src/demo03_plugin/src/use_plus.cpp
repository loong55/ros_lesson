//类加载器相关的头文件
#include "ros/ros.h"
#include "pluginlib/class_loader.h"
#include "demo03_plugin/dbx_base.h"
/*
    创建类加载器，根据需求加载相关插件
        1.创建类加载器
        2.使用类加载器实例化某个插件对象
        3.使用插件
*/
int main(int argc, char** argv)
{
    setlocale(LC_ALL,"");
  //1.创建类加载器 -- 参数1:基类功能包名称 参数2:基类全限定名称
  pluginlib::ClassLoader<dbx_base_ns::Dbx_Base> loader("demo03_plugin", "dbx_base_ns::Dbx_Base");

  try
  {
    //三角形周长
    //创建插件类实例 -- 参数:插件类全限定名称
    boost::shared_ptr<dbx_base_ns::Dbx_Base> san = loader.createInstance("dbx_plugins_ns::SanBian");
    //使用插件
    san->initialize(10);
    double length = san->getlength();
    ROS_INFO("三角形周长: %.2f", length);

    //四角形周长
    //创建插件类实例 -- 参数:插件类全限定名称
    boost::shared_ptr<dbx_base_ns::Dbx_Base> si = loader.createInstance("dbx_plugins_ns::SiBian");
    //使用插件
    si->initialize(10);
    double length2 = si->getlength();
    ROS_INFO("四边形周长: %.2f", length2);
  }
  catch(pluginlib::PluginlibException& ex)
  {
    ROS_ERROR("The plugin failed to load for some reason. Error: %s", ex.what());
  }

  return 0;
}