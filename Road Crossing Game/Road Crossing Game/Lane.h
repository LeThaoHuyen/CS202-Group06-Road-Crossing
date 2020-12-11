#pragma once
#include "GameObject.h"
#include <iostream>
#include <vector>
#include "Buffer.h"
#include "Bird.h"
#include "Dinasaur.h"

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
	~Lane();
};
