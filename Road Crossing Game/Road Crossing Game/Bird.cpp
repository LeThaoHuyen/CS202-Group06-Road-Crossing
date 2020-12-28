#include "Bird.h"

bool Bird::checkCollision(int x, int y)
{
	int mX = this->getX(), mY = this->getY();
	if (mX <= x && x < mX + Bird::length && mY <= y && y < mY + Bird::height) {
		makeSound();
		return true;
	}
	return false;
	return false;
}

void Bird::makeSound()
{
	PlaySound(TEXT("Sound/bird.wav"), NULL, SND_SYNC);
}