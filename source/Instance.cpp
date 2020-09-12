//===-Instance.cpp--------------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// This file contains the implementation of the Instance class.
/// Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#include "Instance.h"
vk::Instance::Instance() {
  app_info_ = {
	  VK_STRUCTURE_TYPE_APPLICATION_INFO,
	  nullptr,
	  "",
	  VK_MAKE_VERSION(1, 0, 0),
	  "",
	  VK_MAKE_VERSION(1, 0, 0),
	  VK_API_VERSION_1_0
  };
  create_info_ = {
	  VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
	  nullptr,
	  0,
	  &app_info_,
	  0,
	  nullptr,
	  0,
	  nullptr
  };
}
vk::Instance::~Instance() {
  if (valid_) {
    destroy();
  }
}
VkResult vk::Instance::create() {
  if (valid_) {
	throw std::runtime_error("Error instance was already created");
  }
  VkResult result = vkCreateInstance(
  	&create_info_,
  	nullptr, &instance_);
  if (result) {
	throw std::runtime_error("Failed attempt to create valid VkInstance");
  }
  valid_ = true;
  return result;
}
void vk::Instance::destroy() {
  if (!valid_) {
	throw std::runtime_error("Error instance has not been created or has"
						  "already been destroyed");
  }
  vkDestroyInstance(instance_, nullptr);
  valid_ = false;
}
