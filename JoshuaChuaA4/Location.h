#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
#include "Item.h"
#include "Monster.h"
#include <fstream>
#include "Boss.h"
#include "Armour.h"
#include "Gold.h"
#include "Lantern.h"
#include "Map.h"
#include "Potion.h"
#include "Provisions.h"
#include "Sword.h"
#include "BattleAxe.h"
#include "Balthazar.h"
#include "Chainmail.h"
#include "SpeedBoots.h"
#include "Elixir.h"

class Location
{
private:
	int roomNumber;
	std::string name;
	std::string description;
	std::vector<char> visibleExits = { 'A','A','A' };
	std::vector<int> connectingExits = { 0,0,0 };
	int monsterInRoom = 0;
	int itemInRoom = 0;
	bool isThereMonster = false;
	bool isThereItem = false;
	Monster MonsterInRoom;
	Item ItemInRoom;
	std::vector<std::string> charMap;
	int coordinateX;
	int coordinateY;


public:

	//Constructors
	Location(int RoomNumber);
	//Location(int RoomNumber, std::string Name, std::string Description, std::vector<char> VisibleExits, std::vector<int> ConnectingExits, int MonsterInRoom, int ItemInRoom, bool IsThereMonster, bool IsThereItem);

	//default constructor
	Location();

	//deconstructor

	~Location();

	//random number
	int generateRandomNumber(int min, int max);





	//mutators
	//get

	int GetRoomNumber();

	std::string GetRoomName();

	std::string GetDescription();

	std::vector<char> GetVisibleExits();

	bool GetIsThereMonster();

	bool GetIsThereItem();

	Monster* GetMonsterInRoom();

	Item* GetItemInRoom();

	void AssignRandomItem();

	std::vector<std::string> Return_charMap();

	std::vector<int> listOfConnectingExits();

	int getX();

	int getY();



	//set

	void SetRoomNumber(int input);

	void SetRoomName(std::string input);

	void SetDescription(std::string input);

	void SetVisibleExits(std::vector<char> input);

	void SetIsThereMonster(bool input);

	void SetIsThereItem(bool input);

	void SetMonsterInRoom(Monster input);

	void SetItemInRoom(Item input);

	void removeMonsterInRoom();

	void removeItemInRoom();

	void UpdateMap();











	//cout object properties
	void getDetails();

};

#endif // !LOCATION_H
