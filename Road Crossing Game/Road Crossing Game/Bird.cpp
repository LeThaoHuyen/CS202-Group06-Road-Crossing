#include "Bird.h"

bool Bird::checkCollision(int x, int y)
{
	int mX = this->getX(), mY = this->getY();
	for (int i = 0; i < Bird::length; i++) {
		for (int j = 0; j < Bird::height; j++) {
			if (mX + i == x && mY + j == y) {
				makeSound();
				return true;
			}
		}
	}
	return false;
}

void Bird::makeSound()
{
	PlaySound(TEXT("Sound/bird.wav"), NULL, SND_SYNC);
}