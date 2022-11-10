#include <iostream>

#include "Game.hpp"
#include "TextureManager.hpp"


Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{ 
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if(m_pWindow != 0)
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if(getRenderer() != 0)
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(getRenderer(), 200, 200, 200, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false;
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false;
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false;
	}
	std::cout << "init success\n";
	m_bRunning = true;

	if(!TheTextureManager::Instance()->load("res/hulking_knight.png", "animate", getRenderer()))
	{
		return false;
	}

	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 64, 64, "animate")));

	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 64, 64, "animate")));

	return true;
}

void Game::update()
{
	for(auto x : m_gameObjects)
		x->update();
}

void Game::render()
{
	SDL_RenderClear(getRenderer());
	
	for(auto x : m_gameObjects)
		x->draw();

	SDL_RenderPresent(getRenderer());
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(getRenderer());
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}