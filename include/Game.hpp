#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <iostream>

#include "InputHandler.hpp"
#include "GameStateMachine.hpp"
#include "MenuState.hpp"
#include "PlayState.hpp"

class Game
{
public:
	static Game* Instance()
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() const {return m_bRunning;}
	SDL_Renderer* getRenderer() const {return m_pRenderer;}

	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

private:

	Game(){}
	~Game(){}

	static Game* s_pInstance;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;

	bool m_bRunning;

	GameStateMachine* m_pGameStateMachine;
};
	
typedef Game TheGame;