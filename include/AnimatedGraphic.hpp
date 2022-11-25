#pragma once

#include "SDLGameObject.hpp"
#include "LoaderParams.hpp"


class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	int m_animSpeed;
};

