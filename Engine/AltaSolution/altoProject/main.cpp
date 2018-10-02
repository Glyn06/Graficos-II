#include <iostream>
#include "Game.h"

using namespace std;

void main() {
	Game* game = new Game();

	if (game->Start(900,1600,(char*)"GOTY"))
	{
		game->Loop();
	}

	game->Stop();
	delete game;

	getchar();
}