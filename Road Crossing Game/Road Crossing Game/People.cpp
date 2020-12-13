#include "People.h"


People::People()
{
	mX = mY = 0;
	mState = true;
	speed = 1;
}
void People::Up()
{
	mY -= speed;
}
void People::Down()
{
	mY += speed;
}
void People::Left()
{
	mX -= speed;
}
void People::Right()
{
	mX += speed;
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
	


People::~People()
{
}