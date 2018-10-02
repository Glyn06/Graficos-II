#pragma once
#include "Exports.h"
#include "Window.h"
#include "glm\glm.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm\gtx\transform.hpp"
#include <iostream>
using namespace std;

class QUINTANAENGINE_API Renderer
{
private:
	Window* currentWindow;
	glm::mat4 world;
	glm::mat4 view;
	glm::mat4 projection;
	glm::mat4 wvp;
public:
	Renderer();
	~Renderer();
	bool Start(Window* win);
	bool Stop();
	void SetClearColor(float r, float g, float b, float a);
	void ClearScreen();
	void SwapBuffers();
	int GenerateBuffers(float vertex[], int cant);
	void DrawBuffer(unsigned int vertexBuffer, int size);
	void CalculateWVP();
	void LoadIdentity();
	void MultiplyMatrix(glm::mat4 matrix);
	glm::mat4 GetWVP();
};

