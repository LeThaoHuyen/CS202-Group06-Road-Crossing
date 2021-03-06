#include "Buffer2.h"

Buffer2::Buffer2(int gw, int gh, int fw, int fh) :console(gw, gh), frame_width(fw), frame_height(fh)
{
	console.fixConsoleWindow();

	game_width = console.width(); // 158
	

	game_height = console.height(); // 63

	board.resize(game_width);
	for (int i = 0; i < game_width; i++) {
		board[i].resize(game_height);
	}
	for (int i = 0; i < game_width; i++) {
		for (int j = 0; j < game_height; j++) {
			board[i][j] = (char)32;
		}
	}

	for (int i = 30; i < game_width; i++) {
		board[i][1] = board[i][7] = board[i][13] = board[i][19] = board[i][25] = board[i][31] = board[i][37] = '-';
		if (i == 30 || i == game_width - 1) {
			for (int j = 1; j <= 37; j++) {
				board[i][j] = '|';
			}
		}
	}
}

void Buffer2::init(int gw, int gh, int fw, int fh) {
	console.init(gw, gh);
	frame_width = fw;
	frame_height = fh;

	console.fixConsoleWindow();

	game_width = console.width(); // 158

	game_height = console.height(); // 63

	board.resize(game_width);
	for (int i = 0; i < game_width; i++) {
		board[i].resize(game_height);
	}
	for (int i = 0; i < game_width; i++) {
		for (int j = 0; j < game_height; j++) {
			board[i][j] = (char)32;
		}
	}

	for (int i = 30; i < game_width; i++) {
		board[i][1] = board[i][7] = board[i][13] = board[i][19] = board[i][25] = board[i][31] = board[i][37] = '-';
		if (i == 30 || i == game_width - 1) {
			for (int j = 1; j <= 37; j++) {
				board[i][j] = '|';
			}
		}
	}
}

void Buffer2::displayMenu()
{
	mtx.lock();
	console.setTextColor(Cyan);
	for (int i = 0; i < 25; i++) {
		if (i == 0 || i == 24) {
			console.gotoXY(i + 1, 2);
			cout << "|";
		}
		console.gotoXY(i + 1, 1);
		cout << "-";
		console.gotoXY(i + 1, 3);
		cout << "-";
		
	}

	console.setTextColor(Green);
	console.gotoXY(3, 2);
	cout << "Level: ";
	console.setTextColor(Cyan);


	for (int i = 0; i < 25; i++) {
		if (i == 0 || i == 24) {
			for (int j = 11; j <= 19; j += 2) {
				console.gotoXY(i + 1, j);
				cout << "|";
			}

		}
		for (int j = 10; j <= 20; j += 2) {
			console.gotoXY(i + 1, j);
			cout << "-";
		}

	}
	console.setTextColor(Green);
	console.gotoXY(3, 11);
	cout << "Press S to save";
	console.gotoXY(3, 13);
	cout << "Press P to pause";
	console.gotoXY(3, 15);
	cout << "Press E to exit";
	console.gotoXY(3, 17);
	cout << "Press U to continue";
	console.gotoXY(3, 19);
	cout << "Press R to reset";
	console.setTextColor(Cyan);

	for (int i = 30; i < game_width; i++) {
		console.gotoXY(i, 1);
		cout << "-";
		console.gotoXY(i, 37);
		cout << "-";
		if (i == 30 || i == game_width - 1) {
			for (int j = 1; j < 38; j++) {
				console.gotoXY(i, j);
				cout << "|";
			}
		}
	}
	mtx.unlock();
}

void Buffer2::showOption(int option)
{
	mtx.lock();
	console.gotoXY(80, 14);
	cout << (char)32;
	console.gotoXY(80, 17);
	cout << (char)32;
	console.gotoXY(80, 20);
	cout << (char)32;
	if (option == 0) {
		console.gotoXY(80, 14);
		cout << ">";
	}
	else if (option == 1) {
		console.gotoXY(80, 17);
		cout << ">";

	}
	else if (option == 2) {
		console.gotoXY(80, 20);
		cout << ">";
	}
	mtx.unlock();
}

