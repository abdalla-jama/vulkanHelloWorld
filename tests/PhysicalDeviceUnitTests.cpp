//===-PhysicalDevice.cpp--------------------------------------------*- C++ -*-//
//
// Part of the vulkanHelloWorld project, under the MIT License.
// Copyright (c) 2020 Abdalla Jama.
// This file contains the unit tests for the PhysicalDevice class.
//
//===----------------------------------------------------------------------===//]
#include <boost/test/unit_test.hpp>
/// \warning macro "#define private public" used for testing purposes only
#define private public
#include "../source/PhysicalDevice.h"
#include "../source/Instance.h" // VkInstance required for tests

BOOST_AUTO_TEST_CASE(catalogPhysicalDevices_validInstance) {
  Instance test_instance;
  test_instance.createInstance();
  PhysicalDevice test_device;
  const VkInstance* instance = test_instance.getVkInstance();
  BOOST_CHECK_EQUAL(test_device.enumeratePhysicalDevices(*instance),
					VK_SUCCESS);
  BOOST_CHECK(!test_device.device_array_.empty());
}
BOOST_AUTO_TEST_CASE(catalogPhysicalDevices_invalidInstance_exceptionThrown) {
  PhysicalDevice test_device;
  VkInstance instance = VK_NULL_HANDLE;
  BOOST_CHECK_THROW(test_device.enumeratePhysicalDevices(instance),
					std::runtime_error);
}
