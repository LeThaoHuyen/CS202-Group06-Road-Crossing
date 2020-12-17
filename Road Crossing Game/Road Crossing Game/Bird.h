#pragma once
#include "GameObject.h"
using namespace std;

class Bird :public GameObject
{
private:
	string sound;
	static vector<char> birdShape;
public:
	Bird(int x, int y, int s, ColorCode code) : GameObject(x, y, Bird::birdShape, s, code) {}
	~Bird() {}
	void makeSound();
};