#pragma once
#ifndef GAME_H
#define GAME_H

#include "Header.h"


/*
Game class which controlls functionality for entire game flow.
Contains the game loop and event handling. All other classes will in some way need to be called or created
inside of this function in order to exist in the game.
*/

class Game {
public:
	Game();

	

private:
	//controlls all game functionality
	void gameLoop();

	//handles all events (such as mouse clicks or button presses)
	void eventHandler(sf::Event &event, sf::RenderWindow &window);

	//handles current state of all keys (ie pressed or not)
	void keystateHandler(sf::RenderWindow &window);
	

	void updateLocations();

	//contains master texture with all the enemies
	sf::Texture masterTexture;
};


#endif // !GAME_H
