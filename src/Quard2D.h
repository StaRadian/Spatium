#pragma once

#include "VertexMat.h"
#include <vector>

namespace spat
{
    class Quard2D
    {
    private:
        std::vector<IndexElement> m_Index;
        unsigned int m_Index0;
    protected:
        void PushIndex();
    public:
        Quard2D();
        ~Quard2D();
        inline unsigned int *GetIndex() { return &(m_Index[0].i0);};
        inline unsigned int GetIndexSize() const { return m_Index.size() * 6;};
    };
}