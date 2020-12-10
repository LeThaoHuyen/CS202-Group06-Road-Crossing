#pragma once
#include "GameObject.h"
#include <iostream>
using namespace std;

class Dinasaur : public GameObject
{
private:
	string sound;
	static vector<char> dinaShape;
public:
	Dinasaur(int x, int y, int s) : GameObject(x, y, Dinasaur :: dinaShape, s){}
	void makeSound();
	~Dinasaur(){}
};

