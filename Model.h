#include "libs.h"
#ifndef CGSE_MODEL_H
#define CGSE_MODEL_H

#include <assimp/scene.h>

#include "Mesh.h"
#include "shader_class.h"

class Model {
public:
	std::vector<Texture> textures_loaded;

	Model(std::string path);
	void Draw(Shader& shader);

private:
	std::vector<Mesh> meshes;
	std::string directory;

	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	unsigned int TextureFromFile(const char* path, const std::string& directory);
};


#endif //CGSE_MODEL_H
