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
void Game2::drawGame(bool isLaneCarRed, bool isLaneTruckRed) {
	if (isLaneCarRed)
		laneManager.stopVehicles("car");
	else laneManager.moveVehicles(currentLevel, "car");
	
	if (isLaneTruckRed)
		laneManager.stopVehicles("truck");
	else laneManager.moveVehicles(currentLevel, "truck");

	laneManager.update();
	laneManager.draw(screen);
	
	screen.drawTrafficLight(isLaneCarRed, isLaneTruckRed);

	Sleep(1100 - currentLevel*50);
}
void Game2::drawPeople()
{
	player.selfDraw(screen);
}

void Game2::newGame(int level, int x, int y) {
	currentLevel = level;
	m_isRunning = true;
	laneManager.init(level);
	player.init(x, y);

	screen.displayMenu();
	screen.drawFrame();
	player.selfDraw(screen);
	screen.showLevel(level);
	drawGame(false, false);
}

void Game2::pauseGame() {
	m_isRunning = false;
}
void Game2::resumeGame() {
	m_isRunning = true;
}

void Game2::saveGame() {
	screen.displayConfirmSave();
	int key;
	key = _getch();
	if (key == 121) {
		ofstream out;
		out.open("save.txt");
		if (out.is_open()) {
			out << currentLevel << " " << player.getX() << " " << player.getY();
			out.close();
			screen.announceComplete();
			Sleep(300);
		}
	}
	screen.deleteAnnounceFrame();
}

void Game2::autoSave() {
	ofstream out;
	out.open("save.txt");
	if (out.is_open()) {
		out << currentLevel << " " << 96 << " " << 34;
		out.close();
	}
}

bool Game2::exitGame() {
	screen.displayConfirmExit();
	int key;
	key = _getch();
	if (key == 121) {
		screen.clearScreen();
		return true;
	}
	else {
		screen.deleteAnnounceFrame();
		return false;
	}
}


void Game2::loadGame() {
	ifstream in;
	in.open("save.txt");
	if (in.is_open()) {
		int level, x, y;
		if (in >> level >> x >> y) {
			newGame(level, x, y);
		}
		else {
			// if no saved game, new game at level 1
			player.init(96, 34);
			newGame(1);
		}
		in.close();
	}
}

bool Game2::isWin()
{
	if (player.getY() <= 6 && player.getY() >= 1)
		return true;
	return false;
}

void Game2::processWin()
{
	PlaySound(TEXT("Sound/LevelUp.wav"), NULL, SND_ASYNC);
	if (currentLevel!= MAX_LEVEL)	{
		currentLevel++;
		screen.printCongrat(false);
	}
	else if (currentLevel == MAX_LEVEL) {
		screen.printCongrat(true);
	}
}

void Game2::processLose()
{
	if (laneManager.checkCollision(player, true))
	{
		PlaySound(TEXT("Sound/GameOver.wav"), NULL, SND_ASYNC);
		screen.printGameover();
	}
}

void Game2 :: printCongrat(bool isMaxLevel) {
	screen.printCongrat(isMaxLevel);
}

void Game2::printGameover() {
	screen.printGameover();
}

bool Game2::checkCollision(bool playSound) {
	return laneManager.checkCollision(player, playSound);
}

void Game2::displayMainMenu()
{
	screen.displayMainMenu();
}

void Game2::displayMenu()
{
	screen.displayMenu();
}

void Game2::showOption(int option, int key)
{
	if (key == key_Enter) {
		screen.showChoice(option);
	}
	else {
		screen.showOption(option);
	}
}

void Game2::resetGame() {
	screen.displayConfirmReset();
	int key;
	key = _getch();
	if (key == 121) {
		newGame(currentLevel);
	}
	screen.deleteAnnounceFrame();
}

