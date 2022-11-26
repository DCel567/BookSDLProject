#include "GameOverState.hpp"

#include "Game.hpp"
#include "MenuState.hpp"
#include "TextureManager.hpp"
#include "AnimatedGraphic.hpp"
#include "LoaderParams.hpp"
#include "MenuButton.hpp"
#include "PlayState.hpp"
#include "PauseState.hpp"


const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update(){
	for(size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}


void GameOverState::render(){
	for(size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->draw();
}


void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}


void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}


bool GameOverState::onEnter()
{
	if(!TheTextureManager::Instance()->load("res/gameOver.png", "gameovertext", TheGame::Instance()->getRenderer()))
		return false;

	if(!TheTextureManager::Instance()->load("res/main_menu.png", "mainbutton", TheGame::Instance()->getRenderer()))
		return false;

	if(!TheTextureManager::Instance()->load("res/restart.png", "restartbutton", TheGame::Instance()->getRenderer()))
		return false;

	GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 62, 60, "gameovertext"), 2);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 200, 128, 64, "mainbutton"), s_gameOverToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 128, 64, "restartbutton"), s_restartPlay);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering PauseState\n";
	return true;
}


bool GameOverState::onExit()
{
	for(size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("gameovertext");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("restartbutton");
	
	std::cout << "exiting GameOverState" << std::endl;;
	return true;
}