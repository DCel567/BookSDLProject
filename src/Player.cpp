#include <SDL2/SDL.h>

#include "Player.hpp"


Player::Player(const LoaderParams* pParams)
: SDLGameObject(pParams)
{}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));

	m_acceleration.setX(1);

	SDLGameObject::update();
}

void Player::clean()
{}