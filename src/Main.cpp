#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"
#include "TexQuard2D.h"

#include "Debug.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace SPAT
{
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

    inline int SPATmain(void)
    {
        GLFWwindow* window;

        if(InitMain(window) == false)
            return -1;

        GLCall(glEnable(GL_BLEND));         //Blending
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));  //GL_SRC_ALPHA: 0, GL_ONE_MINUS_SRC_ALPHA: 1 - 0 = 1
        {
            TexQuard2D quard;
            quard.CreateQuard(300.0f, 100.0f, 150.0f, 150.0f, 0.5f, 0.0f);
            quard.CreateQuard(400.0f, 300.0f, 200.0f, 200.0f, 0.0f, 1.0f);
            quard.CreateQuard(100.0f, 50.0f, 50.0f, 50.0f, 0.0f, 1.0f);
            quard.CreateQuard(600.0f, 400.0f, 100.0f, 100.0f, 0.0f, 1.0f);
            quard.CreateQuard(800.0f, 50.0f, 300.0f, 300.0f, 0.0f, 0.0f);

            VertexArray va;

            VertexBuffer vb(nullptr, quard.GetSize());
            
            VertexBufferLayout layout;
            layout.Push<float>(2);
            layout.Push<float>(2);
            layout.Push<float>(1);
            
            vb.Bind();
            va.AddBuffer(layout);

            IndexBuffer ib(quard.GetIndex(), quard.GetIndexSize());

            Shader shader("./res/shader/shader.vs", "./res/shader/shader.fs");

            shader.Bind();

            Texture Mistarion_catTex("./res/textures/Mistarion_cat.png");
            Texture OscarHedgehogTex("./res/textures/OscarHedgehog.png");
            
            int samplers[2] = { 0, 1 };
            shader.SetUniform1iv("u_Texture", 2, samplers);

            glm::mat4 mvp = 
                glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)
                * glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

            float i = 0.0f;
            float j = 200.0f;
            float jincrease = 1.0f;

            while (!glfwWindowShouldClose(window))
            {
                quard.SetDegree(1.0f, i);

                quard.SetHeight(1.0f, j);

                quard.SetPosX(1.0f, j);

                i += 0.05f;
                j += jincrease;
                if(j > 350.0f)
                    jincrease = -1.0f;
                else if(j < 50.0f)
                    jincrease = 1.0f;

                vb.Bind();
                glBufferSubData(GL_ARRAY_BUFFER, 0, quard.GetSize(), quard.GetVertex());

                glClear(GL_COLOR_BUFFER_BIT);

                OscarHedgehogTex.Bind(0);
                Mistarion_catTex.Bind(1);
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
}

int main(void)
{
    return SPAT::SPATmain();
}