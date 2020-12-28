#include "Dinosaur.h"

void Dinosaur::makeSound()
{
	PlaySound(TEXT("Sound/dino.wav"), NULL, SND_SYNC);
}

bool Dinosaur::checkCollision(int x, int y)
{
	int mX = this->getX(), mY = this->getY();
	for (int i = 0; i < Dinosaur::length; i++) {
		for (int j = 0; j < Dinosaur::height; j++) {
			if (mX == x && mY == y) {
				makeSound();
				return true;
			}
		}
	}
	return false;
}
