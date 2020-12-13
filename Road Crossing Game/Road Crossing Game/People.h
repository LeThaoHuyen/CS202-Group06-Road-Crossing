#pragma once
#include <iostream>
using namespace std;
class People
{
public:
	People();
	~People();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact();
	bool isImpact();
	bool isFinish();
	bool isDead();
private:
	int mX, mY;
	bool mState;
};
