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
	m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
}

void Player::clean()
{}