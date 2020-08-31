//===-PhysicalDevice.h----------------------------------------------*- C++ -*-//
//
/// Part of the vulkanHelloWorldApp.
/// This file contains the definition of the PhysicalDevice class.
/// \copyright Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#ifndef VULKANHELLOWORLD_SOURCE_PHYSICALDEVICE_H_
#define VULKANHELLOWORLD_SOURCE_PHYSICALDEVICE_H_
#include <vulkan/vulkan.h>
#include <stdexcept>
#include <vector>

/// \class PhysicalDevice PhysicalDevice.h "PhysicalDevice.h"
/// \brief This class 
class PhysicalDevice {
 public:
  VkResult enumeratePhysicalDevices(VkInstance instance);
  void selectPhysicalDevice();
  void setAPIVersion(uint32_t version) { api_version_ = version;}
  const std::vector<VkPhysicalDevice>* getPhysicalDevices() const
  {return &device_array_;}
  const VkPhysicalDevice* getSelectedPhysicalDevice() const
  {return &selected_device_;}

 private:
  VkPhysicalDevice selected_device_{VK_NULL_HANDLE};
  std::vector<VkPhysicalDevice> device_array_{};
  uint32_t api_version_{0};
//  uint32_t queue_family
  bool APIVersionCheck(VkPhysicalDevice physical_device) const;
  uint32_t getGraphicsQueueFamilyIndex(VkPhysicalDevice physical_device);
};
#endif //VULKANHELLOWORLD_SOURCE_PHYSICALDEVICE_H_
