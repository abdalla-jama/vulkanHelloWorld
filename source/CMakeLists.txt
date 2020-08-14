add_executable(vulkanHelloWorld
        main.cpp
        Instance.cpp
        Instance.h)
target_link_libraries (vulkanHelloWorld -lvulkan)