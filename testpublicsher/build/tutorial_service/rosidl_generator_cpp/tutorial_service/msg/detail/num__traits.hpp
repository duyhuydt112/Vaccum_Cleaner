// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tutorial_service:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_SERVICE__MSG__DETAIL__NUM__TRAITS_HPP_
#define TUTORIAL_SERVICE__MSG__DETAIL__NUM__TRAITS_HPP_

#include "tutorial_service/msg/detail/num__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tutorial_service::msg::Num>()
{
  return "tutorial_service::msg::Num";
}

template<>
inline const char * name<tutorial_service::msg::Num>()
{
  return "tutorial_service/msg/Num";
}

template<>
struct has_fixed_size<tutorial_service::msg::Num>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tutorial_service::msg::Num>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tutorial_service::msg::Num>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TUTORIAL_SERVICE__MSG__DETAIL__NUM__TRAITS_HPP_
