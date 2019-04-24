#include "Background.h"

Background::Background(){
	
	if (!this->texture.loadFromFile("../../Enemies/Background.png")) {
		std::cout << "ERROR: CAN'T LOAD BACKGROUND IMAGE" << std::endl;

	}
	else {
		this->sprite1.setTexture(texture);
		this->sprite2.setTexture(texture);

		this->sprite1.scale(0.74, 0.74);
		this->sprite2.scale(0.74, 0.74);

		this->sprite1.setPosition(sf::Vector2f(0, 0));
		this->sprite2.setPosition(sf::Vector2f(this->sprite1.getGlobalBounds().width, 0));

	}

}

// DTOR
Background::~Background(){
	
}

void moveLeft(float delta_t) {

}



void Background::showBackground(sf::RenderWindow &window){
		
	window.draw(this->sprite1);
	window.draw(this->sprite2);

}

void Background::moveLeft(float delta_t, sf::RenderWindow &window) {


	this->sprite1.move(sf::Vector2f((-1 * delta_t * BACKGROUNDSCROLLSPEED), 0));
	this->sprite2.move(sf::Vector2f((-1 * delta_t * BACKGROUNDSCROLLSPEED), 0));

	if (this->sprite1.getPosition().x <= -1420.8) {

		std::cout << "============= TELEPORT =============" << std::endl;

		std::cout << "Sprite 1 Position: (" << this->sprite1.getPosition().x << ", " << this->sprite1.getPosition().y << ")" << std::endl;
		std::cout << "Sprite 2 Position: (" << this->sprite2.getPosition().x << ", " << this->sprite2.getPosition().y << ")" << std::endl;
		
		Sprite temp = this->sprite1;



		this->sprite1 = this->sprite2;

		this->sprite2 = temp;
		
		//this->sprite2.move(sf::Vector2f(this->sprite1.getGlobalBounds().width, 0));

		float xpos = this->sprite1.getPosition().x + this->sprite2.getGlobalBounds().width;

		std::cout << xpos << std::endl;


		this->sprite2.setPosition(sf::Vector2f((xpos), 0));

	}

	

}



Sprite * Background::getSprite1(void) {
	return &(this->sprite1);
}

Sprite * Background::getSprite2(void) {
	return &(this->sprite2);

}
