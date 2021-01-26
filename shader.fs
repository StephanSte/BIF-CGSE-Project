#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    sampler2D normal;
    float shininess;
}; 

struct Light {
    vec3 direction;
    vec3 diffuse;
    vec3 ambient;

}; 

in vec3 FragPos;  
in vec3 Normal;  
in vec2 TexCoords;
  
uniform vec3 lightdir;

uniform vec3 viewPos;
uniform Material material;

uniform float alpha;



void main()
{
    // ambient
    vec3 ambient =  texture(material.diffuse, TexCoords).rgb;

    vec3 result = ambient;
    FragColor = vec4(result, alpha);
}
