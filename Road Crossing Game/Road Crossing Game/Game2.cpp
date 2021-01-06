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
	//laneManager.draw(screen);
	if (isLaneCarRed)
		laneManager.stopVehicles("car");
	else laneManager.moveVehicles(currentLevel, "car");
	
	if (isLaneTruckRed)
		laneManager.stopVehicles("truck");
	else laneManager.moveVehicles(currentLevel, "truck");

	laneManager.update();
	laneManager.draw(screen);

	screen.drawTrafficLight(isLaneCarRed, isLaneTruckRed);

	//player.selfDraw(screen);
	//std::this_thread::sleep_for(1s);
	Sleep(1000);
}
void Game2::drawPeople()
{
	player.selfDraw(screen);
}

void Game2::newGame(int level) {
	currentLevel = level;
	m_isRunning = true;
	laneManager.init(level);
	screen.displayMenu();
	screen.drawFrame();
	player.selfDraw(screen);
	drawGame(false, false);
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
	screen.displayConfirm(Pink);
	int key;
	key = _getch();
	if (key == 121) {
		ofstream out;
		out.open("save.txt");
		if (out.is_open()) {
			out << currentLevel << " " << player.getX() << " " << player.getY();
			out.close();
			screen.announceComplete(Pink);
			Sleep(200);
		}
	}
	screen.announceComplete(BlackAll);
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
	if (isWin())
	{
		PlaySound(TEXT("Sound/LevelUp.wav"), NULL, SND_ASYNC);
		screen.printCongrat();
		newGame(++currentLevel);
	}
}

void Game2::processLose()
{
	if (laneManager.checkCollision(player))
	{
		PlaySound(TEXT("Sound/GameOver.wav"), NULL, SND_ASYNC);
		int input = toupper(_getch());
		if (input == 'y' || input == 'Y')
		{
			currentLevel = 1;
			newGame(currentLevel);
		}
		else
		{
			// exit hoan toan khoi game
		}	
	}
}

bool Game2::checkCollision() {
	return laneManager.checkCollision(player);
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
