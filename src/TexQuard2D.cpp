#include "TexQuard2D.h"

#include <math.h>

#define SIN(x) sin(x)
#define COS(x) cos(x)

namespace spat
{
    TexQuard2D::TexQuard2D()
        :m_Index0(0)
    {

    }

    TexQuard2D::~TexQuard2D()
    {

    }

    void TexQuard2D::CreateQuard(const float x, const float y, 
        const float weight, const float height, const float degree, const float textureID)
    {
        Vertex2D vex;
        VertexCache2D vexc;
        
        vexc.x = x;
        vexc.y = y;
        vexc.hWeight = weight / 2.0f;
        vexc.hHeight = height / 2.0f;
        vexc.degree = degree;

        float sind = SIN(degree);
        float cosd = COS(degree);

        float hWeightsind = vexc.hWeight * sind;
        float hWeightcosd = vexc.hWeight * cosd;
        float hHeightsind = vexc.hHeight * sind;
        float hHeightcosd = vexc.hHeight * cosd;

        vex.v0.Position2D = { x - hWeightcosd + hHeightsind, y - hWeightsind - hHeightcosd };
        vex.v0.TexCoords = { 0.0f, 0.0f };
        vex.v0.TexID = textureID;

        vex.v1.Position2D = { x + hWeightcosd + hHeightsind, y + hWeightsind - hHeightcosd };
        vex.v1.TexCoords = { 1.0f, 0.0f };
        vex.v1.TexID = textureID;

        vex.v2.Position2D = { x + hWeightcosd - hHeightsind, y + hWeightsind + hHeightcosd };
        vex.v2.TexCoords = { 1.0f, 1.0f };
        vex.v2.TexID = textureID;

        vex.v3.Position2D = { x - hWeightcosd - hHeightsind, y - hWeightsind + hHeightcosd };
        vex.v3.TexCoords = { 0.0f, 1.0f };
        vex.v3.TexID = textureID;

        m_Vertex.push_back(vex);
        m_VertexCache.push_back(vexc);
        PushIndex();
    }

    void TexQuard2D::EditQuard(const float target, const float x, const float y, 
        const float weight, const float height, const float degree, const float textureID)
    {
        m_VertexCache[target].x = x;
        m_VertexCache[target].y = y;
        m_VertexCache[target].hWeight = weight / 2.0;
        m_VertexCache[target].hHeight = height / 2.0;
        m_VertexCache[target].degree = degree;

        float sind = SIN(degree);
        float cosd = COS(degree);

        float hWeightsind = m_VertexCache[target].hWeight * sind;
        float hWeightcosd = m_VertexCache[target].hWeight * cosd;
        float hHeightsind = m_VertexCache[target].hHeight * sind;
        float hHeightcosd = m_VertexCache[target].hHeight * cosd;

        m_Vertex[target].v0.Position2D = { x - hWeightcosd + hHeightsind, y - hWeightsind - hHeightcosd };
        m_Vertex[target].v0.TexCoords = { 0.0f, 0.0f };
        m_Vertex[target].v0.TexID = textureID;

        m_Vertex[target].v1.Position2D = { x + hWeightcosd + hHeightsind, y + hWeightsind - hHeightcosd };
        m_Vertex[target].v1.TexCoords = { 1.0f, 0.0f };
        m_Vertex[target].v1.TexID = textureID;

        m_Vertex[target].v2.Position2D = { x + hWeightcosd - hHeightsind, y + hWeightsind + hHeightcosd };
        m_Vertex[target].v2.TexCoords = { 1.0f, 1.0f };
        m_Vertex[target].v2.TexID = textureID;

        m_Vertex[target].v3.Position2D = { x - hWeightcosd - hHeightsind, y - hWeightsind + hHeightcosd };
        m_Vertex[target].v3.TexCoords = { 0.0f, 1.0f };
        m_Vertex[target].v3.TexID = textureID;
    }

    void TexQuard2D::SetPosX(const int target, const float x)
    {
        float add = x - m_VertexCache[target].x;
        m_Vertex[target].v0.Position2D.x += add;
        m_Vertex[target].v1.Position2D.x += add;
        m_Vertex[target].v2.Position2D.x += add;
        m_Vertex[target].v3.Position2D.x += add;
        m_VertexCache[target].x += add;
    }

    void TexQuard2D::SetPosY(const int target, const float y)
    {
        float add = y - m_VertexCache[target].y;
        m_Vertex[target].v0.Position2D.y += add;
        m_Vertex[target].v1.Position2D.y += add;
        m_Vertex[target].v2.Position2D.y += add;
        m_Vertex[target].v3.Position2D.y += add;
        m_VertexCache[target].y += add;
    }

    void TexQuard2D::SetPosXY(const int target, const float x, const float y)
    {
        float addx = x - m_VertexCache[target].x;
        float addy = y - m_VertexCache[target].y;
        m_Vertex[target].v0.Position2D.x += addx;
        m_Vertex[target].v1.Position2D.x += addx;
        m_Vertex[target].v2.Position2D.x += addx;
        m_Vertex[target].v3.Position2D.x += addx;
        m_Vertex[target].v0.Position2D.y += addy;
        m_Vertex[target].v1.Position2D.y += addy;
        m_Vertex[target].v2.Position2D.y += addy;
        m_Vertex[target].v3.Position2D.y += addy;
        m_VertexCache[target].x += addx;
        m_VertexCache[target].y += addy;
    }

