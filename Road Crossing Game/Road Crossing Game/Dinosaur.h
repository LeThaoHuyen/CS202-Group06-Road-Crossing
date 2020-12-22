#pragma once
#include "GameObject.h"
//using namespace std;

class Dinosaur : public GameObject
{
private:
	string sound;
	static vector<char> dinoShape;
	static int length;
public:
	Dinosaur(int x, int y, int s, ColorCode code) : GameObject(x, y, Dinosaur::dinoShape, s, code) {}
	~Dinosaur() {}
	void makeSound();
	int getLength() { return length; }
};