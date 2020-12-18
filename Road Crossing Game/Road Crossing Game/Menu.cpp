#include "Menu.h"

Menu::Menu() : input{0} {}

Menu::~Menu() {}

void Menu::mainMenu()
{
	cout << "Start Game" << endl
		<< "Load Game" << endl
		<< "Exit" << endl;
}

void Menu::subMenu()
{
	cout << "Contiue Game" << endl
		<< "Save Game" << endl
		<< "Exit" << endl;
}

void Menu::getInput()
{
	switch ((input = _getch()))
	{
	case key_UpArrow:
		// go up
		break;
	case key_DownArrow:
		// go down
		break;
	default:
		break;
	}
}