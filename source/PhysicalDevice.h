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
/// \brief PhysicalDevice - Represents the physical device (VkPhysicalDevice).
/// \details - The VkPhysicalDevice is an opaque handle representing the complete functionality of the vulkan API for a given device.
class PhysicalDevice {
 public:
  VkResult enumeratePhysicalDevices(VkInstance instance);
  void selectPhysicalDevice();
  void setGraphicsQueueIndex();
/// \brief setAPIVersion - Sets the API version variable.
/// \details The API version variable is initialized to 0 before the function
/// is called. The variable is used in the APIVersionCheck function.
/// \param version - A signed integer with 32 bit width representing the major,
/// minor and patch numbers of the vulkan API.
  void setAPIVersion(uint32_t version) { api_version_ = version;}
/// \brief getPhysicalDevices - Provides access to a vector containing all the
/// vulkan supported devices on the system.
/// \return  const std::vector<VkPhysicalDevice>* - An immutable pointer to a
/// vector of VkPhysicalDevice objects.
  const std::vector<VkPhysicalDevice>* getPhysicalDevices() const
  {return &device_array_;}
/// \brief getSelectedPhysicalDevice - Provides access to a VkPhysicalDevice.
/// \details The VkPhysicalDevice variable is initialized to VK_NULL_HANDLE and
/// can be set with the selectPhysicalDevice function.
/// \return const VkPhysicalDevice* - An immutable pointer to a VkPhysicalDevice
/// handle.
  const VkPhysicalDevice* getSelectedPhysicalDevice() const
  {return &selected_device_;}
/// TODO finish documentation
/// \return
  uint32_t getGraphicsQueueIndex() const {return graphics_queue_index_;}

 private:
  VkPhysicalDevice selected_device_{VK_NULL_HANDLE};
  std::vector<VkPhysicalDevice> device_array_{};
  uint32_t api_version_{0};
  int32_t graphics_queue_index_{-1};
  bool APIVersionCheck(VkPhysicalDevice physical_device) const;
  int32_t getGraphicsQueueFamilyIndex(VkPhysicalDevice physical_device);
};
#endif //VULKANHELLOWORLD_SOURCE_PHYSICALDEVICE_H_
