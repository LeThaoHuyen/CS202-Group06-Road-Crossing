#include "People.h"


People::People()
{
	mX = mY = 0;
	mState = true;
	speedX = 1;
	speedY = 1;
}
People::People(int w, int h)
{
	mState = true;
	mY = h;
	mX = w / 2;
	shape = "";
	shape += (char)220;
	speedX = 5;
	speedY = (h + 2) / 6;
}

void People::init(int w, int h) {
	mState = true;
	mY = h;
	mX = w / 2;
	shape = "";
	shape += (char)220;
	speedX = 5;
	speedY = (h + 2) / 6;
}
void People::Up()
{
	mY -= speedY;
}
void People::Down()
{
	mY += speedY;
}
void People::Left(Buffer & buffer)
{
	if (isOnScreen(buffer))
		mX -= speedX;
}
void People::Right(Buffer & buffer)
{
	if (isOnScreen(buffer))
		mX += speedX;
}
void People::Dead()
{
	mState = false;
}

bool People::isDead()
{
	if (mState == true)
		return false;
	else return true;
}

int People::getX()
{
	return mX;
}

int People::getY()
{
	return mY;
}

string People::getShape()
{
	return shape;
}
void People :: draw(Buffer& buffer)
{
	if (isDead())
		buffer.updateBuffer(mX + 2, mY, shape[0]);
	else
		buffer.updateBuffer(mX, mY, shape[0]);
}

bool People :: isOnScreen(Buffer& buffer)
{
	return mX >= 0 && mX < buffer.bufferWidth();
}

People::~People()
{
}