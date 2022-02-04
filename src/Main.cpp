#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "sandbox/SandKenny.h"
#include "sandbox/SandChaos.h"

#include "stb_image/stb_image.h"

#include "src/Debug.h"

int main(void)
{
    if (!glfwInit())
        return -1;

    box::SandChaos *box = new box::SandChaos;

    if (!box -> GetWindow())
    {
        glfwTerminate();
        return -1;
    }
    
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        return -1;
    }

    box -> RenderInit();

    int i = 0;
    while (!glfwWindowShouldClose(box -> GetWindow()))  //loop
    {
        glClear(GL_COLOR_BUFFER_BIT);

        box -> OnRender();

        glfwSwapBuffers(box -> GetWindow());

        glfwPollEvents();
    }    
    
    delete box;
    glfwTerminate();
}