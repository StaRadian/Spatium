#pragma once

struct Vec3
{
    float x, y, z;
};

struct Vec2
{
    float x, y;
};

struct Vertex
{
    Vec3 Position;
    Vec2 TexCoords;
    float TexID;
};

class TexQuard2D
{
private:
public:
    TexQuard2D();

};