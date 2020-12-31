#include "Bird.h"

bool Bird::checkCollision(int x, int y)
{
	int mX = this->getX(), mY = this->getY();
	if (mX <= x && x < mX + Bird :: length + 1 && y < 13 && y > 7) {
		makeSound();
		return true;
	}
	return false;
}

void Bird::makeSound()
{
	PlaySound(TEXT("Sound/bird.wav"), NULL, SND_SYNC);
}