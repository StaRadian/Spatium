#pragma once

#include "src/VertexArray.h"
#include "src/VertexBuffer.h"
#include "src/IndexBuffer.h"
#include "src/Shader.h"
#include "src/Texture.h"
#include "src/TexQuard2D.h"

#include <memory>

namespace box
{
    class Sandbox
    {
    private:
        std::unique_ptr<spat::VertexArray> m_VAO;
        std::unique_ptr<spat::VertexBuffer> m_VertexBuffer;
        std::unique_ptr<spat::IndexBuffer> m_IndexBuffer;
        std::unique_ptr<spat::Shader> m_Shader;
        std::unique_ptr<spat::Texture> m_OscarHedgehogTex, m_Mistarion_catTex;
        spat::TexQuard2D m_Quard;
        
        float i = 0.0f;
        float j = 200.0f;
        float jincrease = 1.0f;
    public:
        Sandbox();
        ~Sandbox();
        void OnRender();
    };
}