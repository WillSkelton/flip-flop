#pragma once


#include "Header.h"




class Obstacle
{
public:
	virtual void moveLeft(float delta_t) = 0;
	virtual sf::Rect<int> getRect() = 0;
protected:
	sf::Sprite sprite;
	sf::Rect<int> hitBox;
	

	float xPos;
	float yPos;
};