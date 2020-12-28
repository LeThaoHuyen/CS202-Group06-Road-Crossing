#include "Truck.h"

Truck::~Truck() {}

void Truck::makeSound()
{
	PlaySound(TEXT("Sound/truck.wav"), NULL, SND_SYNC);
}

bool Truck::checkCollision(int x, int y)
{
	int mX = this->getX(), mY = this->getY();
	for (int i = 0; i < Truck::length; i++) {
		for (int j = 0; j < Truck::height; j++) {
			if (mX + i == x && mY + j == y) {
				makeSound();
				return true;
			}
		}
	}
	return false;
}
