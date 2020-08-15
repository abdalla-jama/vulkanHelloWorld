add_executable(vulkanHelloWorld
        main.cpp
        DeviceInstance.cpp
        DeviceInstance.h)
target_link_libraries (vulkanHelloWorld -lvulkan)