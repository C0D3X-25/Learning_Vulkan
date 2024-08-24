#pragma once

#include "lve_window.h"

namespace lve {
	class FirstApp{
	public:
		static constexpr int m_WIDTH = 800;
		static constexpr int m_HEIGHT = 600;

		void Run();

	private:
		LveWindow m_lve_window{ m_WIDTH , m_HEIGHT, "Hello Vulkan"};
	};
} // namespace lve

