#include "Quard2D.h"

namespace spat
{
    Quard2D::Quard2D()
        :m_Index0(0)
    {

    }

    Quard2D::~Quard2D()
    {

    }

    void Quard2D::PushIndex()
    {
        m_Index.push_back({m_Index0, m_Index0 + 1, m_Index0 + 2, m_Index0 + 2, m_Index0 + 3, m_Index0});
        m_Index0 += 4;
    }
}