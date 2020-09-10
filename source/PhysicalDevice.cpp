//===-PhysicalDevice.cpp--------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// This file contains the implementation of the PhysicalDevice class.
/// Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#include "PhysicalDevice.h"

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
    throw std::runtime_error("Error occurred enumerating physical devices");
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
    throw std::runtime_error("Error occurred enumerating physical devices");
  }
  return result_2;
}
void PhysicalDevice::setPrimaryDevice() {
  if (device_array_.empty()) {
	throw std::runtime_error(
		"Error cannot select a physical device before they are enumerated");
  }
  for (auto device : device_array_) {
    int32_t index = getGraphicsQueueFamilyIndex(device);
    if (index >= 0 && APIVersionCheck(device)) {
	  primary_device_.device_ = device;
	  primary_device_.graphics_queue_index_ = index;
    }
  }
  if (primary_device_.device_ == VK_NULL_HANDLE) {
	throw std::runtime_error(
		"No device with version and graphics support is available");
  }
}
bool PhysicalDevice::APIVersionCheck(VkPhysicalDevice physical_device) const {
  if (physical_device == VK_NULL_HANDLE) {
	throw std::runtime_error("Error no VkPhysicalDevice available");
  }
  VkPhysicalDeviceProperties properties;
  vkGetPhysicalDeviceProperties(physical_device, &properties);
  return api_version_ <= properties.apiVersion;
}
// TODO refactor function to throw exception instead of returning error code and use uint32_t instead of int32_t
int32_t PhysicalDevice::getGraphicsQueueFamilyIndex(
	VkPhysicalDevice physical_device) {
  if (physical_device == VK_NULL_HANDLE) {
	throw std::runtime_error("Error no VkPhysicalDevice available");
  }
  int32_t graphics_queue_index = -1;
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
	  graphics_queue_index = i;
	  return graphics_queue_index;
	}
  }
  return graphics_queue_index;
}
