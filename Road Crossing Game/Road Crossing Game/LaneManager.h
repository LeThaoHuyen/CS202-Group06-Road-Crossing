#pragma once
#include "Buffer.h"
#include "GameObject.h"
#include <iostream>
#include "Lane.h"
#include "People.h"
using namespace std;

// Game size
const int consoleWidth = 1300;
const int consoleHeight = 1300;
const int frameWidth = 60;
const int frameHeight = 30;

const int laneWidth = frameHeight / 6;

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

	/*** new version ****/
	LaneManager(int level);
	void init(int level);
	void update();
	void draw(Buffer2& buffer);
	~LaneManager();

};

