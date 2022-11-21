#include "PauseState.hpp"

#include "Game.hpp"
#include "TextureManager.hpp"
#include "LoaderParams.hpp"
#include "GameObject.hpp"
#include "InputHandler.hpp"
#include "MenuButton.hpp"


const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
	for(size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->update();
}

void PauseState::render()
{
	for(size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->draw();
}

bool PauseState::onEnter()
{
	if(!TheTextureManager::Instance()->load("res/main_menu.png", "mainbutton", TheGame::Instance()->getRenderer()))
		return false;

	if(!TheTextureManager::Instance()->load("res/continue.png", "resumebutton", TheGame::Instance()->getRenderer()))
		return false;

	GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 128, 64, "mainbutton"), s_pauseToMain);

	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 128, 64, "resumebutton"), s_resumePlay);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "enering PauseState\n";
	return true;
}

bool PauseState::onExit()
{
	for(size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->clean();

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");

	TheInputHandler::Instance()->reset();

	std::cout << "exiting PauseState\n";
	return true;
}