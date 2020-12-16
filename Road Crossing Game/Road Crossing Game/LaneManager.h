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
	LaneManager() = default;
	LaneManager(int, int);
	void update(Buffer& buffer);
	void draw(Buffer& buffer);
	bool checkCollision(int, int);
	bool isVehicleStopped();
	void init(int level, int laneWidth);
	void clear();
	~LaneManager();

};

