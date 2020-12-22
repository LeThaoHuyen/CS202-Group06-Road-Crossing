#pragma once
#include "GameObject.h"
using namespace std;

class Truck : public GameObject
{
private:
	string sound;
	static vector<char> truckShape;
	static int length;
public:
	Truck(int x, int y, int s, ColorCode code) : GameObject(x, y, Truck::truckShape, s, code) {}
	~Truck();
	void makeSound();
	int getLength() { return length; }
};