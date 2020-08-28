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
  VkResult catalogPhysicalDevices(VkInstance instance);

 private:
  VkPhysicalDevice selected_device_{VK_NULL_HANDLE};
  std::vector<VkPhysicalDevice> device_array_{};

};
#endif //VULKANHELLOWORLD_SOURCE_PHYSICALDEVICE_H_
