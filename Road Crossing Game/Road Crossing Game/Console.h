#pragma once

#include <Windows.h>
#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

enum ColorCode {
	Black      = 1,  Gray    = 8,
	DarkGreen  = 2,  Blue    = 9,
	DarkCyan   = 3,  Green   = 10,
	DarkRed    = 4,  Cyan    = 11,
	DarkPink   = 5,  Red     = 12,
	DarkYellow = 6,  Pink    = 13,
	DarkWhite  = 7,  Yellow  = 14,
	White      = 15, Default = 7,
	BlackAll   = 0
};

#define key_Enter		13
#define Ctrl_V			22
#define key_Backspace	8
#define key_DownArrow	80
#define key_UpArrow		72
#define key_LeftArrow	75
#define key_RightArrow	77
#define key_Pause       112
#define key_UnPause     117
#define key_Save        115
#define key_Exit        101

class Console
{
public:
	static const int rightShift = 20;
private:
	int c_width;
	int c_height;

	void printString(string, int, int, int, size_t, size_t);
	string getClipboardText();
public:
	Console();
	Console(int, int);
	~Console();

	void init(int, int);
	void setTextColor(ColorCode color);
	void gotoXY(int x, int y);
	void fixConsoleWindow();
	void clearScreen();
	void hideCursor();
	void showCursor();
	int width() { return c_width; }
	int height() { return c_height; }
	int midVertical() const { return c_width / 2; }
	int midHorizontal() const { return c_height / 2; }
	//string textEdit(int row, int begin, int end);

	
};

