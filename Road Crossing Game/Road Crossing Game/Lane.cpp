#include "Lane.h"

Lane::Lane(int level, string type, int lanePart)
{
	createObject(level, type, lanePart);
}

void Lane::add()
{
	if (objectType == "dinosaur")
	{
		list.insert(list.begin(), new Dinosaur(-laneSpeed + 2 + rand() % laneSpeed, lanePart - 2, laneSpeed, DarkGreen));
	}
	else if (objectType == "bird")
	{
		list.insert(list.begin(), new Bird(-laneSpeed + 2 + rand() % laneSpeed, lanePart - 3, laneSpeed, Yellow));
	}
	else if (objectType == "car")
	{
		list.insert(list.begin(), new Car(-laneSpeed + 2 + rand() % laneSpeed, lanePart - 2, laneSpeed, Red));
	}
	else if (objectType == "truck")
	{
		list.insert(list.begin(), new Truck(-laneSpeed + 2 + rand() % laneSpeed, lanePart - 2, laneSpeed, Blue));
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
			list.push_back(new Dinosaur(coord, lanePart - 2, laneSpeed, DarkGreen));
		}
		else if (type == "bird")
		{
			list.push_back(new Bird(coord, lanePart - 3, laneSpeed, Yellow));
		}
		else if (type == "car")
		{
			list.push_back(new Car(coord, lanePart - 2, laneSpeed, Red));
		}
		else if (type == "truck")
		{
			list.push_back(new Truck(coord, lanePart - 2, laneSpeed,Blue));
		}
	}
}


bool Lane::checkCollision(int x, int y)
{
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->checkCollision(x, y))
			return true;
	}
	return false;
}

void Lane::draw(Buffer& buffer)
{
	for (int i = 0; i < list.size(); i++)
		list[i]->draw(buffer);

}

void Lane::changeSpeed(int speed)
{
	laneSpeed = speed;
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->changeSpeed(laneSpeed);
	}
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
	list.clear();
}

void Lane::init(int level, string type, int _lanePart)
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
			list.push_back(new Dinosaur(coord, lanePart - 2, laneSpeed, DarkGreen));
		}
		else if (type == "bird")
		{
			list.push_back(new Bird(coord, lanePart - 3, laneSpeed, Yellow));
		}
		else if (type == "car")
		{
			list.push_back(new Car(coord, lanePart - 2, laneSpeed, Red));
		}
		else if (type == "truck")
		{
			list.push_back(new Truck(coord, lanePart - 2, laneSpeed, Blue));
		}
	}
}

void Lane::clear()
{
	for (int i = 0; i < list.size(); i++)
	{
		delete list[i];
	}
	list.clear();
}

/******************************                  new version           ***************************/


Lane::Lane(int level, string type)
{
	laneSpeed = level * 5;
	objectType = type;

	if (type == "bird") {
		list.push_back(new Bird(31, 11, laneSpeed, Blue));
	}
	else if (type == "dinosaur") {
		list.push_back(new Dinosaur(31, 16, laneSpeed, Red));
	}
	else if (type == "car") {
		list.push_back(new Car(31, 25, laneSpeed, Yellow));
	}
	else if (type == "truck") {
		list.push_back(new Truck(31, 25, laneSpeed, Green));
	}

	int i = 31 + list[0]->getLength() + 20;
	int cur = list.size();
	while (i < 158) {
		if (type == "bird") {
			list.push_back(new Bird(i, 11, laneSpeed, Blue));
		}
		else if (type == "dinosaur") {
			list.push_back(new Dinosaur(i, 16, laneSpeed, Red));
		}
		else if (type == "car") {
			list.push_back(new Car(i, 24, laneSpeed, Yellow));
		}
		else if (type == "truck") {
			list.push_back(new Truck(i, 36, laneSpeed, Green));
		}
		cur = list.size();
		i += list[cur - 1]->getLength() + 20;
	}
}
void Lane::init(int level, string type) {
	laneSpeed = level * 5;
	objectType = type;

	if (type == "bird") {
		list.push_back(new Bird(31, 11, laneSpeed, Blue));
	}
	else if (type == "dinosaur") {
		list.push_back(new Dinosaur(31, 16, laneSpeed, Red));
	}
	else if (type == "car") {
		list.push_back(new Car(31, 25, laneSpeed, Yellow));
	}
	else if (type == "truck") {
		list.push_back(new Truck(31, 25, laneSpeed, Green));
	}

	int i = 31 + list[0]->getLength() + 20;
	int cur = list.size();
	while (i < 158) {
		if (type == "bird") {
			list.push_back(new Bird(i, 11, laneSpeed, Blue));
		}
		else if (type == "dinosaur") {
			list.push_back(new Dinosaur(i, 16, laneSpeed, Red));
		}
		else if (type == "car") {
			list.push_back(new Car(i, 24, laneSpeed, Yellow));
		}
		else if (type == "truck") {
			list.push_back(new Truck(i, 36, laneSpeed, Green));
		}
		cur = list.size();
		i += list[cur - 1]->getLength() + 20;
	}
}

void Lane::draw(Buffer2& buffer) {
	for (int i = 0; i < list.size(); i++) {
		buffer.drawObject(list[i]->getX(), list[i]->getY(), objectType, laneSpeed);
	}
	int last = list.size() - 1;
	if (last >= 0 && list[last]->getX() > buffer.width()) {
		delete list[last];
		list.pop_back();
		addOne();
	}
}
void Lane::addOne() {
	if (objectType == "bird") {
		list.insert(list.begin(), new Bird(20, 11, laneSpeed, Blue));
	}
	else if (objectType == "dinosaur") {
		list.insert(list.begin(), new Dinosaur(20, 16, laneSpeed, Red));
	}
	else if (objectType == "car") {
		list.insert(list.begin(), new Car(20, 24, laneSpeed, Yellow));
	}
	else if (objectType == "truck") {
		list.insert(list.begin(), new Truck(20, 36, laneSpeed, Green));
	}
}
void Lane::update() {
	for (int i = 0; i < list.size(); i++) {
		list[i]->move();
	}
}

