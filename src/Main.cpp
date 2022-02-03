#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "sandbox/SandboxWin.h"
#include "sandbox/Sandbox.h"

#include "stb_image/stb_image.h"

#include "src/Debug.h"

int main(void)
{
    GLFWwindow* window;

    {
        if (!glfwInit())
            return -1;

        box::SandboxWin boxWin(window);

        if (!window)
        {
            glfwTerminate();
            return -1;
        }
        
        if (glewInit() != GLEW_OK)
        {
            glfwTerminate();
            return -1;
        }

        box::Sandbox box;

        int i = 0;
        while (!glfwWindowShouldClose(window))  //loop
        {
            glClear(GL_COLOR_BUFFER_BIT);
            
            glfwSetWindowPos(window, i++, 0);

            box.OnRender();

            glfwSwapBuffers(window);

            glfwPollEvents();
        }    
    }
    
    glfwTerminate();
}