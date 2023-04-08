#version 410 core

layout(location = 0) in vec4 positionIn;
layout(location = 1) in vec4 colorIn;
layout(location = 2) in vec2 vertexUV;

out vec4 color;
out vec2 UV;
uniform mat4 matrix;
uniform mat4 vMatrix;
uniform mat4 pMatrix;

void main()
{
    color = colorIn;
    UV = vertexUV;
    gl_Position = pMatrix * vMatrix * matrix * positionIn;
}
