// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_service:msg/Sphere.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_SERVICE__MSG__DETAIL__SPHERE__BUILDER_HPP_
#define TUTORIAL_SERVICE__MSG__DETAIL__SPHERE__BUILDER_HPP_

#include "tutorial_service/msg/detail/sphere__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_service
{

namespace msg
{

namespace builder
{

class Init_Sphere_radius
{
public:
  explicit Init_Sphere_radius(::tutorial_service::msg::Sphere & msg)
  : msg_(msg)
  {}
  ::tutorial_service::msg::Sphere radius(::tutorial_service::msg::Sphere::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_service::msg::Sphere msg_;
};

class Init_Sphere_center
{
public:
  Init_Sphere_center()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sphere_radius center(::tutorial_service::msg::Sphere::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_Sphere_radius(msg_);
  }

private:
  ::tutorial_service::msg::Sphere msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_service::msg::Sphere>()
{
  return tutorial_service::msg::builder::Init_Sphere_center();
}

}  // namespace tutorial_service

#endif  // TUTORIAL_SERVICE__MSG__DETAIL__SPHERE__BUILDER_HPP_
