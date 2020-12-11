#pragma once
#include "Buffer.h"
#include "GameObject.h"
#include <iostream>
#include "Lane.h"
using namespace std;


class LaneManager
{
private:
	vector<Lane*> lanes;
	string trafficLight;
public:
	LaneManager(int, int);
	void update(Buffer& buffer);
	void draw(Buffer& buffer);
	bool checkCollision(int, int);
	bool isVehicleStopped();
	~LaneManager();

};

