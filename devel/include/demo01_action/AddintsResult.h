// Generated by gencpp from file demo01_action/AddintsResult.msg
// DO NOT EDIT!


#ifndef DEMO01_ACTION_MESSAGE_ADDINTSRESULT_H
#define DEMO01_ACTION_MESSAGE_ADDINTSRESULT_H


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
struct AddintsResult_
{
  typedef AddintsResult_<ContainerAllocator> Type;

  AddintsResult_()
    : result(0)  {
    }
  AddintsResult_(const ContainerAllocator& _alloc)
    : result(0)  {
  (void)_alloc;
    }



   typedef int32_t _result_type;
  _result_type result;





  typedef boost::shared_ptr< ::demo01_action::AddintsResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::demo01_action::AddintsResult_<ContainerAllocator> const> ConstPtr;

}; // struct AddintsResult_

typedef ::demo01_action::AddintsResult_<std::allocator<void> > AddintsResult;

typedef boost::shared_ptr< ::demo01_action::AddintsResult > AddintsResultPtr;
typedef boost::shared_ptr< ::demo01_action::AddintsResult const> AddintsResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::demo01_action::AddintsResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::demo01_action::AddintsResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::demo01_action::AddintsResult_<ContainerAllocator1> & lhs, const ::demo01_action::AddintsResult_<ContainerAllocator2> & rhs)
{
  return lhs.result == rhs.result;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::demo01_action::AddintsResult_<ContainerAllocator1> & lhs, const ::demo01_action::AddintsResult_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace demo01_action

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::demo01_action::AddintsResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::demo01_action::AddintsResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::demo01_action::AddintsResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::demo01_action::AddintsResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::demo01_action::AddintsResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::demo01_action::AddintsResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::demo01_action::AddintsResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "034a8e20d6a306665e3a5b340fab3f09";
  }

  static const char* value(const ::demo01_action::AddintsResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x034a8e20d6a30666ULL;
  static const uint64_t static_value2 = 0x5e3a5b340fab3f09ULL;
};

template<class ContainerAllocator>
struct DataType< ::demo01_action::AddintsResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "demo01_action/AddintsResult";
  }

  static const char* value(const ::demo01_action::AddintsResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::demo01_action::AddintsResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"# 2.最终响应变量\n"
"int32 result\n"
;
  }

  static const char* value(const ::demo01_action::AddintsResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::demo01_action::AddintsResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AddintsResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::demo01_action::AddintsResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::demo01_action::AddintsResult_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<int32_t>::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DEMO01_ACTION_MESSAGE_ADDINTSRESULT_H
