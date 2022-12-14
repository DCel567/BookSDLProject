#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <utility>

#include "Vector2D.hpp"


enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};


class InputHandler
{
private:

	InputHandler();
	~InputHandler() { delete m_mousePosition; }

	static InputHandler* s_pInstance;

	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialised;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	std::vector<std::vector<bool>> m_buttonStates;

	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;

	const Uint8* m_keystates;

	const int m_joystickDeadZone = 10000;

	//handle keyboard events
	void onKeyDown();
	void onKeyUp();

	//handle mouse events
	void onMouseMotion(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	//handle joystick events
	void onJoystickAxisMove(SDL_Event& event);
	void onJoystickButtonDown(SDL_Event& event);
	void onJoystickButtonUp(SDL_Event& event);

public:

	static InputHandler* Instance()
	{
		if(s_pInstance == 0)
			s_pInstance = new InputHandler();

		return s_pInstance;
	}

	bool getButtonState(int joy, int buttonNumber);

	void update();
	void clean();

	void initialiseJoysticks();
	
	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);
	
	bool joysticksInitialised(){
		return m_bJoysticksInitialised;
	}

	bool getMouseButtonState(int buttonNumber){
		return m_mouseButtonStates[buttonNumber];
	}

	void reset();

	Vector2D* getMousePosition(){
		return m_mousePosition;
	}

	bool isKeyDown(SDL_Scancode key);

};
typedef InputHandler TheInputHandler;