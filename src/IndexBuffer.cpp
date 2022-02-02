#include "IndexBuffer.h"
#include <GL/glew.h>

#include "Debug.h"

namespace SPAT
{
    IndexBuffer::IndexBuffer(const unsigned int *data, const unsigned int count)
        :m_Count(count)
    {
        glGenBuffers(1, &m_RendererID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
    }

    IndexBuffer::~IndexBuffer()
    {

    }

    void IndexBuffer::IndexData()
    {

    }

    void IndexBuffer::Bind() const
    {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
    }

    void IndexBuffer::Unbind() const
    {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }

    unsigned int IndexBuffer::GetCount() const
    {
        return m_Count;
    }
}