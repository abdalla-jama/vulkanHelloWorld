//===-Instance.cpp--------------------------------------------------*- C++ -*-//
//
// Part of vulkanHelloWorld, under the MIT License 
// Copyright (c) 2020 Abdalla Jama
//
//===----------------------------------------------------------------------===//
//
// Implementation of Instance
//
//===----------------------------------------------------------------------===//

#include "Instance.h"

void Instance::fillApplicationInfo(VkApplicationInfo* vk) {
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
void Instance::fillCreateInfo(VkInstanceCreateInfo* vk) {
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
  instance_status_ = result;
  return result;
}
void Instance::destroyInstance() {
  vkDestroyInstance(instance_, nullptr);
}