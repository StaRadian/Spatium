#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"

#include "Debug.h"

inline bool InitMain(GLFWwindow*& window)
{
    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        return false;
    }
    return true;
}

int main(void)
{
    GLFWwindow* window;

    if(InitMain(window) == false)
        return -1;

    float positions[] = {       //x,y
         0.5f,  0.5f,  0.1,  0.1,   //0
         0.5f, -0.5f,  0.1, -0.1,   //1
        -0.5f, -0.5f, -0.1, -0.1,   //2
        -0.5f,  0.5f, -0.1,  0.1    //3
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };
    
    {
        VertexArray va;
        va.Bind();

        VertexBuffer vb(positions, sizeof(positions));
        
        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);

        va.AddBuffer(layout);

        IndexBuffer ib(indices, 6);

        Shader shader;

        //Texture texture("./Source/res/textures/Mistarion_cat.png");

        while (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);

            shader.Bind();
            
            GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));

            glfwSwapBuffers(window);

            glfwPollEvents();
        }
    }

    glfwTerminate();
    return 0;
}