#include <iostream>

#include "PlayState.hpp"
#include "Game.hpp"
#include "PauseState.hpp"


const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}

	for(size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->update();
}

void PlayState::render()
{
	for(size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->draw();
}

bool PlayState::onEnter()
{
	if(!TheTextureManager::Instance()->load("res/heli.png", "helicopter", TheGame::Instance()->getRenderer()))
		return false;

	GameObject* player = new Player(new LoaderParams(100, 100, 81, 81, "helicopter"));

	m_gameObjects.push_back(player);

	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{

	for(size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->clean();

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");

	std::cout << "exiting PlayState\n";
	return true;
}