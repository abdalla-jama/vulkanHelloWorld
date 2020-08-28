set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (tests_all
        mainTest.cpp
        ../source/Instance.cpp
        InstanceUnitTests.cpp
        ../source/PhysicalDevice.cpp
        PhysicalDeviceUnitTests.cpp)
target_link_libraries (tests_all ${Boost_LIBRARIES} -lvulkan)