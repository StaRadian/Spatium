#include <GL/glew.h>
#include <GLFW/glfw3.h>

// #include "sandbox/SandboxWin.h"
#include "sandbox/Sandbox.h"

namespace setmain
{
    static inline bool Init(GLFWwindow*& window)
    {
        if (!glfwInit())
            return false;

        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);    //화면 투명화

        window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return false;
        }

        glfwMakeContextCurrent(window);

        glfwSwapInterval(1);    //vsync 활성화
        
        if (glewInit() != GLEW_OK)
        {
            glfwTerminate();
            return false;
        }

        return true;
    }

    static inline void Update(GLFWwindow* window)
    {   
        box::Sandbox box;

        while (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);
            
            box.OnRender();

            glfwSwapBuffers(window);

            glfwPollEvents();
        }
    }
}

int main(void)
{
    GLFWwindow* window;

    if(setmain::Init(window) == -1)
        return -1;
    setmain::Update(window);
    glfwTerminate();
    return 0;
}