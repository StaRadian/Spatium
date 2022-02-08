#include "Sandbox.h"
#include "stb_image/stb_image.h"

namespace box
{
    Sandbox::Sandbox()
    {
        m_Monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(m_Monitor);
        m_MonitorSize.width = mode -> width;
        m_MonitorSize.height = mode -> height;
    }

    Sandbox::~Sandbox()
    {

    }

    void Sandbox::SetIcon(const std::string& icon_path)
    {
        GLFWimage images[1]; 
        images[0].pixels = stbi_load(icon_path.c_str(), &images[0].width, &images[0].height, 0, 4); //rgba channels 
        glfwSetWindowIcon(m_Window, 1, images); 
        stbi_image_free(images[0].pixels);
    }

    void Sandbox::UpdateDelta()
    {
        m_CurrentTime = glfwGetTime();
        m_Delta = m_CurrentTime - m_LastTime;
        m_LastTime = m_CurrentTime;
    }
}