//===-DeviceInstance.cpp--------------------------------------------*- C++ -*-//
//
// Part of vulkanHelloWorld, under the MIT License 
// Copyright (c) 2020 Abdalla Jama
//
//===----------------------------------------------------------------------===//
//
// Implementation of DeviceInstance
//
//===----------------------------------------------------------------------===//

#include "DeviceInstance.h"

void DeviceInstance::createInstance() {
  fillApplicationInfo();
  fillCreateInfo();
  VkResult result = vkCreateInstance(&create_info_, nullptr, &instance_);
  instance_status_ = result;
}
void DeviceInstance::fillApplicationInfo() {
  app_info_ = {
	  VK_STRUCTURE_TYPE_APPLICATION_INFO,
	  nullptr,
	  "Vulkan Hello World",
	  VK_MAKE_VERSION(1,0,0),
	  "Vulkan Base Engine",
	  VK_MAKE_VERSION(1,0,0),
	  VK_API_VERSION_1_0
  };
}
void DeviceInstance::fillCreateInfo() {
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
DeviceInstance::~DeviceInstance() {
  destroyInstance();
}
void DeviceInstance::destroyInstance() {
  vkDestroyInstance(instance_, nullptr);
}