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
        inline unsigned int GetCount() const { return m_Count; }
    };
}