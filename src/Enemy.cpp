#include <SDL2/SDL.h>

#include "Enemy.hpp"


Enemy::Enemy(const LoaderParams* pParams)
: SDLGameObject(pParams)
{}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_y += 1;
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks()/100) % 5));
}

void Enemy::clean()
{}