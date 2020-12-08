#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>
class Buffer
{
private:
	int width, height;
	std::vector<std::vector<char>> board;

public:
	Buffer(int, int);
	void display();
	void updateBuffer(int x, int y, char t);
	void updateBuffer(int x, int y, std::string s, int speed);
	void GotoXY(int, int);
	void displayFrame();
	int bufferWidth() { return width; }

};

