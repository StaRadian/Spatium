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

    void TexQuard2D::CreateQuard(const VertexCache2D& num, const float textureID)
    {
        Vertex2D vex;

        float sind = SIN(num.degree);
        float cosd = COS(num.degree);

        float hWidthsind = num.hsize.x * sind;
        float hWidthcosd = num.hsize.x * cosd;
        float hHeightsind = num.hsize.y * sind;
        float hHeightcosd = num.hsize.y * cosd;

        vex.v0.Position2D = { num.pos.x - hWidthcosd + hHeightsind, num.pos.y - hWidthsind - hHeightcosd };
        vex.v0.TexCoords = { num.pctpos.x, num.pctpos.y };
        vex.v0.TexID = textureID;

        vex.v1.Position2D = { num.pos.x + hWidthcosd + hHeightsind, num.pos.y + hWidthsind - hHeightcosd };
        vex.v1.TexCoords = { num.pctpos.x + num.pctsize.x, num.pctpos.y };
        vex.v1.TexID = textureID;

        vex.v2.Position2D = { num.pos.x + hWidthcosd - hHeightsind, num.pos.y + hWidthsind + hHeightcosd };
        vex.v2.TexCoords = { num.pctpos.x + num.pctsize.x, num.pctpos.y + num.pctsize.y };
        vex.v2.TexID = textureID;

        vex.v3.Position2D = { num.pos.x - hWidthcosd - hHeightsind, num.pos.y - hWidthsind + hHeightcosd };
        vex.v3.TexCoords = { num.pctpos.x, num.pctpos.y + num.pctsize.y };
        vex.v3.TexID = textureID;

        m_Vertex.push_back(vex);
        m_VertexCache.push_back(num);
        PushIndex();
    }

    void TexQuard2D::EditQuard(const int target, const float x, const float y, 
        const float width, const float height, const float degree, const float textureID)
    {
        m_VertexCache[target].pos.x = x;
        m_VertexCache[target].pos.y = y;
        m_VertexCache[target].hsize.x = width / 2.0;
        m_VertexCache[target].hsize.y = height / 2.0;
        m_VertexCache[target].degree = degree;

        float sind = SIN(degree);
        float cosd = COS(degree);

        float hWidthsind = m_VertexCache[target].hsize.x * sind;
        float hWidthcosd = m_VertexCache[target].hsize.x * cosd;
        float hHeightsind = m_VertexCache[target].hsize.y * sind;
        float hHeightcosd = m_VertexCache[target].hsize.y * cosd;

        m_Vertex[target].v0.Position2D = { x - hWidthcosd + hHeightsind, y - hWidthsind - hHeightcosd };
        m_Vertex[target].v0.TexCoords = { 0.0f, 0.0f };
        m_Vertex[target].v0.TexID = textureID;

        m_Vertex[target].v1.Position2D = { x + hWidthcosd + hHeightsind, y + hWidthsind - hHeightcosd };
        m_Vertex[target].v1.TexCoords = { 1.0f , 0.0f };
        m_Vertex[target].v1.TexID = textureID;

        m_Vertex[target].v2.Position2D = { x + hWidthcosd - hHeightsind, y + hWidthsind + hHeightcosd };
        m_Vertex[target].v2.TexCoords = { 1.0f , 1.0f };
        m_Vertex[target].v2.TexID = textureID;

        m_Vertex[target].v3.Position2D = { x - hWidthcosd - hHeightsind, y - hWidthsind + hHeightcosd };
        m_Vertex[target].v3.TexCoords = { 0.0f, 1.0f };
        m_Vertex[target].v3.TexID = textureID;
    }

    void TexQuard2D::SetPosX(const int target, const float x)
    {
        float add = x - m_VertexCache[target].pos.x;
        m_Vertex[target].v0.Position2D.x += add;
        m_Vertex[target].v1.Position2D.x += add;
        m_Vertex[target].v2.Position2D.x += add;
        m_Vertex[target].v3.Position2D.x += add;
        m_VertexCache[target].pos.x += add;
    }

    void TexQuard2D::SetPosY(const int target, const float y)
    {
        float add = y - m_VertexCache[target].pos.y;
        m_Vertex[target].v0.Position2D.y += add;
        m_Vertex[target].v1.Position2D.y += add;
        m_Vertex[target].v2.Position2D.y += add;
        m_Vertex[target].v3.Position2D.y += add;
        m_VertexCache[target].pos.y += add;
    }

    void TexQuard2D::SetPosXY(const int target, const float x, const float y)
    {
        float addx = x - m_VertexCache[target].pos.x;
        float addy = y - m_VertexCache[target].pos.y;
        m_Vertex[target].v0.Position2D.x += addx;
        m_Vertex[target].v1.Position2D.x += addx;
        m_Vertex[target].v2.Position2D.x += addx;
        m_Vertex[target].v3.Position2D.x += addx;
        m_Vertex[target].v0.Position2D.y += addy;
        m_Vertex[target].v1.Position2D.y += addy;
        m_Vertex[target].v2.Position2D.y += addy;
        m_Vertex[target].v3.Position2D.y += addy;
        m_VertexCache[target].pos.x += addx;
        m_VertexCache[target].pos.y += addy;
    }

    void TexQuard2D::AddPosX(const int target, const float add)
    {
        m_Vertex[target].v0.Position2D.x += add;
        m_Vertex[target].v1.Position2D.x += add;
        m_Vertex[target].v2.Position2D.x += add;
        m_Vertex[target].v3.Position2D.x += add;
        m_VertexCache[target].pos.x += add;
    }

    void TexQuard2D::AddPosY(const int target, const float add)
    {
        m_Vertex[target].v0.Position2D.y += add;
        m_Vertex[target].v1.Position2D.y += add;
        m_Vertex[target].v2.Position2D.y += add;
        m_Vertex[target].v3.Position2D.y += add;
        m_VertexCache[target].pos.y += add;
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
        m_VertexCache[target].pos.x += addx;
        m_VertexCache[target].pos.y += addy;
    }

    void TexQuard2D::SetWidth(const int target, const float width)
    {
        float hwidth = (width / 2.0f);
        float addwidth = hwidth - m_VertexCache[target].hsize.x;
        float degree = m_VertexCache[target].degree;
        float addx = addwidth * cos(degree);
        float addy = addwidth * sin(degree);

        m_Vertex[target].v0.Position2D.x -= addx;
        m_Vertex[target].v1.Position2D.x += addx;
        m_Vertex[target].v2.Position2D.x += addx;
        m_Vertex[target].v3.Position2D.x -= addx;
        m_Vertex[target].v0.Position2D.y -= addy;
        m_Vertex[target].v1.Position2D.y += addy;
        m_Vertex[target].v2.Position2D.y += addy;
        m_Vertex[target].v3.Position2D.y -= addy;
        m_VertexCache[target].hsize.x = hwidth;
    }
    void TexQuard2D::SetHeight(const int target, const float height)
    {
        float hheight = (height / 2.0f);
        float addwidth = hheight - m_VertexCache[target].hsize.y;
        float degree = m_VertexCache[target].degree;
        float addx = addwidth * sin(degree);
        float addy = addwidth * cos(degree);

        m_Vertex[target].v0.Position2D.x += addx;
        m_Vertex[target].v1.Position2D.x += addx;
        m_Vertex[target].v2.Position2D.x -= addx;
        m_Vertex[target].v3.Position2D.x -= addx;
        m_Vertex[target].v0.Position2D.y -= addy;
        m_Vertex[target].v1.Position2D.y -= addy;
        m_Vertex[target].v2.Position2D.y += addy;
        m_Vertex[target].v3.Position2D.y += addy;
        m_VertexCache[target].hsize.y = hheight;
    }
    void TexQuard2D::SetSize(const int target, const float width, const float height)
    {

    }
    void TexQuard2D::AddWidth(const int target, const float add)
    {

    }
    void TexQuard2D::AddHeight(const int target, const float add)
    {

    }
    void TexQuard2D::AddSize(const int target, const float addWidth, const float addHeight)
    {

    }
    void TexQuard2D::SetDegree(const int target, const float degree)
    {
        float sind = SIN(degree);
        float cosd = COS(degree);

        float hWidthsind = m_VertexCache[target].hsize.x * sind;
        float hWidthcosd = m_VertexCache[target].hsize.x * cosd;
        float hHeightsind = m_VertexCache[target].hsize.y * sind;
        float hHeightcosd = m_VertexCache[target].hsize.y * cosd;

        m_Vertex[target].v0.Position2D = { m_VertexCache[target].pos.x - hWidthcosd + hHeightsind, m_VertexCache[target].pos.y - hWidthsind - hHeightcosd };
        m_Vertex[target].v1.Position2D = { m_VertexCache[target].pos.x + hWidthcosd + hHeightsind, m_VertexCache[target].pos.y + hWidthsind - hHeightcosd };
        m_Vertex[target].v2.Position2D = { m_VertexCache[target].pos.x + hWidthcosd - hHeightsind, m_VertexCache[target].pos.y + hWidthsind + hHeightcosd };
        m_Vertex[target].v3.Position2D = { m_VertexCache[target].pos.x - hWidthcosd - hHeightsind, m_VertexCache[target].pos.y - hWidthsind + hHeightcosd };

        m_VertexCache[target].degree = degree;
    }

    void TexQuard2D::PushIndex()
    {
        m_Index.push_back({m_Index0, m_Index0 + 1, m_Index0 + 2, m_Index0 + 2, m_Index0 + 3, m_Index0});
        m_Index0 += 4;
    }
}