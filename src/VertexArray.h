#pragma once
#include "VertexBufferLayout.h"

namespace SPAT
{
    class VertexArray
    {
    private:
        unsigned int m_RendererID;
    public:
        VertexArray();
        ~VertexArray();

        void AddBuffer(const VertexBufferLayout &layout);

        void Bind() const;
        void Unbind() const;
    };
}