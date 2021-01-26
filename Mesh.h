
#ifndef MESH_H
#define MESH_H

#include "libs.h"
#include "shader_class.h"

#include <vector>

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoord;
	glm::vec3 Tangent;
};

struct Texture {
	unsigned int id;
	std::string type;
	std::string path;
};

class Mesh {
public:
	// mesh data
	std::vector<Vertex> 		vertices;
	std::vector<unsigned int> 	indices;
	std::vector<Texture> 		textures;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	void Draw(Shader& shader);

private:
	// render data
	unsigned int VAO, VBO, EBO;
	void setupMesh();
};

#endif // MESH_H