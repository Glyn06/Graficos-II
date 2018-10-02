#include "Game.h"

Triangle* triangle;
//Square* square;

Game::Game()
{
	count = 0;
}


Game::~Game()
{
}

bool Game::OnStart() {
	Renderer* rend = new Renderer;
	Material* mat1 = new Material;
	//programID = mat1->LoadShaders("vertexshader.txt", "fragmentshader.txt");
	triangle = new Triangle(rend);
	triangle->SetVertex();
	triangle->SetMaterial(mat1);
	//square = new Square(rend);
	//square->SetVertex();
	return true;
}

bool Game::OnStop() {
	
	return true;
}

bool Game::OnUpdate() {
	count++;
	cout << "Loop!" << count << endl;
	if (count >= 2)
	{
		return true;
	}
	return false;
}

bool Game::OnDraw() {
	triangle->Draw();
	//square->Draw();
	return true;
}
