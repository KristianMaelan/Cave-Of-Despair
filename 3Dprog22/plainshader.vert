#version 410 core

layout(location = 0) in vec4 positionIn;   // 1st attribute buffer = vertex positions
layout(location = 1) in vec4 colorIn;   // 2nd attribute buffer = colors
// heightmap
layout(location = 2) in vec2 textureCoordIn;
out vec2 textureCoord;
out vec4 normal;    // Usikker
out vec3 fragPos;   // Usikker
out vec4 displacedPosition;

out vec4 color;                           //color sent to rest of pipeline
uniform mat4 pMatrix;                   // Leksjon 3
uniform mat4 vMatrix;                   // Leksjon 3
uniform mat4 matrix;                    //the matrix for the model

// heightmap
uniform sampler2D heightmap;
uniform bool bHasHeightmap;
const float heightScale = -2;

void main()
{
    if (bHasHeightmap)
    {
        // Get height value from heightmap texture
        float height = texture(heightmap, textureCoordIn).r * heightScale;

        // Displace the vertex pos along y-axis
        // uncomplete? y axis or z axis?
        vec4 positionDisplaced = vec4(positionIn.x, positionIn.y + height, positionIn.z);

        // Transform the vertex position into world space
        vec4 worldPos = matrix * positionDisplaced;

        // Calculate the normal in world space
        //normal = mat3(transpose(inverse(matrix))) * vec3(0, 1, 0);

        // Transform the vertex pos and normal into view space
        fragPos = vec3(vMatrix * worldPos);
        normal = vec4(textureCoordIn.x, textureCoordIn.y, 0.0, 1.0);
        gl_Position = pMatrix * vMatrix * worldPos;
        if (height != 0)
        {
            // Stål sa det var noe rart med displacedPosition og positionDisplaced
            displacedPosition = vec4(gl_Position.x, height, gl_Position.z, 1);
        }
    }
    else
    {
        gl_Position = pMatrix * vMatrix * matrix * positionIn;
        normal = colorIn;
    }

    textureCoord = textureCoordIn;
    fragPos = vec3(matrix * positionIn);

  //color = colorIn;                       //passing on the vertex color
  //gl_Position = pMatrix * vMatrix * matrix * positionIn;      //calculate the position of the model
}

/*
layout(location = 0) in vec4 positionIn;   // 1st attribute buffer = vertex positions
layout(location = 1) in vec4 colorIn;   // 2nd attribute buffer = colors
out vec4 color;                           //color sent to rest of pipeline
uniform mat4 pMatrix;                   // Leksjon 3
uniform mat4 vMatrix;                   // Leksjon 3
uniform mat4 matrix;                    //the matrix for the model

// Heightmap
uniform sampler2D heightmap;
uniform bool bHasHeightmap;
const float heightScale = -2;

void main() {
    if (bHasHeightmap)
    {
        // Get height value from heightmap texture

    }
  color = colorIn;                       //passing on the vertex color
  gl_Position = pMatrix * vMatrix * matrix * positionIn;      //calculate the position of the model
}
*/
