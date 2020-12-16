#include "Dinosaur.h"

void Dinosaur::makeSound()
{
	PlaySound(TEXT("Sound/dino.wav"), NULL, SND_SYNC);
}