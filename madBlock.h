#pragma once
#include "Obstacle.h"





class MadBlock : public Obstacle
{
public:
	MadBlock(sf::Texture &enemies);

	sf::Rect<int> getRect();
};


MadBlock::MadBlock(sf::Texture &enemies)
{
	this->xPos = this->hitBox.left = 0;
	this->yPos = this->hitBox.top = 0;

	this->sprite.setTexture(enemies);
	sprite.setTextureRect(sf::IntRect(136, 66, 51, 51));

	this->hitBox.height = this->hitBox.width = 51;
}

sf::Rect<int> MadBlock::getRect()
{
	return this->hitBox;
}

void moveLeft(float delta_t, sf::RenderWindow &window)
{

}

