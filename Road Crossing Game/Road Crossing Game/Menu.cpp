#include "Menu.h"

Menu::Menu() : input{0} {}

Menu::~Menu() {}

void Menu::showMain(Buffer &buffer)
{
	buffer.createMainMenu();
	buffer.displayMenu();
}

void Menu::showSub(Buffer &buffer)
{
	buffer.createInGameMenu();
	buffer.displayMenu();
}

int Menu::processMain(Buffer &buffer, )
{
	int choice = 1;
	buffer.updateOption(choice);
	buffer.showOption();
	switch ((input = _getch()))
	{
	case key_UpArrow:
		if (choice != 1)
			--choice;
		buffer.updateOption(choice);
		buffer.showOption();
		break;
	case key_DownArrow:
		if (choice != 3)
			++choice;
		buffer.updateOption(choice);
		buffer.showOption();
		break;
	case key_Enter:
		if (choice == 1)
			return 1;	// NEW GAME
		else if (choice == 2)
			return 2;	// LOAD GAME
		else
			return 3;	// EXIT
	default:
		break;
	}
}

int Menu::processSub(Buffer &buffer)
{
	int choice = 1;
	buffer.updateOption(choice);
	buffer.showOption();
	switch ((input = _getch()))
	{
	case key_UpArrow:
		if (choice != 1)
			--choice;
		buffer.updateOption(choice);
		buffer.showOption();
		break;
	case key_DownArrow:
		if (choice != 4)
			++choice;
		buffer.updateOption(choice);
		buffer.showOption();
		break;
	case key_Enter:
		if (choice == 1)
			return 1;	// CONTINUE
		else if (choice == 2)
			return 2;	// NEW GAME
		else if (choice == 3)
			return 3; 	// SAVE GAME
		else
			return 4;	// EXIT
	default:
		break;
	}
}