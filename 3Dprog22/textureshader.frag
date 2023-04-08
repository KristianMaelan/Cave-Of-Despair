#version 410 core

in vec2 UV;
uniform sampler2D textureSampler;
out vec3 fragmentColor;

void main()
{
    fragmentColor = texture(textureSampler, UV).rgb;
}
