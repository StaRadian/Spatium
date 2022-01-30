#pragma once

#include <string>

class Shader
{
private:
    unsigned int m_RendererID;

    std::string m_VertexShader =
    "#version 460 core\n"
    "layout(location = 0) in vec4 position;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = position;\n"
    "}";

    std::string m_FragmentShader =
    "#version 460 core\n"
    "layout(location = 0) out vec4 color;\n"
    "layout(location = 1) out vec2 texCoord;\n"
    "void main()\n"
    "{\n"
    "   color = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}";

    unsigned int CompileShader(unsigned int type, const std::string source);
    unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
public:
    Shader();
    ~Shader();
    void Bind();
    void Unbind();
};