void Buffer2::displayMainMenu() {
	const char Title[][82] = { { 32,95,95,95,95,95,32,32,     32,32,32,32,32,32,32,		 32,32,32,32,32,32,32,		  32,32,32,32,32,'_',32,	   32,32,32,32,32,  32,32,32,'_','_','_','_',32,	32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,	   32,32,32,32,32,		 32,32,32,	  32,32,32,32,32,32,32,		   },
								 { 32,'_',95,95,95,95,32,32,     32,32,32,32,32,32,32,		 32,32,32,32,32,32,32,		  32,32,32,32,32,'_',32,	   32,32,32,32,32,  32,32,32,'_','_','_','_',32,	32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,	   32,32,32,32,32,		 32,32,32,	  32,32,32,32,32,32,32,		   },
								{ '|',32,32,'_','_',32,92,32,	 32,32,32,32,32,32,32,		 32,32,32,32,32,32,32,		  32,32,32,32,'|',32,178,	   32,32,32,32,32,  32,32,'/',32,'_','_','_',178,	32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,	   32,32,32,32,32,		 32,32,32,	  32,32,32,32,32,32,32,		   },
								{ '|',32,178,'_','_',')',32,')', 32,32,'_','_','_',32,32,	 32,32,'_','_',32,'_',32,	  32,32,'_','_','|',32,178,	   32,32,32,32,32,  32,'/',32,32,178,32,32,32,		32,'_',32,'_','_',32,	 32,32,'_','_','_',32,32,	 32,'_','_','_',32,    32,'_','_','_',32,	 '(','_',')', 32,'_',32,'_','_',32,32,	  32,32,'_','_',32,'_',32},
								{ '|',32,32,'_',32,32,'/',32,	 32,'/',32,'_',32,'\\',32,	 32,'/',32,'_','\'',32,178,	  32,'/',32,'_',32,32,178,	   32,32,32,32,32,  '|',32,32,32,178,32,32,32,		'|',32,'\'','_','_',178, 32,'/',32,'_',32,'\\',32,	 '/',32,'_','_',178,   '/',32,'_','_',178,   '|',32,178,  '|',32,'\'','_',32,'\\',32, 32,'/',32,'_','\'',32,178},
								{ '|',32,178,32,92,32,92,32,	 '(',32,'(','_',')',32,')',	 '(',32,'(','_',')',32,178,	  '(',32,'(','_',')',32,178,   32,32,32,32,32,  32,'\\',32,32,178,'_','_','_',  '|',32,178,32,32,32,	 '(',32,'(','_',')',32,')',  '\\','_','_',32,'\\', '\\','_','_',32,'\\', '|',32,178,  '|',32,178,32,'|',32,178,	  '(',32,'(','_',')',32,178},
								{ '|','_',178,32,32,92,'_',92,	 32,'\\','_','_','_','/',32, 32,'\\','_','_',',','_',178, 32,'\\','_','_',',','_',178, 32,32,32,32,32,  32,32,'\\','_','_','_','_',178, '|','_',178,32,32,32,	 32,'\\','_','_','_','/',32, 178,'_','_','_','/',  178,'_','_','_','/',  '|','_',178, '|','_',178,32,'|','_',179, 32,'\\','_','_',',',32,178},
								{ 32,32,32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,32,32,		  32,32,32,32,32,32,32,		   32,32,32,32,32,  32,32,32,32,32,32,32,32,		32,32,32,32,32,32,		 32,32,32,32,32,32,32,		 32,32,32,32,32,	   32,32,32,32,32,		 32,32,32,	  32,32,32,32,32,32,32,		  32,178,'_','_','_','/'} };

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int row = 3;
	int column = 55;
	int i, j;
	for (i = 0; i < 8; ++i) {
		console.gotoXY(column, row++);
		for (j = 0; j < 82; ++j) {
			SetConsoleTextAttribute(hConsole, i);
			cout << Title[i][j];
		}
	}

	console.setTextColor(Cyan);
	console.gotoXY(82, 13);
	cout << "------------------------";
	console.gotoXY(82, 14);
	cout << "*      New game        *";
	console.gotoXY(82, 15);
	cout << "------------------------";
	console.gotoXY(82, 16);
	cout << "------------------------";
	console.gotoXY(82, 17);
	cout << "*      Load game       *";
	console.gotoXY(82, 18);
	cout << "------------------------";
	console.gotoXY(82, 19);
	cout << "------------------------";
	console.gotoXY(82, 20);
	cout << "*      Exit game       *";
	console.gotoXY(82, 21);
	cout << "------------------------";
	console.gotoXY(80, 14);
	cout << ">";
	console.hideCursor();
}
void Buffer2::showChoice(int option)
{
	mtx.lock();
	if (option == 0) {
		console.gotoXY(82, 14);
		console.setTextColor(x);
		cout << "*      New game        *";
	}
	else if (option == 1) {
		console.gotoXY(82, 17);
		console.setTextColor(x);
		cout << "*      Load game       *";
	}
	else if (option == 2) {
		console.gotoXY(82, 20);
		console.setTextColor(x);
		cout << "*      Exit game       *";
	}
	console.setTextColor(White);
	mtx.unlock();
}


