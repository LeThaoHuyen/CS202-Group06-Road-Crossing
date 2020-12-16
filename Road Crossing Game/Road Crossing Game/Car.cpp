#include "Car.h"
#include <conio.h>

Car::~Car() {}

void Car::makeSound()
{
	mciSendStringA("play nen.mp3", 0, NULL, 0);
}