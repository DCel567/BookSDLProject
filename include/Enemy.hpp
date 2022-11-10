#pragma once

#include "SDLGameObject.hpp"

class Enemy : public SDLGameObject
{
public:

	Enemy(const LoaderParams* pParams);

	void draw();
	void update();
	void clean();
};