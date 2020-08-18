//===-DeviceInstance.h----------------------------------------------*- C++ -*-//
//
// Part of vulkanHelloWorld, under the MIT License 
// Copyright (c) 2020 Abdalla Jama
//
//===----------------------------------------------------------------------===//
//
// This class represents the vulkan instance
//
//===----------------------------------------------------------------------===//

#ifndef VULKANHELLOWORLD_SOURCE_DEVICEINSTANCE_H_
#define VULKANHELLOWORLD_SOURCE_DEVICEINSTANCE_H_
#include <vulkan/vulkan.h>

class DeviceInstance {
 public:
  void fillApplicationInfo(VkApplicationInfo*);
  void fillCreateInfo(VkInstanceCreateInfo*);
  void createInstance();
  void destroyInstance();
  const VkApplicationInfo* getApplicationInfo() const {return &app_info_;}
  VkResult getInstanceStatus() const {return instance_status_;}
 private:
  VkApplicationInfo app_info_{};
  VkInstanceCreateInfo create_info_{};
  VkInstance instance_{VK_NULL_HANDLE};
  VkResult instance_status_{VK_NOT_READY};
};
#endif //VULKANHELLOWORLD_SOURCE_DEVICEINSTANCE_H_