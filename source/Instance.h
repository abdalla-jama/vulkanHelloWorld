//===-Instance.h----------------------------------------------------*- C++ -*-//
//
// Part of the vulkanHelloWorld project, under the MIT License.
// Copyright (c) 2020 Abdalla Jama.
// This file contains the definition of the Instance class.
//
//===----------------------------------------------------------------------===//
#ifndef VULKANHELLOWORLD_SOURCE_INSTANCE_H_
#define VULKANHELLOWORLD_SOURCE_INSTANCE_H_
#include <vulkan/vulkan.h>

/// \class Instance "Instance.h"
/// \brief This class represents the vulkan instance (VkInstance)
/// \details The class initializes a VkInstance to a null handle. Additionally
/// it provides all the methods needed to create a valid VkInstance. The
/// VkInstance can also be accessed through a getter.
class Instance {
 public:
  void fillApplicationInfo(VkApplicationInfo* vk = nullptr);
  void fillCreateInfo(VkInstanceCreateInfo* vk = nullptr);
  VkResult createInstance();
  void destroyInstance();
  //TODO getter function for instance_
  VkResult getInstanceStatus() const {return instance_status_;}
 private:
  VkApplicationInfo app_info_{};
  VkInstanceCreateInfo create_info_{};
  VkInstance instance_{VK_NULL_HANDLE};
  VkResult instance_status_{VK_NOT_READY};
};
#endif //VULKANHELLOWORLD_SOURCE_INSTANCE_H_