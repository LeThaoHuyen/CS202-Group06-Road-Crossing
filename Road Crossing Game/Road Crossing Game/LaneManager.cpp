#include "LaneManager.h"




// **** check collision ****

bool LaneManager::checkCollision(People& player, bool playSound)
{
	int x = player.getX(), y = player.getY();
	
	for (int i = lanes.size() - 1; i > -1; --i) {
		if (lanes[i]->checkCollision(x, y)) {
			if (playSound) {
				lanes[i]->getObject()->makeSound();
			}
			return true;
		}
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


void LaneManager::clear()
{
	for (int i = 0; i < lanes.size(); i++)
	{
		lanes[i]->clear();
	}
	lanes.clear();
}


// *** Control vehicles traffic ***
void LaneManager::stopVehicles(string vehicleType)
{
	for (int i = 0; i < lanes.size(); i++)
	{
		if (lanes[i]->type() == vehicleType)
			lanes[i]->changeSpeed(0);
	}
}

void LaneManager::moveVehicles(int level, string vehicleType)
{
	for (int i = 0; i < lanes.size(); i++) {
		if (lanes[i]->type() == vehicleType)
			lanes[i]->changeSpeed(5);
	}
}
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

