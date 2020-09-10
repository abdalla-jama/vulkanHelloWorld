//===-LogicalDevice.h-----------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// This file contains the definition of the LogicalDevice class.
/// Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#ifndef VULKAN_HELLO_WORLD_APP_SOURCE_LOGICALDEVICE_H_
#define VULKAN_HELLO_WORLD_APP_SOURCE_LOGICALDEVICE_H_
#include <vulkan/vulkan.h>
#include <vector>

class LogicalDevice {
 public:
  void setQueueInfo();
  void setCreateInfo();
  VkResult createLogicalDevice();
  void destroyLogicalDevice();
  const VkDevice* getVkDevice() const {return &device_;}
 private:
  VkDeviceQueueCreateInfo queue_info_{};
  VkDeviceCreateInfo create_info_{};
  std::vector<float> queue_priorities_{1.0f};
  VkDevice device_{VK_NULL_HANDLE};
};
#endif //VULKAN_HELLO_WORLD_APP_SOURCE_LOGICALDEVICE_H_
