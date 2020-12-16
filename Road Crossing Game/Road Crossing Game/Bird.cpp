#include "Bird.h"

void Bird::makeSound()
{
	PlaySound("/Sound/bird.wav", NULL, SND_SYNC);
}