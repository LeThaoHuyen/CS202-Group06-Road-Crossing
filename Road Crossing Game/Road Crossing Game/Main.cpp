
#include "GameObject.h"
#include "Lane.h"
#include "LaneManager.h"
#include "People.h"
#include "Buffer2.h"
#include "Game2.h"
#include "thread"

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

// demo
void runGame() {
	while (game.isRunning()) {
		
		
		game.drawGame();
		// Test collision

		if (game.checkCollision()) {
			game.pauseGame();
		}
		
		
	}
}
int main() 
{
	game.newGame(2);
	thread t1(runGame);
	int key;
	while (true) {
		key = _getch();
		if (key == key_Pause) {
			game.pauseGame();
		}
		if (key == key_UnPause) {
			if (!game.isRunning()) {
				game.resumeGame();
				t1.detach();
				t1 = thread(runGame);
			}
		}
		if (key == key_UpArrow) {
			game.player.Up();
			game.drawPeople();
			
		}
		if (key == key_DownArrow) {
			game.player.Down();
			game.drawPeople();
		
		}
		if (key == key_RightArrow) {
			game.player.Right();
			game.drawPeople();
			
		}
		if (key == key_LeftArrow) {
			game.player.Left();
			game.drawPeople();
			
		}
	}
	

	///* Test  */
	///*Lane lane(1, "bird");
	//Lane lane1(1, "dinosaur");
	//Lane lane2(1, "car");
	//Lane lane3(1, "truck");*/
	//LaneManager manager(1);
	//Buffer2 screen(1300, 1300, 60, 30);
	//screen.displayMenu();
	//screen.drawFrame();
	///*lane.draw(screen);
	//lane1.draw(screen);
	//lane2.draw(screen);
	//lane3.draw(screen);*/
	//manager.draw(screen);

	//for (int i = 0; i < 100; i++) {
	//	/*lane.update();
	//	lane1.update();
	//	lane2.update();
	//	lane3.update();*/
	//	manager.update();
	//	//screen.clear();
	//	/*lane.draw(screen);
	//	lane1.draw(screen);
	//	lane2.draw(screen);
	//	lane3.draw(screen);*/
	//	manager.draw(screen);
	//	Sleep(1000);
	//}



	
	return 0;
}