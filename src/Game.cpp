#include <iostream>

#include "Game.hpp"
#include "TextureManager.hpp"

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

			if(m_pRenderer != 0)
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 200, 200, 200, 255);
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

	if(!TheTextureManager::Instance()->load("res/hulking_knight.png", "animate", m_pRenderer))
	{
		return false;
	}

	return true;
}

void Game::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	
	TheTextureManager::Instance()->draw("animate", 0, 0, 64, 64, m_pRenderer);

	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 64, 64, 1, m_currentFrame, m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
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