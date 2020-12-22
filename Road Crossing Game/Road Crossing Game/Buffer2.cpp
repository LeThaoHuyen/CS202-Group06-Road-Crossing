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


	for (int i = 0; i < 25; i++) {
		if (i == 0 || i == 24) {
			console.gotoXY(i + 1, 4);
			cout << "|";
			console.gotoXY(i + 1, 2);
			cout << "|";
		}
		console.gotoXY(i + 1, 1);
		cout << "-";
		console.gotoXY(i + 1, 3);
		cout << "-";
		console.gotoXY(i + 1, 5);
		cout << "-";
	}

	console.gotoXY(3, 2);
	cout << "User: ";
	console.gotoXY(3, 4);
	cout << "Level: ";


	for (int i = 0; i < 25; i++) {
		if (i == 0 || i == 24) {
			for (int j = 11; j <= 17; j += 2) {
				console.gotoXY(i + 1, j);
				cout << "|";
			}

		}
		for (int j = 10; j <= 18; j += 2) {
			console.gotoXY(i + 1, j);
			cout << "-";
		}

	}
	console.gotoXY(3, 11);
	cout << "Press S to save";
	console.gotoXY(3, 13);
	cout << "Press P to pause";
	console.gotoXY(3, 15);
	cout << "Press E to exit";
	console.gotoXY(3, 17);
	cout << "Press U to continue";

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
	console.gotoXY(60, 10);
	cout << "CROSSING ROAD";
	console.gotoXY(50, 13);
	cout << "------------------------";
	console.gotoXY(50, 14);
	cout << "*      New game        *";
	console.gotoXY(50, 15);
	cout << "------------------------";
	console.gotoXY(50, 16);
	cout << "------------------------";
	console.gotoXY(50, 17);
	cout << "*      Load game       *";
	console.gotoXY(50, 18);
	cout << "------------------------";
	console.gotoXY(50, 19);
	cout << "------------------------";
	console.gotoXY(50, 20);
	cout << "*      Exit game       *";
	console.gotoXY(50, 21);
	cout << "------------------------";
	console.gotoXY(70, 70);

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
	console.hideCursor();
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

}

void Buffer2::drawObject(int x, int y, string type, int speed) {
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
		console.setTextColor(Green);
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
		console.setTextColor(Blue);
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
}

