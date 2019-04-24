#pragma once
#include "Obstacle.h"





class MadBlock : public Obstacle
{
public:
	//constructor for block
	MadBlock(sf::Texture &enemies);
	//get rekd
	sf::Rect<int> getRect();
	//move
	void moveLeft(float delta_t);
	//display
	void showMadBlock(sf::RenderWindow &window);
};


MadBlock::MadBlock(sf::Texture &enemies)
{
	this->sprite.setTexture(enemies);
	sprite.setTextureRect(sf::IntRect(136, 66, 51, 51));

	sprite.setColor(sf::Color::Magenta);

	this->xPos = this->hitBox.left = (850 + (rand() % 2000));
	this->yPos = this->hitBox.top = (rand() %562) + 93;
	
	sprite.setPosition(sf::Vector2f(xPos, yPos));

	this->hitBox.height = this->hitBox.width = 51;
}

sf::Rect<int> MadBlock::getRect()
{
	return this->hitBox;
}

void MadBlock::moveLeft(float delta_t)
{
	if (this->xPos < (-50 - this->getRect().width))
	{
		this->xPos = (850 + (rand() % 2000));
		this->yPos = (rand() % 562) + 93;
	}
	else
	{
		this->xPos -= (delta_t * BACKGROUNDSCROLLSPEED);
	}

	this->hitBox.left = xPos;
	this->hitBox.top = yPos;
	this->sprite.setPosition(sf::Vector2f(xPos, yPos));
}

void MadBlock::showMadBlock(sf::RenderWindow &window)
{
	window.draw(this->sprite);
}
