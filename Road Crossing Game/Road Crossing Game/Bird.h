#pragma once
#include "GameObject.h"
using namespace std;

class Bird :public GameObject
{
private:
	static int length;
	static int height;
public:
	Bird(int x, int y, int s, ColorCode code) : GameObject(x, y, s, code) {}
	~Bird() {}
	int getLength() { return length; }
	bool checkCollision(int, int);
	void makeSound();
};