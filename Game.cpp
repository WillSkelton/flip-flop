#include "Game.h"
#include "Background.h"
#include "madBlock.h"
#include "Slime.h"


Game::Game() {
	//initialize the master texture
	if (!this->masterTexture.loadFromFile("enemies_spritesheet.png")) {
		std::cout << "Master Texture failed to load. see Game.cpp constructor." << std::endl;
	}

	//runs game automatically
	gameLoop();
}

//controlls game functionality
void Game::gameLoop() {
	//clock used to check frame times
	sf::Clock clock;
	float delta_t = 0;

	float YEEHAW = 0.1;

	//create window
	sf::RenderWindow window;
	Player player;
	Background background;
	Slime slime1(masterTexture);
	Slime slime2(masterTexture);
	Slime slime3(masterTexture);
	Slime slime4(masterTexture);

	MadBlock mb1(masterTexture);
	MadBlock mb2(masterTexture);
	MadBlock mb3(masterTexture);
	MadBlock mb4(masterTexture);



	window.create(sf::VideoMode(800, 800), "Game Window");


	//disable autorepeating keypress function in Windows machines
	window.setKeyRepeatEnabled(false);

	clock.restart();

	//game loop
	while (window.isOpen()) {
		sf::Event event;
		window.clear(sf::Color::Black);	//clear buffer for next frame

		keystateHandler(window);
		
		//event handler
		while (window.pollEvent(event)) {
			//handles all events (such as mouse clicks or button presses)
			eventHandler(player, event, window);
			
		}

		//update delta_t in milliseconds();
		delta_t = (clock.getElapsedTime().asMilliseconds());

		//update all parts of the screen (player, obstacle list, and )
		background.showBackground(window);
		player.draw(window);

		slime1.showSlime(window);
		slime2.showSlime(window);
		slime3.showSlime(window);
		slime4.showSlime(window);

		mb1.showMadBlock(window);
		mb2.showMadBlock(window);
		mb3.showMadBlock(window);
		mb4.showMadBlock(window);


		//move all items across screen
		background.moveLeft(YEEHAW, window);
		player.movePlayer(1);
		mb1.moveLeft(YEEHAW);
		mb2.moveLeft(YEEHAW);
		mb3.moveLeft(YEEHAW);
		mb4.moveLeft(YEEHAW);

		slime1.moveLeft(YEEHAW);
		slime2.moveLeft(YEEHAW);
		slime3.moveLeft(YEEHAW);
		slime4.moveLeft(YEEHAW);

		//check collisions (player with obstacle list)

		


		window.display();	//display next frame

		//reset time for this frame
		clock.restart();


		YEEHAW += 0.005;
	}
}

//handles all events (such as mouse clicks or button presses)
void Game::eventHandler(Player & player, sf::Event &event, sf::RenderWindow &window) {

	//we have to handle each event by TYPE, since otherwise we can run into serious errors
	switch (event.type) {

		//handles user closing window
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Space)
				player.flip();
			break;
		//we want to do nothing if there is a undefined event
		default:
			break;
	}
}

void Game::keystateHandler(sf::RenderWindow &window) {
	//move up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		//std::cout << "'space' key was pressed." << std::endl;
	}
	
}