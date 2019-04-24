#include "Header.h"

using sf::Sprite;
using sf::Texture;


class Background {

// CTOR
public:
	Background();

	//DTOR
	~Background();

	void showBackground(sf::RenderWindow &window);

	void moveLeft(float delta_t, sf::RenderWindow &window);

	Sprite * getSprite1(void);
	Sprite * getSprite2(void);


private:

	Texture texture;

	Sprite sprite1;
	Sprite sprite2;

};