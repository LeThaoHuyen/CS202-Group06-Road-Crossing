#pragma once
#include "Buffer.h"
#include "GameObject.h"
#include <iostream>
#include "Lane.h"
#include "People.h"
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
	bool checkCollision(People& player);
	bool isVehicleStopped();
	void init(int level, int laneWidth);
	void clear();
	void stopVehicles();
	void moveVehicles(int level);
	~LaneManager();

};

