#include "Truck.h"

Truck::~Truck() {}

void Truck::makeSound()
{
	PlaySound(TEXT("Sound/truck.wav"), NULL, SND_SYNC);
}