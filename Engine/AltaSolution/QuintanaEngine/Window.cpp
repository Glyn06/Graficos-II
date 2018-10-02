#include "Window.h"
#include "GLFW\glfw3.h"



Window::Window()
{
	height = 0;
	widht = 0;
	windowName = nullptr;
}


Window::~Window()
{
}

bool Window::Start(int _height, int _width, char* _windowName)
{
	if (!glfwInit())
	{
		cout << "FAILED TO INITIALIZE GLFW" << endl;
		return false;
	}

	height = _height;
	widht = _width;
	int size = strlen(_windowName) + 1;
	windowName = new char[size];
	
	strcpy_s(windowName, size, _windowName);

	window = glfwCreateWindow(widht, height, windowName, NULL, NULL);
	if (!window)
	{
		cout << "FAILED TO CREATE WINDOW" << endl;
		glfwTerminate();
		return false;
	}

	return true;
}

bool Window::Stop()
{
	glfwDestroyWindow((GLFWwindow*)window);
	glfwTerminate();
	return true;
}

bool Window::ShouldClose()
{
	if (window)
		return glfwWindowShouldClose((GLFWwindow*)window);

	return true;
}
void Window::PollEvents()
{
	glfwPollEvents();
}

void* Window::GetWindow(){
	return window;
}
