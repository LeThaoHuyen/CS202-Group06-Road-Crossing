#include "Game.h"

Game::Game() {
	screen.init(consoleWidth, consoleHeight, frameWidth, frameHeight);
	laneManager.init(1, laneWidth);
	player.init(frameWidth, frameHeight - 2);
	currentLevel = 1;
	m_isRunning = true;
}

Game::Game (int level) {
	screen.init(consoleWidth, consoleHeight, frameWidth, frameHeight);
	laneManager.init(level, laneWidth);
	player.init(frameWidth, frameHeight - 2);
	currentLevel = level;
	m_isRunning = true;
}

Game::~Game() {}

void Game::clearGame() {
	laneManager.clear();
	screen.update();
}

void Game::resetGame() {
	clearGame();
	m_isRunning = true;
	newGame(currentLevel);
}

void Game::newGame(int level) {
	currentLevel = level;
	m_isRunning = true;
	laneManager.init(currentLevel, laneWidth);
	screen.displayFrame();
	screen.update();
	laneManager.draw(screen);
	player.draw(screen);
	drawGame();
}

void Game::saveGame() {
	ofstream out;
	out.open("save.txt");
	if (out.is_open()) {
		out << currentLevel;
	}
}

void Game::loadGame() {
	ifstream in;
	in.open("save.txt");
	int level = 1;
	if (in.is_open()) {
		in >> level;
	}
	newGame(level);
}

void Game::pauseGame()
{
	m_isRunning = false;
	// Display Sub Menu
	menu.showSub(screen);
	int choice = menu.processSub(screen);
	if (choice == 1)
		resumeGame();
	else if (choice == 2)
		newGame(1);
	else if (choice == 3)
		saveGame();
	else
		//exitGame();
		return;
}

void Game::resumeGame() {
	m_isRunning = true;
}

void Game::drawGame()
{
	laneManager.update(screen);
	screen.update();
	laneManager.draw(screen);
	player.draw(screen);
	screen.display();
	// Display Main Menu
	menu.showMain(screen);
	int choice = menu.processMain(screen);
	if (choice == 1)
		newGame(1);
	else if (choice == 2)
		loadGame();
	else
		//exitGame();
		cout << "exit" << endl;
}

void Game::exitGame(thread* game) {
	m_isRunning = false;
	game->join();
}