#pragma once
#include "Exports.h"
#include "Renderer.h"
#include "Window.h"
#include "TypeDefs.h"
#include <iostream>
using namespace std;

class QUINTANAENGINE_API GameBase
{
private:
	bool gameOver;
	Renderer* rend;
	Window* win;
public:
	GameBase();
	~GameBase();
	bool Start(int _height, int _width, char* _windowName);
	bool Stop();
	void Loop();

protected:
	virtual bool OnStart() = 0;
	virtual bool OnStop() = 0;
	virtual bool OnUpdate() = 0;
	virtual bool OnDraw() = 0;
};

