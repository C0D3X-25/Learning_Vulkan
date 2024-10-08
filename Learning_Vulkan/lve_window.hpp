// Manage the creation of a window

#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace lve {
	class LveWindow {
	public:
		LveWindow(int width, int height, std::string name);
		~LveWindow();

		LveWindow(const LveWindow&) = delete;
		LveWindow& operator=(const LveWindow&) = delete;

		bool shouldClose() { return glfwWindowShouldClose(m_p_window); }

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* p_surface);

	private:
		void initWindow();

		const int m_width;
		const int m_height;

		std::string m_window_name;
		GLFWwindow* m_p_window;
	};
} // namespace lve

