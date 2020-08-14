#ifndef VULKANHELLOWORLD_INSTANCE_HPP
#define VULKANHELLOWORLD_INSTANCE_HPP
#include <vulkan/vulkan.h>

class Instance {
 public:
  Instance();
  ~Instance();
  const VkApplicationInfo* getApplicationInfo() const {return &app_info_;}
 private:
  VkApplicationInfo app_info_{};
  VkInstanceCreateInfo create_info_{};
  VkInstance instance_{};
  void fillApplicationInfo();
  void fillCreateInfo();
  void createInstance();
  void destroyInstance();
};
#endif //VULKANHELLOWORLD_INSTANCE_HPP