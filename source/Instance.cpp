#include "Instance.h"

Instance::Instance() {
	fillApplicationInfo();
	fillCreateInfo();
	createInstance();
}
Instance::~Instance() {
	destroyInstance();
}
void Instance::fillApplicationInfo() {
	app_info_ = {
		VK_STRUCTURE_TYPE_APPLICATION_INFO,
		nullptr,
		"Vulkan Hello World",
		VK_MAKE_VERSION(1,0,0),
		"Vulkan Base Engine",
		VK_MAKE_VERSION(1,0,0),
		VK_API_VERSION_1_0
	};
}
void Instance::fillCreateInfo() {
	create_info_ = {
		VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		nullptr,
		0,
		&app_info_,
		0,
		nullptr,
		0,
		nullptr
	};
}
void Instance::createInstance() {
	vkCreateInstance(&create_info_, nullptr, &instance_);
}
void Instance::destroyInstance() {
	vkDestroyInstance(instance_, nullptr);
}