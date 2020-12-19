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
	void showMenu(Buffer &buffer); 		// display when starting game
	void showSub(Buffer &buffer); 		// display if users press P when playing
	int processMain(Buffer &buffer);	// process main menu
	int processSub(Buffer &buffer);    	// process sub menu
};