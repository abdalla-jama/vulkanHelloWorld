//===-PhysicalDevice.cpp--------------------------------------------*- C++ -*-//
//
/// Part of the vulkanHelloWorldApp.
/// \brief This file contains the unit tests for the PhysicalDevice class.
/// \copyright Copyright (c) 2020 Abdalla Jama under the MIT License. See
/// accompanying file LICENSE or copy at https://opensource.org/licenses/MIT
//
//===----------------------------------------------------------------------===//
#include <boost/test/unit_test.hpp>
/// \warning macro "#define private public" used for testing purposes only
#define private public
#include "../source/PhysicalDevice.h"
#include "../source/Instance.h" // VkInstance required for tests

BOOST_AUTO_TEST_CASE(enumeratePhysicalDevices_validInstance) {
  Instance test_instance;
  test_instance.createInstance();
  PhysicalDevice test_device;
  const VkInstance* instance = test_instance.getVkInstance();
  BOOST_CHECK_EQUAL(test_device.enumeratePhysicalDevices(*instance),
					VK_SUCCESS);
  BOOST_CHECK(!test_device.device_array_.empty());
}
BOOST_AUTO_TEST_CASE(ewnumeratePhysicalDevices_invalidInstance_exceptionThrown){
  PhysicalDevice test_device;
  VkInstance instance = VK_NULL_HANDLE;
  BOOST_CHECK_THROW(test_device.enumeratePhysicalDevices(instance),
					std::runtime_error);
}
BOOST_AUTO_TEST_CASE(selectPhysicalDevice_enumeratedDevices) {
  Instance test_instance;
  test_instance.createInstance();
  PhysicalDevice test_device;
  const VkInstance* instance = test_instance.getVkInstance();
  test_device.enumeratePhysicalDevices(*instance);
  test_device.selectPhysicalDevice();
  BOOST_CHECK(test_device.selected_device_ != VK_NULL_HANDLE);
}
BOOST_AUTO_TEST_CASE(selectPhysicalDevice_noEnumeration_exceptionThrown) {
  PhysicalDevice test_device;
  BOOST_CHECK_THROW(test_device.selectPhysicalDevice(),
					std::runtime_error);
}
BOOST_AUTO_TEST_CASE(setGraphicsQueueIndex_validDevice) {
  Instance test_instance;
  test_instance.createInstance();
  PhysicalDevice test_device;
  const VkInstance* instance = test_instance.getVkInstance();
  test_device.enumeratePhysicalDevices(*instance);
  test_device.selectPhysicalDevice();
  test_device.setGraphicsQueueIndex(); /// Target Function
  int32_t test_value = test_device.getGraphicsQueueFamilyIndex(
  	test_device.selected_device_);
  BOOST_CHECK_EQUAL(test_device.graphics_queue_index_, test_value);
}
BOOST_AUTO_TEST_CASE(setGraphicsQueueIndex_invalidDevice_exceptionThrown) {
  PhysicalDevice test_device;
  BOOST_CHECK_THROW(test_device.setGraphicsQueueIndex(),
					std::runtime_error);
}
BOOST_AUTO_TEST_CASE(APIVersionCheck) {
  Instance test_instance;
  test_instance.createInstance();
  PhysicalDevice test_device;
  test_device.enumeratePhysicalDevices(*test_instance.getVkInstance());
  VkPhysicalDeviceProperties properties;
  vkGetPhysicalDeviceProperties(
  	test_device.device_array_[0],
  	&properties);
  BOOST_CHECK_EQUAL(test_device.APIVersionCheck(test_device.device_array_[0])
					,test_device.api_version_ <= properties.apiVersion);
  BOOST_CHECK_EQUAL(test_device.APIVersionCheck(test_device.device_array_[0])
					, true);
}
BOOST_AUTO_TEST_CASE(getGraphicsQueueFamilyIndex) {
  Instance test_instance;
  test_instance.createInstance();
  PhysicalDevice test_device;
  test_device.enumeratePhysicalDevices(*test_instance.getVkInstance());
  uint32_t test_value = test_device.getGraphicsQueueFamilyIndex(
  	test_device.device_array_[0]);
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