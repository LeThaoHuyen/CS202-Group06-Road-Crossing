
#include "Console.h"
#include "Buffer.h"
#include "GameObject.h"
#include "Lane.h"
#include "LaneManager.h"
#include "People.h"


vector<char> Bird::birdShape = { (char)223, (char)220, (char)223 };
vector<char> Dinosaur::dinoShape = { (char)220, (char)219, (char)223 };
//vector<char> Car::carShape = { (char)221, (char)223, (char)222 };
//vector<char> Truck::truckShape = { (char)219, (char)219, (char)220 };

vector<char> Car::carShape = { (char)220, (char)219, (char)219, (char)220 };
vector<char> Truck::truckShape = { (char)219, (char)219, (char)220, (char)220 };

// Game size
const int consoleWidth = 800;
const int consoleHeight = 600;
const int frameWidth = 60;
const int frameHeight = 30;
const int laneWidth = frameHeight / 6;


int main() 
{
	Buffer screen(consoleWidth, consoleHeight, frameWidth, frameHeight);

	LaneManager manager(1, laneWidth);
	People p(frameWidth, frameHeight - 2);
	
	screen.displayFrame();
	screen.update();
	p.draw(screen);
	manager.draw(screen);
	screen.display();
	
	
	for (int i = 0; i < 50; i++)
	{
		manager.update(screen);
		p.Up();
		

		screen.update();
		manager.draw(screen);
		p.draw(screen);
		screen.display();

		if (p.getY() == laneWidth - 2 || p.isDead())
		{
			break;
		}

		Sleep(1000);
	}
	
	if (p.isDead())
	{
		cout << "You lost" << endl;
	}
	else
	{
		cout << "You won. Go to next level ? " << endl;
	}
	return 0;

}