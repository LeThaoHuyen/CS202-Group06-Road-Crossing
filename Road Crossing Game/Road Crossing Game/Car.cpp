#include "Car.h"

void Car::makeSound()
{
	PlaySound(TEXT("Sound/car.wav"), NULL, SND_SYNC);
}