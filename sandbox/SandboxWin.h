#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

namespace box
{
    class SandboxWin
    {
    private:
        int m_Width, m_Height;
        GLFWwindow* m_Window;
    public:
        SandboxWin(GLFWwindow*& window);
        ~SandboxWin();
    };
}