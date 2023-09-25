#include <SDL2/SDL.h>
#include <iostream>

#include "Player.hpp"


Player::Player(const LoaderParams* pParams)
: SDLGameObject(pParams)
{}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::handleInput()
{

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	m_velocity = (*vec - m_position) / 50;

	// if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	// {
	// 	m_velocity.setX(2);
	// }

	// if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	// {
	// 	m_velocity.setX(-2);
	// }

	// if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	// {
	// 	m_velocity.setY(-2);
	// }

	// if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	// {
	// 	m_velocity.setY(2);
	// }
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput();

	//m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	m_currentFrame = 0;

	SDLGameObject::update();
}

void Player::clean()
{}