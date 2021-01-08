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
	mX = w;
	shape = "";
	shape += (char)187;
	//shape += (char)223;
	shape += (char)201;
	speedX = 5;
	// Speed y changes only if the frame height changes
	speedY = 6;
}

void People::init(int w, int h) {
	mState = true;
	mY = h;
	mX = w ;
	shape = "";
	shape += (char)187;
	//shape += (char)223;
	shape += (char)201;
	speedX = 5;
	// Speed y changes only if the frame height changes
	speedY = 6; 
}
void People::Up()
{
	//invisible();
	if (mY - speedY > 1) {
		PlaySound(TEXT("Sound/MovingSound.wav"), NULL, SND_SYNC);
		mY -= speedY;
		direction = "up";
	}
}
void People::Down()
{
	//invisible();
	if (mY + speedY < 37) {
		PlaySound(TEXT("Sound/MovingSound.wav"), NULL, SND_SYNC);
		mY += speedY;
		direction = "down";
	}
}
void People::Left()
{
	if (mX - speedX > frameLeftBorder) {
		//invisible();
		PlaySound(TEXT("Sound/MovingSound.wav"), NULL, SND_SYNC);
		mX -= speedX;
		direction = "left";
	}
}
void People::Right()
{
	if (mX + speedX < frameRightBorder) {
		//invisible();
		PlaySound(TEXT("Sound/MovingSound.wav"), NULL, SND_SYNC);
		mX += speedX;
		direction = "right";
	}
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

void People::selfDraw(Buffer2& buffer2)
{
	buffer2.drawPeople(mX, mY, speedX, speedY, direction);
}
People::~People()
{
}