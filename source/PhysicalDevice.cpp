//===-PhysicalDevice.cpp--------------------------------------------*- C++ -*-//
//
/// Part of the vulkanHelloWorldApp.
/// This file contains the implementation of the PhysicalDevice class.
/// \copyright Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
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
/// \brief selectPhysicalDevice - Selects a physical device.
/// \details The function makes a selection based on criteria implemented in private helper functions.
//TODO finish documenting
void PhysicalDevice::selectPhysicalDevice() {
  if (device_array_.empty()) {
	throw std::runtime_error(
		"Error cannot select a physical device before they are enumerated");
  }
  for (auto device : device_array_) {
    if (getGraphicsQueueFamilyIndex(device) >= 0 && APIVersionCheck(device)) {
	  selected_device_ = device;
    }
  }
  if (selected_device_ == VK_NULL_HANDLE) {
	throw std::runtime_error(
		"No device with version and graphics support is available");
  }
}
/// \brief setGraphicsQueueIndex - Sets the graphics queue index variable.
/// \details The function is set with the private helper function
/// getGraphicsQueueFamilyIndex. The selected device variable is passed and
/// returns a signed integer with 32 bit width representing the queue family
/// index with graphics support. An exception is thrown if no device has been
/// selected or if graphics support is unavailable.
void PhysicalDevice::setGraphicsQueueIndex() {
  if (selected_device_ == VK_NULL_HANDLE) {
    throw std::runtime_error("No device has been selected");
  }
  graphics_queue_index_ = getGraphicsQueueFamilyIndex(selected_device_);
  if (graphics_queue_index_ == -1) {
	throw std::runtime_error("No graphics support available");
  }
}
/// \brief APIVersionCheck - Checks if the application specified API version is
/// less than or equal to the API version of a given device.
/// \warning No argument checking.
/// \param physical_device - A valid VkPhysicalDevice handle.
/// \return bool - True if the device API is equal or greater than the
/// application, false otherwise.
bool PhysicalDevice::APIVersionCheck(VkPhysicalDevice physical_device) const {
  VkPhysicalDeviceProperties properties;
  vkGetPhysicalDeviceProperties(physical_device, &properties);
  return api_version_ <= properties.apiVersion;
}
/// \brief getGraphicsQueueFamilyIndex - Attempts to find graphics processing
/// support on any queue family of a given device.
/// \details - The function initializes the the variable to be returned to -1
/// and a variable representing the number of queue families to 0.
/// vkGetPhysicalDeviceQueueFamilyProperties is called twice. The first tine the
/// last argument passed with nullptr. This has the effect of setting the queue
/// family variable. If the variable is still 0 an exception is thrown otherwise
/// the variable is used to initialize the size of a vector of
/// VkQueueFamilyProperties. This vector is populated through the second call to
/// vkGetPhysicalDeviceQueueFamilyProperties. The rest of the function loops
/// through the vector checking for graphics support and returning the first
/// index value that satisfies the criteria, otherwise -1 is returned.
/// \warning No argument checking.
/// \param physical_device - A valid VkPhysicalDevice handle.
/// \return int32_t - A signed integer with 32 bit width representing an index
/// to the queue family is returned if the call  is successful, otherwise
/// -1 is returned.
int32_t PhysicalDevice::getGraphicsQueueFamilyIndex(
	VkPhysicalDevice physical_device) {
  uint32_t graphics_queue_index = -1;
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
