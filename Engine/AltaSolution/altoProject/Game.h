#pragma once
#include "Triangle.h"
#include "Square.h"
#include "GameBase.h"
class Game : public GameBase
{
private:
	int count;
	unsigned int programID;
public:
	Game();
	~Game();
protected:
	bool OnStart() override;
	bool OnStop() override;
	bool OnUpdate() override;
	bool OnDraw() override;
};

