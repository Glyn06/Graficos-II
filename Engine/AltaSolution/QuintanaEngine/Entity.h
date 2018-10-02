#pragma once
#include "Renderer.h"
#include "Material.h"
#include "glm\glm.hpp"
class QUINTANAENGINE_API Entity
{

protected:
	float* vertex;
	int cantVertex;
	float bufferID;

	Material* mat;

	Renderer* rend;

	glm::vec3 pos;
	glm::vec3 scale;
	glm::vec3 rot;

	glm::mat4 world;
	glm::mat4 translateMat;
	glm::mat4 rotationMat;
	glm::mat4 scaleMat;
public:
	Entity(Renderer* renderer);
	Entity();
	~Entity();
	virtual void Draw() = 0;
	void SetPos(glm::vec3 positon);
	glm::vec3 GetPos();
	void SetScale(glm::vec3 scale);
	glm::vec3 GetScale();
	void SetRotation(glm::vec3 rotation);
	glm::vec3 GetRotation();
	void UpdateWorldMatrix();
	void SetMaterial(Material* _mat);
};

