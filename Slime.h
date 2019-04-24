#pragma once
#include "Obstacle.h"


class Slime : public Obstacle
{
public:
	//constructor
	Slime(sf::Texture &enemies);
	//get rekt
	sf::Rect<int> getRect();
	//move left
	void moveLeft(float delta_t);
	//display slime
	void showSlime(sf::RenderWindow &window);
};

Slime::Slime(sf::Texture &enemies)
{
	this->sprite.setTexture(enemies);
	sprite.setTextureRect(sf::IntRect(52, 125, 50, 28));


	this->xPos = this->hitBox.left = (850 + (rand() % 2000));
	this->yPos = this->hitBox.top = (rand() % 585) + 93;

		
	sprite.setPosition(sf::Vector2f(xPos, yPos));

	this->hitBox.height = 28;
	this->hitBox.width = 50;
}

sf::Rect<int> Slime::getRect()
{
	return this->hitBox;
}

void Slime::moveLeft(float delta_t)
{
	if (this->xPos < (-50 - this->getRect().width))
	{
		this->xPos = (850 + (rand() % 2000));
	}
	else
	{
		this->xPos -= (delta_t * BACKGROUNDSCROLLSPEED);
	}

	this->hitBox.left = xPos;
	this->sprite.setPosition(sf::Vector2f(xPos, yPos));
}

void Slime::showSlime(sf::RenderWindow &window)
{
	window.draw(this->sprite);
}