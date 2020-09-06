add_executable(vulkanHelloWorld
        main.cpp
        Instance.cpp
        Instance.h
        PhysicalDevice.cpp
        PhysicalDevice.h
        LogicalDevice.cpp
        LogicalDevice.h)
target_link_libraries (vulkanHelloWorld -lvulkan)