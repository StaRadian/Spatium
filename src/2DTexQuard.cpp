#include "2DTexQuard.h"

std::array<Vertex, 4> 2DTexQuard::CreateQuard(float x, float y, float textureID)
{
    float size = 100.0f;

    Vertex v0;
    v0.Position = { x, y, 0.0f };
    v0.TexCoords = { 0.0f, 0.0f };
    v0.TexID = textureID;
    
    Vertex v1;
    v1.Position = { x + size, y, 0.0f };
    v1.TexCoords = { 1.0f, 0.0f };
    v1.TexID = textureID;
    
    Vertex v2;
    v2.Position = { x + size, y + size, 0.0f };
    v2.TexCoords = { 1.0f, 1.0f };
    v2.TexID = textureID;
    
    Vertex v3;
    v3.Position = { x, y + size, 0.0f };
    v3.TexCoords = { 0.0f, 1.0f };
    v3.TexID = textureID;

    return { v0, v1, v2 ,v3 };
}