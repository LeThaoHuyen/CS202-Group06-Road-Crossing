#include "Car.h"

bool Car::checkCollision(int x, int y)
{
	int mX = this->getX(), mY = this->getY();
	if (mX <= x && x < mX + Car :: length + 2 && y > 25 && y < 31) {
		makeSound();
		return true;
	}
	return false;
}

void Car::makeSound()
{
	PlaySound(TEXT("Sound/car.wav"), NULL, SND_SYNC);
}