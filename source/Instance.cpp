//===-Instance.cpp--------------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// \brief This file contains the implementation of the Instance class.
/// \copyright Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#include "Instance.h"

/// \brief setApplicationInfo - Initializes and populates the member
/// VkApplicationInfo struct.
/// \details A VkApplicationInfo struct may be passed in to the function in
/// which case it is assigned to the member VkApplicationInfo struct, otherwise
/// a default set of values populates the struct.
/// \param vk (default nullptr) A pointer to a VkApplicationInfo struct.
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
/// \brief setCreateInfo - Initializes and populates the member
/// VkInstanceCreateInfo struct.
/// \details A VkInstanceCreateInfo struct may be passed in to the function in
/// which case it is assigned to the member VkApplicationInfo struct, otherwise
/// a default set of values populates the struct.
/// \param vk (default nullptr) A pointer to a VkInstanceCreateInfo struct.
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
/// \brief createInstance - Creates a new vulkan instance.
/// \details Functions as a thin wrapper for the analogous vulkan API function
/// vkCreateInstance, passing in member variables for VkApplicationInfo,
/// VkInstanceCreateInfo and the VkInstance. The instance status member is
/// updated as well. A successful call will return VK_SUCCESS.
/// \return VkResult - An enumeration of vulkan command return codes.
/// \exception std::runtime_error thrown if VK_SUCCESS not returned.
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
/// \brief destroyInstance - Destroys a vulkan instance.
/// \details Functions as a thin wrapper for the analogous vulkan API function
/// vkDestroyInstance with the member VkInstance passed in. Additionally the
/// instance status is updated as well.
void Instance::destroyInstance() {
  vkDestroyInstance(instance_, nullptr);
  instance_status_ = VK_NOT_READY;
}