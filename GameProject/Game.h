#pragma once
#include "Location.h"
#include "Player.h"
#include <vector>
class Game
{
private:
	Location*** world;
	Player p;
	int rows;
	int cols;
	int playerRow;
	int playerCol;

public:
	Game();
	vector<int> setUpGame();
	void drawGame();
	void playGame();
	virtual ~Game();
};

