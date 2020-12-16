#pragma once
#include"LaneManager.h"
#include"People.h"


// Game size
const int consoleWidth = 800;
const int consoleHeight = 600;
const int frameWidth = 60;
const int frameHeight = 30;
const int laneWidth = frameHeight / 6;

class Game {
public:
	static const int MAX_LEVEL;
private:
	Buffer screen;
	LaneManager laneManager;
	People people;
	int currentLevel;
	int isRunning;

//	void clearGame();
//	void copyGame(const Game&);
//public:
//	Game();
//	Game(int level);
//	Game(const Game&);
//	~Game();
//
//public:
	/*void newGame();
	void resetGame();

	void pauseGame();
	void saveGame();
	void loadGame();
	void showMenu();*/
};

