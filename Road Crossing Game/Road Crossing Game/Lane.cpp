#include "Lane.h"

Lane::Lane(int level, string type, int lanePart)
{
	createObject(level, type, lanePart);
}

void Lane::add()
{
	if (objectType == "dinosaur")
	{
		list.insert(list.begin(), new Dinosaur(-laneSpeed + 2 + rand() % laneSpeed, lanePart - 2, laneSpeed));
	}
	else if (objectType == "bird")
	{
		list.insert(list.begin(), new Bird(-laneSpeed + 2 + rand() % laneSpeed, lanePart - 3, laneSpeed));
	}
	else if (objectType == "car")
	{
		list.insert(list.begin(), new Car(-laneSpeed + 2 + rand() % laneSpeed, lanePart - 2, laneSpeed));
	}
	else if (objectType == "truck")
	{
		list.insert(list.begin(), new Truck(-laneSpeed + 2 + rand() % laneSpeed, lanePart - 2, laneSpeed));
	}
}

void Lane::createObject(int level, string type, int _lanePart)
{
	lanePart = _lanePart;
	objectType = type;
	laneSpeed = 5 * level;

	int coord = -1;
	for (int i = 0; i < 60; i++)
	{
		// avoid overlapping between 2 consecutive objects
		coord = i == 0 ? rand() % 23 + 2 : list[i - 1]->getX() + list[i - 1]->getLength() + (rand() % 23 + 2);
		if (coord >= 60) {
			break;
		}
		if (type == "dinosaur")
		{
			list.push_back(new Dinosaur(coord, lanePart - 2, laneSpeed));
		}
		else if (type == "bird")
		{
			list.push_back(new Bird(coord, lanePart - 3, laneSpeed));
		}
		else if (type == "car")
		{
			list.push_back(new Car(coord, lanePart - 2, laneSpeed));
		}
		else if (type == "truck")
		{
			list.push_back(new Truck(coord, lanePart - 2, laneSpeed));
		}
	}
}


bool Lane::checkCollision(int x, int y)
{
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->checkCollision(x, y))
			return true;
	}
	return true;
}

void Lane::draw(Buffer& buffer)
{
	for (int i = 0; i < list.size(); i++)
		list[i]->draw(buffer);

}

void Lane::changeSpeed(int speed)
{
	laneSpeed = speed;
}

void Lane::update(Buffer& buffer)
{
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->move();
	}


	if (list.size() != 0 && !list[list.size() - 1]->isOnScreen(buffer))
	{
		delete list[list.size() - 1];
		list.pop_back();
		add();
	}


}

string Lane::type()
{
	return objectType;
}


Lane::~Lane()
{
	for (int i = 0; i < list.size(); i++) {
		delete list[i];
	}
}
