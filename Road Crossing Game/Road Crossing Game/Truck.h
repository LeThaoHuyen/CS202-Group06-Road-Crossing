#pragma once
#include "GameObject.h"
using namespace std;

class Truck : public GameObject
{
private:
	string sound;
	static vector<char> truckShape;
public:
	Truck(int x, int y, int s) : GameObject(x, y, Truck::truckShape, s) {}
	~Truck();
	void makeSound();
};