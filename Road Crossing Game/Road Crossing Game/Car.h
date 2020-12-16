#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "GameObject.h"
using namespace std;

class Car : public GameObject
{
private:
	string sound;
	static vector<char> carShape;
public:
	Car::Car(int x, int y, int s) : GameObject(x, y, carShape, s) {}
	~Car();
	void makeSound();
};