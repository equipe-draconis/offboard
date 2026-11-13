// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from px4_msgs:action/GoToPostion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "px4_msgs/action/go_to_postion.hpp"


#ifndef PX4_MSGS__ACTION__DETAIL__GO_TO_POSTION__BUILDER_HPP_
#define PX4_MSGS__ACTION__DETAIL__GO_TO_POSTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "px4_msgs/action/detail/go_to_postion__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_GoToPostion_Goal_z
{
public:
  explicit Init_GoToPostion_Goal_z(::px4_msgs::action::GoToPostion_Goal & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::GoToPostion_Goal z(::px4_msgs::action::GoToPostion_Goal::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_Goal msg_;
};

class Init_GoToPostion_Goal_y
{
public:
  explicit Init_GoToPostion_Goal_y(::px4_msgs::action::GoToPostion_Goal & msg)
  : msg_(msg)
  {}
  Init_GoToPostion_Goal_z y(::px4_msgs::action::GoToPostion_Goal::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_GoToPostion_Goal_z(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_Goal msg_;
};

class Init_GoToPostion_Goal_x
{
public:
  Init_GoToPostion_Goal_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToPostion_Goal_y x(::px4_msgs::action::GoToPostion_Goal::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GoToPostion_Goal_y(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::GoToPostion_Goal>()
{
  return px4_msgs::action::builder::Init_GoToPostion_Goal_x();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_GoToPostion_Result_success
{
public:
  Init_GoToPostion_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::px4_msgs::action::GoToPostion_Result success(::px4_msgs::action::GoToPostion_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::GoToPostion_Result>()
{
  return px4_msgs::action::builder::Init_GoToPostion_Result_success();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_GoToPostion_Feedback_current_z
{
public:
  explicit Init_GoToPostion_Feedback_current_z(::px4_msgs::action::GoToPostion_Feedback & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::GoToPostion_Feedback current_z(::px4_msgs::action::GoToPostion_Feedback::_current_z_type arg)
  {
    msg_.current_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_Feedback msg_;
};

class Init_GoToPostion_Feedback_current_y
{
public:
  explicit Init_GoToPostion_Feedback_current_y(::px4_msgs::action::GoToPostion_Feedback & msg)
  : msg_(msg)
  {}
  Init_GoToPostion_Feedback_current_z current_y(::px4_msgs::action::GoToPostion_Feedback::_current_y_type arg)
  {
    msg_.current_y = std::move(arg);
    return Init_GoToPostion_Feedback_current_z(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_Feedback msg_;
};

class Init_GoToPostion_Feedback_current_x
{
public:
  Init_GoToPostion_Feedback_current_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToPostion_Feedback_current_y current_x(::px4_msgs::action::GoToPostion_Feedback::_current_x_type arg)
  {
    msg_.current_x = std::move(arg);
    return Init_GoToPostion_Feedback_current_y(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::GoToPostion_Feedback>()
{
  return px4_msgs::action::builder::Init_GoToPostion_Feedback_current_x();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_GoToPostion_SendGoal_Request_goal
{
public:
  explicit Init_GoToPostion_SendGoal_Request_goal(::px4_msgs::action::GoToPostion_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::GoToPostion_SendGoal_Request goal(::px4_msgs::action::GoToPostion_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_SendGoal_Request msg_;
};

class Init_GoToPostion_SendGoal_Request_goal_id
{
public:
  Init_GoToPostion_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToPostion_SendGoal_Request_goal goal_id(::px4_msgs::action::GoToPostion_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_GoToPostion_SendGoal_Request_goal(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::GoToPostion_SendGoal_Request>()
{
  return px4_msgs::action::builder::Init_GoToPostion_SendGoal_Request_goal_id();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_GoToPostion_SendGoal_Response_stamp
{
public:
  explicit Init_GoToPostion_SendGoal_Response_stamp(::px4_msgs::action::GoToPostion_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::GoToPostion_SendGoal_Response stamp(::px4_msgs::action::GoToPostion_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_SendGoal_Response msg_;
};

class Init_GoToPostion_SendGoal_Response_accepted
{
public:
  Init_GoToPostion_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToPostion_SendGoal_Response_stamp accepted(::px4_msgs::action::GoToPostion_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_GoToPostion_SendGoal_Response_stamp(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::GoToPostion_SendGoal_Response>()
{
  return px4_msgs::action::builder::Init_GoToPostion_SendGoal_Response_accepted();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_GoToPostion_SendGoal_Event_response
{
public:
  explicit Init_GoToPostion_SendGoal_Event_response(::px4_msgs::action::GoToPostion_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::GoToPostion_SendGoal_Event response(::px4_msgs::action::GoToPostion_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_SendGoal_Event msg_;
};

class Init_GoToPostion_SendGoal_Event_request
{
public:
  explicit Init_GoToPostion_SendGoal_Event_request(::px4_msgs::action::GoToPostion_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_GoToPostion_SendGoal_Event_response request(::px4_msgs::action::GoToPostion_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GoToPostion_SendGoal_Event_response(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_SendGoal_Event msg_;
};

class Init_GoToPostion_SendGoal_Event_info
{
public:
  Init_GoToPostion_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToPostion_SendGoal_Event_request info(::px4_msgs::action::GoToPostion_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GoToPostion_SendGoal_Event_request(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::GoToPostion_SendGoal_Event>()
{
  return px4_msgs::action::builder::Init_GoToPostion_SendGoal_Event_info();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_GoToPostion_GetResult_Request_goal_id
{
public:
  Init_GoToPostion_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::px4_msgs::action::GoToPostion_GetResult_Request goal_id(::px4_msgs::action::GoToPostion_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::GoToPostion_GetResult_Request>()
{
  return px4_msgs::action::builder::Init_GoToPostion_GetResult_Request_goal_id();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_GoToPostion_GetResult_Response_result
{
public:
  explicit Init_GoToPostion_GetResult_Response_result(::px4_msgs::action::GoToPostion_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::GoToPostion_GetResult_Response result(::px4_msgs::action::GoToPostion_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_GetResult_Response msg_;
};

class Init_GoToPostion_GetResult_Response_status
{
public:
  Init_GoToPostion_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToPostion_GetResult_Response_result status(::px4_msgs::action::GoToPostion_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GoToPostion_GetResult_Response_result(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::GoToPostion_GetResult_Response>()
{
  return px4_msgs::action::builder::Init_GoToPostion_GetResult_Response_status();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_GoToPostion_GetResult_Event_response
{
public:
  explicit Init_GoToPostion_GetResult_Event_response(::px4_msgs::action::GoToPostion_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::GoToPostion_GetResult_Event response(::px4_msgs::action::GoToPostion_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_GetResult_Event msg_;
};

class Init_GoToPostion_GetResult_Event_request
{
public:
  explicit Init_GoToPostion_GetResult_Event_request(::px4_msgs::action::GoToPostion_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_GoToPostion_GetResult_Event_response request(::px4_msgs::action::GoToPostion_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GoToPostion_GetResult_Event_response(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_GetResult_Event msg_;
};

class Init_GoToPostion_GetResult_Event_info
{
public:
  Init_GoToPostion_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToPostion_GetResult_Event_request info(::px4_msgs::action::GoToPostion_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GoToPostion_GetResult_Event_request(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::GoToPostion_GetResult_Event>()
{
  return px4_msgs::action::builder::Init_GoToPostion_GetResult_Event_info();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_GoToPostion_FeedbackMessage_feedback
{
public:
  explicit Init_GoToPostion_FeedbackMessage_feedback(::px4_msgs::action::GoToPostion_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::GoToPostion_FeedbackMessage feedback(::px4_msgs::action::GoToPostion_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_FeedbackMessage msg_;
};

class Init_GoToPostion_FeedbackMessage_goal_id
{
public:
  Init_GoToPostion_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToPostion_FeedbackMessage_feedback goal_id(::px4_msgs::action::GoToPostion_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_GoToPostion_FeedbackMessage_feedback(msg_);
  }

private:
  ::px4_msgs::action::GoToPostion_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::GoToPostion_FeedbackMessage>()
{
  return px4_msgs::action::builder::Init_GoToPostion_FeedbackMessage_goal_id();
}

}  // namespace px4_msgs

#endif  // PX4_MSGS__ACTION__DETAIL__GO_TO_POSTION__BUILDER_HPP_
