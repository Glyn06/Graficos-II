#include "Entity.h"



Entity::Entity(Renderer* renderer)
{
	rend = renderer;
	mat = NULL;
}


Entity::~Entity()
{
}

Entity::Entity() {

}

void Entity::SetPos(glm::vec3 position) {
	pos = position;

	translateMat = glm::translate(glm::mat4(1.0f), pos);

	UpdateWorldMatrix();
}

glm::vec3 Entity::GetPos() {
	return pos;
}

void Entity::SetScale(glm::vec3 scaleVector) {
	scale = scaleVector;

	scaleMat = glm::scale(glm::mat4(1.0f), scale);

	UpdateWorldMatrix();
}

glm::vec3 Entity::GetScale() {
	return scale;
}

void Entity::SetRotation(glm::vec3 rotation) {
	rot = rotation;

	rotationMat = glm::rotate(glm::mat4(1.0f), rot[0], glm::vec3(1.0f, 0.0f, 0.0f));
	rotationMat *= glm::rotate(glm::mat4(1.0f), rot[1], glm::vec3(0.0f, 1.0f, 0.0f));
	rotationMat *= glm::rotate(glm::mat4(1.0f), rot[2], glm::vec3(0.0f, 0.0f, 1.0f));

	UpdateWorldMatrix();
}

glm::vec3 Entity::GetRotation() {
	return rot;
}

void Entity::UpdateWorldMatrix() {
	world = translateMat * rotationMat * scaleMat;
}

void Entity::SetMaterial(Material* _mat) {
	mat = _mat;
}
