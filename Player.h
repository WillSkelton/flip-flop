#include "Header.h"


using sf::Rect;
using sf::Sprite;
using sf::Texture;
using sf::Vector2f;
using std::cout;
using std::endl;
using sf::IntRect;


class Player
{
public:
	Player();
	Sprite & getSprite();
	Rect<int> getRect(Vector2f &position, const Vector2f &size);

	void movePlayer(float delta_t);

	//applies the player sprite to the window provided
	void draw(sf::RenderWindow &window);
	
	//inverts gravity
	void flip();

private:
	Rect<int> player;
	Sprite pSprite;
	Texture pTexture;

	bool gravityIsDown;
};