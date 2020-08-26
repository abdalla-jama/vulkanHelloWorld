//===-Instance.cpp--------------------------------------------------*- C++ -*-//
//
// Part of the vulkanHelloWorld project, under the MIT License.
// Copyright (c) 2020 Abdalla Jama.
// This file contains the implementation of the Instance class.
//
//===----------------------------------------------------------------------===//
#include "Instance.h"

/// \brief This function initializes the app_info_ variable by populating a
/// VkApplicationInfo struct.
/// \details A VkApplicationInfo struct is passed in and filled with a default
/// set of values or with the values provided by vk. The struct is assigned to
/// app_info_
/// \param vk (default nullptr) A pointer to a VkApplicationInfo struct.
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
/// \brief This function initializes the create_info_ variable by populating a
/// VkInstanceCreateInfo struct.
/// \details A VkInstanceCreateInfo struct is passed in and filled with a
/// default set of values or with the values provided by vk. The struct is assigned to
/// create_info_
/// \param vk (default nullptr) A pointer to a VkInstanceCreateInfo struct.
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