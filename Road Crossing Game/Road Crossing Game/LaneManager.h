#pragma once

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
	bool checkCollision(People& player, bool playSound );
	bool isVehicleStopped();
	void clear();

	/*** control vehicle traffic ***/
	void stopVehicles(string);
	void moveVehicles(int level, string);

	/*** new version ****/
	LaneManager(int level);
	void init(int level);
	void update();
	void draw(Buffer2& buffer);
	~LaneManager();

};

