
#include "Console.h"
#include "Buffer.h"
#include "GameObject.h"
#include "Lane.h"
#include "LaneManager.h"


vector<char> Bird::birdShape = { (char)223, (char)220, (char)223 };
vector<char> Dinasaur::dinaShape = { (char)220, (char)219, (char)223 };

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
	
	screen.displayFrame();
	
	
	for (int i = 0; i < 50; i++)
	{
		manager.update(screen);
		screen.update();
		manager.draw(screen);
		screen.display();
		Sleep(1000);
	}
	

	return 0;

}