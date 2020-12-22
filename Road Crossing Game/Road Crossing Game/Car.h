#pragma once
#include "GameObject.h"
using namespace std;

class Car : public GameObject
{
private:
	string sound;
	static vector<char> carShape;
	static int length;
public:
	//Car(int x, int y, int s, ColorCode code) : GameObject(x, y, s, code) {}
	Car(int x, int y, int s, ColorCode code) : GameObject(x, y,Car :: carShape, s, code){}
	~Car() {}
	int getLength() { return length; }
	void makeSound();
};