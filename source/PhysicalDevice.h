//===-PhysicalDevice.h----------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// This file contains the definition of the PhysicalDevice class.
/// \copyright Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#ifndef VULKAN_HELLO_WORLD_APP_SOURCE_PHYSICALDEVICE_H_
#define VULKAN_HELLO_WORLD_APP_SOURCE_PHYSICALDEVICE_H_
#include <vulkan/vulkan.h>
#include <stdexcept>
#include <vector>

/// \class PhysicalDevice PhysicalDevice.h "PhysicalDevice.h"
/// \brief PhysicalDevice - Represents the physical device (VkPhysicalDevice).
/// \details - PhysicalDevice initializes a primary VkPhysicalDevice with a
/// null handle and an empty array of VkPhysicalDevices. The class provides
/// facilities to enumerate all the vulkan compatible physical devices on the
/// system, set a primary device and access the devices and features. The
/// VkPhysicalDevice is an opaque handle representing the complete functionality
/// of the vulkan API for a given device. For more information on the
/// VkPhysicalDevice object see the vulkan specification at
/// https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkPhysicalDevice
class PhysicalDevice {
 public:
  VkResult enumeratePhysicalDevices(VkInstance instance);
  void setPrimaryDevice();
/// \brief setAPIVersion - Sets the API version variable.
/// \details The API version variable is initialized to 0 before the function
/// is called. The function can be used to set a minimum API version for the
/// primary device.
/// \param version - An unsigned integer with 32 bit width representing the
/// major, minor and patch numbers of the vulkan API.
  void setAPIVersion(uint32_t version) { api_version_ = version;}
/// \brief getPhysicalDevices - Provides access to a vector containing all the
/// vulkan supported devices on the system.
/// \return  const std::vector<VkPhysicalDevice>* - An immutable pointer to a
/// vector of VkPhysicalDevice objects.
  const std::vector<VkPhysicalDevice>* getPhysicalDevices() const
  {return &device_array_;}
/// \brief getPrimaryDevice - Provides access to a selected VkPhysicalDevice.
/// \details The VkPhysicalDevice variable is initialized to VK_NULL_HANDLE and
/// can be set with the setPrimaryDevice function.
/// \return const VkPhysicalDevice* - An immutable pointer to a VkPhysicalDevice
/// handle.
  const VkPhysicalDevice* getPrimaryDevice() const
  {return &primary_device_.device_;}
/// \brief getGraphicsQueueIndex - Provides access to the index of the queue
/// family that support graphics processing on the primary device.
/// \return int32_t - a signed integer with 32 bit width representing the index.
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