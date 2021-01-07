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

	void drawGame(bool, bool);
	void drawPeople();

	void newGame(int level, int x = 96, int y = 34);
	void resetGame();
	void pauseGame();
	void resumeGame();
	void saveGame();
	bool exitGame();
	void loadGame();

	bool isWin();
	void processWin();
	void processLose();
	void printCongrat();
	void printGameover();
	
	// void processMaxLevel();
	
	
	bool checkCollision(bool playSound);
	void displayMenu();
	void displayMainMenu();
	void showOption(int option, int key);

};

