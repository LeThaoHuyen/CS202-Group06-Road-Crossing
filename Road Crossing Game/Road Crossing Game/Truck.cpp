#include "Truck.h"

Truck::~Truck() {}

void Truck::makeSound()
{
	PlaySound(TEXT("Sound/truck.wav"), NULL, SND_SYNC);
}

bool Truck::checkCollision(int x, int y)
{
	int mX = this->getX(), mY = this->getY();
	
	if (mX <= x && x < mX + Truck :: length + 1 && y > 19 && y < 25) {
		cout << mX << " ";
		makeSound();
		return true;
	}
	return false;
}
