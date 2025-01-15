#include "pluginlib/class_list_macros.h"
#include "demo03_plugin/dbx_base.h"
#include "demo03_plugin/dbx_plugins.h"

//外部导入拓展插件类,参数：子类，父类
PLUGINLIB_EXPORT_CLASS(dbx_plugins_ns::SanBian,dbx_base_ns::Dbx_Base)
PLUGINLIB_EXPORT_CLASS(dbx_plugins_ns::SiBian,dbx_base_ns::Dbx_Base)