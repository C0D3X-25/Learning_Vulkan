#pragma once

#include "lve_device.hpp"

#include <string>
#include <vector>

namespace lve {

	struct PipelineConfigInfo {

	};

	class LvePipeline{
	public:

		LvePipeline(
			LveDevice& device, 
			const std::string& vert_file_path,
			const std::string& frag_file_path,
			const PipelineConfigInfo& config_info);

		~LvePipeline() {};

		LvePipeline(const LvePipeline&) = delete;
		void operator=(const LvePipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

	private:

		static std::vector<char> m_read_file(const std::string& file_path);

		void createGraphicsPipeline(
			const std::string& vert_file_path,
			const std::string& frag_file_path,
			const PipelineConfigInfo& config_info);
	
		void createShaderModule(const std::vector<char>& code, VkShaderModule* shader_module);

		LveDevice& m_p_lve_device;
		VkPipeline m_graphics_pipeline;
		VkShaderModule m_vert_shader_module;
		VkShaderModule m_frag_shader_module;
	};
} // namespace lve

