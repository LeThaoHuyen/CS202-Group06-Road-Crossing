#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "GameObject.h"
using namespace std;

class Truck : public GameObject
{
private:
	string sound;
	static vector<char> truckShape;
public:
	Truck::Truck(int x, int y, int s) : GameObject(x, y, truckShape, s) {}
	~Truck();
	void makeSound();
};