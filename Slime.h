#pragma once

#include "Obstacle.h"


class Slime : public Obstacle
{
	Slime(sf::Texture &enemies);
};

Slime::Slime(sf::Texture &enemies)
{
	this->xPos = this->hitBox.left = 0;
	this->yPos = this->hitBox.top = 0;

	this->sprite.setTexture(enemies);
	sprite.setTextureRect(sf::IntRect(52, 125, 50, 28));

	this->hitBox.height = 28;
	this->hitBox.width = 50;
}