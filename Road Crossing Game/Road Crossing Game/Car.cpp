#include "Car.h"

bool Car::checkCollision(int x, int y)
{
	int mX = this->getX(), mY = this->getY();
	for (int i = 0; i < Car::length; i++) {
		for (int j = 0; j < Car::height; j++) {
			if (mX + i == x && mY + j == y) {
				makeSound();
				return true;
			}
		}
	}
	return false;
}

void Car::makeSound()
{
	PlaySound(TEXT("Sound/car.wav"), NULL, SND_SYNC);
}