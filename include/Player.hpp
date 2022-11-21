#pragma once

#include "SDLGameObject.hpp"
#include "InputHandler.hpp"

class Player : public SDLGameObject
{
public:

	Player(const LoaderParams* pParams);
	
	void draw();
	void update();
	void clean();

private:

	void handleInput();

};