#pragma once

#include <vector>

#include "GameState.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "SDLGameObject.hpp"


class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }


private:

	static const std::string s_playID;

	std::vector<GameObject*> m_gameObjects;

	bool m_bReleased;
	void check_shot();
	
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
};