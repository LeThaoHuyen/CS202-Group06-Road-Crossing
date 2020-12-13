#pragma once
#include "Lane.h"
#include "LaneManager.h"
#include "Console.h"
#include "Buffer.h"
#include <iostream>
using namespace std;
class People
{
public:
	People();
	~People();
	void Up();
	void Left();
	void Right();
	void Down();
	void Dead();
	bool isDead();
private:
	int mX, mY;
	bool mState;
	int speed;
};
