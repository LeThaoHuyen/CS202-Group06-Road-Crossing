#pragma once

#include <iostream>
#include "Console.h"
#include "Buffer.h"
#include "Game.h"
using namespace std;

class Menu : public Console
{
private:
	int input;
public:
	Menu();
	~Menu();
	void mainMenu(); // display when starting game
	void subMenu(); // display if users press P when playing
	void getInput(); // process menu
};