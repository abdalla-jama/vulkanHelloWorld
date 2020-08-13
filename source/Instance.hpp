#ifndef VULKANHELLOWORLD_INSTANCE_HPP
#define VULKANHELLOWORLD_INSTANCE_HPP
#include <vulkan/vulkan.h>

class Instance {
private:
    VkApplicationInfo app_info_;
    VkInstanceCreateInfo create_info_;
    VkInstance instance_;
};
#endif //VULKANHELLOWORLD_INSTANCE_HPP