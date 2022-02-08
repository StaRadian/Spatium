#pragma once

#include "VertexMat.h"
#include <vector>

namespace spat
{
    class TexQuard2D
    {
    private:
        std::vector<Vertex2D> m_Vertex;
        std::vector<VertexCache2D> m_VertexCache;
        std::vector<IndexElement> m_Index;
        unsigned int m_Index0;

        void PushIndex();
    public:
        TexQuard2D();
        ~TexQuard2D();
        void CreateQuard(const VertexCache2D& num, const float textureID);
        void EditQuard(const int target, const float x, const float y, 
        const float width, const float height, const float degree, const float textureID);

        void SetPosX(const int target, const float x);
        void SetPosY(const int target, const float y);
        void SetPosXY(const int target, const float x, const float y);
        void AddPosX(const int target, const float add);
        void AddPosY(const int target, const float add);
        void AddPosXY(const int target, const float addx, const float addy);

        void SetWidth(const int target, const float width);
        void SetHeight(const int target, const float height);
        void SetSize(const int target, const float width, const float height);
        void AddWidth(const int target, const float add);
        void AddHeight(const int target, const float add);
        void AddSize(const int target, const float addWidth, const float addHeight);

        void SetDegree(const int target, const float degree);

        inline Vertex2D *GetElement(const int target) { return &(m_Vertex[target]); }
        inline float *GetVertex() { return &(m_Vertex[0].v0.Position2D.x); }
        inline unsigned int GetSize() const { return m_Vertex.size() * sizeof(Vertex2D); }
        inline unsigned int *GetIndex() { return &(m_Index[0].i0);};
        inline unsigned int GetIndexSize() const { return m_Index.size() * 6;};
    };
}