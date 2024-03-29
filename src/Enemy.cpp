#include <SDL2/SDL.h>

#include "Enemy.hpp"


Enemy::Enemy(const LoaderParams* pParams)
: SDLGameObject(pParams)
{
	m_velocity.setY(2);
	m_velocity.setX(0.01);
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_currentFrame = curr_frame_num(m_numFrames);

	if(m_position.getY() < 0)
	{
		m_velocity.setY(2);
	}
	else if(m_position.getY() > 400)
	{
		m_velocity.setY(-2);
	}

	SDLGameObject::update();
}



void Enemy::clean()
{}