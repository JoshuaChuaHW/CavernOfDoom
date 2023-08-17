#ifndef CONSOLE_H
#define CONSOLE_H
#include <vector>
#include <string>


class window_Console
{
public:
	const char player_Symbol = 1;
	window_Console();
	~window_Console();
	void Move(int Vertical, int Horizontal);
	void updateMap(std::vector<std::string> input);
	bool checkForEvent();
	bool checkForChangingMap();
	bool checkForItemFound();
	void setMonster_Encountr(bool input);
	bool exiting = false;
	char exitingExit;
	char ReturnExiting_Exit();
	void set_exiting(bool input);
	void set_exitingExit(char input);
	void setItem_Encounter(bool inpt);

	void setX(int input);
	void setY(int input);
	int returnX();
	int returnY();
private:

	int x = 1;
	int y = 1;
	bool monster_Encounter = false;
	bool item_Encounter = false;

};

extern char map[23][54];



#endif // !CONSOLE_H
