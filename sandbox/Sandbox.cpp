#include "Sandbox.h"
#include <GL/glew.h>

#include "src/Debug.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace box
{
    Sandbox::Sandbox()
    {
        GLCall(glEnable(GL_BLEND));         //Blending
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));  //GL_SRC_ALPHA: 0, GL_ONE_MINUS_SRC_ALPHA: 1 - 0 = 1

        m_Quard.CreateQuard(50.0f, 50.0f, 100.0f, 100.0f, 0.0f, 1.0f);

        m_VertexBuffer = std::make_unique<spat::VertexBuffer>(nullptr, m_Quard.GetSize());

        spat::VertexBufferLayout layout;
        
        layout.Push<float>(2);
        layout.Push<float>(2);
        layout.Push<float>(1);
        
        m_VertexBuffer -> Bind();
        m_VAO -> AddBuffer(layout);

        m_IndexBuffer = std::make_unique<spat::IndexBuffer>(m_Quard.GetIndex(), m_Quard.GetIndexSize());

        m_Shader = std::make_unique<spat::Shader>("./res/shader/shader.vs", "./res/shader/shader.fs");

        m_Shader -> Bind();

        m_OscarHedgehogTex = std::make_unique<spat::Texture>("./res/textures/OscarHedgehog.png");
        m_Mistarion_catTex = std::make_unique<spat::Texture>("./res/textures/Mistarion_cat.png");
        
        int samplers[2] = { 0, 1 };
        m_Shader -> SetUniform1iv("u_Texture", 2, samplers);

        //GLCall(glClearColor(0.2f, 0.3f, 0.8f, 1.0f));
    }

    Sandbox::~Sandbox()
    {

    }

    void Sandbox::OnRender()
    {
        m_Quard.SetDegree(0.0f, i);
        //m_Quard.SetHeight(1.0f, j);
        //m_Quard.SetPosX(1.0f, j);

        i += 0.05f;
        j += jincrease;
        if(j > 350.0f)
            jincrease = -1.0f;
        else if(j < 50.0f)
            jincrease = 1.0f;
        
        glm::mat4 mvp = 
            glm::ortho(0.0f, 100.0f, 0.0f, 100.0f, -1.0f, 1.0f)
            * glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

        m_VertexBuffer -> Bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, m_Quard.GetSize(), m_Quard.GetVertex());

        m_OscarHedgehogTex -> Bind(0);
        m_Mistarion_catTex -> Bind(1);
        m_Shader -> Bind();
        
        m_Shader -> SetUniformMat4f("u_MVP", mvp);
        GLCall(glDrawElements(GL_TRIANGLES, m_IndexBuffer -> GetCount(), GL_UNSIGNED_INT, nullptr));
    }   
}