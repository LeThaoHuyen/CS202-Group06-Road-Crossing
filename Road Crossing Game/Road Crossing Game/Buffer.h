#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>
#include "Console.h"
using namespace std;
class Buffer
{
private:
	int frame_width, frame_height, game_width, game_height;
	std::vector<std::vector<char>> board;
	Console console;
	int dx, dy;

	
public:
	Buffer(){}
	Buffer(int, int, int, int);
	void display();
	void updateBuffer(int x, int y, char t);
	void updateBuffer(int x, int y, std::string s, int speed);
	void update();
	void displayFrame();
	int bufferWidth() { return frame_width; }
	void init(int gw, int gh, int fw, int fh);

};

