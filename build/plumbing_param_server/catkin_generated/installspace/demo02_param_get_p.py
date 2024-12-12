#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
    参数服务器操作之查询_Python实现:    
        rospy.get_param(键,默认值)
            当键存在时，返回对应的值，如果不存在返回默认值
        rospy.get_param_cached(键,默认值)
            速度更快，当键存在时，返回对应的值，如果不存在返回默认值
        rospy.get_param_names
        rospy.has_param
        rospy.search_param
"""

import rospy

if __name__ == "__main__":
    rospy.init_node("get_param_p")

    #获取参数
    int_value = rospy.get_param("p_int",10000)
    double_value = rospy.get_param("p_double")
    bool_value = rospy.get_param("p_bool")
    string_value = rospy.get_param("p_string")
    p_list = rospy.get_param("p_list")
    p_dict = rospy.get_param("p_dict")

    rospy.loginfo("获取的数据:%d,%.2f,%d,%s",
                int_value,
                double_value,
                bool_value,
                string_value)
    #获取的数据:100,3.14,1,hello python

    for ele in p_list:
        rospy.loginfo("ele = %s", ele)
    # [INFO] [1724210194.246411]: ele = hello
    # [INFO] [1724210194.247279]: ele = haha
    # [INFO] [1724210194.248085]: ele = xixi

    rospy.loginfo("name = %s, age = %d",p_dict["name"],p_dict["age"])
    # name = hulu, age = 8

    # get_param_cached
    int_cached = rospy.get_param_cached("p_int")
    rospy.loginfo("缓存数据:%d",int_cached)
    # 缓存数据:100

    # get_param_names
    names = rospy.get_param_names()
    for name in names:
        rospy.loginfo("name = %s",name)
    # [INFO] [1724210194.254186]: name = /p_string
    # [INFO] [1724210194.255053]: name = /p_dict/age
    # [INFO] [1724210194.256032]: name = /p_dict/name
    # [INFO] [1724210194.257405]: name = /p_bool
    # [INFO] [1724210194.259344]: name = /p_double
    # [INFO] [1724210194.261331]: name = /p_list
    # [INFO] [1724210194.262646]: name = /p_int

    rospy.loginfo("-"*80)

    # has_param
    flag = rospy.has_param("p_int")
    rospy.loginfo("包含p_int吗？%d",flag)
    # 包含p_int吗？1

    # search_param
    key = rospy.search_param("p_int")
    rospy.loginfo("搜索的键 = %s",key)
    #搜索的键 = /p_int