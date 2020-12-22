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
	speedY = (h + 2) / 6;
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
	speedY = (h + 2) / 6;
}
void People::Up()
{
	invisible();
	mY -= speedY;
}
void People::Down()
{
	invisible();
	mY += speedY;
}
void People::Left()
{
	if (mX - speedX > frameLeftBorder) {
		invisible();
		mX -= speedX;
	}
}
void People::Right()
{
	if (mX + speedX < frameRightBorder) {
		invisible();
		mX += speedX;
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
void People :: draw(Buffer& buffer)
{
	buffer.updateBuffer(mX, mY, shape, 0, Green);
}

bool People :: isOnScreen(Buffer& buffer)
{
	return mX >= 0 && mX < buffer.bufferWidth();
}
void People::selfDraw() {
	HANDLE  hConsole;
	Console g;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	x = this->mX;
	y = this->mY;
	const char TITLE[][3] = { {32,153,32},
							{218, 219, 191 },
							{32,208,32} };

	g.setTextColor(Cyan);
	int i, j;
	for (i = 0; i < 3; ++i) {
		g.gotoXY(x, y++);
		for (j = 0; j < 3; ++j) {
			cout << TITLE[i][j];
		}
	}
}
void People::invisible() {
	HANDLE  hConsole;
	Console g;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	x = this->mX;
	y = this->mY;
	const char TITLE[][3] = { {32,153,32},
							{218, 219, 191 },
							{32,208,32} };

	g.setTextColor(BlackAll);
	int i, j;
	for (i = 0; i < 3; ++i) {
		g.gotoXY(x, y++);
		for (j = 0; j < 3; ++j) {
			cout << TITLE[i][j];
		}
	}
}
People::~People()
{
}