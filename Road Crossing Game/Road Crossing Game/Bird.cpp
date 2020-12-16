#include "Bird.h"

void Bird::makeSound()
{
	PlaySound(TEXT("Sound/bird.wav"), NULL, SND_SYNC);
}