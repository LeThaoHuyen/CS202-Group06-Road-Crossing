#pragma once
#include"LaneManager.h"
#include"People.h"
#include<fstream>
#include<thread>

// Game size
const int consoleWidth = 1300;
const int consoleHeight = 1300;
const int frameWidth = 60;
const int frameHeight = 30;
const int laneWidth = frameHeight / 6;

class Game {
public:
	static const int MAX_LEVEL;
private:
	Buffer screen;
	LaneManager laneManager;
	People player;
	int currentLevel;
	int m_isRunning;

	void clearGame();
	//void copyGame(const Game&);
public:
	Game();
	Game(int level);
	Game(const Game&);
	~Game();

public:
	bool isRunning() {
		return m_isRunning;
	}

	int getLevel() {
		return currentLevel;
	}

	void newGame(int level);
	void resetGame();
	void drawGame();

	void pauseGame();
	void resumeGame();

	void saveGame();
	void loadGame();

	void showMenu();
	
	void exitGame(thread*game);
};

