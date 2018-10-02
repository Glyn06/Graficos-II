#include "GameBase.h"

GameBase::GameBase()
{
	gameOver = false;
	rend = new Renderer();
	win = new Window();
}


GameBase::~GameBase()
{
}

bool GameBase::Start(int _height, int _width, char* _gameName){
	
	if (!win->Start(_height,_width,_gameName))
	{
		return false;
	}
	if (!rend->Start(win))
	{
		return false;
	}
	return OnStart();
}

bool GameBase::Stop(){
	OnStop();

	rend->Stop();
	win->Stop();

	delete rend;
	delete win;
	return true;
}

void GameBase::Loop() {
	while (!gameOver || !win->ShouldClose())
	{
		rend->SetClearColor(0, 0, 1, 1);
		rend->ClearScreen();
		OnDraw();
		rend->SwapBuffers();
		gameOver = OnUpdate();
		win->PollEvents();
	}
}
