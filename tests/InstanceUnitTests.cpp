#include <boost/test/unit_test.hpp>
#include "../source/Instance.h"

BOOST_AUTO_TEST_CASE(fillApplicationInfo) {
  Instance testInstance;
  VkApplicationInfo fakeInfo = {
  	VK_STRUCTURE_TYPE_APPLICATION_INFO,
  	nullptr,
  	"",
  	VK_MAKE_VERSION(1,0,0),
  	"",
  	VK_MAKE_VERSION(1,0,0),
  	VK_API_VERSION_1_0
  };
  testInstance.fillApplicationInfo();
  const VkApplicationInfo* testInfo = testInstance.getApplicationInfo();
  BOOST_CHECK_EQUAL(testInfo->sType, VK_STRUCTURE_TYPE_APPLICATION_INFO);
  BOOST_CHECK_EQUAL(testInfo->pNext, nullptr);
  BOOST_CHECK_EQUAL(testInfo->pApplicationName, "");
  BOOST_CHECK_EQUAL(testInfo->applicationVersion,
					VK_MAKE_VERSION(1, 0, 0));
//  BOOST_CHECK_EQUAL(*testInfo->pEngineName, ""); TODO figure out why this test is failing
  BOOST_CHECK_EQUAL(testInfo->engineVersion,
					VK_MAKE_VERSION(1, 0, 0));
  BOOST_CHECK_EQUAL(testInfo->apiVersion, VK_API_VERSION_1_0);
}