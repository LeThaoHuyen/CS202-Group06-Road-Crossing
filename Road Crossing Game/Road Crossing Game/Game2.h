#pragma once
#include"Buffer2.h"
#include"LaneManager.h"
#include"People.h"
#include<fstream>

class Game2 {
public:
	static const int MAX_LEVEL;
	People player;
private:
	Buffer2 screen;
	LaneManager laneManager;
	int currentLevel;
	int m_isRunning;
	
	void clearGame();
public:
	Game2();
	Game2(int level);
	~Game2();
public:
	bool isRunning() {
		return m_isRunning;
	}

	int getLevel() {
		return currentLevel;
	}

	void drawGame();
	void newGame(int level);
	void resetGame();
	void pauseGame();
	void resumeGame();
	void saveGame();
	void loadGame();

	bool isWin();
	void processWin();
	void processLose();
	// void processPassLevel();


};
