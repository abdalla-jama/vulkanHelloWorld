//===-PhysicalDevice.cpp--------------------------------------------*- C++ -*-//
//
// Part of the vulkanHelloWorld project, under the MIT License.
// Copyright (c) 2020 Abdalla Jama.
// This file contains the implementation of the PhysicalDevice class.
//
//===----------------------------------------------------------------------===//
#include "PhysicalDevice.h"

/// \brief enumeratePhysicalDevices - Exposes vulkan supported devices to the
/// application.
/// \details The function performs a null check on its argument, throwing a
/// runtime exception if the check fails. The rest of the function uses the
/// analogous Vulkan API function vkEnumeratePhysicalDevices twice, calling it
/// the first time with a nullptr as the third argument. This call provides the
/// number of vulkan supported devices, if the number is zero a runtime
/// exception is thrown. A vector is resized to the number of devices available.
/// The vkEnumeratePhysicalDevices function is called again with the address of
/// the first element of the vector as the third argument. Each element in the
/// vector is filled with a VkPhysicalDevice object. If either of the API
/// function calls do not return VK_SUCCESS a runtime exception is thrown.
/// \param instance - A valid VkInstance object.
/// \return VkResult - An enumeration of vulkan command return codes.
VkResult PhysicalDevice::enumeratePhysicalDevices(VkInstance instance) {
  if (instance == VK_NULL_HANDLE) {
    throw std::runtime_error("No valid vulkan instance available!");
  }
  uint32_t num_devices{0};
  VkResult result_1 = vkEnumeratePhysicalDevices(
  	instance,
  	&num_devices,
  	nullptr);
  if (result_1 != VK_SUCCESS) {
    throw std::runtime_error("Error occurred enumerating physical device");
  }
  if (num_devices == 0) {
    throw std::runtime_error("No devices with vulkan support available");
  }
  device_array_.resize(num_devices);
  VkResult result_2 = vkEnumeratePhysicalDevices(
  	instance,
  	&num_devices,
  	device_array_.data());
  if (result_2 != VK_SUCCESS) {
    throw std::runtime_error("Error occurred enumerating physical device");
  }
  return result_2;
}
void PhysicalDevice::selectPhysicalDevice() {
  for (auto device : device_array_) {
    if (APIVersionCheck(device) && isGraphicsSupported(device)) {
      selected_device_ = device;
    }
  }
  if (selected_device_ == VK_NULL_HANDLE) {
	throw std::runtime_error(
		"No device with version and graphics support is available");
  }
}
bool PhysicalDevice::APIVersionCheck(VkPhysicalDevice physical_device) {
  VkPhysicalDeviceProperties properties;
  vkGetPhysicalDeviceProperties(physical_device, &properties);
  uint32_t version = VK_VERSION_MAJOR(properties.apiVersion);
  if (version < 1) {
	return false;
  }
  return true;
}
/// \brief isGraphicsSupported - Checks if graphics processing is supported on
/// any queue family of a given device.
/// \details
/// \param physical_device
/// \return
bool PhysicalDevice::isGraphicsSupported(VkPhysicalDevice physical_device) {
  uint32_t queue_family_count{0};
  vkGetPhysicalDeviceQueueFamilyProperties(
	  physical_device,
	  &queue_family_count,
	  nullptr);
  if (queue_family_count == 0) {
	throw std::runtime_error("Error occurred selecting physical device");
  }
  std::vector<VkQueueFamilyProperties>
	  queue_family_properties(queue_family_count);
  vkGetPhysicalDeviceQueueFamilyProperties(
	  physical_device,
	  &queue_family_count,
	  queue_family_properties.data());
  for (uint32_t i = 0; i < queue_family_count; i++) {
	if (queue_family_properties[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
	  return true;
	}
  }
  return false;
}
