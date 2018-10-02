#pragma once
#include "Entity.h"
class QUINTANAENGINE_API Square :
	public Entity
{
public:
	Square(Renderer* renderer);
	~Square();
	void Draw() override;
	void SetVertex();
};