void Buffer2::clear() {
	for (int i = 31; i < game_width - 1; i++) {
		for (int j = 1; j <= 37; j++) {
			if (j != 1 && j != 7 && j != 13 && j != 19 && j != 25 && j != 31 && j != 37) {
				console.gotoXY(i, j);
				cout << (char)32;
			}
		}
	}
}
void Buffer2::drawFrame() {
	mtx.lock();
	console.hideCursor();
	console.setTextColor(Cyan);
	for (int i = 30; i < game_width; i++) {
		for (int j = 1; j <= 37; j++) {
			if (board[i][j] != '|' || board[i][j] != '-') {
				console.gotoXY(i, j);
				cout << (char)32;
			}
		}
	}

	for (int i = 30; i < game_width; i++) {
		board[i][1] = board[i][7] = board[i][13] = board[i][19] = board[i][25] = board[i][31] = board[i][37] = '-';
		console.gotoXY(i, 1);
		cout << "-";
		console.gotoXY(i, 7);
		cout << "-";
		console.gotoXY(i, 13);
		cout << "-";
		console.gotoXY(i, 19);
		cout << "-";
		console.gotoXY(i, 25);
		cout << "-";
		console.gotoXY(i, 31);
		cout << "-";
		console.gotoXY(i, 37);
		cout << "-";
		if (i == 30 || i == game_width - 1) {
			for (int j = 1; j < 38; j++) {
				console.gotoXY(i, j);
				board[i][j] = '|';
				cout << "|";
			}
		}
	}
	console.setTextColor(Green);
	console.gotoXY(32, 3);
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
		<< "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
	console.gotoXY(32, 4);
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ";
	console.setTextColor(x);
	cout << "FINAL PROJECT";
	console.setTextColor(Green);
	cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
	console.gotoXY(32, 5);
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ";
	console.setTextColor(x);
	cout << "CS202 - GROUP 6 - 19APCS2";
	console.setTextColor(Green);
	cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
	mtx.unlock();
}

