#pragma once

#define PI 3.1415926

namespace spat
{
    struct Vec2
    {
        float x, y;
    };

    struct TrigData
    {
        float sind;
        float cosd;
        float degree;
    };

    struct PosSizeData
    {
        Vec2 pos;
        Vec2 size;
    };

    struct VertexElement
    {
        Vec2 Position2D;
        Vec2 TexCoords;
        float TexID;
    };

    struct Vertex2D
    {
        VertexElement v0;
        VertexElement v1;
        VertexElement v2;
        VertexElement v3;
    };

    struct VertexCache2D
    {
        Vec2 pos;
        Vec2 hsize; //half size
        TrigData trig;
    };

    struct IndexElement
    {
        unsigned int i0;
        unsigned int i1;
        unsigned int i2;
        unsigned int i3;
        unsigned int i4;
        unsigned int i5;
    };
}