// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from px4_msgs:action/ExecuteMission.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "px4_msgs/action/execute_mission.hpp"


#ifndef PX4_MSGS__ACTION__DETAIL__EXECUTE_MISSION__BUILDER_HPP_
#define PX4_MSGS__ACTION__DETAIL__EXECUTE_MISSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "px4_msgs/action/detail/execute_mission__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_Goal_start
{
public:
  Init_ExecuteMission_Goal_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::px4_msgs::action::ExecuteMission_Goal start(::px4_msgs::action::ExecuteMission_Goal::_start_type arg)
  {
    msg_.start = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::ExecuteMission_Goal>()
{
  return px4_msgs::action::builder::Init_ExecuteMission_Goal_start();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_Result_message
{
public:
  explicit Init_ExecuteMission_Result_message(::px4_msgs::action::ExecuteMission_Result & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::ExecuteMission_Result message(::px4_msgs::action::ExecuteMission_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_Result msg_;
};

class Init_ExecuteMission_Result_success
{
public:
  Init_ExecuteMission_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_Result_message success(::px4_msgs::action::ExecuteMission_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ExecuteMission_Result_message(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::ExecuteMission_Result>()
{
  return px4_msgs::action::builder::Init_ExecuteMission_Result_success();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_Feedback_progress
{
public:
  explicit Init_ExecuteMission_Feedback_progress(::px4_msgs::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::ExecuteMission_Feedback progress(::px4_msgs::action::ExecuteMission_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_current_state
{
public:
  Init_ExecuteMission_Feedback_current_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_Feedback_progress current_state(::px4_msgs::action::ExecuteMission_Feedback::_current_state_type arg)
  {
    msg_.current_state = std::move(arg);
    return Init_ExecuteMission_Feedback_progress(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::ExecuteMission_Feedback>()
{
  return px4_msgs::action::builder::Init_ExecuteMission_Feedback_current_state();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_SendGoal_Request_goal
{
public:
  explicit Init_ExecuteMission_SendGoal_Request_goal(::px4_msgs::action::ExecuteMission_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::ExecuteMission_SendGoal_Request goal(::px4_msgs::action::ExecuteMission_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_SendGoal_Request msg_;
};

class Init_ExecuteMission_SendGoal_Request_goal_id
{
public:
  Init_ExecuteMission_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_SendGoal_Request_goal goal_id(::px4_msgs::action::ExecuteMission_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteMission_SendGoal_Request_goal(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::ExecuteMission_SendGoal_Request>()
{
  return px4_msgs::action::builder::Init_ExecuteMission_SendGoal_Request_goal_id();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_SendGoal_Response_stamp
{
public:
  explicit Init_ExecuteMission_SendGoal_Response_stamp(::px4_msgs::action::ExecuteMission_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::ExecuteMission_SendGoal_Response stamp(::px4_msgs::action::ExecuteMission_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_SendGoal_Response msg_;
};

class Init_ExecuteMission_SendGoal_Response_accepted
{
public:
  Init_ExecuteMission_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_SendGoal_Response_stamp accepted(::px4_msgs::action::ExecuteMission_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ExecuteMission_SendGoal_Response_stamp(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::ExecuteMission_SendGoal_Response>()
{
  return px4_msgs::action::builder::Init_ExecuteMission_SendGoal_Response_accepted();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_SendGoal_Event_response
{
public:
  explicit Init_ExecuteMission_SendGoal_Event_response(::px4_msgs::action::ExecuteMission_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::ExecuteMission_SendGoal_Event response(::px4_msgs::action::ExecuteMission_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_SendGoal_Event msg_;
};

class Init_ExecuteMission_SendGoal_Event_request
{
public:
  explicit Init_ExecuteMission_SendGoal_Event_request(::px4_msgs::action::ExecuteMission_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_SendGoal_Event_response request(::px4_msgs::action::ExecuteMission_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ExecuteMission_SendGoal_Event_response(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_SendGoal_Event msg_;
};

class Init_ExecuteMission_SendGoal_Event_info
{
public:
  Init_ExecuteMission_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_SendGoal_Event_request info(::px4_msgs::action::ExecuteMission_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ExecuteMission_SendGoal_Event_request(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::ExecuteMission_SendGoal_Event>()
{
  return px4_msgs::action::builder::Init_ExecuteMission_SendGoal_Event_info();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_GetResult_Request_goal_id
{
public:
  Init_ExecuteMission_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::px4_msgs::action::ExecuteMission_GetResult_Request goal_id(::px4_msgs::action::ExecuteMission_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::ExecuteMission_GetResult_Request>()
{
  return px4_msgs::action::builder::Init_ExecuteMission_GetResult_Request_goal_id();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_GetResult_Response_result
{
public:
  explicit Init_ExecuteMission_GetResult_Response_result(::px4_msgs::action::ExecuteMission_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::ExecuteMission_GetResult_Response result(::px4_msgs::action::ExecuteMission_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_GetResult_Response msg_;
};

class Init_ExecuteMission_GetResult_Response_status
{
public:
  Init_ExecuteMission_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_GetResult_Response_result status(::px4_msgs::action::ExecuteMission_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ExecuteMission_GetResult_Response_result(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::ExecuteMission_GetResult_Response>()
{
  return px4_msgs::action::builder::Init_ExecuteMission_GetResult_Response_status();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_GetResult_Event_response
{
public:
  explicit Init_ExecuteMission_GetResult_Event_response(::px4_msgs::action::ExecuteMission_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::ExecuteMission_GetResult_Event response(::px4_msgs::action::ExecuteMission_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_GetResult_Event msg_;
};

class Init_ExecuteMission_GetResult_Event_request
{
public:
  explicit Init_ExecuteMission_GetResult_Event_request(::px4_msgs::action::ExecuteMission_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_GetResult_Event_response request(::px4_msgs::action::ExecuteMission_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ExecuteMission_GetResult_Event_response(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_GetResult_Event msg_;
};

class Init_ExecuteMission_GetResult_Event_info
{
public:
  Init_ExecuteMission_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_GetResult_Event_request info(::px4_msgs::action::ExecuteMission_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ExecuteMission_GetResult_Event_request(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::ExecuteMission_GetResult_Event>()
{
  return px4_msgs::action::builder::Init_ExecuteMission_GetResult_Event_info();
}

}  // namespace px4_msgs


namespace px4_msgs
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_FeedbackMessage_feedback
{
public:
  explicit Init_ExecuteMission_FeedbackMessage_feedback(::px4_msgs::action::ExecuteMission_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::px4_msgs::action::ExecuteMission_FeedbackMessage feedback(::px4_msgs::action::ExecuteMission_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_FeedbackMessage msg_;
};

class Init_ExecuteMission_FeedbackMessage_goal_id
{
public:
  Init_ExecuteMission_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_FeedbackMessage_feedback goal_id(::px4_msgs::action::ExecuteMission_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteMission_FeedbackMessage_feedback(msg_);
  }

private:
  ::px4_msgs::action::ExecuteMission_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::action::ExecuteMission_FeedbackMessage>()
{
  return px4_msgs::action::builder::Init_ExecuteMission_FeedbackMessage_goal_id();
}

}  // namespace px4_msgs

#endif  // PX4_MSGS__ACTION__DETAIL__EXECUTE_MISSION__BUILDER_HPP_
