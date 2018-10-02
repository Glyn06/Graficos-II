#include "Square.h"



Square::Square(Renderer* renderer) : Entity(rend)
{
	cantVertex = 4;
	rend = renderer;
}


Square::~Square()
{
}

void Square::Draw() {
	rend->LoadIdentity();
	rend->MultiplyMatrix(world);

	if (mat != NULL)
	{
		mat->Bind();
		mat->SetMatrixProperty("WVP", rend->GetWVP());
	}

	rend->DrawBuffer(bufferID,cantVertex);
}

void Square::SetVertex() {

	float vertexArray[12] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f
	};

	vertex = vertexArray;
	bufferID = rend->GenerateBuffers(vertex, sizeof(float) * cantVertex * 4);
}
