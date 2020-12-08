#include "Buffer.h"

Buffer::Buffer(int w, int h) : width(w), height(h)
{
	board.resize(w);
	for (int i = 0; i < w; i++) 
	{
		for (int j = 0; j < h; j++) 
		{
			if (i == 0 || j == 0 || i == w - 1 || j == h - 1)
				board[i].push_back('-');
			else if (6 * (j + 1) % h == 0)
				board[i].push_back('-');
			else
				board[i].push_back((char)32);
		}
	}
}

void Buffer::display()
{
	for (int i = 0; i < width; i++) 
	{
		for (int j = 0; j < height; j++) 
		{
			if (board[i][j] != '-') 
			{
				GotoXY(i, j);
				std::cout << board[i][j] << std::endl;
			}
		}

	}
}

void Buffer::updateBuffer(int x, int y, char t)
{
	board[x][y] = t;

}

void Buffer::updateBuffer(int x, int y, std::string s, int speed)
{
	for (int i = 0; i < s.length(); i++) 
	{
		if (x + i < width) {
			board[x + i][y] = s[i];
		}
	}
}

void Buffer::GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void Buffer::displayFrame()
{
	for (int i = 0; i < width; i++) 
	{
		for (int j = 0; j < height; j++) 
		{
			if (board[i][j] == '-') 
			{
				GotoXY(i, j);
				std::cout << board[i][j];
			}
		}
	}
}



