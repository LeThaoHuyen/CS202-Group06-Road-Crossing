
#include "GameObject.h"
#include "Lane.h"
#include "LaneManager.h"
#include "People.h"
#include "Buffer2.h"
#include "Game2.h"
#include "thread"
#include "ctime"

vector<char> Bird::birdShape = { (char)223, (char)220, (char)223 };
vector<char> Dinosaur::dinoShape = { (char)220, (char)219, (char)223 };
vector<char> Car::carShape = { (char)220,(char)219,(char)219,(char)220 };
vector<char> Truck::truckShape = { (char)219, (char)219, (char)220 };

string Buffer :: menu[3] = { "1. NEW GAME", "2. LOAD GAME", "3. EXIT" };
string Buffer :: in_game_menu[4] = { "1. CONTINUE", "2. NEW GAME", "3. SAVE GAME", "4. EXIT" };


int Bird::length = 9;
int Dinosaur::length = 8;
int Car::length = 13;
int Truck::length = 14;

int Car::height = 4;
int Dinosaur::height = 4;
int Bird::height = 3;
int Truck::height = 4;

Game2 game(2);
bool isLaneCarRed = false;
bool isLaneTruckRed = false;

// demo
void runGame() {
	while (game.isRunning()) {
		
		game.drawGame(isLaneCarRed, isLaneTruckRed);
		
		// Test collision
		if (game.checkCollision()) {
			game.pauseGame();
			game.processLose();
		}
		if (game.isWin()) {
			game.pauseGame();
		}
		
	}
}


void trafficLight() {
	time_t currentTime;

	while (true) {
		time(&currentTime);

		if (currentTime % 17 == 0) {
			isLaneCarRed = true;
			Sleep(5000);
		}

		if (currentTime % 13 == 0) {
			isLaneTruckRed = true;
			std::this_thread::sleep_for(5s);
			Sleep(5000);
		}

		isLaneCarRed = false;
		isLaneTruckRed = false;
	}
}

int main() 
{
	/****  menu ****/
	game.displayMainMenu();
	
	int key;
	int option = 0;
	
	while (true) {
		key = _getch();
		if (key == key_Enter) {
			game.showOption(option, key);
			break;

		}
		if (key == key_UpArrow) {
			option = option == 0 ? 2 : option - 1;
			game.showOption(option, key);

		}
		if (key == key_DownArrow) {
			option = option == 2 ? 0 : option + 1;
			game.showOption(option, key);

		}

	}
	if (option == 0) {
		game.newGame(2);
	}
	else if (option == 1) {
		game.loadGame();
	}
	else if (option == 2) {
		exit(0);
	}

	thread t1(runGame);
	thread t2(trafficLight);
	while (true) {
		key = _getch();
		if (key == key_Pause) {
			game.pauseGame();
		}
		else if (key == key_UnPause) {
			if (!game.isRunning()) {
				game.resumeGame();
				t1.detach();
				t1 = thread(runGame);
			}
		}
		
		else if (key == key_Save) {
			game.pauseGame();
			game.saveGame();
			game.resumeGame();
			t1.detach();
			t1 = thread(runGame);
		}
		
		else if (key == key_Exit) {
			
		}

		else if (game.isRunning()) {
			if (key == key_UpArrow) {
				game.player.Up();
				//game.player.selfDraw();
				game.drawPeople();
			}

			if (key == key_DownArrow) {
				game.player.Down();
				//game.player.selfDraw();
				game.drawPeople();

			}
			if (key == key_RightArrow) {
				game.player.Right();
				//game.player.selfDraw();
				game.drawPeople();

			}
			if (key == key_LeftArrow) {
				game.player.Left();
				game.drawPeople();

			}
		}
	}
	
		
	return 0;
}