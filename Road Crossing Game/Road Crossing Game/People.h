#pragma once
#include "GameObject.h"
#include <iostream>
using namespace std;

const int frameLeftBorder = 31;
const int frameRightBorder = 158;

class People
{
public:
	People();
	People(int w, int h);
	~People();
	void init(int, int);
	void Up();
	void Left();
	void Right();
	void Down();
	void Dead();
	bool isDead();
	string getShape();
	int getX();
	int getY();
	void selfDraw(Buffer2 & buffer2);

private:
	int mX, mY;
	bool mState;
	int speedX;
	int speedY;
	string shape;
	string direction;
};
