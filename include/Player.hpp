#pragma once

#include "SDLGameObject.hpp"

class Player : public SDLGameObject
{
public:

	Player(const LoaderParams* pParams);
	
	void draw();
	void update();
	void clean();
};