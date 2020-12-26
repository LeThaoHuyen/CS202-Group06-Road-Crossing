#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>
#include "Console.h"
using namespace std;
class Buffer2
{
private:
	int frame_width, frame_height;
	int game_width, game_height;
	std::vector<std::vector<char>> board;
	Console console;

	/* shape */
	string truck[4] = {
		"__________",
		"|         |__",
		"|_________|__|",
		" (_)      (_)"

	};
	string car[4] = {
	 "     ___",
	 " ___/   \\___" ,
	 "|___ ____ __|" ,
	 "    O    O"
	};
	string bird[3] = {
	"__     __" ,
	 "\\ \\o o/ /" ,
	" \\__V__/"
	};
	string dino[4] = {
	 "    \\_\\" ,
	 "  _/ ^_)" ,
	 "\\/_L_/L",
	 " U  U" 
	};


public:
	Buffer2() = default;
	Buffer2(int, int, int, int);
	void init(int, int, int, int);
	void displayMenu();
	void drawFrame();
	void drawObject(int, int, string type, int speed);
	void clear();
	int width() { return game_width; }
};
