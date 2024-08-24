#include "lve_pipeline.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>


namespace lve {

    LvePipeline::LvePipeline(
        LveDevice& device, 
        const std::string& vert_file_path, 
        const std::string& frag_file_path, 
        const PipelineConfigInfo& config_info)
        :m_p_lve_device{device}
    {

        createGraphicsPipeline(vert_file_path, frag_file_path, config_info);
    }


    PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
        PipelineConfigInfo config_info;
        return config_info;
    }


    // Try to open a file and read it in binary (to avoid string transformation)
    std::vector<char> LvePipeline::m_read_file(const std::string& file_path) {
        
        std::ifstream file{ file_path, std::ios::ate, std::ios::binary };

        // Throw an error if not the good file OR missing permissions
        if (!file.is_open()) {
            throw std::runtime_error("failed to open file: " + file_path);
        }

        // Get the file size for the vector size initialization
        size_t file_size = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(file_size);

        // Read the file
        file.seekg(0);
        file.read(buffer.data(), file_size);
        
        file.close();

        return buffer;
    }


    void LvePipeline::createGraphicsPipeline(
        const std::string& vert_file_path, 
        const std::string& frag_file_path, 
        const PipelineConfigInfo& config_info) {
        
        auto vert_code = m_read_file(vert_file_path);
        auto frag_code = m_read_file(frag_file_path);
        
        std::cout << "Vertex Shader Code Size: " << vert_code.size() << "\n";
        std::cout << "Fragment Shader Code Size: " << frag_code.size() << "\n";
    }


    void LvePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shader_module) {
        VkShaderModuleCreateInfo create_info{};
        create_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        create_info.codeSize = code.size();
        create_info.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if (vkCreateShaderModule(m_p_lve_device.device(), &create_info, nullptr, shader_module) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create shader module");
        }
    }
} // namespace lve
