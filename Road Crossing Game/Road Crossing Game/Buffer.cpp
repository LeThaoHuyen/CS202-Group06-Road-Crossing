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

	for (int i = 0; i < game_width; i++) 
	{
		board[i].resize(game_height);
	}
	for (int i = 0; i < game_width; i++) 
	{
		for (int j = 0; j < game_height; j++) 
		{
			board[i][j] = (char)32;
		}
	}
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

void Buffer::display()
{
	for (int i = 0; i < frame_width; i++) 
	{
		for (int j = 0; j < frame_height; j++) 
		{
			if (board[i + dx][j + dy] != '-') 
			{
				console.gotoXY(i + dx, j + dy);
				std::cout << board[i + dx][j + dy];
			}
		}

	}
}

void Buffer::updateBuffer(int x, int y, char t)
{
	board[x][y] = t;
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
				std::cout << board[i + dx][j + dy];
			}
		}
	}
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
