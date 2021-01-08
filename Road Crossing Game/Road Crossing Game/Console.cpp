#include "Console.h"

Console::Console() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	c_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	c_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

Console::Console(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);

	// modified --------------------------------------------
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	int size =  columns * 1000 + rows;
	
	c_width = size / 1000;
	c_height = size % 1000;
	//-------------------------------------------------------
}

Console::~Console(){

}

void Console::init(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);

	// modified --------------------------------------------
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	int size = columns * 1000 + rows;

	c_width = size / 1000;
	c_height = size % 1000;
}


void Console::printString(string s, int row, int begin, int end, size_t cursorPos, size_t cursorPosConsole) {
	hideCursor();
	--end;
	size_t len;

	gotoXY(begin, row);
	for (len = begin; len <= end; ++len)
		cout << " ";

	gotoXY(begin, row);
	len = s.length();
	if (len <= end - begin + 1)
		cout << s;
	else {
		for (size_t i = cursorPos - (cursorPosConsole - begin); i <= cursorPos - cursorPosConsole + end; ++i)
			cout << s[i];
	}
	showCursor();
}

string Console::getClipboardText() {
	string text;

	if (OpenClipboard(NULL)){
		HANDLE clip;
		clip = GetClipboardData(CF_TEXT);
		// lock and copy
		text = (LPSTR)GlobalLock(clip);
		// unlock 
		GlobalUnlock(clip);
		CloseClipboard();
	}

	return text;
}

void Console::setTextColor(ColorCode color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Console::gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void Console::clearScreen() {
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void Console::hideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void Console::showCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 10;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

//string Console::textEdit(int row, int begin, int end) {
//	showCursor();
//	gotoXY(begin, row);
//	string res;
//	size_t cursorPos = 0, cursorPosConsole = begin;
//	char c;
//	do {
//		c = _getch();
//		if (c == Ctrl_V) {
//			string paste = getClipboardText();
//			res.insert(cursorPos, paste);
//			goRight(cursorPos, cursorPosConsole, end, res, paste.length());
//		}
//		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
//			|| c == ':' || c == '/' || c == '.' || c == ' ') {
//			res.insert(cursorPos, 1, c);
//			goRight(cursorPos, cursorPosConsole, end, res, 1);
//		}
//		else if (c == key_Backspace) {
//			if (cursorPos > 0) {
//				res.erase(cursorPos - 1, 1);
//				goLeft(cursorPos, cursorPosConsole, begin);
//			}
//		}
//		else if (c == -32) {
//			switch (_getch()) {
//			case key_RightArrow:
//				if (cursorPos < res.length()) {
//					goRight(cursorPos, cursorPosConsole, end, res, 1);
//				}
//				break;
//			case key_LeftArrow:
//				if (cursorPos > 0) {
//					goLeft(cursorPos, cursorPosConsole, begin);
//				}
//			}
//		}
//
//		printString(res, row, begin, end, cursorPos, cursorPosConsole);
//		gotoXY(cursorPosConsole, row);
//	} while (c != key_Enter);
//
//	hideCursor();
//	return res;
//}

void goRight(size_t& cursor1, size_t& cursor2, int end, string s, int step) {
	cursor1 += step;
	cursor2 += step;
	if (cursor2 > end)
		cursor2 = end - (s.length() - cursor1);
}

void goLeft(size_t& cursor1, size_t& cursor2, int begin) {
	--cursor1;
	if (cursor1 < cursor2 - begin)
		--cursor2;
}
