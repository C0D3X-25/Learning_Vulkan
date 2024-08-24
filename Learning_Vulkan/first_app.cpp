#include "first_app.hpp"

namespace lve {

	void FirstApp::Run() {

		while (!m_lve_window.shouldClose()) {
			glfwPollEvents();
		}


	}
} // namespace lve
