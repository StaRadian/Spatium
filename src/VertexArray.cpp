#include "VertexArray.h"

#include "Debug.h"

namespace SPAT
{
    VertexArray::VertexArray()
    {
        GLCall(glGenVertexArrays(1, &m_RendererID));
        Bind();
    }

    VertexArray::~VertexArray()
    {
        GLCall(glDeleteVertexArrays(1, &m_RendererID));
    }

    void VertexArray::AddBuffer(const VertexBufferLayout &layout)
    {
        const auto& elements = layout.GetElements();
        unsigned int offset = 0;
        
        for(int i = 0; i < elements.size(); i++)
        {
            auto& element = elements[i];
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, element.count, element.type, element.normalized,
                layout.GetStride(), (const void*)offset);
            offset += element.count * sizeof(element.type);
        }
    }

    void VertexArray::Bind() const
    {
        GLCall(glBindVertexArray(m_RendererID));
    }

    void VertexArray::Unbind() const
    {
        GLCall(glBindVertexArray(0));
    }
}