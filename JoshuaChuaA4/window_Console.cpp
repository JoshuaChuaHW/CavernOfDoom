#include "window_Console.h"
#include <iostream>

char map[23][54] = {
	"#####################################################",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#                                                   #",
	"#####################################################"

};

window_Console::window_Console() {

	x = 1;
	y = 1;
};





window_Console::~window_Console() {

};

int window_Console::returnX() {
	return x;
}
int window_Console::returnY() {
	return y;
}
void window_Console::setX(int input) {
	x = input;
}
void window_Console::setY(int input) {
	y = input;
}
void window_Console::Move(int Vertical, int Horizontal) {
	char east = 'E';
	char north = 'N';
	char west = 'W';
	char south = 'S';
	int new_X_Coords = x + Horizontal;
	int new_Y_Coords = y + Vertical;

	if (map[y][new_X_Coords] == ' ') {
		map[y][x] = ' ';
		x += Horizontal;
		map[y][x] = player_Symbol;
	};
	if (map[new_Y_Coords][x] == ' ') {
		map[y][x] = ' ';
		y += Vertical;
		map[y][x] = player_Symbol;
	}
	else if (map[new_Y_Coords][x] == 'X' || map[y][new_X_Coords] == 'X') {
		monster_Encounter = true;
	}
	else if (map[new_Y_Coords][x] == 'I' || map[y][new_X_Coords] == 'I') {
		item_Encounter = true;
	}
	else if (map[new_Y_Coords][x] == east || map[y][new_X_Coords] == east) {
		exitingExit = 'E';
		exiting = true;
	}
	else if (map[new_Y_Coords][x] == west || map[y][new_X_Coords] == west) {
		exitingExit = 'W';
		exiting = true;
	}
	else if (map[new_Y_Coords][x] == south || map[y][new_X_Coords] == south) {
		exitingExit = 'S';
		exiting = true;
	}
	else if (map[new_Y_Coords][x] == north || map[y][new_X_Coords] == north) {
		exitingExit = 'N';
		exiting = true;
	}


};

void window_Console::updateMap(std::vector<std::string> input) {
	for (int i = 0; i < 23; i++) {
		std::string currentLine = input[i];
		for (int x = 0; x < 53; x++) {
			char currentChar = currentLine[x];
			map[i][x] = currentChar;
		}
	}
	map[x][y] = char(1);
};
bool window_Console::checkForEvent() {
	return monster_Encounter;
}
bool window_Console::checkForItemFound() {
	return item_Encounter;
}
void window_Console::setMonster_Encountr(bool input) {
	monster_Encounter = input;
};
bool window_Console::checkForChangingMap() {
	return exiting;
};
void window_Console::set_exiting(bool input) {
	exiting = input;
}
void window_Console::setItem_Encounter(bool inpt) {
	item_Encounter = inpt;
}
char window_Console::ReturnExiting_Exit() {
	return exitingExit;
}
void window_Console::set_exitingExit(char input) {
	exitingExit = input;
}