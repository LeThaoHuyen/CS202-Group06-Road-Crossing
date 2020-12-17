#pragma once
#include "GameObject.h"
using namespace std;

class Car : public GameObject
{
private:
	string sound;
	static vector<char> carShape;
public:
	Car(int x, int y, int s, ColorCode code) : GameObject(x, y, Car::carShape, s, code) {}
	~Car() {}
	void makeSound();
};