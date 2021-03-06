#pragma once
#include "Exports.h"
#include "GL\glew.h"
#include "glm\gtc\matrix_transform.hpp"
class QUINTANAENGINE_API Material
{
private:
	unsigned int programID;
public:
	Material();
	~Material();
	unsigned int LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
	void Bind();
	void SetMatrixProperty(const char* name, glm::mat4 mvp);
};

