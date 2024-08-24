#include "lve_window.h"


namespace lve {

	LveWindow::LveWindow(int width, int height, std::string name)
		: m_width{ width }, m_height{ height }, m_window_name{ name } 
	{
		initWindow();
	}

	LveWindow::~LveWindow() {
		glfwDestroyWindow(m_p_window);
		glfwTerminate();
	}

	void LveWindow::initWindow(){
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_p_window = glfwCreateWindow(m_width, m_height, m_window_name.c_str(), nullptr, nullptr);
	}
} // namespace lve
