#include "Dinosaur.h"

void Dinosaur::makeSound()
{
	PlaySound("/Sound/dino.wav", NULL, SND_SYNC);
}
