//===-PhysicalDevice.cpp--------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// This file contains the implementation of the PhysicalDevice class.
/// \copyright Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#include "PhysicalDevice.h"

/// \brief enumeratePhysicalDevices - Exposes vulkan supported devices to the
/// application.
/// \details The function begins by performing a null check on its argument and
/// throwing an exception if the check fails. The rest of the function uses the
/// analogous Vulkan API function vkEnumeratePhysicalDevices twice, calling it
/// the first time with a nullptr as the third argument. This call provides the
/// number of vulkan supported devices, if the number is zero an exception is
/// thrown. A vector is resized to the number of devices available. The
/// vkEnumeratePhysicalDevices function is called again with the address of the
/// first element of the vector as the third argument. Each element in the
/// vector is filled with a VkPhysicalDevice object. If either of the API
/// function calls do not return VK_SUCCESS an exception is thrown.
/// \param instance - A valid VkInstance object.
/// \return VkResult - An enumeration of vulkan command return codes.
/// \exception std::runtime_error thrown if an invalid VkInstance is passed in.
/// \exception std::runtime_error thrown if either call to
/// vkEnumeratePhysicalDevices does not return VK_SUCCESS.
/// \exception std::runtime_error thrown if no physical devices on the system
/// provides vulkan support.
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
/// \details Initially the function checks if the vulkan supported devices have
/// been enumerated and throws an exception if they have not. The function
/// proceeds to loop through the enumerated devices and select the first device
/// that satisfies criteria implemented in private helper functions. The helper
/// functions check for minimum API version support and graphics processing
/// support. The function sets the members of the primary device struct to the
/// first device that fulfills the criteria and lastly if no device meets
/// the criteria an exception is thrown.
/// \exception std::runtime_error thrown if physical devices have not been
/// enumerated
/// \exception std::runtime_error thrown if no physical device satisfies
/// selection criteria.
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
/// \brief APIVersionCheck - Checks if the application specified API version is
/// less than or equal to the API version of a given device.
/// \details Initially the function null checks the argument and throws an
/// exception if it fails. The function proceeds to use the
/// vkGetPhysicalDeviceProperties to query the properties of the given device.
/// The function checks if the device supported API version is greater than or
/// equal to the client specified one.
/// \param physical_device - A valid VkPhysicalDevice handle.
/// \return bool - True if the device API is equal or greater than the
/// application, false otherwise.
/// \exception std::runtime_error thrown if parameter is invalid.
bool PhysicalDevice::APIVersionCheck(VkPhysicalDevice physical_device) const {
  if (physical_device == VK_NULL_HANDLE) {
	throw std::runtime_error("Error no VkPhysicalDevice available");
  }
  VkPhysicalDeviceProperties properties;
  vkGetPhysicalDeviceProperties(physical_device, &properties);
  return api_version_ <= properties.apiVersion;
}
/// \brief getGraphicsQueueFamilyIndex - Attempts to find graphics processing
/// support.
/// \details - Initially the function null checks the argument and throws an
/// exception if it fails. The function then initializes the the variable to be
/// returned to -1 and a variable representing the number of queue families to
/// 0. vkGetPhysicalDeviceQueueFamilyProperties is called twice. The first call
/// passes nullptr as the last argument. This has the effect of setting the
/// queue family count variable. If the variable is still 0 an exception is
/// thrown otherwise the variable is used to initialize the size of a vector of
/// VkQueueFamilyProperties. This vector is populated through the second call to
/// vkGetPhysicalDeviceQueueFamilyProperties. The rest of the function loops
/// through the vector checking for graphics support and returning the first
/// index value that satisfies the criteria, otherwise -1 is returned.
/// \param physical_device - A valid VkPhysicalDevice handle.
/// \return int32_t - A signed integer with 32 bit width representing an index
/// to the queue family is returned if the call  is successful, otherwise
/// -1 is returned.
/// \exception std::runtime_error thrown if parameter is invalid.
/// \exception std::runtime_error thrown if the call to
/// vkGetPhysicalDeviceQueueFamilyProperties fails.
int32_t PhysicalDevice::getGraphicsQueueFamilyIndex(
	VkPhysicalDevice physical_device) {
  if (physical_device == VK_NULL_HANDLE) {
	throw std::runtime_error("Error no VkPhysicalDevice available");
  }
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
