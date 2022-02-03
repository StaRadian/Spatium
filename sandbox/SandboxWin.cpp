#include "SandboxWin.h"
#include <GL/glew.h>

#include "src/Debug.h"

namespace box
{
    SandboxWin::SandboxWin(GLFWwindow*& window)
        :m_Window(window)
    {
        //glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
        glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

        //window = glfwCreateWindow(1920, 1080, "title", NULL, NULL);
        window = glfwCreateWindow(500, 500, "title", NULL, NULL);
        glfwSetWindowPos(window, 0, 0);
    }

    SandboxWin::~SandboxWin()
    {

    }
}