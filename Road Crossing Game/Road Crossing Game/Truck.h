#pragma once
#include "GameObject.h"
using namespace std;

class Truck : public GameObject
{
private:
	static int length;
	static int height;
public:
	Truck(int x, int y, int s, ColorCode code) : GameObject(x, y, s, code) {}
	~Truck();
	void makeSound();
	int getLength() { return length; }
	bool checkCollision(int, int);
};