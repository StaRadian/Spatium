#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "sandbox/SandKenny.h"
#include "sandbox/SandChaos.h"

#include "src/Debug.h"

int main(void)
{
    if (!glfwInit())
        return -1;

    box::Sandbox *box = nullptr;
    box = new box::SandKenny;
    // box = new box::SandChaos;

    if (!box -> GetWindow())
    {
        delete box;
        glfwTerminate();
        return -1;
    }
    
    if (glewInit() != GLEW_OK)
    {
        delete box;
        glfwTerminate();
        return -1;
    }

    box -> RenderInit();

    while (!glfwWindowShouldClose(box -> GetWindow()))  //loop
    {
        glClear(GL_COLOR_BUFFER_BIT);

        box -> OnUpdate();
        box -> OnRender();

        glfwSwapBuffers(box -> GetWindow());

        glfwPollEvents();
    }    
    
    delete box;
    glfwTerminate();
    return 0;
}