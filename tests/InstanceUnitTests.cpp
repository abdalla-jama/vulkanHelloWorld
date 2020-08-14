#include <boost/test/unit_test.hpp>
#include "../source/Instance.h"

BOOST_AUTO_TEST_CASE(fillApplicationInfo) {
    Instance testInstance;
    VkApplicationInfo testInfo = *testInstance.getApplicationInfo();
    BOOST_CHECK_EQUAL(testInfo.sType, VK_STRUCTURE_TYPE_APPLICATION_INFO);
    BOOST_CHECK_EQUAL(testInfo.pNext, nullptr);
    BOOST_CHECK_EQUAL(testInfo.applicationVersion,VK_MAKE_VERSION( 1, 0, 0 ));
}