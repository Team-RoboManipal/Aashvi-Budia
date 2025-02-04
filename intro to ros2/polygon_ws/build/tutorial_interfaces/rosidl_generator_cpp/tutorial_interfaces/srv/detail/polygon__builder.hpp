// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:srv/Polygon.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__SRV__DETAIL__POLYGON__BUILDER_HPP_
#define TUTORIAL_INTERFACES__SRV__DETAIL__POLYGON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tutorial_interfaces/srv/detail/polygon__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tutorial_interfaces
{

namespace srv
{

namespace builder
{

class Init_Polygon_Request_n
{
public:
  Init_Polygon_Request_n()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::srv::Polygon_Request n(::tutorial_interfaces::srv::Polygon_Request::_n_type arg)
  {
    msg_.n = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::srv::Polygon_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::srv::Polygon_Request>()
{
  return tutorial_interfaces::srv::builder::Init_Polygon_Request_n();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace srv
{

namespace builder
{

class Init_Polygon_Response_success
{
public:
  Init_Polygon_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::srv::Polygon_Response success(::tutorial_interfaces::srv::Polygon_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::srv::Polygon_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::srv::Polygon_Response>()
{
  return tutorial_interfaces::srv::builder::Init_Polygon_Response_success();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__SRV__DETAIL__POLYGON__BUILDER_HPP_
