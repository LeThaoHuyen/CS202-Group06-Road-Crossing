#include "Buffer.h"

Buffer::Buffer(int gw, int gh, int fw, int fh) :console(gw, gh), frame_width(fw), frame_height(fh)
{
	console.fixConsoleWindow();

	// game_width, game_height are always greater than frame_width, frame_height;
	game_width = console.width();
	game_height = console.height();
	dx = (game_width - frame_width) / 2 - 1;
	dy = (game_height - frame_height) / 2 - 1;
	board.resize(game_width);
	color.resize(game_width);

	for (int i = 0; i < game_width; i++) 
	{
		board[i].resize(game_height);
		color[i].resize(game_height);
	}
	for (int i = 0; i < game_width; i++) 
	{
		for (int j = 0; j < game_height; j++) 
		{
			board[i][j] = (char)32;
			color[i][j] = Black;
		}
	}
	for (int i = 0; i < frame_width; i++) 
	{
		for (int j = 0; j < frame_height; j++) 
		{
			if (i == 0 || j == 0 || i == frame_width - 1 || j == frame_height - 1)
			{
				board[i + dx][j + dy] = '-';
				color[i + dx][j + dy] = Yellow;
			}
			else if (6 * (j + 1) % frame_height == 0)
			{
				board[i + dx][j + dy] = '-';
				color[i + dx][j + dy] = White;
			}
			else
			{
				board[i + dx][j + dy] = (char)32;
				color[i + dx][j + dy] = Black;
			}
		}
	}
	/* create menu  */
	menu_y = game_height / 2 - 10;
	menu_x = 5;
	createMainMenu();

}

void Buffer::display()
{
	for (int i = 0; i < frame_width; i++) 
	{
		for (int j = 0; j < frame_height; j++) 
		{
			if (board[i + dx][j + dy] != '-') 
			{
				console.gotoXY(i + dx, j + dy);
				console.setTextColor(color[i + dx][j + dy]);
				std::cout << board[i + dx][j + dy];
			}
		}

	}
}

void Buffer::updateBuffer(int x, int y, char t)
{
	board[x + dx][y + dy] = t;
}
void Buffer::update() {
	for (int i = 0; i < frame_width; i++) 
	{
		for (int j = 0; j < frame_height; j++) 
		{
			if (i == 0 || j == 0 || i == frame_width - 1 || j == frame_height - 1)
				board[i + dx][j + dy] = '-';
			else if (6 * (j + 1) % frame_height == 0)
				board[i + dx][j + dy] = '-';
			else
				board[i + dx][j + dy] = (char)32;
		}
	}

}

void Buffer::displayFrame()
{
	for (int i = 0; i < frame_width; i++) 
	{
		for (int j = 0; j < frame_height; j++) 
		{
			if (board[i + dx][j + dy] == '-') 
			{
				console.gotoXY(i + dx, j + dy);
				console.setTextColor(color[i + dx][j + dy]);
				std::cout << board[i + dx][j + dy];
			}
		}
	}
}

void Buffer::init(int gw, int gh, int fw, int fh)
{
	frame_width = fw;
	frame_height = fh;
	console.init(gw, gh);

	console.fixConsoleWindow();

	// game_width, game_height are always greater than frame_width, frame_height;
	game_width = console.width();
	game_height = console.height();
	dx = (game_width - frame_width) / 2 - 1;
	dy = (game_height - frame_height) / 2 - 1;
	board.resize(game_width);
	color.resize(game_width);

	for (int i = 0; i < game_width; i++)
	{
		board[i].resize(game_height);
		color[i].resize(game_height);
	}
	for (int i = 0; i < game_width; i++)
	{
		for (int j = 0; j < game_height; j++)
		{
			board[i][j] = (char)32;
			color[i][j] = Black;
		}
	}
	for (int i = 0; i < frame_width; i++)
	{
		for (int j = 0; j < frame_height; j++)
		{
			if (i == 0 || j == 0 || i == frame_width - 1 || j == frame_height - 1)
			{
				board[i + dx][j + dy] = '-';
				color[i + dx][j + dy] = DarkYellow;
			}
			else if (6 * (j + 1) % frame_height == 0)
			{
				board[i + dx][j + dy] = '-';
				color[i + dx][j + dy] = White;
			}
			else
			{
				board[i + dx][j + dy] = (char)32;
				color[i + dx][j + dy] = Black;
			}
		}
	}


}

void Buffer::setColor(int x, int y, ColorCode code)
{
	color[x + dx][y + dy] = code;
}

void Buffer::updateBuffer(int x, int y, std::string s, int speed)
{


	for (int i = 0; i < s.length(); i++) 
	{
		if (x + i < frame_width) 
		{
			board[x + i + dx][y + dy] = s[i];
		}
	}

}

void Buffer::updateBuffer(int x, int y, std::string s, int speed, ColorCode code) {

	for (int i = 0; i < s.length(); i++)
	{
		if (x + i < frame_width)
		{
			board[x + i + dx][y + dy] = s[i];
			color[x + i + dx][y + dy] = code;
		}
	}

}
//---------------------------------


/*  menu  frame  */

void Buffer::displayMenu()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < Buffer::menu[i].length(); j++)
		{
			console.gotoXY(menu_x + j, menu_y + i);
			console.setTextColor(color[menu_x + j][menu_y + i]);
			cout << board[menu_x + j][menu_y + i];
		}
	}
}

void Buffer::updateOption(int choice)
{
	for (int i = 0; i < 3; i++)
	{
		board[menu_x - 2][menu_y + i] = (char)32;
		color[menu_x - 2][menu_y + i] = Black;

	}
	board[menu_x - 2][menu_y + choice - 1] = (char)62;
	color[menu_x - 2][menu_y + choice - 1] = Red;
}


void Buffer::showOption()
{
	for (int i = 0; i < 3; i++)
	{
		if (board[menu_x - 1][menu_y + i] == (char)62)
		{
			console.gotoXY(menu_x - 2, menu_y + i);
			console.setTextColor(color[menu_x - 2][menu_y + i]);
			cout << board[menu_x - 2][menu_y + i];
			break;
		}
	}
}

void Buffer::createInGameMenu()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < Buffer::in_game_menu[i].length(); j++)
		{
			board[menu_x + j][menu_y + i] = Buffer::in_game_menu[i][j];
			color[menu_x + j][menu_y + i] = Green;
		}
	}
	board[menu_x - 2][menu_y] = (char)62;
	color[menu_x - 2][menu_y] = Red;
}

void Buffer::createMainMenu()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < Buffer::menu[i].length(); j++)
		{
			board[menu_x + j][menu_y + i] = Buffer::menu[i][j];
		}
	}
	board[menu_x - 2][menu_y] = (char)62;
	color[menu_x - 2][menu_y] = Red;
}