#pragma once
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <windows.h>
#include "Buffer.h"

class GameObject
{
private:
	int mX, mY;
	int objectLength;
	std :: string shape;
	int speed;
public:
	GameObject(int, int, std::vector<char>& list, int);
	void move(int, int);
	void move();
	std :: string getShape();
	int getX() { return mX; }
	void draw(Buffer& buffer);
	bool checkCollision(GameObject& other);
	bool checkCollision(int, int);
	virtual void makeSound() = 0;
	bool isOnScreen(Buffer& buffer);
	int getLength();
	int getSpeed();
	void changeSpeed(int );
	void setX(int x) { mX = x; }
};

