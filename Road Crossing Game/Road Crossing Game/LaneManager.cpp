#include "LaneManager.h"

LaneManager::LaneManager(int level, int laneWidth)
{
	int random = rand() % 4;
	lanes.resize(4);
	int index;
	for (int i = 0; i < 4; i++)
	{
		index = random + i < 4 ? random + i : (random + i) % 4;
		if (i == 0)
		{
			lanes[i] = new Lane(level, "bird", laneWidth * (index + 2));
		}
		else if (i == 1)
		{
			lanes[i] = new Lane(level, "dinosaur", laneWidth * (index + 2));
		}
		else if (i == 2)
		{
			lanes[i] = new Lane(level, "car", laneWidth * (index + 2)); // replace with car
		}
		else
		{
			lanes[i] = new Lane(level, "truck", laneWidth * (index + 2)); // replace with truck
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
	}

}

bool LaneManager::checkCollision(int x, int y)
{
	for (int i = 0; i < lanes.size(); i++)
	{
		if (lanes[i]->checkCollision(x, y))
			return true;
	}
	return false;
}

bool LaneManager::isVehicleStopped()
{
	return trafficLight == "red";
}



LaneManager::~LaneManager()
{
	for (int i = 0; i < lanes.size(); i++)
	{
		delete lanes[i];
	}
}
