#pragma once
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <windows.h>
#include "Buffer.h"
#include "Buffer2.h"

class GameObject
{
private:
	int mX, mY;
	int objectLength;
	int speed;
	string shape;
	ColorCode code;
public:
	GameObject(int, int, int, ColorCode);
	GameObject(int, int, vector<char> & list, int, ColorCode);
	void move(int, int);
	void move();
	std :: string getShape();
	int getX() { return mX; }
	int getY() { return mY; }
	void draw(Buffer& buffer);
	bool checkCollision(GameObject& other);
	bool checkCollision(int, int);
	virtual void makeSound() = 0;
	bool isOnScreen(Buffer& buffer);
	virtual int getLength();
	int getSpeed();
	void changeSpeed(int );
	void setX(int x) { mX = x; }
	ColorCode getCode() { return code; }
};

