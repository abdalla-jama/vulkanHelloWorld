//===-PhysicalDevice.h----------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// This file contains the documentation of the PhysicalDevice class.
/// \copyright Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//

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

/// \fn VkResult enumeratePhysicalDevices(VkInstance instance)
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

/// \fn void setPrimaryDevice()
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

/// \fn void setAPIVersion(uint32_t version)
/// \brief setAPIVersion - Sets the API version variable.
/// \details The API version variable is initialized to 0 before the function
/// is called. The function can be used to set a minimum API version for the
/// primary device.
/// \param version - An unsigned integer with 32 bit width representing the
/// major, minor and patch numbers of the vulkan API.

/// \fn const std::vector<VkPhysicalDevice>* getPhysicalDevices()
/// \brief getPhysicalDevices - Provides access to a vector containing all the
/// vulkan supported devices on the system.
/// \return  const std::vector<VkPhysicalDevice>* - An immutable pointer to a
/// vector of VkPhysicalDevice objects.

/// \fn const VkPhysicalDevice* getPrimaryDevice()
/// \brief getPrimaryDevice - Provides access to a selected VkPhysicalDevice.
/// \details The VkPhysicalDevice variable is initialized to VK_NULL_HANDLE and
/// can be set with the setPrimaryDevice function.
/// \return const VkPhysicalDevice* - An immutable pointer to a VkPhysicalDevice
/// handle.

/// \fn int32_t getGraphicsQueueIndex()
/// \brief getGraphicsQueueIndex - Provides access to the index of the queue
/// family that support graphics processing on the primary device.
/// \return int32_t - a signed integer with 32 bit width representing the index.

/// \fn bool APIVersionCheck(VkPhysicalDevice physical_device)
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

/// \fn int32_t getGraphicsQueueFamilyIndex(VkPhysicalDevice physical_device)
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