#pragma once
#include "Buffer.h"
#include <iostream>
using namespace std;
class People
{
public:
	People();
	People(int w, int h);
	~People();
	void init(int, int);
	void Up();
	void Left(Buffer & buffer);
	void Right(Buffer & buffer);
	void Down();
	void Dead();
	bool isDead();
	string getShape();
	int getX();
	int getY();
	void selfDraw();
	void draw(Buffer& buffer);
	bool isOnScreen(Buffer& buffer);
private:
	int mX, mY;
	bool mState;
	int speedX;
	int speedY;
	string shape;
};
