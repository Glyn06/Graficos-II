#pragma once
#include "Entity.h"
class QUINTANAENGINE_API Triangle :
	public Entity
{
public:
	Triangle(Renderer* renderer);
	~Triangle();
	void Draw() override;
	void SetVertex();
};