    void TexQuard2D::AddPosX(const int target, const float add)
    {
        m_Vertex[target].v0.Position2D.x += add;
        m_Vertex[target].v1.Position2D.x += add;
        m_Vertex[target].v2.Position2D.x += add;
        m_Vertex[target].v3.Position2D.x += add;
        m_VertexCache[target].x += add;
    }

    void TexQuard2D::AddPosY(const int target, const float add)
    {
        m_Vertex[target].v0.Position2D.y += add;
        m_Vertex[target].v1.Position2D.y += add;
        m_Vertex[target].v2.Position2D.y += add;
        m_Vertex[target].v3.Position2D.y += add;
        m_VertexCache[target].y += add;
    }

    void TexQuard2D::AddPosXY(const int target, const float addx, const float addy)
    {
        m_Vertex[target].v0.Position2D.x += addx;
        m_Vertex[target].v1.Position2D.x += addx;
        m_Vertex[target].v2.Position2D.x += addx;
        m_Vertex[target].v3.Position2D.x += addx;
        m_Vertex[target].v0.Position2D.y += addy;
        m_Vertex[target].v1.Position2D.y += addy;
        m_Vertex[target].v2.Position2D.y += addy;
        m_Vertex[target].v3.Position2D.y += addy;
        m_VertexCache[target].x += addx;
        m_VertexCache[target].y += addy;
    }

    void TexQuard2D::SetWeight(const int target, const float weight)
    {
        float hweight = (weight / 2.0f);
        float addweight = hweight - m_VertexCache[target].hWeight;
        float degree = m_VertexCache[target].degree;
        float addx = addweight * cos(degree);
        float addy = addweight * sin(degree);

        m_Vertex[target].v0.Position2D.x -= addx;
        m_Vertex[target].v1.Position2D.x += addx;
        m_Vertex[target].v2.Position2D.x += addx;
        m_Vertex[target].v3.Position2D.x -= addx;
        m_Vertex[target].v0.Position2D.y -= addy;
        m_Vertex[target].v1.Position2D.y += addy;
        m_Vertex[target].v2.Position2D.y += addy;
        m_Vertex[target].v3.Position2D.y -= addy;
        m_VertexCache[target].hWeight = hweight;
    }
    void TexQuard2D::SetHeight(const int target, const float height)
    {
        float hheight = (height / 2.0f);
        float addweight = hheight - m_VertexCache[target].hHeight;
        float degree = m_VertexCache[target].degree;
        float addx = addweight * sin(degree);
        float addy = addweight * cos(degree);

        m_Vertex[target].v0.Position2D.x += addx;
        m_Vertex[target].v1.Position2D.x += addx;
        m_Vertex[target].v2.Position2D.x -= addx;
        m_Vertex[target].v3.Position2D.x -= addx;
        m_Vertex[target].v0.Position2D.y -= addy;
        m_Vertex[target].v1.Position2D.y -= addy;
        m_Vertex[target].v2.Position2D.y += addy;
        m_Vertex[target].v3.Position2D.y += addy;
        m_VertexCache[target].hHeight = hheight;
    }
    void TexQuard2D::SetSize(const int target, const float weight, const float height)
    {

    }
    void TexQuard2D::AddWeight(const int target, const float add)
    {

    }
    void TexQuard2D::AddHeight(const int target, const float add)
    {

    }
    void TexQuard2D::AddSize(const int target, const float addWeight, const float addHeight)
    {

    }
    void TexQuard2D::SetDegree(const int target, const float degree)
    {
        float sind = SIN(degree);
        float cosd = COS(degree);

        float hWeightsind = m_VertexCache[target].hWeight * sind;
        float hWeightcosd = m_VertexCache[target].hWeight * cosd;
        float hHeightsind = m_VertexCache[target].hHeight * sind;
        float hHeightcosd = m_VertexCache[target].hHeight * cosd;

        m_Vertex[target].v0.Position2D = { m_VertexCache[target].x - hWeightcosd + hHeightsind, m_VertexCache[target].y - hWeightsind - hHeightcosd };
        m_Vertex[target].v1.Position2D = { m_VertexCache[target].x + hWeightcosd + hHeightsind, m_VertexCache[target].y + hWeightsind - hHeightcosd };
        m_Vertex[target].v2.Position2D = { m_VertexCache[target].x + hWeightcosd - hHeightsind, m_VertexCache[target].y + hWeightsind + hHeightcosd };
        m_Vertex[target].v3.Position2D = { m_VertexCache[target].x - hWeightcosd - hHeightsind, m_VertexCache[target].y - hWeightsind + hHeightcosd };

        m_VertexCache[target].degree = degree;
    }

    void TexQuard2D::PushIndex()
    {
        m_Index.push_back({m_Index0, m_Index0 + 1, m_Index0 + 2, m_Index0 + 2, m_Index0 + 3, m_Index0});
        m_Index0 += 4;
    }
}