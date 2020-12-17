
#include "Console.h"
#include "Buffer.h"
#include "GameObject.h"
#include "Lane.h"
#include "LaneManager.h"
#include "People.h"
#include "Game.h"

vector<char> Bird::birdShape = { (char)223, (char)220, (char)223 };
vector<char> Dinosaur::dinoShape = { (char)220, (char)219, (char)223 };
vector<char> Car::carShape = { (char)220,(char)219,(char)219,(char)220 };
vector<char> Truck::truckShape = { (char)219, (char)219, (char)220 };

// game size
//const int consolewidth = 1300;
//const int consoleheight = 1600;
//const int framewidth = 60;
//const int frameheight = 30;
//const int lanewidth = frameheight / 6;

Game game(1);

// demo
void runGame() {
	game.newGame(1);
	while (game.isRunning()) {
		game.drawGame();
		Sleep(1000);
	}
}
int main() 
{
	//Buffer screen(consoleWidth, consoleHeight, frameWidth, frameHeight);

	//LaneManager manager(1, laneWidth);
	//People p(frameWidth, frameHeight - 2);
	//
	//screen.displayFrame();
	//screen.update();
	//p.draw(screen);
	//manager.draw(screen);
	//screen.display();
	//
	//
	//for (int i = 0; i < 50; i++)
	//{
	//	if (i < 10 && i > 5)
	//		manager.stopVehicles();

	//	else {
	//		manager.moveVehicles(1);
	//	}
	//	
	//	manager.update(screen);
	//	screen.update();
	//	manager.draw(screen);
	//	/*p.draw(screen);*/
	//	screen.display();

	//	/*if (p.getY() == laneWidth - 2 || p.isDead())
	//	{
	//		break;
	//	}*/

	//	Sleep(1000);
	//}
	//
	//if (p.isDead())
	//{
	//	cout << "You lost" << endl;
	//}
	//else
	//{
	//	cout << "You won. Go to next level ? " << endl;
	//}
	//return 0;
	
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
	}
	
	return 0;
}