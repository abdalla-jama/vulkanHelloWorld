//===-Instance.h----------------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// This file contains the definition of the Instance class.
/// \copyright Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#ifndef VULKAN_HELLO_WORLD_APP_SOURCE_INSTANCE_H_
#define VULKAN_HELLO_WORLD_APP_SOURCE_INSTANCE_H_
#include <vulkan/vulkan.h>
#include <stdexcept>

/// \class Instance Instance.h "Instance.h"
/// \brief Instance - Represents the vulkan instance (VkInstance).
/// \details Instance initializes a VkInstance object to a null handle.
/// Additionally it provides all the methods needed to create, access and query
/// the status of a valid VkInstance. A valid VkInstance object initializes the
/// vulkan library and allows communication between the application and the
/// vulkan implementation. For more information on the VkInstance see the vulkan
/// specification at
/// https://www.khronos.org/registry/vulkan/specs/1.2-extensions/html/vkspec.html#VkInstance
class Instance {
 public:
  void setApplicationInfo(VkApplicationInfo* vk = nullptr);
  void setCreateInfo(VkInstanceCreateInfo* vk = nullptr);
  VkResult createInstance();
  void destroyInstance();
/// \brief getVkInstance - Provides access to the member VkInstance.
/// \return const VkInstance* - an immutable pointer to the VkInstance
  const VkInstance* getVkInstance() const {return &instance_;}
/// \brief getInstanceStatus - Provides the status of the member VkInstance.
/// \return VkResult - An enumeration of vulkan command return codes.
  VkResult getInstanceStatus() const {return instance_status_;}
/// \brief getAPIVersion - Provides the vulkan API version being used by the
/// application.
/// \return uint32_t - Unsigned integer with 32 bit width representing the major
/// , minor and patch numbers of the vulkan API.
  uint32_t getAPIVersion() const {return app_info_.apiVersion;}
 private:
  VkApplicationInfo app_info_{};
  VkInstanceCreateInfo create_info_{};
  VkInstance instance_{VK_NULL_HANDLE};
  VkResult instance_status_{VK_NOT_READY};
};
#endif //VULKAN_HELLO_WORLD_APP_SOURCE_INSTANCE_H_