// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_service:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_SERVICE__MSG__DETAIL__NUM__STRUCT_H_
#define TUTORIAL_SERVICE__MSG__DETAIL__NUM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Num in the package tutorial_service.
typedef struct tutorial_service__msg__Num
{
  int64_t num;
} tutorial_service__msg__Num;

// Struct for a sequence of tutorial_service__msg__Num.
typedef struct tutorial_service__msg__Num__Sequence
{
  tutorial_service__msg__Num * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_service__msg__Num__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_SERVICE__MSG__DETAIL__NUM__STRUCT_H_
