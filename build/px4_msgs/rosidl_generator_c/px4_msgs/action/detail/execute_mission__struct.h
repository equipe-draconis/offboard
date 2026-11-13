// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4_msgs:action/ExecuteMission.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "px4_msgs/action/execute_mission.h"


#ifndef PX4_MSGS__ACTION__DETAIL__EXECUTE_MISSION__STRUCT_H_
#define PX4_MSGS__ACTION__DETAIL__EXECUTE_MISSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/ExecuteMission in the package px4_msgs.
typedef struct px4_msgs__action__ExecuteMission_Goal
{
  bool start;
} px4_msgs__action__ExecuteMission_Goal;

// Struct for a sequence of px4_msgs__action__ExecuteMission_Goal.
typedef struct px4_msgs__action__ExecuteMission_Goal__Sequence
{
  px4_msgs__action__ExecuteMission_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__ExecuteMission_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteMission in the package px4_msgs.
typedef struct px4_msgs__action__ExecuteMission_Result
{
  bool success;
  rosidl_runtime_c__String message;
} px4_msgs__action__ExecuteMission_Result;

// Struct for a sequence of px4_msgs__action__ExecuteMission_Result.
typedef struct px4_msgs__action__ExecuteMission_Result__Sequence
{
  px4_msgs__action__ExecuteMission_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__ExecuteMission_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'current_state'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteMission in the package px4_msgs.
typedef struct px4_msgs__action__ExecuteMission_Feedback
{
  rosidl_runtime_c__String current_state;
  float progress;
} px4_msgs__action__ExecuteMission_Feedback;

// Struct for a sequence of px4_msgs__action__ExecuteMission_Feedback.
typedef struct px4_msgs__action__ExecuteMission_Feedback__Sequence
{
  px4_msgs__action__ExecuteMission_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__ExecuteMission_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "px4_msgs/action/detail/execute_mission__struct.h"

/// Struct defined in action/ExecuteMission in the package px4_msgs.
typedef struct px4_msgs__action__ExecuteMission_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  px4_msgs__action__ExecuteMission_Goal goal;
} px4_msgs__action__ExecuteMission_SendGoal_Request;

// Struct for a sequence of px4_msgs__action__ExecuteMission_SendGoal_Request.
typedef struct px4_msgs__action__ExecuteMission_SendGoal_Request__Sequence
{
  px4_msgs__action__ExecuteMission_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__ExecuteMission_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ExecuteMission in the package px4_msgs.
typedef struct px4_msgs__action__ExecuteMission_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} px4_msgs__action__ExecuteMission_SendGoal_Response;

// Struct for a sequence of px4_msgs__action__ExecuteMission_SendGoal_Response.
typedef struct px4_msgs__action__ExecuteMission_SendGoal_Response__Sequence
{
  px4_msgs__action__ExecuteMission_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__ExecuteMission_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  px4_msgs__action__ExecuteMission_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  px4_msgs__action__ExecuteMission_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ExecuteMission in the package px4_msgs.
typedef struct px4_msgs__action__ExecuteMission_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  px4_msgs__action__ExecuteMission_SendGoal_Request__Sequence request;
  px4_msgs__action__ExecuteMission_SendGoal_Response__Sequence response;
} px4_msgs__action__ExecuteMission_SendGoal_Event;

// Struct for a sequence of px4_msgs__action__ExecuteMission_SendGoal_Event.
typedef struct px4_msgs__action__ExecuteMission_SendGoal_Event__Sequence
{
  px4_msgs__action__ExecuteMission_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__ExecuteMission_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ExecuteMission in the package px4_msgs.
typedef struct px4_msgs__action__ExecuteMission_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} px4_msgs__action__ExecuteMission_GetResult_Request;

// Struct for a sequence of px4_msgs__action__ExecuteMission_GetResult_Request.
typedef struct px4_msgs__action__ExecuteMission_GetResult_Request__Sequence
{
  px4_msgs__action__ExecuteMission_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__ExecuteMission_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "px4_msgs/action/detail/execute_mission__struct.h"

/// Struct defined in action/ExecuteMission in the package px4_msgs.
typedef struct px4_msgs__action__ExecuteMission_GetResult_Response
{
  int8_t status;
  px4_msgs__action__ExecuteMission_Result result;
} px4_msgs__action__ExecuteMission_GetResult_Response;

// Struct for a sequence of px4_msgs__action__ExecuteMission_GetResult_Response.
typedef struct px4_msgs__action__ExecuteMission_GetResult_Response__Sequence
{
  px4_msgs__action__ExecuteMission_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__ExecuteMission_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  px4_msgs__action__ExecuteMission_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  px4_msgs__action__ExecuteMission_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ExecuteMission in the package px4_msgs.
typedef struct px4_msgs__action__ExecuteMission_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  px4_msgs__action__ExecuteMission_GetResult_Request__Sequence request;
  px4_msgs__action__ExecuteMission_GetResult_Response__Sequence response;
} px4_msgs__action__ExecuteMission_GetResult_Event;

// Struct for a sequence of px4_msgs__action__ExecuteMission_GetResult_Event.
typedef struct px4_msgs__action__ExecuteMission_GetResult_Event__Sequence
{
  px4_msgs__action__ExecuteMission_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__ExecuteMission_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "px4_msgs/action/detail/execute_mission__struct.h"

/// Struct defined in action/ExecuteMission in the package px4_msgs.
typedef struct px4_msgs__action__ExecuteMission_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  px4_msgs__action__ExecuteMission_Feedback feedback;
} px4_msgs__action__ExecuteMission_FeedbackMessage;

// Struct for a sequence of px4_msgs__action__ExecuteMission_FeedbackMessage.
typedef struct px4_msgs__action__ExecuteMission_FeedbackMessage__Sequence
{
  px4_msgs__action__ExecuteMission_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__ExecuteMission_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4_MSGS__ACTION__DETAIL__EXECUTE_MISSION__STRUCT_H_
