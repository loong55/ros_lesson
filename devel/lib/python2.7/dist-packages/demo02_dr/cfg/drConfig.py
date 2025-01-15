## *********************************************************
##
## File autogenerated for the demo02_dr package
## by the dynamic_reconfigure package.
## Please do not edit.
##
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'upper': 'DEFAULT', 'lower': 'groups', 'srcline': 246, 'name': 'Default', 'parent': 0, 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'cstate': 'true', 'parentname': 'Default', 'class': 'DEFAULT', 'field': 'default', 'state': True, 'parentclass': '', 'groups': [], 'parameters': [{'srcline': 291, 'description': '\xe6\x95\xb4\xe5\x9e\x8b\xe5\x8f\x82\xe6\x95\xb0', 'max': 100, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'int_param', 'edit_method': '', 'default': 50, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 291, 'description': '\xe6\xb5\xae\xe7\x82\xb9\xe5\x8f\x82\xe6\x95\xb0', 'max': 3.14, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'double_param', 'edit_method': '', 'default': 1.57, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 291, 'description': '\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe5\x8f\x82\xe6\x95\xb0', 'max': '', 'cconsttype': 'const char * const', 'ctype': 'std::string', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'string_param', 'edit_method': '', 'default': 'hello world ', 'level': 0, 'min': '', 'type': 'str'}, {'srcline': 291, 'description': 'bool\xe5\x8f\x82\xe6\x95\xb0', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'bool_param', 'edit_method': '', 'default': True, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 291, 'description': '\xe5\x88\x97\xe8\xa1\xa8\xe5\x8f\x82\xe6\x95\xb0', 'max': 2, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'list_param', 'edit_method': "{'enum_description': 'a car size set', 'enum': [{'srcline': 27, 'description': 'a small size', 'srcfile': '/home/book/ws/src/demo02_dr/cfg/dr.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'small'}, {'srcline': 28, 'description': 'a medium size', 'srcfile': '/home/book/ws/src/demo02_dr/cfg/dr.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'mediun'}, {'srcline': 29, 'description': 'a big size', 'srcfile': '/home/book/ws/src/demo02_dr/cfg/dr.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'big'}]}", 'default': 0, 'level': 0, 'min': 0, 'type': 'int'}], 'type': '', 'id': 0}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

dr_small = 0
dr_mediun = 1
dr_big = 2
