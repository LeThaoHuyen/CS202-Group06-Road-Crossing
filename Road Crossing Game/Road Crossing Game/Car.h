#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "GameObject.h"
using namespace std;

class Car : public GameObject
{
private:
	string sound;
	static vector<char> carShape;
public:
	Car(int x, int y, int s);
	~Car();
	void makeSound();
};