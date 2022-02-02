#include "VertexBuffer.h"

#include <GL/glew.h>

#include "Debug.h"

namespace SPAT
{
    VertexBuffer::VertexBuffer(const void* data, const unsigned int size)
    {
        GLCall(glGenBuffers(1, &m_RendererID));
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
    }

    VertexBuffer::~VertexBuffer()
    {
        GLCall(glDeleteBuffers(1, &m_RendererID));
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}