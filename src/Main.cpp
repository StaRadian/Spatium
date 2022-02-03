#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "sandbox/SandboxWin.h"
#include "sandbox/Sandbox.h"

#include "stb_image/stb_image.h"


int main(void)
{
    GLFWwindow* window;
    
    if (!glfwInit())
        return -1;

    box::SandboxWin test(window);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);    //vsync 활성화
    
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        return -1;
    }
    {
        box::Sandbox box;

        while (!glfwWindowShouldClose(window))  //loop
        {

            glClear(GL_COLOR_BUFFER_BIT);
            
            box.OnRender();

            glfwSwapBuffers(window);

            glfwPollEvents();
        }    
    }
    glfwTerminate();
}