//===-PhysicalDevice.h----------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// This file contains the definition of the PhysicalDevice class.
/// Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#ifndef VULKAN_HELLO_WORLD_APP_SOURCE_PHYSICALDEVICE_H_
#define VULKAN_HELLO_WORLD_APP_SOURCE_PHYSICALDEVICE_H_
#include <vulkan/vulkan.h>
#include <stdexcept>
#include <vector>

class PhysicalDevice {
 public:
  VkResult enumeratePhysicalDevices(VkInstance instance);
  void setPrimaryDevice();
  void setAPIVersion(uint32_t version) { api_version_ = version;}
  const std::vector<VkPhysicalDevice>* getPhysicalDevices() const
  {return &device_array_;}
  const VkPhysicalDevice* getPrimaryDevice() const
  {return &primary_device_.device_;}
  int32_t getGraphicsQueueIndex() const
  {return primary_device_.graphics_queue_index_;}
 private:
  struct PrimaryDevice {
	VkPhysicalDevice device_{VK_NULL_HANDLE};
	int32_t graphics_queue_index_{-1};
  } primary_device_;
  std::vector<VkPhysicalDevice> device_array_{};
  uint32_t api_version_{0};
  bool APIVersionCheck(VkPhysicalDevice physical_device) const;
  int32_t getGraphicsQueueFamilyIndex(VkPhysicalDevice physical_device);
};
#endif //VULKAN_HELLO_WORLD_APP_SOURCE_PHYSICALDEVICE_H_