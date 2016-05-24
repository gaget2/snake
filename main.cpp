#include <SFML/Graphics.hpp>
#include "game_object.h"
#include "constants.h"

int main(){

	// Create window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SSSnake");

	// Prevent events from creating when the user holds down a key
	window.setKeyRepeatEnabled(false);

	// Create instances of Game
	GameObject game;

	// Main Game Loop
	while( game.isRunning() ){

		// Process events
		game.processEvents(window);

		// Process logic
		game.processLogic(window);

		// Draw udates to window
		game.render(window);

		// Limit framerate to 60 FPS
		window.setFramerateLimit(60);
	}

	return 0;
}