//===-Instance.h----------------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// This file contains the definition of the Instance class.
/// Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#ifndef VULKAN_HELLO_WORLD_APP_SOURCE_INSTANCE_H_
#define VULKAN_HELLO_WORLD_APP_SOURCE_INSTANCE_H_
#include <vulkan/vulkan.h>
#include <stdexcept>

class Instance {
 public:
  void setApplicationInfo(VkApplicationInfo* vk = nullptr);
  void setCreateInfo(VkInstanceCreateInfo* vk = nullptr);
  VkResult createInstance();
  void destroyInstance();
  const VkInstance* getVkInstance() const {return &instance_;}
  VkResult getInstanceStatus() const {return instance_status_;}
  uint32_t getAPIVersion() const {return app_info_.apiVersion;}
 private:
  VkApplicationInfo app_info_{};
  VkInstanceCreateInfo create_info_{};
  VkInstance instance_{VK_NULL_HANDLE};
  VkResult instance_status_{VK_NOT_READY};
};
#endif //VULKAN_HELLO_WORLD_APP_SOURCE_INSTANCE_H_