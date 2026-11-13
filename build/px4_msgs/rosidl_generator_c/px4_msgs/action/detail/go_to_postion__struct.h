// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4_msgs:action/GoToPostion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "px4_msgs/action/go_to_postion.h"


#ifndef PX4_MSGS__ACTION__DETAIL__GO_TO_POSTION__STRUCT_H_
#define PX4_MSGS__ACTION__DETAIL__GO_TO_POSTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/GoToPostion in the package px4_msgs.
typedef struct px4_msgs__action__GoToPostion_Goal
{
  float x;
  float y;
  float z;
} px4_msgs__action__GoToPostion_Goal;

// Struct for a sequence of px4_msgs__action__GoToPostion_Goal.
typedef struct px4_msgs__action__GoToPostion_Goal__Sequence
{
  px4_msgs__action__GoToPostion_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__GoToPostion_Goal__Sequence;

// Constants defined in the message

/// Struct defined in action/GoToPostion in the package px4_msgs.
typedef struct px4_msgs__action__GoToPostion_Result
{
  bool success;
} px4_msgs__action__GoToPostion_Result;

// Struct for a sequence of px4_msgs__action__GoToPostion_Result.
typedef struct px4_msgs__action__GoToPostion_Result__Sequence
{
  px4_msgs__action__GoToPostion_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__GoToPostion_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/GoToPostion in the package px4_msgs.
typedef struct px4_msgs__action__GoToPostion_Feedback
{
  float current_x;
  float current_y;
  float current_z;
} px4_msgs__action__GoToPostion_Feedback;

// Struct for a sequence of px4_msgs__action__GoToPostion_Feedback.
typedef struct px4_msgs__action__GoToPostion_Feedback__Sequence
{
  px4_msgs__action__GoToPostion_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__GoToPostion_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "px4_msgs/action/detail/go_to_postion__struct.h"

/// Struct defined in action/GoToPostion in the package px4_msgs.
typedef struct px4_msgs__action__GoToPostion_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  px4_msgs__action__GoToPostion_Goal goal;
} px4_msgs__action__GoToPostion_SendGoal_Request;

// Struct for a sequence of px4_msgs__action__GoToPostion_SendGoal_Request.
typedef struct px4_msgs__action__GoToPostion_SendGoal_Request__Sequence
{
  px4_msgs__action__GoToPostion_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__GoToPostion_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/GoToPostion in the package px4_msgs.
typedef struct px4_msgs__action__GoToPostion_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} px4_msgs__action__GoToPostion_SendGoal_Response;

// Struct for a sequence of px4_msgs__action__GoToPostion_SendGoal_Response.
typedef struct px4_msgs__action__GoToPostion_SendGoal_Response__Sequence
{
  px4_msgs__action__GoToPostion_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__GoToPostion_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  px4_msgs__action__GoToPostion_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  px4_msgs__action__GoToPostion_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/GoToPostion in the package px4_msgs.
typedef struct px4_msgs__action__GoToPostion_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  px4_msgs__action__GoToPostion_SendGoal_Request__Sequence request;
  px4_msgs__action__GoToPostion_SendGoal_Response__Sequence response;
} px4_msgs__action__GoToPostion_SendGoal_Event;

// Struct for a sequence of px4_msgs__action__GoToPostion_SendGoal_Event.
typedef struct px4_msgs__action__GoToPostion_SendGoal_Event__Sequence
{
  px4_msgs__action__GoToPostion_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__GoToPostion_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/GoToPostion in the package px4_msgs.
typedef struct px4_msgs__action__GoToPostion_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} px4_msgs__action__GoToPostion_GetResult_Request;

// Struct for a sequence of px4_msgs__action__GoToPostion_GetResult_Request.
typedef struct px4_msgs__action__GoToPostion_GetResult_Request__Sequence
{
  px4_msgs__action__GoToPostion_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__GoToPostion_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "px4_msgs/action/detail/go_to_postion__struct.h"

/// Struct defined in action/GoToPostion in the package px4_msgs.
typedef struct px4_msgs__action__GoToPostion_GetResult_Response
{
  int8_t status;
  px4_msgs__action__GoToPostion_Result result;
} px4_msgs__action__GoToPostion_GetResult_Response;

// Struct for a sequence of px4_msgs__action__GoToPostion_GetResult_Response.
typedef struct px4_msgs__action__GoToPostion_GetResult_Response__Sequence
{
  px4_msgs__action__GoToPostion_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__GoToPostion_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  px4_msgs__action__GoToPostion_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  px4_msgs__action__GoToPostion_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/GoToPostion in the package px4_msgs.
typedef struct px4_msgs__action__GoToPostion_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  px4_msgs__action__GoToPostion_GetResult_Request__Sequence request;
  px4_msgs__action__GoToPostion_GetResult_Response__Sequence response;
} px4_msgs__action__GoToPostion_GetResult_Event;

// Struct for a sequence of px4_msgs__action__GoToPostion_GetResult_Event.
typedef struct px4_msgs__action__GoToPostion_GetResult_Event__Sequence
{
  px4_msgs__action__GoToPostion_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__GoToPostion_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "px4_msgs/action/detail/go_to_postion__struct.h"

/// Struct defined in action/GoToPostion in the package px4_msgs.
typedef struct px4_msgs__action__GoToPostion_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  px4_msgs__action__GoToPostion_Feedback feedback;
} px4_msgs__action__GoToPostion_FeedbackMessage;

// Struct for a sequence of px4_msgs__action__GoToPostion_FeedbackMessage.
typedef struct px4_msgs__action__GoToPostion_FeedbackMessage__Sequence
{
  px4_msgs__action__GoToPostion_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__action__GoToPostion_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4_MSGS__ACTION__DETAIL__GO_TO_POSTION__STRUCT_H_
