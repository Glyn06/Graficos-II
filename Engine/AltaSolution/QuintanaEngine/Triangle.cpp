#include "Triangle.h"


Triangle::Triangle(Renderer* renderer) : Entity(rend)
{
	cantVertex = 3;
	rend = renderer;
}


Triangle::~Triangle()
{
}

void Triangle::Draw() {
	rend->LoadIdentity();
	rend->MultiplyMatrix(world);

	if (mat != NULL)
	{
		mat->Bind();
		mat->SetMatrixProperty("WVP", rend->GetWVP());
	}

	rend->DrawBuffer(bufferID, cantVertex);
}

void Triangle::SetVertex() {
	
	float vertexArray[9] = {
		-1.0, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};

	vertex = vertexArray;

	bufferID = rend->GenerateBuffers(vertex, sizeof(float) * cantVertex * 3);
}