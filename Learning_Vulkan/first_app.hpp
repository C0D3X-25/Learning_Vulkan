#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"

namespace lve {
	class FirstApp{
	public:
		static constexpr int m_WIDTH = 800;
		static constexpr int m_HEIGHT = 600;

		void Run();

	private:
		LveWindow m_lve_window{ m_WIDTH , m_HEIGHT, "Hello Vulkan" };
		LveDevice m_lve_device{ m_lve_window };
		LvePipeline m_lve_pipeline{
			m_lve_device,
			"shaders/simple_shader.vert.spv",
			"shaders/simple_shader.frag.spv",
			LvePipeline::defaultPipelineConfigInfo(m_WIDTH, m_HEIGHT)
		};
	};
} // namespace lve

