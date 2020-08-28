add_executable(vulkanHelloWorld
        main.cpp
        Instance.cpp
        Instance.h
        PhysicalDevice.cpp
        PhysicalDevice.h)
target_link_libraries (vulkanHelloWorld -lvulkan)