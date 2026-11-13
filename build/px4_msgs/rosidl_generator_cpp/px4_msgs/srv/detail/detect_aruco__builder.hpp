// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from px4_msgs:srv/DetectAruco.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "px4_msgs/srv/detect_aruco.hpp"


#ifndef PX4_MSGS__SRV__DETAIL__DETECT_ARUCO__BUILDER_HPP_
#define PX4_MSGS__SRV__DETAIL__DETECT_ARUCO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "px4_msgs/srv/detail/detect_aruco__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace px4_msgs
{

namespace srv
{

namespace builder
{

class Init_DetectAruco_Request_start
{
public:
  Init_DetectAruco_Request_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::px4_msgs::srv::DetectAruco_Request start(::px4_msgs::srv::DetectAruco_Request::_start_type arg)
  {
    msg_.start = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::srv::DetectAruco_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::srv::DetectAruco_Request>()
{
  return px4_msgs::srv::builder::Init_DetectAruco_Request_start();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace srv
{

namespace builder
{

class Init_DetectAruco_Response_target_number
{
public:
  Init_DetectAruco_Response_target_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::px4_msgs::srv::DetectAruco_Response target_number(::px4_msgs::srv::DetectAruco_Response::_target_number_type arg)
  {
    msg_.target_number = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::srv::DetectAruco_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::srv::DetectAruco_Response>()
{
  return px4_msgs::srv::builder::Init_DetectAruco_Response_target_number();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace srv
{

namespace builder
{

class Init_DetectAruco_Event_response
{
public:
  explicit Init_DetectAruco_Event_response(::px4_msgs::srv::DetectAruco_Event & msg)
  : msg_(msg)
  {}
  ::px4_msgs::srv::DetectAruco_Event response(::px4_msgs::srv::DetectAruco_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::srv::DetectAruco_Event msg_;
};

class Init_DetectAruco_Event_request
{
public:
  explicit Init_DetectAruco_Event_request(::px4_msgs::srv::DetectAruco_Event & msg)
  : msg_(msg)
  {}
  Init_DetectAruco_Event_response request(::px4_msgs::srv::DetectAruco_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_DetectAruco_Event_response(msg_);
  }

private:
  ::px4_msgs::srv::DetectAruco_Event msg_;
};

class Init_DetectAruco_Event_info
{
public:
  Init_DetectAruco_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectAruco_Event_request info(::px4_msgs::srv::DetectAruco_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_DetectAruco_Event_request(msg_);
  }

private:
  ::px4_msgs::srv::DetectAruco_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::srv::DetectAruco_Event>()
{
  return px4_msgs::srv::builder::Init_DetectAruco_Event_info();
}

}  // namespace px4_msgs

#endif  // PX4_MSGS__SRV__DETAIL__DETECT_ARUCO__BUILDER_HPP_
