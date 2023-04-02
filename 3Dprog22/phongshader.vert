#version 410

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec3 vertexUV;

out vec3 fragmentPosition;  // position of each fragment to have the dotproduct for diffuse lighting to be accurate, it will interpolate between vertices on model
out vec3 normalTransposed;  //

uniform mat4 matrix;
uniform mat4 vMatrix;
uniform mat4 pMatrix;

void main()
{
    fragmentPosition = vec3(matrix*vec4(vertexPosition, 1.0));
    normalTransposed = mat3(transpose(inverse(matrix))) * vertexNormal;

    gl_Position = pMatrix * vMatrix * vec4(vertexPosition, 1.0);
}
