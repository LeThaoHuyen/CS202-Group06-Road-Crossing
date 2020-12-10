#pragma once
#include<string.h>
#include <vector>
#include <iostream>
#include "GameObject.h"


class Bird :public GameObject
{
private:
	string sound;
	static vector<char> birdShape;
public:
	Bird(int x, int y, int s) : GameObject(x, y, Bird::birdShape, s) {}
	void makeSound();
	~Bird() {}

};