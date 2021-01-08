#include "GameObject.h"

GameObject::GameObject(int x, int y, int s, ColorCode code) 
{

	mX = x;
	mY = y;
	speed = s;
	this->code = code;
}
void GameObject::move(int x, int y)
{
	mX = x;
	mY = y;
}

void GameObject::move()
{
	
	mX += speed;
}


bool GameObject::checkCollision(GameObject& other)
{
	return true;
}

bool GameObject::checkCollision(int x, int y)
{
	for (int i = 0; i < this->getLength(); ++i) {
		if (mX + i == x && mY == y)
			return true;
	}
	return false;
}

int GameObject::getLength()
{
	return objectLength;
}

int GameObject::getSpeed()
{
	return speed;
}

void GameObject::changeSpeed(int speed)
{
	this->speed = speed;
}
