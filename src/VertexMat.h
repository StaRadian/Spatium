#pragma once

#define PI 3.1415926

namespace SPAT
{
    struct Vec2
    {
        float x, y;
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
        float x, y;
        float hWeight;
        float hHeight;
        float degree;
    };
}