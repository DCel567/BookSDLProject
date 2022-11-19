#include <iostream>

#include "MenuState.hpp"
#include "TextureManager.hpp"
#include "Game.hpp"
#include "MenuButton.hpp"
#include "LoaderParams.hpp"


const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	for(size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->update();
}

void MenuState::render()
{
	for(size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->draw();
}

bool MenuState::onEnter()
{
	if(!TheTextureManager::Instance()->load("res/play_button.png", "playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if(!TheTextureManager::Instance()->load("res/exit_button.png", "exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 128, 64, "playbutton"));
	GameObject* button2 = new MenuButton(new LoaderParams(300, 100, 128, 64, "exitbutton"));

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{

	for(size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->clean();

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

	std::cout << "exiting MenuState\n";
	return true;
}