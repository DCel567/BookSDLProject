#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Game
{
public:
	Game(){}
	~Game(){}

	bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running(){ return m_bRunning; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;

	bool m_bRunning;
};