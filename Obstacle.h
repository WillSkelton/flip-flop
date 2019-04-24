#pragma once


#include "Header.h"




class Obstacle
{
public:
	virtual void moveLeft(float delta_t, sf::RenderWindow &window) = 0;
	virtual sf::Rect<int> getRect() = 0;
protected:
	sf::Sprite sprite;
	sf::Rect<int> hitBox;
	

	int xPos;
	int yPos;
};