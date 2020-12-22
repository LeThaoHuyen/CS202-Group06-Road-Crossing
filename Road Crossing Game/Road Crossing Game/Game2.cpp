#include "Game2.h"

Game2::Game2()  {
	screen.init(consoleWidth, consoleHeight, frameWidth, frameHeight);
	laneManager.init(1);
	player.init(96, 34);
	currentLevel = 1;
	m_isRunning = true;
}

Game2::Game2(int level) {
	screen.init(consoleWidth, consoleHeight, frameWidth, frameHeight);
	laneManager.init(level);
	player.init(96, 34);
	currentLevel = level;
	m_isRunning = true;
}

Game2::~Game2() {
}

void Game2::clearGame() {
	laneManager.clear();
}
void Game2::drawGame() {
	laneManager.draw(screen);
	laneManager.update();
	//player.selfDraw();
	Sleep(1000);
}
void Game2::newGame(int level) {
	currentLevel = level;
	m_isRunning = true;
	laneManager.init(level);
	screen.displayMenu();
	screen.drawFrame();
	player.selfDraw();
	drawGame();
}
void Game2::resetGame() {
	clearGame();
	m_isRunning = true;
	newGame(currentLevel);
}
void Game2::pauseGame() {
	m_isRunning = false;
}
void Game2::resumeGame() {
	m_isRunning = true;
}
void Game2::saveGame() {
	ofstream out;
	out.open("save.txt");
	if (out.is_open()) {
		out << currentLevel << player.getX() << player.getY();
	}
}
void Game2::loadGame() {
	ifstream in;
	in.open("save.txt");
	if (in.is_open()) {
		int level, x, y;
		if (in >> level >> x >> y) {
			player.init(x, y);
			newGame(level);
		}
		else {
			// no game to load
		}
	}
	
}
