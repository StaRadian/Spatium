#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"

#include "Debug.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

inline bool InitMain(GLFWwindow*& window)
{
    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

    window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
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

    unsigned int indices[] = {
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4
    };

    GLCall(glEnable(GL_BLEND));         //Blending
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));  //GL_SRC_ALPHA: 0, GL_ONE_MINUS_SRC_ALPHA: 1 - 0 = 1
    
    {
        VertexArray va;
        va.Bind();

        VertexBuffer vb(nullptr, sizeof(Vertex) * 1000);
        
        VertexBufferLayout layout;
        layout.Push<float>(3);
        layout.Push<float>(2);
        layout.Push<float>(1);
        
        vb.Bind();
        va.AddBuffer(layout);

        IndexBuffer ib(indices, 12);

        Shader shader("./res/shader/shader.vs", "./res/shader/shader.fs");

        shader.Bind();

        Texture texture1("./res/textures/Mistarion_cat.png");
        Texture texture2("./res/textures/OscarHedgehog.png");
        
        int samplers[2] = { 0, 1 };
        shader.SetUniform1iv("u_Texture", 2, samplers);

        glm::mat4 mvp = 
            glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)
            * glm::translate(glm::mat4(1.0f), glm::vec3(50, 50, 0));

        while (!glfwWindowShouldClose(window))
        {
            auto q0 = CreateQuard(-50.0f, -50.0f, 0.0f);
            auto q1 = CreateQuard( 0.0f, -50.0f, 1.0f);

            Vertex vertices[8];
            memcpy(vertices, q0.data(), q0.size() * sizeof(Vertex));
            memcpy(vertices + q0.size(), q1.data(), q1.size() * sizeof(Vertex));

            vb.Bind();
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

            glClear(GL_COLOR_BUFFER_BIT);

            texture1.Bind(0);
            texture2.Bind(1);
            shader.Bind();
            
            shader.SetUniformMat4f("u_MVP", mvp);
            GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));

            glfwSwapBuffers(window);

            glfwPollEvents();
        }
    }

    glfwTerminate();
    return 0;
}