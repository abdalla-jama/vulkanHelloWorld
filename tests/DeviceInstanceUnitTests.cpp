#include <boost/test/unit_test.hpp>
#include "../source/DeviceInstance.h"

BOOST_AUTO_TEST_CASE(fillApplicationInfo) {
    DeviceInstance testInstance;
    VkApplicationInfo fakeInfo = {
		VK_STRUCTURE_TYPE_APPLICATION_INFO,
		nullptr,
		"Vulkan Hello World",
		VK_MAKE_VERSION(1,0,0),
		"Vulkan Base Engine",
		VK_MAKE_VERSION(1,0,0),
		VK_API_VERSION_1_0
	};
    VkApplicationInfo testInfo = *testInstance.getApplicationInfo();
    BOOST_CHECK_EQUAL(testInfo.sType, fakeInfo.sType);
}