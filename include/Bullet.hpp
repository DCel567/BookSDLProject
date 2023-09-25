#pragma once

#include "SDLGameObject.hpp"

class Bullet : public SDLGameObject
{
public:

	Bullet(const LoaderParams* pParams);

	void draw();
	void update();
	void clean();

	int m_numFrames = 1;

private:
	bool is_moving_right;
	int move_speed;
	int move_angle;
};