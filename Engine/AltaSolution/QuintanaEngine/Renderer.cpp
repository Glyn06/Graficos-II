#include "Renderer.h"
#include "GL\glew.h"
#include "GLFW\glfw3.h"

Renderer::Renderer()
{
	world = glm::mat4(1.0f);
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);
	wvp = glm::mat4(1.0f);
}


Renderer::~Renderer()
{
}

bool Renderer::Start(Window* win) {
	currentWindow = win;

	glfwMakeContextCurrent((GLFWwindow*)currentWindow->GetWindow());

	if (glewInit() != GLEW_OK)
	{
		cout << "Could not initialize GLEW" << endl;
		return false;
	}

	//VAO
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	return true;
}

bool Renderer::Stop() {
	return true;
}

void Renderer::SetClearColor(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
}

void Renderer::ClearScreen() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::SwapBuffers() {
	glfwSwapBuffers((GLFWwindow*)currentWindow->GetWindow());
}

int Renderer::GenerateBuffers(float vertex[], int size) {

	unsigned int vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, size, vertex, GL_STATIC_DRAW);
	return vertexbuffer;
}

void Renderer::DrawBuffer(unsigned int vertexBuffer, int cant) {
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	// Draw the triangle !
	if (cant == 3)
	{
		glDrawArrays(GL_TRIANGLES, 0, cant); // Starting from vertex 0; 3 vertices total -> 1 triangle
	}
	else if (cant == 4)
	{
		glDrawArrays(GL_TRIANGLE_STRIP, 0, cant);
	}

	glDisableVertexAttribArray(0);
	}

void Renderer::CalculateWVP() {
	wvp = projection * view * world;
}

void Renderer::LoadIdentity() {
	world = glm::mat4(1.0f);
	CalculateWVP();
}

void Renderer::MultiplyMatrix(glm::mat4 matrix) {
	world *= matrix;
	CalculateWVP();
}

glm::mat4 Renderer::GetWVP() {
	return wvp;
}