void Buffer2::drawObject(int x, int y, string type, int speed) {
	mtx.lock();
	if (type == "car") {
		console.setTextColor(Black);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < car[i].length(); j++) {
				if (x + j - speed < game_width && x + j - 5 >= 31) {
					console.gotoXY(x + j - speed, 27 + i);
					cout << (char)32;
				}
			}
		}
		console.setTextColor(Yellow);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < car[i].length(); j++) {
				if (x + j >= 30 && x + j < game_width) {
					console.gotoXY(x + j, 27 + i);
					cout << car[i][j];
				}
			}
		}
	}
	else if (type == "truck") {
		console.setTextColor(Black);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < truck[i].length(); j++) {
				if (x + j - speed < game_width && x + j - 5 >= 31) {
					console.gotoXY(x + j - speed, 21 + i);
					cout << (char)32;
				}
			}
		}
		console.setTextColor(Blue);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < truck[i].length(); j++) {
				if (x + j >= 30 && x + j < game_width) {
					console.gotoXY(x + j, 21 + i);
					cout << truck[i][j];
				}
			}
		}

	}
	else if (type == "bird") {
		console.setTextColor(Black);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < bird[i].length(); j++) {
				if (x + j - speed < game_width && x + j - 5 >= 31) {
					console.gotoXY(x + j - speed, 8 + i);
					cout << (char)32;
				}
			}
		}
		console.setTextColor(Pink);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < bird[i].length(); j++) {
				if (x + j >= 30 && x + j < game_width) {
					console.gotoXY(x + j, 8 + i);
					cout << bird[i][j];
				}
			}
		}

	}
	else if (type == "dinosaur") {
		console.setTextColor(Black);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < dino[i].length(); j++) {
				if (x + j - speed < game_width && x + j - 5 >= 31) {
					console.gotoXY(x + j - speed, 15 + i);
					cout << (char)32;
				}

			}
		}
		console.setTextColor(Red);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < dino[i].length(); j++) {
				if (x + j >= 30 && x + j < game_width) {
					console.gotoXY(x + j, 15 + i);
					cout << dino[i][j];
				}
			}
		}
	}
	mtx.unlock();
}

void Buffer2::drawPeople(int x, int y, int speedX, int speedY, string direction)
{
	mtx.lock();
	int newX = x, newY = y;
	if (direction == "down")
	{
		newY -= speedY;
	}
	else if (direction == "up")
	{
		newY += speedY;
	}
	else if (direction == "left")
	{
		newX += speedX;
	}
	else // right
	{
		newX -= speedX;
	}

	const char TITLE[][3] = { {32,153,32},
							{218, 219, 191 },
							{32,208,32} };
	int i, j;
	string human[3] = {
		" () ",
		"-||-",
		"//\\\\"

	};
	console.setTextColor(Black);

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < human[i].length(); ++j) {
			console.gotoXY(newX + j, newY + i);
			cout << (char)32;
		}
	}

	console.setTextColor(White);
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < human[i].length(); j++) {
			console.gotoXY(x + j, y + i);
			cout << human[i][j];
		}
	}
	mtx.unlock();
}

void Buffer2::drawTrafficLight(bool isLaneCarRed, bool isLaneTruckRed) {
	mtx.lock();
	ColorCode color1, color2;
	color1 = isLaneCarRed ? Red : Gray;
	color2 = isLaneCarRed ? Gray : Green;

	console.setTextColor(color1);
	console.gotoXY(157, 25);
	cout << char(254);

	console.setTextColor(color2);
	console.gotoXY(157, 26);
	cout << char(254);
	
	color1 = isLaneTruckRed ? Red : Gray;
	color2 = isLaneTruckRed ? Gray : Green;

	
	console.setTextColor(color1);
	console.gotoXY(157, 19);
	cout << char(254);

	console.setTextColor(color2);
	console.gotoXY(157, 20);
	cout << char(254);
	mtx.unlock();
}

void Buffer2:: displayConfirmSave() {
	int row = 15;
	int column = 60;
	mtx.lock();
	console.setTextColor(Pink);
	console.gotoXY(column, row++);
	cout << "----------------------------------------------------------\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "|           Do you want to save your progress?           |\n";
	console.gotoXY(column, row++);
	cout << "|    This action may overwrite the existing saved game   |\n";
	console.gotoXY(column, row++);
	cout << "|                 Press Y(yes) or N(no)                  |\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "----------------------------------------------------------\n";
	mtx.unlock();
}

void Buffer2::displayConfirmExit() {
	int row = 15;
	int column = 60;
	mtx.lock();
	console.setTextColor(Pink);
	console.gotoXY(column, row++);
	cout << "----------------------------------------------------------\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "|            Are you sure you want to exit?              |\n";
	console.gotoXY(column, row++);
	cout << "|      Your progress may not be properly saved yet       |\n";
	console.gotoXY(column, row++);
	cout << "|                 Press Y(yes) or N(no)                  |\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "----------------------------------------------------------\n";
	mtx.unlock();
}

