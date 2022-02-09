#include "TexQuard2D.h"

#include <math.h>

#define SIN(x) sin(x)
#define COS(x) cos(x)

namespace spat
{
    TexQuard2D::TexQuard2D()
    {

    }

    TexQuard2D::~TexQuard2D()
    {

    }

    void TexQuard2D::CreateQuard(const PosSizeData& num, const PosSizeData& ptr_num, const float textureID)
    {
        Vertex2D vex;

        Vec2 hsize = {
            num.size.x / 2.0f, 
            num.size.y / 2.0f};

        vex.v0.Position2D = { num.pos.x - hsize.x, num.pos.y - hsize.y };
        vex.v0.TexCoords = { ptr_num.pos.x, ptr_num.pos.y };
        vex.v0.TexID = textureID;

        vex.v1.Position2D = { num.pos.x + hsize.x, num.pos.y - hsize.y };
        vex.v1.TexCoords = { ptr_num.pos.x + ptr_num.size.x, ptr_num.pos.y };
        vex.v1.TexID = textureID;

        vex.v2.Position2D = { num.pos.x + hsize.x, num.pos.y + hsize.y };
        vex.v2.TexCoords = { ptr_num.pos.x + ptr_num.size.x, ptr_num.pos.y + ptr_num.size.y };
        vex.v2.TexID = textureID;

        vex.v3.Position2D = { num.pos.x - hsize.x, num.pos.y + hsize.y };
        vex.v3.TexCoords = { ptr_num.pos.x, ptr_num.pos.y + ptr_num.size.y };
        vex.v3.TexID = textureID;

        m_Vertex.push_back(vex);
        m_VertexCache.push_back({ num.size, hsize, {0.0f, 1.0f, 0.0f} });
        PushIndex();
    }

    void TexQuard2D::EditQuard(const int& target, const PosSizeData& num, const PosSizeData& ptr_num, const float textureID)
    {
        Vec2 hsize = {
        num.size.x / 2.0f, 
        num.size.y / 2.0f};

        m_Vertex[target].v0.Position2D = { num.pos.x - hsize.x, num.pos.y - hsize.y };
        m_Vertex[target].v0.TexCoords = { ptr_num.pos.x, ptr_num.pos.y };
        m_Vertex[target].v0.TexID = textureID;

        m_Vertex[target].v1.Position2D = { num.pos.x + hsize.x, num.pos.y - hsize.y };
        m_Vertex[target].v1.TexCoords = { ptr_num.pos.x + ptr_num.size.x, ptr_num.pos.y };
        m_Vertex[target].v1.TexID = textureID;

        m_Vertex[target].v2.Position2D = { num.pos.x + hsize.x, num.pos.y + hsize.y };
        m_Vertex[target].v2.TexCoords = { ptr_num.pos.x + ptr_num.size.x, ptr_num.pos.y + ptr_num.size.y };
        m_Vertex[target].v2.TexID = textureID;

        m_Vertex[target].v3.Position2D = { num.pos.x - hsize.x, num.pos.y + hsize.y };
        m_Vertex[target].v3.TexCoords = { ptr_num.pos.x, ptr_num.pos.y + ptr_num.size.y };
        m_Vertex[target].v3.TexID = textureID;

        m_VertexCache[target].pos = num.pos;
        m_VertexCache[target].hsize = hsize;
    }

    void TexQuard2D::SetPosX(const int& target, const float x)
    {
        float add = x - m_VertexCache[target].pos.x;
        m_Vertex[target].v0.Position2D.x += add;
        m_Vertex[target].v1.Position2D.x += add;
        m_Vertex[target].v2.Position2D.x += add;
        m_Vertex[target].v3.Position2D.x += add;
        m_VertexCache[target].pos.x += add;
    }

    void TexQuard2D::SetPosY(const int& target, const float y)
    {
        float add = y - m_VertexCache[target].pos.y;
        m_Vertex[target].v0.Position2D.y += add;
        m_Vertex[target].v1.Position2D.y += add;
        m_Vertex[target].v2.Position2D.y += add;
        m_Vertex[target].v3.Position2D.y += add;
        m_VertexCache[target].pos.y += add;
    }

    void TexQuard2D::SetPosXY(const int& target, const float x, const float y)
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

    void TexQuard2D::AddPosX(const int& target, const float add)
    {
        m_Vertex[target].v0.Position2D.x += add;
        m_Vertex[target].v1.Position2D.x += add;
        m_Vertex[target].v2.Position2D.x += add;
        m_Vertex[target].v3.Position2D.x += add;
        m_VertexCache[target].pos.x += add;
    }

    void TexQuard2D::AddPosY(const int& target, const float add)
    {
        m_Vertex[target].v0.Position2D.y += add;
        m_Vertex[target].v1.Position2D.y += add;
        m_Vertex[target].v2.Position2D.y += add;
        m_Vertex[target].v3.Position2D.y += add;
        m_VertexCache[target].pos.y += add;
    }

    void TexQuard2D::AddPosXY(const int& target, const float addx, const float addy)
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

    void TexQuard2D::SetWidth(const int& target, const float width)
    {
        float hwidth = (width / 2.0f);
        float addwidth = hwidth - m_VertexCache[target].hsize.x;
        float addx = addwidth * m_VertexCache[target].trig.cosd;
        float addy = addwidth * m_VertexCache[target].trig.sind;

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
    void TexQuard2D::SetHeight(const int& target, const float height)
    {
        float hheight = (height / 2.0f);
        float addwidth = hheight - m_VertexCache[target].hsize.y;
        float addx = addwidth * m_VertexCache[target].trig.sind;
        float addy = addwidth * m_VertexCache[target].trig.cosd;

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
    void TexQuard2D::SetSize(const int& target, const float width, const float height)
    {

    }
    void TexQuard2D::AddWidth(const int& target, const float add)
    {

    }
    void TexQuard2D::AddHeight(const int& target, const float add)
    {

    }
    void TexQuard2D::AddSize(const int& target, const float addWidth, const float addHeight)
    {

    }
    void TexQuard2D::SetDegree(const int& target, const float degree)
    {
        m_VertexCache[target].trig.sind = SIN(degree);
        m_VertexCache[target].trig.cosd = COS(degree);
        m_VertexCache[target].trig.degree = degree;

        float hWidthsind = m_VertexCache[target].hsize.x * m_VertexCache[target].trig.sind;
        float hWidthcosd = m_VertexCache[target].hsize.x * m_VertexCache[target].trig.cosd;
        float hHeightsind = m_VertexCache[target].hsize.y * m_VertexCache[target].trig.sind;
        float hHeightcosd = m_VertexCache[target].hsize.y * m_VertexCache[target].trig.cosd;

        m_Vertex[target].v0.Position2D = { m_VertexCache[target].pos.x - hWidthcosd + hHeightsind, m_VertexCache[target].pos.y - hWidthsind - hHeightcosd };
        m_Vertex[target].v1.Position2D = { m_VertexCache[target].pos.x + hWidthcosd + hHeightsind, m_VertexCache[target].pos.y + hWidthsind - hHeightcosd };
        m_Vertex[target].v2.Position2D = { m_VertexCache[target].pos.x + hWidthcosd - hHeightsind, m_VertexCache[target].pos.y + hWidthsind + hHeightcosd };
        m_Vertex[target].v3.Position2D = { m_VertexCache[target].pos.x - hWidthcosd - hHeightsind, m_VertexCache[target].pos.y - hWidthsind + hHeightcosd };
    }
}