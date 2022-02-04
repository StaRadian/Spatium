#include "Sandbox.h"

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
}