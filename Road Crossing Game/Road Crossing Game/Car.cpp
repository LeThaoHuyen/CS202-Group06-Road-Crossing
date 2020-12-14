#include "Car.h"



Car::Car(int x, int y, int s) : GameObject(x, y, carShape, s) {}

Car::~Car() {}

void Car::makeSound()
{
	cout << "In In" << endl;
}