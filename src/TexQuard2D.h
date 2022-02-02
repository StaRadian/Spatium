#pragma once

#include "Math.h"
#include <vector>

namespace SPAT
{
    class TexQuard2D
    {
    private:
        std::vector<Vertex> m_Vertex;
        std::vector<VertexCache> m_VertexCache;
    public:
        float CreateQuard(const float x = 0.0f, const float y = 0.0f, 
            const float height = 100.0f, const float weight = 100.0f, const float textureID = 0.0f);
        void SetPosX(const int target, const float x);
        void SetPosY(const int target, const float y);
        void AddPosX(const int target, const float add);
        void AddPosY(const int target, const float add);
        void SetWeight(const int target, const float weight);
        void SetHeight(const int target, const float height);
        void AddWeight(const int target, const float add);
        void AddHeight(const int target, const float add);

        Vertex *GetElement(const int target) { return &(m_Vertex[target]); }
        float *GetVertex() { return &(m_Vertex[0].v0.Position.x); }
        unsigned int GetSize() { return m_Vertex.size() * sizeof(Vertex); }
    };
}