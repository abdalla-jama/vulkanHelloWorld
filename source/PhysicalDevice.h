//===-PhysicalDevice.h----------------------------------------------*- C++ -*-//
//
// Part of the vulkanHelloWorld project, under the MIT License.
// Copyright (c) 2020 Abdalla Jama
// This file contains the definition of the PhysicalDevice class.
//
//===----------------------------------------------------------------------===//
#ifndef VULKANHELLOWORLD_SOURCE_PHYSICALDEVICE_H_
#define VULKANHELLOWORLD_SOURCE_PHYSICALDEVICE_H_
#include <vulkan/vulkan.h>
#include <stdexcept>
#include <vector>

/// \class PhysicalDevice "PhysicalDevice.h"
/// \brief This class 
class PhysicalDevice {
 public:
  VkResult enumeratePhysicalDevices(VkInstance instance);
  void selectPhysicalDevice();
  const std::vector<VkPhysicalDevice>* getPhysicalDevices() const
  {return &device_array_;}
  const VkPhysicalDevice* getSelectedPhysicalDevice() const
  {return &selected_device_;}

 private:
  VkPhysicalDevice selected_device_{VK_NULL_HANDLE};
  std::vector<VkPhysicalDevice> device_array_{};
  bool APIVersionCheck(VkPhysicalDevice physical_device);
  bool isGraphicsSupported(VkPhysicalDevice physical_device);
};
#endif //VULKANHELLOWORLD_SOURCE_PHYSICALDEVICE_H_