void Buffer2::displayConfirmReset() {
	int row = 15;
	int column = 60;
	mtx.lock();
	console.setTextColor(Pink);
	console.gotoXY(column, row++);
	cout << "----------------------------------------------------------\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "|          Are you sure you want to reset game?          |\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "|                 Press Y(yes) or N(no)                  |\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "----------------------------------------------------------\n";
	mtx.unlock();
}
void Buffer2::announceComplete() {
	int row = 15;
	int column = 60;
	mtx.lock();
	console.setTextColor(Pink);
	console.gotoXY(column, row++);
	cout << "----------------------------------------------------------\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "|                 Save successfully!                     |\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "----------------------------------------------------------\n";
	mtx.unlock();
}


void Buffer2::printCongrat(bool isMaxLevel) {
	clearScreen();

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	const char congrat[][82] = { {32,32,32,'_','_','_','_',32,    32,32,32,32,32,32,32,32,        32,32,32,32,32,32,         32,32,32,32,32,32,32,        32,32,32,32,32,32,32,32,  32,32,32,32,32,32,32,32,  32,32,32,32,32,32,32,32,  },
							   { 32,32,32,'_','_','_','_',32,  32,32,32,32,32,32,32,32,        32,32,32,32,32,32,         32,32,32,32,32,32,32,         32,32,32,32,32,32,32,32,  32,32,32,32,32,32,32,32,  32,32,32,32,32,32,32,32,  },
							   { 32,32,'/',32,'_','_','_',178,   32,32,32,32,32,32,32,             32,32,32,32,32,32,32,32,        32,32,32,32,32,32,         32,32,32,32,32,32,32,         32,32,32,32,32,32,32,32,  32,32,'_','_',32,32,32,  },
							   {32,'/',32,32,178,32,32,32,      32,32,'_','_','_',32,32,      32,'_',32,'_','_',32,32,          32,32,'_','_',32,'_',32,32,     32,'_',32,'_','_',32,      32,32,'_','_',32,'_',32,      32,'_','|',' ',178,'_',},
							   {'|',32,32,32,178,32,32,32,      32,'/',32,'_',32,'\\',32,     '|',32,'\'','_',32,'\\',32,       32,'/',32,'_','\'',32,178,32,   '|',32,'\'','_','_',178,   32,'/',32,'_','\'',32,178,    '|','_',32,32,32,'_',178,},
							   {32,'\\',32,32,178,'_','_','_',  '(',32,'(','_',')',32,')',    '|',32,178,32,'|',32,'|',         '(',32,'(','_',')',32,178,32,   '|',32,178,32,32,32,       '(',32,'(','_',')',32,178,    32,32,'|',32,178,32,},
							   {32,32,'\\','_','_',',','_',178,  32,'\\','_','_','_','/',32,  '|','_',178,32,'|','_','|',       32,'\\','_','_',',',32,178,32,  '|','_',178,32,32,32,      32,'\\','_','_',',','_',178,  32,32,'\\','_','_',178,32,32,32,},
							   {32,32,32,32,32,32,32,            32,32,32,32,32,32,32,        32,32,32,32,32,32,32,32,          32,178,'_','_','_','/',         32,32,32,32,32,32,         32,32,32,32,32,32,32,         32,32,32,32,32,32,},};
	mtx.lock();
	int row = 5;
	int column = 55;
	int i, j;
	for (i = 0; i < 8; ++i) {
		console.gotoXY(column, row++);
		for (j = 0; j < 82; ++j) {
			SetConsoleTextAttribute(hConsole, i);
			cout << congrat[i][j];
		}
	}

	console.gotoXY(65, 19);
	console.setTextColor(White);
	if (!isMaxLevel) {
		cout << "Press C to continue or E to exit\n";
	}
	else {
		cout << "You pass the max level!!";
		console.gotoXY(65, 20);
		cout << "Press E to exit";
	}
	mtx.unlock();
}

