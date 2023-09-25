#include <SDL2/SDL.h>

#include "Bullet.hpp"


Bullet::Bullet(const LoaderParams* pParams)
: SDLGameObject(pParams), m_numFrames(2){
	is_moving_right = false;
	move_angle = 0;

	if(is_moving_right){
		m_velocity.setX(5);
		m_velocity.setY(0);
	}
	else{
		m_velocity.setX(-5);
		m_velocity.setY(0);	
	}
}

void Bullet::draw(){
	SDLGameObject::draw();
}

void Bullet::update(){
	m_currentFrame = curr_frame_num(m_numFrames);
	SDLGameObject::update();
}

void Bullet::clean(){}