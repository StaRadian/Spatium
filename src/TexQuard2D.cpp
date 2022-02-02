#include "TexQuard2D.h"

namespace SPAT
{
    float TexQuard2D::CreateQuard(const float x, const float y, 
        const float weight, const float height, const float textureID)
    {
        Vertex vertex;
        VertexCache vertexCache;
        vertexCache.height = height;
        vertexCache.weight = weight;

        vertex.v0.Position = { x, y, 0.0f };
        vertex.v0.TexCoords = { 0.0f, 0.0f };
        vertex.v0.TexID = textureID;

        vertex.v1.Position = { x + weight, y, 0.0f };
        vertex.v1.TexCoords = { 1.0f, 0.0f };
        vertex.v1.TexID = textureID;

        vertex.v2.Position = { x + weight, y + height, 0.0f };
        vertex.v2.TexCoords = { 1.0f, 1.0f };
        vertex.v2.TexID = textureID;

        vertex.v3.Position = { x, y + height, 0.0f };
        vertex.v3.TexCoords = { 0.0f, 1.0f };
        vertex.v3.TexID = textureID;

        m_Vertex.push_back(vertex);
        m_VertexCache.push_back(vertexCache);

        return textureID;
    }

    void TexQuard2D::SetPosX(const int target, const float x)
    {
        m_Vertex[target].v0.Position.x = x;
        m_Vertex[target].v1.Position.x = x + m_VertexCache[target].weight;
        m_Vertex[target].v2.Position.x = x + m_VertexCache[target].weight;
        m_Vertex[target].v3.Position.x = x;
    }

    void TexQuard2D::SetPosY(const int target, const float y)
    {
        m_Vertex[target].v0.Position.y = y;
        m_Vertex[target].v1.Position.y = y;
        m_Vertex[target].v2.Position.y = y + m_VertexCache[target].height;
        m_Vertex[target].v3.Position.y = y + m_VertexCache[target].height;
    }

    void TexQuard2D::AddPosX(const int target, const float add)
    {
        m_Vertex[target].v0.Position.x += add;
        m_Vertex[target].v1.Position.x += add;
        m_Vertex[target].v2.Position.x += add;
        m_Vertex[target].v3.Position.x += add;
    }

    void TexQuard2D::AddPosY(const int target, const float add)
    {
        m_Vertex[target].v0.Position.y += add;
        m_Vertex[target].v1.Position.y += add;
        m_Vertex[target].v2.Position.y += add;
        m_Vertex[target].v3.Position.y += add;
    }

    void TexQuard2D::SetWeight(const int target, const float weight)
    {
        float add = weight - m_VertexCache[target].weight;

        m_Vertex[target].v1.Position.x += add;
        m_Vertex[target].v2.Position.x += add;

        m_VertexCache[target].weight = weight;
    }

    void TexQuard2D::SetHeight(const int target, const float height)
    {
        float add = height - m_VertexCache[target].height;

        m_Vertex[target].v2.Position.y += add;
        m_Vertex[target].v3.Position.y += add;

        m_VertexCache[target].height = height;
    }

    void TexQuard2D::AddWeight(const int target, const float add)
    {
        m_Vertex[target].v1.Position.x += add;
        m_Vertex[target].v2.Position.x += add;

        m_VertexCache[target].weight += add;
    }

    void TexQuard2D::AddHeight(const int target, const float add)
    {
        m_Vertex[target].v2.Position.y += add;
        m_Vertex[target].v3.Position.y += add;

        m_VertexCache[target].height += add;
    }
}