// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:srv/Polygon.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__SRV__DETAIL__POLYGON__STRUCT_H_
#define TUTORIAL_INTERFACES__SRV__DETAIL__POLYGON__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Polygon in the package tutorial_interfaces.
typedef struct tutorial_interfaces__srv__Polygon_Request
{
  int64_t n;
} tutorial_interfaces__srv__Polygon_Request;

// Struct for a sequence of tutorial_interfaces__srv__Polygon_Request.
typedef struct tutorial_interfaces__srv__Polygon_Request__Sequence
{
  tutorial_interfaces__srv__Polygon_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__srv__Polygon_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Polygon in the package tutorial_interfaces.
typedef struct tutorial_interfaces__srv__Polygon_Response
{
  bool success;
} tutorial_interfaces__srv__Polygon_Response;

// Struct for a sequence of tutorial_interfaces__srv__Polygon_Response.
typedef struct tutorial_interfaces__srv__Polygon_Response__Sequence
{
  tutorial_interfaces__srv__Polygon_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__srv__Polygon_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__SRV__DETAIL__POLYGON__STRUCT_H_
