#include "Shader.h"
#include <GL/glew.h>
#include <fstream>
#include <sstream>

#include "Debug.h"

namespace spat
{
    Shader::Shader(const std::string& vertexpath, const std::string& fragmentpath)
    {
        m_RendererID = CreateShader(vertexpath, fragmentpath);
    }

    Shader::~Shader()
    {
        GLCall(glDeleteProgram(m_RendererID));
    }

    unsigned int Shader::CompileShader(unsigned int type, const std::string source)
    {
        unsigned int id = glCreateShader(type); //create empty shader object
        const char* src = source.c_str();
        GLCall(glShaderSource(id, 1, &src, nullptr));
        GLCall(glCompileShader(id));    //Shader compile

        int result;
        GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));  //
        if(result == GL_FALSE)  //failed compiled shader
        {
            int length;
            GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
            char message[length];
            GLCall(glGetShaderInfoLog(id, length, &length, message));
            GLCall(glDeleteShader(id));
            return 0;
        }
        else
        {
            LOG("succeed to compiled "
                << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
                << " shader!");
        }

        return id;
    }

    unsigned int Shader::CreateShader(const std::string& vertexpath, const std::string& fragmentpath)
    {
        std::ifstream v_stream(vertexpath, std::ios::in);
        std::ifstream f_stream(fragmentpath, std::ios::in);
        std::stringstream vertexShader; 
        std::stringstream fragmentShader; 
        vertexShader << v_stream.rdbuf();
        fragmentShader << f_stream.rdbuf();

        unsigned int program = glCreateProgram();   //create empty program object
        unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader.str());
        unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader.str());

        GLCall(glAttachShader(program, vs)); //program에 vs shader를 연결
        GLCall(glAttachShader(program, fs)); //program에 fs shader를 연결
        GLCall(glLinkProgram(program));     //link program
    #if DEBUG
        GLCall(glValidateProgram(program)); //유효성 검사 program 지정, 개발용으로만 유용
    #endif
        GLCall(glDeleteShader(vs)); //delete shader vs 
        GLCall(glDeleteShader(fs)); //delete shader fs

        return program;
    }

    void Shader::Bind()
    {
        GLCall(glUseProgram(m_RendererID));
    }

    void Shader::Unbind()
    {
        GLCall(glUseProgram(0));
    }

    int Shader::GetUniformLocation(const std::string& name)
    {
        if(m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
            return m_UniformLocationCache[name];
        
        GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
        if(location == -1)
            LOG("Warring: Uniform '" << name << "' doesn't exist!");
        
        m_UniformLocationCache[name] = location;
        return location;
    }

    void Shader::SetUniform1i(const std::string& name, int value)
    {
        GLCall(glUniform1i(GetUniformLocation(name), value));
    }

    void Shader::SetUniform1iv(const std::string& name, int count ,int* value)
    {
        GLCall(glUniform1iv(GetUniformLocation(name), count, value));
    }

    void Shader::SetUniform1f(const std::string& name, float value)
    {
        GLCall(glUniform1f(GetUniformLocation(name), value));
    }

    void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
    {
        GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
    }

    void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix)
    {
        GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
    }
}