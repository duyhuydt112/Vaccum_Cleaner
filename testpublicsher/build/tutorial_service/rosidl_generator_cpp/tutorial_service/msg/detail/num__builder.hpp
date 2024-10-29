// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_service:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_SERVICE__MSG__DETAIL__NUM__BUILDER_HPP_
#define TUTORIAL_SERVICE__MSG__DETAIL__NUM__BUILDER_HPP_

#include "tutorial_service/msg/detail/num__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_service
{

namespace msg
{

namespace builder
{

class Init_Num_num
{
public:
  Init_Num_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_service::msg::Num num(::tutorial_service::msg::Num::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_service::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_service::msg::Num>()
{
  return tutorial_service::msg::builder::Init_Num_num();
}

}  // namespace tutorial_service

#endif  // TUTORIAL_SERVICE__MSG__DETAIL__NUM__BUILDER_HPP_
