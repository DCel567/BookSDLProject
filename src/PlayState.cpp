#include <iostream>

#include "Game.hpp"
#include "GameObject.hpp"

#include "PlayState.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"


const std::string PlayState::s_playID = "PLAY";


void PlayState::update(){
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)){
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}

	for (size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->update();

	if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1]))){
		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
	}

	check_shot();
}


void PlayState::render(){
	for(size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->draw();
}


bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2){
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }

	return true;
}


bool PlayState::onEnter(){
	if(!TheTextureManager::Instance()->load("res/heli.png", "helicopter", TheGame::Instance()->getRenderer()))
		return false;

	if(!TheTextureManager::Instance()->load("res/heli2.png", "helicopter2", TheGame::Instance()->getRenderer()))
		return false;

	if(!TheTextureManager::Instance()->load("res/Bullet.png", "bullet", TheGame::Instance()->getRenderer()))
		return false;

	GameObject* player = new Player(new LoaderParams(500, 100, 81, 81, "helicopter"));

	GameObject* enemy = new Enemy(new LoaderParams(100, 100, 81, 81, "helicopter2"));

	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);

	std::cout << "entering PlayState\n";
	return true;
}


bool PlayState::onExit(){

	for(size_t i = 0; i < m_gameObjects.size(); ++i)
		m_gameObjects[i]->clean();

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");

	std::cout << "exiting PlayState\n";
	return true;
}

void PlayState::check_shot(){
	if(TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
	{
		if(m_bReleased){
			GameObject* bullet = 
					new Bullet(new LoaderParams(500, 100, 25, 10,"bullet"));

			m_gameObjects.push_back(bullet);

			std::cout << "Bullet created\t gameObject.size: " << m_gameObjects.size() << "\n";
		}
		m_bReleased = false;
	}
	else if(!TheInputHandler::Instance()->getMouseButtonState(LEFT)){
		if(!m_bReleased){
			m_bReleased = true;
		
		}
	}
}