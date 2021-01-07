#pragma once
#include "GameObject.h"
#include <iostream>
#include <vector>
#include <time.h>
#include "Buffer.h"
#include "Bird.h"
#include "Dinosaur.h"
#include "Car.h"
#include "Truck.h"
#include "Buffer2.h"

using namespace std;
class Lane
{
private:
	vector<GameObject*> list;
	int laneSpeed;
	string objectType;
	int lanePart;
public:
	Lane(){}
	Lane(int level, string type, int _lanePart);
	void add();
	void createObject(int level, string type, int lanePart);
	bool checkCollision(int, int);
	void draw(Buffer& buffer);
	void changeSpeed(int speed);
	void update(Buffer& buffer);
	string type();
	void init(int level, string type, int _lanePart);
	void clear();

	/*** new version ***/
	Lane(int level, string type);
	void createObjects(int level, string type);
	void update();
	void draw(Buffer2& buffer);
	void addOne();
	void init(int level, string type);
	GameObject* getObject() { return list.size() == 0 ? nullptr : list[0]; }
	~Lane();
};
