#include "Header.h"

Player::Player() //instantiate sprite
{
	this->gravityIsDown = true;
	if (!pTexture.loadFromFile("Player.png"))
	{
		// error...
		cout << "Player image load error" << endl;
	}
	else
	{
		pSprite.setTexture(pTexture);
		pSprite.setColor(sf::Color(0,85,175));

		//set player's initial position
		this->player.top = PLAYER_BOTTOM_BOUND;
		this->pSprite.setPosition(50, PLAYER_BOTTOM_BOUND);

		//set origin
		this->pSprite.setOrigin(25, 25);
	}
}


Sprite & Player::getSprite()
{
	return this->pSprite;
}


Rect<int> Player::getRect(Vector2f &position, const Vector2f &size) // generate hitbox
{
	return this->player;
}

void Player::movePlayer(float delta_t) // update position
{
	if (gravityIsDown) {
		this->player.top += delta_t * PLAYERSPEED;
		this->pSprite.move(0, delta_t * PLAYERSPEED);
	}
	else {	//gravity is up
		this->player.top -= delta_t * PLAYERSPEED;
		this->pSprite.move(0, -1 * delta_t * PLAYERSPEED);
	}

	//make sure player doesnt go out of bounds
	if (this->player.top < PLAYER_TOP_BOUND) {
		this->player.top = PLAYER_TOP_BOUND;
		this->pSprite.setPosition(50, PLAYER_TOP_BOUND);
	}
	else if (this->player.top > PLAYER_BOTTOM_BOUND) {
		this->player.top = PLAYER_BOTTOM_BOUND;
		this->pSprite.setPosition(50, PLAYER_BOTTOM_BOUND);
	}
}

//inverts gravity
void Player::flip() {
	//reverse gravity
	this->gravityIsDown = !gravityIsDown;

	//flip character model 180 degrees
	this->pSprite.setRotation(pSprite.getRotation() + 180);

	//reverse about y-axis
	if (gravityIsDown) {

		this->pSprite.setScale(1, 1);
	}
	else {
		this->pSprite.setScale(-1, 1);

	}
}


void Player::draw(sf::RenderWindow &window) {
	window.draw(this->getSprite());
}