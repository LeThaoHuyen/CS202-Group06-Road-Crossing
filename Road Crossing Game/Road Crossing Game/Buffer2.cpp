#include "Buffer2.h"

Buffer2::Buffer2(int gw, int gh, int fw, int fh) :console(gw, gh), frame_width(fw), frame_height(fh)
{
	console.fixConsoleWindow();

	game_width = console.width(); // 95

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


	for (int i = 30; i < 95; i++) {
		board[i][1] = board[i][8] = board[i][15] = board[i][22] = board[i][29] = board[i][36] = board[i][43] = '-';
		if (i == 30 || i == 94) {
			for (int j = 1; j < 44; j++) {
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

	for (int i = 30; i < 95; i++) {
		console.gotoXY(i, 1);
		cout << "-";
		console.gotoXY(i, 37);
		cout << "-";
		if (i == 30 || i == 94) {
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
	for (int i = 31; i < 94; i++) {
		for (int j = 1; j <= 43; j++) {
			if (j != 1 && j != 8 && j != 15 && j != 22 && j != 29 && j != 36 && j != 43) {
				console.gotoXY(i, j);
				cout << (char)32;
			}
		}
	}
}
void Buffer2::drawFrame() {
	for (int i = 30; i < 95; i++) {
		for (int j = 1; j <= 43; j++) {
			if (board[i][j] != '|' || board[i][j] != '-') {
				console.gotoXY(i, j);
				cout << (char)32;
			}
		}
	}

	for (int i = 30; i < 95; i++) {
		board[i][1] = board[i][8] = board[i][15] = board[i][22] = board[i][29] = board[i][36] = board[i][43] = '-';
		console.gotoXY(i, 1);
		cout << "-";
		console.gotoXY(i, 8);
		cout << "-";
		console.gotoXY(i, 15);
		cout << "-";
		console.gotoXY(i, 22);
		cout << "-";
		console.gotoXY(i, 29);
		cout << "-";
		console.gotoXY(i, 36);
		cout << "-";
		console.gotoXY(i, 43);
		cout << "-";
		if (i == 30 || i == 94) {
			for (int j = 1; j < 43; j++) {
				console.gotoXY(i, j);
				board[i][j] = '|';
				cout << "|";
			}
		}
	}

}

void Buffer2::drawObject(int x, int y, string type) {
	if (type == "car") {
		console.setTextColor(Yellow);
		console.gotoXY(x, 32);
		cout << car[0];
		console.gotoXY(x, 33);
		cout << car[1];
		console.gotoXY(x, 34);
		cout << car[2];
		console.gotoXY(x, 35);
		cout << car[3];
	}
	else if (type == "truck") {
		console.setTextColor(Green);
		console.gotoXY(x, 25);
		cout << truck[0];
		console.gotoXY(x, 26);
		cout << truck[1];
		console.gotoXY(x, 27);
		cout << truck[2];
		console.gotoXY(x, 28);
		cout << truck[3];
	}
	else if (type == "bird") {
		console.setTextColor(Blue);
		if (x < 95 && x + bird[0].length() < 95) {
			console.gotoXY(x, 10);
			cout << bird[0];
		}
		else {
			console.gotoXY(31, 10);
			cout << bird[0];
		}

		if (x < 95 && x + bird[1].length() < 95) {
			console.gotoXY(x, 11);
			cout << bird[1];
		}
		else {
			console.gotoXY(31, 11);
			cout << bird[1];
		}
		if (x < 95 && x + bird[0].length() < 95) {
			console.gotoXY(x, 12);
			cout << bird[2];
		}
		else {
			console.gotoXY(31, 12);
			cout << bird[2];
		}

	}
	else if (type == "dinosaur") {
		console.setTextColor(Red);
		console.gotoXY(x, 16);
		cout << dino[0];
		console.gotoXY(x, 17);
		cout << dino[1];
		console.gotoXY(x, 18);
		cout << dino[2];
		console.gotoXY(x, 19);
		cout << dino[3];
		console.gotoXY(x, 20);
		cout << dino[4];
		console.gotoXY(x, 21);
		cout << dino[5];
	}
}