void Buffer2::printGameover() {
		clearScreen();

		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		const char lose[][82] = { { 32,32,32,32,32,32,32,        32,32,32,32,32,32,32,         32,32,32,32,32,32,32,32,32,32,               32,32,32,32,32,32,                       32,32,32,32,32,32,  32,32,32,32,32,32,32,           32,32,32,32,32,32,32,                      32,32,32,32,32,32,             32,32,32,32,32,32,32,},
								  {32,32,32,32,32,32,               32,32,32,32,32,32,32,         32,32,32,32,32,32,32,32,32,32,               32,32,32,32,32,32,                       32,32,32,32,32,32,  32,32,32,32,32,32,32,           32,32,32,32,32,32,32,                      32,32,32,32,32,32,             32,32,32,32,32,32,32,},
							       {32,32,'_','_',32,'_',32,     32,32,'_','_',32,'_',32,      32,'_',32,'_','_',32,32,'_','_',32,32,       32,32,'_','_','_',32,32,                 32,32,32,32,32,32,  32,32,'_','_','_',32,32,        '_','_',32,32,32,32,'_','_',         32,32,'_','_','_',32,32,             32,'_',32,'_','_',32,},
									   { 32,'/',32,'_','\'',32,'|',  32,'/',32,'_','\'',32,'|',    '|',32,'\'','_',32,'\\',32,'_',32,'\\',      32,32,'/',32,'_',32,32,'\\',             32,32,32,32,32,32,  32,'/',32,'_',32,'\\',32,       '\\',32,'\\',32,32,'/',32,'/',       32,'/',32,'_',32,32,'\\',            '|',32,'\'','_','_','|',},
									   {'(',32,'(','_',')',32,'|',   '(',32,'(','_',')',32,'|',    '|',32,'|',32,'|',32,'|',32,'|',32,'|',      '|',32,'|','_',')',32,'/',               32,32,32,32,32,32,   '(',32,'(','_',')',32,')',     32,'\\',32,'\\','/',32,'/',         32,'|',32,'|','_',')',32,'/',         '|',32,'|',32,32,32,},
									   {32,'\\','_','_',',',32,'|',  32,'\\','_','_',',','_','|',  '|','_','|',32,'|','_','|',32,'|','_','|',   32,'\\','_','_','_','_',')',             32,32,32,32,32,32,  32,'\\','_','_','_','/',32,     32,32,'\\','_','_','/',32,            32,32,'\\','_','_','_','_',')',     '|','_','|',32,32,32,},
									   {32,'|','_','_','_','/',         32,32,32,32,32,32,32,          32,32,32,32,32,32,32,32,32,32,              32,32,32,32,32,32,32,32,                 32,32,32,32,32,32,   32,32,32,32,32,32,32,          32,32,32,32,32,32,32,                       32,32,32,32,32,32,32,32,      32,32,32,32,32,32,},
		};
		mtx.lock();
		int row = 5;
		int column = 55;
		int i, j;
		for (i = 0; i < 7; ++i) {
			console.gotoXY(column, row++);
			for (j = 0; j < 82; ++j) {
				SetConsoleTextAttribute(hConsole, i);
				cout << lose[i][j];
			}
		}

		console.gotoXY(65, 20);
		console.setTextColor(White);
		cout << "Press C to play again or E to exit\n";
		mtx.unlock();
}

void Buffer2::showLevel(int level)
{
	console.setTextColor(White);
	console.gotoXY(10, 2);
	cout << level;
}

void Buffer2::deleteAnnounceFrame() {
	int row = 15;
	int column = 60;
	mtx.lock();
	console.setTextColor(BlackAll);
	console.gotoXY(column, row++);
	cout << "----------------------------------------------------------\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	console.setTextColor(Cyan);
	cout << "----------------------------------------------------------\n";
	console.setTextColor(BlackAll);
	console.gotoXY(column, row++);
	cout << "|                                                        |\n";
	console.gotoXY(column, row++);
	cout << "----------------------------------------------------------\n";
	mtx.unlock();

}

void Buffer2::clearScreen() {
	console.clearScreen();
}