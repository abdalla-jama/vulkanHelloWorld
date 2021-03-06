//===-PhysicalDevice.cpp--------------------------------------------*- C++ -*-//
//
/// Part of the Vulkan Hello World App.
/// This file contains the unit tests for the PhysicalDevice class.
/// Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#include <boost/test/unit_test.hpp>
/// \warning macro "#define private public" used for testing purposes only
#define private public
#include "../source/PhysicalDevice.h"
#include "../source/Instance.h" // VkInstance required for test
/*
BOOST_AUTO_TEST_CASE(enumeratePhysicalDevices_validInstance) {
  Instance test_instance;
  test_instance.create();
  PhysicalDevice test_device;
  const VkInstance* instance = test_instance.getVkInstance();
  /// Target Function Call
  BOOST_CHECK_EQUAL(test_device.enumeratePhysicalDevices(*instance),
					VK_SUCCESS);
  BOOST_CHECK(!test_device.device_array_.empty());
}
BOOST_AUTO_TEST_CASE(ewnumeratePhysicalDevices_invalidInstance_exceptionThrown){
  PhysicalDevice test_device;
  VkInstance instance = VK_NULL_HANDLE;
  /// Target Function Call
  BOOST_CHECK_THROW(test_device.enumeratePhysicalDevices(instance),
					std::runtime_error);
}
BOOST_AUTO_TEST_CASE(setPrimaryDevice_enumeratedDevices) {
  Instance test_instance;
  test_instance.create();
  PhysicalDevice test_device;
  const VkInstance* instance = test_instance.getVkInstance();
  test_device.enumeratePhysicalDevices(*instance);
  test_device.setPrimaryDevice();   /// Target Function Call
  BOOST_CHECK(test_device.primary_device_.device_ != VK_NULL_HANDLE);
  BOOST_CHECK(test_device.primary_device_.graphics_queue_index_ != -1);
}
BOOST_AUTO_TEST_CASE(setPrimaryDevice_noEnumeration_exceptionThrown) {
  PhysicalDevice test_device;
  BOOST_CHECK_THROW(test_device.setPrimaryDevice(),
					std::runtime_error);
}
BOOST_AUTO_TEST_CASE(setAPIVersion) {
  PhysicalDevice test_device;
  uint32_t test_version = VK_MAKE_VERSION(1,0,0);
  test_device.setAPIVersion(test_version); /// Target Function Call
  BOOST_CHECK_EQUAL(test_device.api_version_, test_version);
}
BOOST_AUTO_TEST_CASE(getPhysicalDevices) {
  PhysicalDevice test_device;
  for (uint32_t i = 0; i < test_device.device_array_.size(); i++) {
	/// Target Function Call
	BOOST_CHECK_EQUAL((*test_device.getPhysicalDevices())[i],
					  test_device.device_array_[i]);
  }
}
BOOST_AUTO_TEST_CASE(getPrimaryDevice) {
  PhysicalDevice test_device;
  BOOST_CHECK_EQUAL(*test_device.getPrimaryDevice(), /// Target Function Call
					test_device.primary_device_.device_);
}
BOOST_AUTO_TEST_CASE(getGraphicsQueueIndex) {
  PhysicalDevice test_device;
  /// Target Function Call
  BOOST_CHECK_EQUAL(test_device.getGraphicsQueueIndex(),
					test_device.primary_device_.graphics_queue_index_);
}
BOOST_AUTO_TEST_CASE(APIVersionCheck) {
  Instance test_instance;
  test_instance.create();
  PhysicalDevice test_device;
  test_device.enumeratePhysicalDevices(*test_instance.getVkInstance());
  VkPhysicalDeviceProperties properties;
  vkGetPhysicalDeviceProperties(
  	test_device.device_array_[0],
  	&properties);
  /// Target Function Call
  BOOST_CHECK_EQUAL(test_device.APIVersionCheck(test_device.device_array_[0])
					,test_device.api_version_ <= properties.apiVersion);
  /// Target Function Call
  BOOST_CHECK_EQUAL(test_device.APIVersionCheck(test_device.device_array_[0])
					, true);
}
BOOST_AUTO_TEST_CASE(getGraphicsQueueFamilyIndex) {
  Instance test_instance;
  test_instance.create();
  PhysicalDevice test_device;
  test_device.enumeratePhysicalDevices(*test_instance.getVkInstance());
  uint32_t test_value = test_device.getGraphicsQueueFamilyIndex(
  	test_device.device_array_[0]); /// Target Function Call
  uint32_t queue_count{0};
  vkGetPhysicalDeviceQueueFamilyProperties(
  	test_device.device_array_[0],
  	&queue_count,
	nullptr);
  std::vector<VkQueueFamilyProperties> queue_props(queue_count);
  vkGetPhysicalDeviceQueueFamilyProperties(
  	test_device.device_array_[0],
  	&queue_count,
  	queue_props.data());
  for (uint32_t i = 0; i < queue_props.size(); i++) {
	if ( queue_props[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
	  BOOST_CHECK_EQUAL(test_value, i);
	}
  }
}
*/