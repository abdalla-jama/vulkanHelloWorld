//===-InstanceUnitTests.cpp-----------------------------------------*- C++ -*-//
//
// Part of the vulkanHelloWorld project, under the MIT License.
// Copyright (c) 2020 Abdalla Jama.
// This file contains the unit tests for the Instance class.
//
//===----------------------------------------------------------------------===//
#include <boost/test/unit_test.hpp>
/// \warning macro "#define private public" used for testing purposes only
#define private public
#include "../source/Instance.h"

BOOST_AUTO_TEST_CASE(setApplicationInfo_noParameters) {
  Instance test_instance;
  test_instance.setApplicationInfo();
  VkApplicationInfo* test_info = &test_instance.app_info_;
  BOOST_CHECK_EQUAL(test_info->sType, VK_STRUCTURE_TYPE_APPLICATION_INFO);
  BOOST_CHECK_EQUAL(test_info->pNext, nullptr);
  BOOST_CHECK_EQUAL(test_info->pApplicationName, "");
  BOOST_CHECK_EQUAL(test_info->applicationVersion,
					VK_MAKE_VERSION(1, 0, 0));
  BOOST_CHECK_EQUAL(test_info->pEngineName, "");
  BOOST_CHECK_EQUAL(test_info->engineVersion,
					VK_MAKE_VERSION(1, 0, 0));
  BOOST_CHECK_EQUAL(test_info->apiVersion, VK_API_VERSION_1_0);
}
BOOST_AUTO_TEST_CASE(setApplicationInfo_withParameters) {
  Instance test_instance;
  VkApplicationInfo test_info = {
	  VK_STRUCTURE_TYPE_APPLICATION_INFO,
	  nullptr,
	  "RANDOM VALUE",
	  VK_MAKE_VERSION(2, 0, 0),
	  "RANDOM VALUE",
	  VK_MAKE_VERSION(2, 0, 0),
	  VK_API_VERSION_1_0
  };
  test_instance.setApplicationInfo(&test_info);
  BOOST_CHECK_EQUAL(test_instance.app_info_.sType, test_info.sType);
  BOOST_CHECK_EQUAL(test_instance.app_info_.pNext, test_info.pNext);
  BOOST_CHECK_EQUAL(test_instance.app_info_.pApplicationName,
					test_info.pApplicationName);
  BOOST_CHECK_EQUAL(test_instance.app_info_.applicationVersion,
					test_info.applicationVersion);
  BOOST_CHECK_EQUAL(test_instance.app_info_.pEngineName,
					test_info.pEngineName);
  BOOST_CHECK_EQUAL(test_instance.app_info_.engineVersion,
					test_info.engineVersion);
  BOOST_CHECK_EQUAL(test_instance.app_info_.apiVersion,
					test_info.apiVersion);
}
BOOST_AUTO_TEST_CASE(setCreateInfo_noParameters) {
  Instance test_instance;
  test_instance.setCreateInfo();
  VkInstanceCreateInfo* test_info = &test_instance.create_info_;
  BOOST_CHECK_EQUAL(test_info->sType, VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO);
  BOOST_CHECK_EQUAL(test_info->pNext, nullptr);
  BOOST_CHECK_EQUAL(test_info->flags, 0);
  BOOST_CHECK_EQUAL(test_info->pApplicationInfo, &test_instance.app_info_);
  BOOST_CHECK_EQUAL(test_info->enabledLayerCount, 0);
  BOOST_CHECK_EQUAL(test_info->ppEnabledLayerNames, nullptr);
  BOOST_CHECK_EQUAL(test_info->enabledExtensionCount, 0);
  BOOST_CHECK_EQUAL(test_info->ppEnabledExtensionNames, nullptr);
}
BOOST_AUTO_TEST_CASE(setCreateInfo_withParameters) {
  Instance test_instance;
  VkInstanceCreateInfo test_info = {
	  VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
	  nullptr,
	  5,
	  &test_instance.app_info_,
	  5,
	  nullptr,
	  5,
	  nullptr
  };
  test_instance.setCreateInfo(&test_info);
  BOOST_CHECK_EQUAL(test_instance.create_info_.sType, test_info.sType);
  BOOST_CHECK_EQUAL(test_instance.create_info_.pNext, test_info.pNext);
  BOOST_CHECK_EQUAL(test_instance.create_info_.flags, test_info.flags);
  BOOST_CHECK_EQUAL(test_instance.create_info_.pApplicationInfo,
					test_info.pApplicationInfo);
  BOOST_CHECK_EQUAL(test_instance.create_info_.enabledLayerCount,
					test_info.enabledLayerCount);
  BOOST_CHECK_EQUAL(test_instance.create_info_.ppEnabledLayerNames,
					test_info.ppEnabledLayerNames);
  BOOST_CHECK_EQUAL(test_instance.create_info_.enabledExtensionCount,
					test_info.enabledExtensionCount);
  BOOST_CHECK_EQUAL(test_instance.create_info_.ppEnabledExtensionNames,
					test_info.ppEnabledExtensionNames);
}
BOOST_AUTO_TEST_CASE(createInstance_validInstance) {
  Instance test_instance;
  BOOST_CHECK_EQUAL(test_instance.createInstance(), VK_SUCCESS);
}
BOOST_AUTO_TEST_CASE(destroyInstance_validInstance) {
  Instance test_instance;
  test_instance.createInstance();
  BOOST_CHECK_EQUAL(test_instance.instance_status_, VK_SUCCESS);
  test_instance.destroyInstance();
  BOOST_CHECK_EQUAL(test_instance.instance_status_, VK_NOT_READY);
}
BOOST_AUTO_TEST_CASE(getVkInstance) {
  Instance test_instance;
  BOOST_CHECK_EQUAL(*test_instance.getVkInstance(),
					test_instance.instance_);
}
BOOST_AUTO_TEST_CASE(getInstanceStatus) {
  Instance test_instance;
  BOOST_CHECK_EQUAL(test_instance.getInstanceStatus(),
					test_instance.instance_status_);
}