#version 410

layout(location = 0) in vec3 vertexPosition;    //
layout(location = 1) in vec3 vertexNormal;      //
layout(location = 2) in vec2 vertexUV;          //

// information output (result from work with shader)
out vec3 fragmentPosition;
out vec3 normalTransposed;
out vec3 color;                // correspondingly named Normal in fragment shader
out vec2 UV;

// information in through uniform
uniform mat4 matrix;
uniform mat4 vMatrix;
uniform mat4 pMatrix;

void main()
{
    fragmentPosition = vec3( matrix * vec4( vertexPosition, 1.0));
    normalTransposed = mat3( transpose( inverse ( matrix ))) *vertexNormal;

    UV = vertexUV;
    color = vertexNormal;

    gl_Position = pMatrix * vMatrix * matrix * vec4( vertexPosition, 1.0);
}
