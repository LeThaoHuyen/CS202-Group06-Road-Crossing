#pragma once
#include "GameObject.h"
#include <iostream>
using namespace std;

class Dinosaur : public GameObject
{
private:
	string sound;
	static vector<char> dinoShape;
public:
	Dinosaur(int x, int y, int s) : GameObject(x, y, Dinosaur::dinoShape, s) {}
	void makeSound();
	~Dinosaur() {}
};
