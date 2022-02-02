#pragma once

#include "VertexMat.h"
#include <vector>

namespace SPAT
{
    class TexQuard2D
    {
    private:
        std::vector<Vertex2D> m_Vertex;
        std::vector<VertexCache2D> m_VertexCache;
    public:
        void CreateQuard(const float textureID = 0.0f, const float x = 0.0f, const float y = 0.0f, 
            const float weight = 0.0f, const float height = 0.0f, const float degree = 0.0f);
        void EditQuard(const float target, const float x, const float y, 
        const float weight, const float height, const float degree, const float textureID);

        void SetPosX(const int target, const float x);
        void SetPosY(const int target, const float y);
        void SetPosXY(const int target, const float x, const float y);
        void AddPosX(const int target, const float add);
        void AddPosY(const int target, const float add);
        void AddPosXY(const int target, const float addx, const float addy);

        void SetWeight(const int target, const float weight);
        void SetHeight(const int target, const float height);
        void SetSize(const int target, const float weight, const float height);
        void AddWeight(const int target, const float add);
        void AddHeight(const int target, const float add);
        void AddSize(const int target, const float addWeight, const float addHeight);

        Vertex2D *GetElement(const int target) { return &(m_Vertex[target]); }
        float *GetVertex() { return &(m_Vertex[0].v0.Position2D.x); }
        unsigned int GetSize() { return m_Vertex.size() * sizeof(Vertex2D); }
    };
}