#pragma once

namespace SPAT
{
    struct Vec3
    {
        float x, y, z;
    };

    struct Vec2
    {
        float x, y;
    };

    struct VertexElement
    {
        Vec3 Position;
        Vec2 TexCoords;
        float TexID;
    };

    struct Vertex
    {
        VertexElement v0;
        VertexElement v1;
        VertexElement v2;
        VertexElement v3;
    };

    struct VertexCache
    {
        float weight;
        float height;
    };
}