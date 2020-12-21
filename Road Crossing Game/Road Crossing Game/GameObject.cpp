#include "GameObject.h"

GameObject::GameObject(int x, int y, int s, ColorCode code) 
{

	mX = x;
	mY = y;
	speed = s;
	this->code = code;
}
GameObject::GameObject(int x, int y, std::vector<char>& list, int s, ColorCode code)
{

	mX = x;
	mY = y;
	shape = "";
	for (char ch : list)
		shape += ch;
	objectLength = shape.length();
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



void GameObject::draw(Buffer& buffer)
{
	if (isOnScreen(buffer))
		buffer.updateBuffer(mX, mY, "", speed, code);
}

bool GameObject::checkCollision(GameObject& other)
{
	return mX == other.mX && mY == other.mY;
}

bool GameObject::checkCollision(int x, int y)
{
	return mX == x && mY == y;
}

bool GameObject::isOnScreen(Buffer& buffer)
{
	if (mX > buffer.bufferWidth() - 1)
		return false;
	return true;
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
