#pragma once
#include "GameObject.h"
//using namespace std;

class Dinosaur : public GameObject
{
private:
	static int length;
	static int height;
public:
	Dinosaur(int x, int y, int s, ColorCode code) : GameObject(x, y, s, code) {}
	~Dinosaur() {}
	void makeSound();
	int getLength() { return length; }
	bool checkCollision(int, int);
};