#include <SFML/Graphics.hpp>
#include <vector>
#include "constants.h"
#include <string>
#include <cstdlib>
#include <ctime>

struct Coordinate{
	int x, y;
};

class SnakeObject{
private:
	int snakePieceWidth, snakePieceHeight, xvel, yvel;

	Coordinate incomingVelocity;//fixes problem, won't update velocity until snake actually moves
	//problem was that by pressing down and then right or left or a similar combination, one could
	//force the snake to move into itself. By delaying the change of velocity until it actually moves
	//you can't move into yourself by rapidly pressing orthogonal directions

	// Used for moving the snake
	int frameCount;
public:
	std::vector<Coordinate> snakePieceLocations;
	SnakeObject();

	int getSnakePieceWidth();

	void update();

	void moveSnake();

	void setVelocity(int x, int y);

	Coordinate getVelocity();

	bool inSnake(Coordinate coor);

	bool inSnake(Coordinate coor, int index);
};

// Game Object, duh!
class GameObject{

	private:
		// Flag to determine if the game is running
		bool running;

		// Flag to determine if the game is over
		bool gameOver;

		// The snake object reference
		SnakeObject * snake;

		Coordinate food;

		sf::Font font;
		sf::Text gameOverText;
		sf::Text scoreText;

		int score;

	public:
		GameObject();
		~GameObject();

		void processEvents(sf::RenderWindow &window);

		void processLogic(sf::RenderWindow &window);

		void render(sf::RenderWindow &window);

		bool isRunning();

		void drawSnake(sf::RenderWindow &window);

		void placeFood();
};