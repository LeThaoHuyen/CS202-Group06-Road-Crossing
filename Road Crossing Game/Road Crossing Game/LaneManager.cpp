#include "LaneManager.h"

LaneManager::LaneManager(int level, int laneWidth)
{
	
	lanes.resize(4);
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			lanes[i] = new Lane(level, "bird", laneWidth * (i + 2));
		}
		else if (i == 1)
		{
			lanes[i] = new Lane(level, "dinosaur", laneWidth * (i + 2));
		}
		else if (i == 2)
		{
			lanes[i] = new Lane(level, "truck", laneWidth * (i + 2)); 
		}
		else
		{
			lanes[i] = new Lane(level, "car", laneWidth * (i + 2)); 
		}
	}
}

void LaneManager::update(Buffer& buffer)
{
	for (int i = 0; i < lanes.size(); i++)
	{

		lanes[i]->update(buffer);
	}
}

void LaneManager::draw(Buffer& buffer)
{
	for (int i = 0; i < lanes.size(); i++)
	{
		lanes[i]->draw(buffer);
		if (i == 2){
			buffer.updateBuffer(1, 15, (char)220);
			buffer.updateBuffer(1, 16, (char)220);
			buffer.setColor(1, 16, Green);
		}
		else if (i == 3) {
			buffer.updateBuffer(buffer.bufferWidth()-2, 20 , (char)220);
			buffer.updateBuffer(buffer.bufferWidth()-2, 21, (char)220);
			buffer.setColor(buffer.bufferWidth() - 2 , 21, Green);
			
		}
	}

}
// **** check collision ****
bool LaneManager::checkCollision(int x, int y)
{
	for (int i = 0; i < lanes.size(); i++)
	{
		if (lanes[i]->checkCollision(x, y))
		{
			string type = lanes[i]->type();
			if (type == "car")
			{
				// car sound
			}
			else if (type == "truck")
			{
				// truck sound
			}
			else if (type == "dinosaur")
			{
				// dino sound
			}
			else
			{
				// bird sound
			}
			// play GameOver.wav
			return true;
		}
	}
	return false;
}
bool LaneManager::checkCollision(People& player)
{
	int x = player.getX(), y = player.getY();
	
	for (int i = 0; i < lanes.size(); ++i) {
		if (lanes[i]->checkCollision(x, y) || lanes[i]->checkCollision(x, y + 1) || lanes[i]->checkCollision(x, y + 2)) {
			return true;
		}
	}
	return false;
}



bool LaneManager::isVehicleStopped()
{
	return trafficLight == "red";
}


// *** initialize ***
void LaneManager::init(int level, int laneWidth)
{
	
	lanes.resize(4);
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			lanes[i] = new Lane(level, "bird", laneWidth * (i + 2));
		}
		else if (i == 1)
		{
			lanes[i] = new Lane(level, "dinosaur", laneWidth * (i + 2));
		}
		else if (i == 2)
		{
			lanes[i] = new Lane(level, "truck", laneWidth * (i + 2));
		}
		else
		{
			lanes[i] = new Lane(level, "car", laneWidth * (i + 2)); 
		}
	}

}



LaneManager::~LaneManager()
{
	for (int i = 0; i < lanes.size(); i++)
	{
		delete lanes[i];
	}
}


void LaneManager::clear()
{
	for (int i = 0; i < lanes.size(); i++)
	{
		lanes[i]->clear();
	}
	lanes.clear();
}


// *** Control vehicles traffic ***
void LaneManager::stopVehicles()
{
	for (int i = 0; i < lanes.size(); i++)
	{
		if (lanes[i]->type() == "car" || lanes[i]->type() == "truck")
			lanes[i]->changeSpeed(0);
	}
}

void LaneManager::moveVehicles(int level)
{
	for (int i = 0; i < lanes.size(); i++) {
		if (lanes[i]->type() == "car" || lanes[i]->type() == "truck")
			lanes[i]->changeSpeed(level * 5);
	}
}

/*** new version ***/
LaneManager::LaneManager(int level)
{
	lanes.resize(4);
	lanes[0] = new Lane(level, "bird");
	lanes[1] = new Lane(level, "dinosaur");
	lanes[2] = new Lane(level, "truck");
	lanes[3] = new Lane(level, "car");
}

void LaneManager::init(int level) 
{
	lanes.resize(4);
	lanes[0] = new Lane(level, "bird");
	lanes[1] = new Lane(level, "dinosaur");
	lanes[2] = new Lane(level, "truck");
	lanes[3] = new Lane(level, "car");
}

void LaneManager::update()
{
	for (int i = 0; i < lanes.size(); i++) {
		lanes[i]->update();
	}
}

void LaneManager::draw(Buffer2& buffer) {
	for (int i = 0; i < lanes.size(); i++) {
		lanes[i]->draw(buffer);
	}
}

