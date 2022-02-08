#include "SandChaos.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <GL/glew.h>

#include "src/Debug.h"

namespace box
{
    SandChaos::SandChaos()
    {
        //glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);    //배경 투명
        glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);   //top screan

        m_WinSize = {1024, 768};

        m_Window = glfwCreateWindow(m_WinSize.width, m_WinSize.height, "My Title", NULL, NULL);

        glfwSetWindowPos(GetWindow(), (m_MonitorSize.width - m_WinSize.width) / 2, (m_MonitorSize.height - m_WinSize.height) / 2);

        SetIcon("./res/textures/kenny.png");

        glfwMakeContextCurrent(GetWindow());
        
        glfwSwapInterval(1);    //vsync 활성화
    }

    SandChaos::~SandChaos()
    {

    }

    void SandChaos::RenderInit()
    {
        GLCall(glEnable(GL_BLEND));         //Blending
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));  //GL_SRC_ALPHA: 0, GL_ONE_MINUS_SRC_ALPHA: 1 - 0 = 1

        const spat::VertexCache2D quardInit[] = {
            { 50.0f,  50.0f,  50.0f,  50.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f},                     //0
            {800.0f, 500.0f, 200.0f, 200.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f},                     //1
            {150.0f, 250.0f, 100.0f, 100.0f, 0.0f, 0.0f, 1.0f, 1.0f, -1.0f},                    //2
            {600.0f, 150.0f, 100.0f, 100.0f, 0.0f, 0.0f, 1.0f, 1.0f, 2.0f},                     //3 
                    
            {200.0f, 200.0f, 100.0f, 150.0f, 0.0f, 0.0f, 1.0f / 3.0f, 1.0f, 0.0f},              //4
            {400.0f, 200.0f, 100.0f, 150.0f, 1.0f / 3.0f, 0.0f, 1.0f / 3.0f, 1.0f, 0.0f},       //5
            {600.0f, 200.0f, 100.0f, 150.0f, 2.0f / 3.0f, 0.0f, 1.0f / 3.0f, 1.0f, 0.0f}};      //6

        m_Quard.CreateQuard(quardInit[4], 2.0f);
        m_Quard.CreateQuard(quardInit[5], 2.0f);
        m_Quard.CreateQuard(quardInit[6], 2.0f);

        m_Quard.CreateQuard(quardInit[0], 0.0f);
        m_Quard.CreateQuard(quardInit[1], 1.0f);
        m_Quard.CreateQuard(quardInit[2], 0.0f);
        m_Quard.CreateQuard(quardInit[3], 1.0f);

        m_VertexBuffer = std::make_unique<spat::VertexBuffer>(nullptr, m_Quard.GetSize());

        spat::VertexBufferLayout layout;
        
        layout.Push<float>(2);
        layout.Push<float>(2);
        layout.Push<float>(1);
        
        m_VertexBuffer -> Bind();
        m_VAO -> AddBuffer(layout);

        m_IndexBuffer = std::make_unique<spat::IndexBuffer>(m_Quard.GetIndex(), m_Quard.GetIndexSize());

        m_Shader = std::make_unique<spat::Shader>("./res/shader/Chaos.vs", "./res/shader/Chaos.fs");

        m_Shader -> Bind();

        m_OscarHedgehogTex = std::make_unique<spat::Texture>("./res/textures/OscarHedgehog.png");
        m_Mistarion_catTex = std::make_unique<spat::Texture>("./res/textures/Mistarion_cat.png");
        m_Main_charactersTex = std::make_unique<spat::Texture>("./res/textures/main_characters.png");
        
        int samplers[3] = { 0, 1, 2 };
        m_Shader -> SetUniform1iv("u_Texture", 3, samplers);
    }

    void SandChaos::OnUpdate()
    {
        m_Quard.SetDegree(1, i);
        m_Quard.SetHeight(1, j);
        m_Quard.SetPosX(1, j);

        i += 0.05f;
        j += jincrease;
        if(j > 350.0f)
            jincrease = -1.0f;
        else if(j < 50.0f)
            jincrease = 1.0f;
    }

    void SandChaos::OnRender()
    {   
        glm::mat4 mvp = 
            glm::ortho(0.0f, (float)m_WinSize.width, 0.0f, (float)m_WinSize.height, -1.0f, 1.0f)
            * glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

        m_VertexBuffer -> Bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, m_Quard.GetSize(), m_Quard.GetVertex());

        m_OscarHedgehogTex -> Bind(0);
        m_Mistarion_catTex -> Bind(1);
        m_Main_charactersTex -> Bind(2);
        m_Shader -> Bind();
        
        m_Shader -> SetUniformMat4f("u_MVP", mvp);
        GLCall(glDrawElements(GL_TRIANGLES, m_IndexBuffer -> GetCount(), GL_UNSIGNED_INT, nullptr));
    }   
}