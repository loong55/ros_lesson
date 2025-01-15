// Generated by gencpp from file demo01_action/AddintsFeedback.msg
// DO NOT EDIT!


#ifndef DEMO01_ACTION_MESSAGE_ADDINTSFEEDBACK_H
#define DEMO01_ACTION_MESSAGE_ADDINTSFEEDBACK_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace demo01_action
{
template <class ContainerAllocator>
struct AddintsFeedback_
{
  typedef AddintsFeedback_<ContainerAllocator> Type;

  AddintsFeedback_()
    : progerss_bar(0.0)  {
    }
  AddintsFeedback_(const ContainerAllocator& _alloc)
    : progerss_bar(0.0)  {
  (void)_alloc;
    }



   typedef double _progerss_bar_type;
  _progerss_bar_type progerss_bar;





  typedef boost::shared_ptr< ::demo01_action::AddintsFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::demo01_action::AddintsFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct AddintsFeedback_

typedef ::demo01_action::AddintsFeedback_<std::allocator<void> > AddintsFeedback;

typedef boost::shared_ptr< ::demo01_action::AddintsFeedback > AddintsFeedbackPtr;
typedef boost::shared_ptr< ::demo01_action::AddintsFeedback const> AddintsFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::demo01_action::AddintsFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::demo01_action::AddintsFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::demo01_action::AddintsFeedback_<ContainerAllocator1> & lhs, const ::demo01_action::AddintsFeedback_<ContainerAllocator2> & rhs)
{
  return lhs.progerss_bar == rhs.progerss_bar;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::demo01_action::AddintsFeedback_<ContainerAllocator1> & lhs, const ::demo01_action::AddintsFeedback_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace demo01_action

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::demo01_action::AddintsFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::demo01_action::AddintsFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::demo01_action::AddintsFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::demo01_action::AddintsFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::demo01_action::AddintsFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::demo01_action::AddintsFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::demo01_action::AddintsFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "02110171e2018aaea07999b32009b866";
  }

  static const char* value(const ::demo01_action::AddintsFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x02110171e2018aaeULL;
  static const uint64_t static_value2 = 0xa07999b32009b866ULL;
};

template<class ContainerAllocator>
struct DataType< ::demo01_action::AddintsFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "demo01_action/AddintsFeedback";
  }

  static const char* value(const ::demo01_action::AddintsFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::demo01_action::AddintsFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"# 3.连续反馈变量\n"
"float64 progerss_bar\n"
"\n"
;
  }

  static const char* value(const ::demo01_action::AddintsFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::demo01_action::AddintsFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.progerss_bar);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AddintsFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::demo01_action::AddintsFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::demo01_action::AddintsFeedback_<ContainerAllocator>& v)
  {
    s << indent << "progerss_bar: ";
    Printer<double>::stream(s, indent + "  ", v.progerss_bar);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DEMO01_ACTION_MESSAGE_ADDINTSFEEDBACK_H
