#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <utility>

#include "Vector2D.hpp"

class InputHandler
{
private:

	InputHandler() {}
	~InputHandler() {}

	static InputHandler* s_pInstance;

	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialised;

	const int m_joystickDeadZone = 10000;

	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;

	std::vector<std::vector<bool>> m_buttonStates;

public:

	static InputHandler* Instance()
	{
		if(s_pInstance == 0)
			s_pInstance = new InputHandler();

		return s_pInstance;
	}


	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	bool getButtonState(int joy, int buttonNumber);

	void update();
	void clean();

	void initialiseJoysticks();
	
	bool joysticksInitialised(){
		return m_bJoysticksInitialised;
	}


};
typedef InputHandler TheInputHandler;