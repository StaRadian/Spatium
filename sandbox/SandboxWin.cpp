#include "SandboxWin.h"
#include <GL/glew.h>

namespace box
{
    SandboxWin::SandboxWin(GLFWwindow*& window)
        :m_Window(window)
    {

        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
 
        glfwWindowHint(GLFW_DECORATED, false);
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
        glfwWindowHint(GLFW_FLOATING , GLFW_TRUE);

        window = glfwCreateWindow(100, 100, "My Title", NULL, NULL);

        //glfwSetWindowPos(window, 0, 0);

        glfwMakeContextCurrent(window);

        glfwSwapInterval(1);    //vsync 활성화
    }

    SandboxWin::~SandboxWin()
    {

    }
}