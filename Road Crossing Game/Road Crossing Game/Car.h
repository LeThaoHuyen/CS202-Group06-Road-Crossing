#pragma once
#include "GameObject.h"
using namespace std;

class Car : public GameObject
{
private:
	string sound;
	static vector<char> carShape;
public:
<<<<<<< Updated upstream
	Car(int x, int y, int s) : GameObject(x, y, Car::carShape, s) {}
	~Car() {}
=======
	Car(int x, int y, int s) : GameObject(x, y, Car :: carShape, s) {}
	~Car();
>>>>>>> Stashed changes
	void makeSound();
};