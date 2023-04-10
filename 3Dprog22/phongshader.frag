#version 410

out vec4 fragColor;

in vec3 fragmentPosition;
in vec3 normalTransposed;
in vec3 Normal;
in vec2 uv;


// uniform sampler2D textureSampler;

uniform float ambientStrength = 0.8;
uniform vec3 lightPosition;             // position of the source of light Does it need a getter?
uniform vec3 cameraPosition;            // position of the camera does it have a getter?
//uniform float lightStrength = 0.41;
uniform vec3 lightColor = vec3(0.8, 0.8, 0.3);
uniform vec3 objectColor = vec3(0.7, 0.7, 0.7);

uniform float lightPower = 0.5;
uniform float specularStrength = 0.5;
uniform float specularExponent = 64;

void main()
{

    // ambient
    vec3 ambient = ambientStrength * lightColor;

    // diffuse
    vec3 normalCorrect = normalize(normalTransposed);
    vec3 lightDirection = normalize(lightPosition - fragmentPosition);
    float angleFactor = max(dot(normalCorrect, lightDirection), 0.0);
    vec3 diffuse = angleFactor * objectColor * lightColor * lightPower;

    // specular
    vec3 viewDirection = normalize(cameraPosition - fragmentPosition);
    float spec = 0.0;
    if (angleFactor > 0.0)
    {
        vec3 reflectDirection = reflect(-lightDirection, normalCorrect);
        spec = pow(max(dot(viewDirection, reflectDirection), 0.0), specularExponent);
    }

    vec3 specular = spec * lightColor * specularStrength;

    vec3 result = ambient  + diffuse + specular;

    fragColor = vec4(result, 1.0);
}
