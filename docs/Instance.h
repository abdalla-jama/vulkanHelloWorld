//===-Instance.h----------------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// This file contains the documentation of the Instance class.
/// \copyright Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//

/// \class Instance Instance.h "Instance.h"
/// \brief Instance - Represents the vulkan instance (VkInstance).
/// \details Instance initializes a VkInstance object to a null handle.
/// Additionally it provides all the methods needed to create, access and query
/// the status of a valid VkInstance. A valid VkInstance object initializes the
/// vulkan library and allows communication between the application and the
/// vulkan implementation. For more information on the VkInstance see the vulkan
/// specification at
/// https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstance

/// \fn void setApplicationInfo(VkApplicationInfo* vk = nullptr)
/// \brief setApplicationInfo - Initializes and populates the member
/// VkApplicationInfo struct.
/// \details A VkApplicationInfo struct may be passed in to the function in
/// which case it is assigned to the member VkApplicationInfo struct, otherwise
/// a default set of values populates the struct.
/// \param vk (default nullptr) A pointer to a VkApplicationInfo struct.

/// \fn void setCreateInfo(VkInstanceCreateInfo* vk = nullptr)
/// \brief setCreateInfo - Initializes and populates the member
/// VkInstanceCreateInfo struct.
/// \details A VkInstanceCreateInfo struct may be passed in to the function in
/// which case it is assigned to the member VkApplicationInfo struct, otherwise
/// a default set of values populates the struct.
/// \param vk (default nullptr) A pointer to a VkInstanceCreateInfo struct.

/// \fn VkResult createInstance()
/// \brief createInstance - Creates a new vulkan instance.
/// \details Functions as a thin wrapper for the analogous vulkan API function
/// vkCreateInstance, passing in member variables for VkApplicationInfo,
/// VkInstanceCreateInfo and the VkInstance. The instance status member is
/// updated as well. A successful call will return VK_SUCCESS.
/// \return VkResult - An enumeration of vulkan command return codes.
/// \exception std::runtime_error thrown if VK_SUCCESS not returned.

/// \fn void destroyInstance()
/// \brief destroyInstance - Destroys a vulkan instance.
/// \details Functions as a thin wrapper for the analogous vulkan API function
/// vkDestroyInstance with the member VkInstance passed in. Additionally the
/// instance status is updated as well.

/// \fn const VkInstance* getVkInstance()
/// \brief getVkInstance - Provides access to the member VkInstance.
/// \return const VkInstance* - an immutable pointer to the VkInstance

/// \fn VkResult getInstanceStatus()
/// \brief getInstanceStatus - Provides the status of the member VkInstance.
/// \return VkResult - An enumeration of vulkan command return codes.

/// \fn uint32_t getAPIVersion()
/// \brief getAPIVersion - Provides the vulkan API version being used by the
/// application.
/// \return uint32_t - Unsigned integer with 32 bit width representing the major
/// , minor and patch numbers of the vulkan API.