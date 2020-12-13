#include "Truck.h"

vector<char> Truck::truckShape;

Truck::Truck(int x, int y, int s) : GameObject(x, y, truckShape, s) {}

Truck::~Truck() {}

void Truck::makeSound()
{
	cout << "Bum Bum" << endl;
}