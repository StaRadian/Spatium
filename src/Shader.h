#pragma once

#include <string>
#include <unordered_map>
#include "glm/glm.hpp"

namespace spat
{
    class Shader
    {
    private:
        unsigned int m_RendererID;
        std::unordered_map<std::string, int> m_UniformLocationCache;
        unsigned int CompileShader(unsigned int type, const std::string source);
        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
        int GetUniformLocation(const std::string& name);
    public:
        Shader(const std::string& vertexpath, const std::string& fragmentpath);
        ~Shader();
        void Bind();
        void Unbind();

        void SetUniform1i(const std::string& name, int value);
        void SetUniform1iv(const std::string& name, int count ,int* value);
        void SetUniform1f(const std::string& name, float value);
        void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
        void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
    };
}