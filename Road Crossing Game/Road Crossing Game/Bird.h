#pragma once
#include "GameObject.h"
using namespace std;

class Bird :public GameObject
{
private:
	string sound;
	static vector<char> birdShape;
public:
	Bird(int x, int y, int s) : GameObject(x, y, Bird::birdShape, s) {}
	~Bird() {}
	void makeSound();
};