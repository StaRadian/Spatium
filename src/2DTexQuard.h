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

class 2DTexQuard
{
private:
    std::array<Vertex, 4> CreateQuard(float x, float y, float textureID);
public:
    2DTexQuard();

};