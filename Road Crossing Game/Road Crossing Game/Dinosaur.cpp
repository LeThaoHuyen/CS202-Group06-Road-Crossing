#include "Dinosaur.h"

void Dinosaur::makeSound()
{
	PlaySound(TEXT("Sound/dino.wav"), NULL, SND_SYNC);
}

bool Dinosaur::checkCollision(int x, int y)
{
	int mX = this->getX(), mY = this->getY();
	if (mX <= x && x < mX + Dinosaur :: length + 1 && y > 13 && y < 19 ) {
		return true;
	}
	return false;
}
