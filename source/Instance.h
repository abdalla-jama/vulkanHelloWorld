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

namespace vk {
class Instance {
 public:
  Instance();
  ~Instance();
  VkResult create();
  void destroy();
  void setApplicationInfo(const VkApplicationInfo &vai) { app_info_ = vai; }
  void setCreateInfo(const VkInstanceCreateInfo &vici) { create_info_ = vici; }
  uint32_t getAPIVersion() const { return app_info_.apiVersion; }
  VkInstance operator*() { return instance_; }
  bool isInstanceValid() const {return valid_;}
 private:
  VkApplicationInfo app_info_{};
  VkInstanceCreateInfo create_info_{};
  VkInstance instance_{VK_NULL_HANDLE};
  bool valid_{false};
};
}
#endif //VULKAN_HELLO_WORLD_APP_SOURCE_INSTANCE_H_