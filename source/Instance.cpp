//===-Instance.cpp--------------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// This file contains the implementation of the Instance class.
/// Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#include "Instance.h"

void Instance::setApplicationInfo(VkApplicationInfo* vk) {
  if (vk == nullptr) {
	app_info_ = {
		VK_STRUCTURE_TYPE_APPLICATION_INFO,
		nullptr,
		"",
		VK_MAKE_VERSION(1, 0, 0),
		"",
		VK_MAKE_VERSION(1, 0, 0),
		VK_API_VERSION_1_0
	};
  } else {
    app_info_ = *vk;
  }
}
void Instance::setCreateInfo(VkInstanceCreateInfo* vk) {
  if (vk == nullptr) {
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
  } else {
    create_info_ = *vk;
  }
}
VkResult Instance::createInstance() {
  VkResult result = vkCreateInstance(
  	&create_info_,
  	nullptr, &instance_);
  if (result) {
	throw std::runtime_error("Failed attempt to create valid VkInstance");
  }
  instance_status_ = result;
  return result;
}
void Instance::destroyInstance() {
  vkDestroyInstance(instance_, nullptr);
  instance_status_ = VK_NOT_READY;
}