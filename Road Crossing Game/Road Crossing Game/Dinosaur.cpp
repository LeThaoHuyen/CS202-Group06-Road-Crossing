#include "Dinosaur.h"

void Dinosaur::makeSound()
{
	PlaySound(TEXT("Sound/dino.wav"), NULL, SND_SYNC);
}

bool Dinosaur::checkCollision(int x, int y)
{
	int mX = this->getX(), mY = this->getY();
	if (mX <= x && x < mX + Dinosaur::length && mY <= y && y < mY + Dinosaur::height) {
		makeSound();
		return true;
	}
	return false;
}
