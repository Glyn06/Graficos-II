#pragma once

#include <string>
#include <iostream>
using namespace std;

class Window
{
private:
	void* window;
	int height;
	int widht;
	char* windowName;
public:
	Window();
	~Window();
	bool Start(int _height, int _width, char* _windowName);
	bool Stop();
	bool ShouldClose();
	void PollEvents();
	void* GetWindow();
};

