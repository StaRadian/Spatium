#pragma once

namespace SPAT
{
    class IndexBuffer
    {
    private:
        unsigned int m_RendererID;
        unsigned int m_Count;
        void IndexData();
    public:
        IndexBuffer(const unsigned int *data, const unsigned int count);
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;
        unsigned int GetCount() const;
    };
}