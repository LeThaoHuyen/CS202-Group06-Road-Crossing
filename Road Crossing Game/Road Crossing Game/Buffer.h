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
	std::vector<std::vector<ColorCode>> color;
	Console console;
	int dx, dy;

	/* menu frame */
	static string menu[3];
	static string in_game_menu[3];
	int menu_x, menu_y;
	
public:
	Buffer(){}
	Buffer(int, int, int, int);
	void display();
	void updateBuffer(int x, int y, char t);
	void updateBuffer(int x, int y, std::string s, int speed);
	void updateBuffer(int x, int y, std::string s,int speed,ColorCode code);
	void update();
	void displayFrame();
	int bufferWidth() { return frame_width; }
	void init(int gw, int gh, int fw, int fh);
	void setColor(int x, int y, ColorCode code);

	/*  menu  */
	void displayMenu();
	void updateOption(int choice);
	void showOption();
	void createInGameMenu();
	void createMainMenu();
};

