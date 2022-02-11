#version 460 core

layout(location = 0) out vec4 color;
uniform sampler2D u_Texture[1];

in vec2 v_TexCoord;
in float v_TexIndex;

void main()
{
   int index = int(v_TexIndex);
   vec4 texColor = texture(u_Texture[index], v_TexCoord);
   color = texColor;
};