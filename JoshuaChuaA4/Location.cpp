#include "Location.h"
#include "Location.h"
#include <cstring>

//function for truly random numbers

int Location::generateRandomNumber(int min, int max) {
	std::random_device val;
	std::mt19937 gen(val());
	std::uniform_int_distribution<> distr(min, max);
	return distr(gen);
}

void Location::AssignRandomItem() {

	int idOfItem = generateRandomNumber(2, 7);

	switch (idOfItem)
	{
	case 2:
		ItemInRoom = Gold();
		break;
	case 3:
		ItemInRoom = Lantern();
		break;
	case 4:
		ItemInRoom = Provisions();
		break;
	case 5:
		ItemInRoom = Potion();
		break;
	case 6:
		ItemInRoom = Sword();
		break;
	case 7:
		ItemInRoom = Armour();
		break;
	default:
		break;
	}
}


//Constructors
//Default Constructor
Location::Location() {

};

//Destructor

Location::~Location() {

}


//for constructing when loading map based on the input given(parameter)
Location::Location(int roomInt) {
	std::vector<char> SNE = { 'S','N','E' };
	std::vector<char> SWE = { 'S','W','E' };
	std::vector<char> SWN = { 'S','W','N' };
	std::vector<char> WNE = { 'W','N','E' };
	coordinateX = 0;
	coordinateY = 0;

	roomNumber = roomInt;													//assign input to variable roomNumber

	//switch case based on the room being instantiating
	switch (roomNumber)
	{
	case 0:
		name = "Entrance";
		description = "A slight breeze greets you as you enter the brightly illuminated cave.";
		visibleExits = WNE;
		connectingExits = { 13,9,1 };
		coordinateX = 50;
		coordinateY = 33;
		break;
	case 1:
		name = "Doomed Corner";
		connectingExits = { 0,2,3 };
		description = "Seems to be a connecter of some sort.";
		visibleExits = SWN;
		coordinateX = 120;
		coordinateY = 31;
		break;
	case 2:
		name = "Abandoned Camp";
		connectingExits = { 10,4,1 };
		description = "Remnants of what seem to be a abandoned camp.";
		visibleExits = WNE;
		coordinateX = 102;
		coordinateY = 31;
		break;
	case 3:
		name = "Hallowed Corridor";
		connectingExits = { 1,6,7 };
		description = "A long corridor that never seems to end.";
		visibleExits = SNE;
		coordinateX = 107;
		coordinateY = 20;
		break;
	case 4:
		name = "Tunnel Connector";
		connectingExits = { 2,10,5 };
		description = "A chilly area with dark colored drapes blowing from the outside wind.";
		visibleExits = SWN;
		coordinateX = 85;
		coordinateY = 24;
		break;
	case 5:
		name = "Castle's Peak";
		connectingExits = { 4,8,6 };
		description = "You reach the top of the castle, and get a good bird eye view of everything.";
		visibleExits = SWN;
		coordinateX = 91;
		coordinateY = 16;
		break;
	case 6:
		name = "Dark Room";
		connectingExits = { 3,5,7 };
		description = "An extremely dark and pitch black room, you have to wander aronund with no vision.";
		visibleExits = SWN;
		coordinateX = 14;
		coordinateY = 5;
		break;
	case 7:
		name = "Building Outskirts";
		connectingExits = { 6,8,3 };
		description = "You reach the top of the castle, and get a good bird eye view of everything.";
		visibleExits = SWE;
		coordinateX = 80;
		coordinateY = 6;
		break;
	case 8:
		name = "Stairway Tunnel";
		connectingExits = { 19,7,5 };
		description = "A stairway down into the depths of the tunnel. You can barely see anything except for the next step step.";
		visibleExits = WNE;
		coordinateX = 62;
		coordinateY = 13;
		break;
	case 9:
		name = "Rotten Room";
		connectingExits = { 10,0,11 };
		description = "You enter a room that absolutely stinks. Then, you realise it's just you.";
		visibleExits = SWN;
		coordinateX = 60;
		coordinateY = 26;
		break;
	case 10:
		name = "Chilly Courtyard";
		connectingExits = { 6,8,3 };
		description = "You reach the top of the castle, and get a good bird eye view of everything";
		visibleExits = WNE;
		coordinateX = 72;
		coordinateY = 31;
		break;
	case 11:
		name = "Watch Tower";
		connectingExits = { 12,17,9 };
		description = "There is a bunch of tools in a watch tower you see. They may be broken though";
		visibleExits = SNE;
		coordinateX = 54;
		coordinateY = 20;
		break;
	case 12:
		name = "Giant Gates";
		connectingExits = { 13,15,11 };
		description = "Two HUGE gates stand between you and whatever it's guarding";
		visibleExits = SWN;
		coordinateX = 32;
		coordinateY = 35;
		break;
	case 13:
		name = "Rotten Kitchen";
		connectingExits = { 0,14,12 };
		description = "It's a kitchen but everything's rotting";
		visibleExits = SNE;
		coordinateX = 25;
		coordinateY = 33;
		break;
	case 14:
		name = "Walkway of dead bodies";
		connectingExits = { 13,18,15 };
		description = "Two HUGE gates stand between you and whatever it's guarding";
		visibleExits = SWN;
		coordinateX = 14;
		coordinateY = 25;
		break;
	case 15:
		name = "Statue of Liberation";
		connectingExits = { 14,16,12 };
		description = "There's a statue in the middle of room seems to be pointing to the sky";
		visibleExits = SNE;
		coordinateX = 14;
		coordinateY = 17;
		break;
	case 16:
		name = "Armoury Room";
		connectingExits = { 15,18,17 };
		description = "A room filled with armor and weapons. Most seem broken, however";
		visibleExits = SNE;
		coordinateX = 14;
		coordinateY = 11;
		break;
	case 17:
		name = "Dragon Lair's";
		connectingExits = { 16,19,11 };
		description = "A room that seems to be the a dragon's resting nest. Better be careful.";
		visibleExits = SNE;
		coordinateX = 38;
		coordinateY = 13;
		break;
	case 18:
		name = "Dark Tunnel";
		connectingExits = { 16,14,19 };
		description = "Seems like another dark tunnel. You see a small glimmer of light infront of you";
		visibleExits = SWN;
		coordinateX = 14;
		coordinateY = 5;
		break;
	case 19:
		name = "Treasure Room";
		connectingExits = { 17,18,8 };
		description = "Room filled with riches and gold! Most seems to have been burned by the dragon though.";
		visibleExits = SWE;
		coordinateX = 38;
		coordinateY = 4;
		break;

	}
	if (roomNumber == 17) {
		MonsterInRoom = Boss(17);
		isThereMonster = true;
	}
	else if (roomNumber != 0) {
		//Entrance will have no item or monster
		int randomMonsterID = generateRandomNumber(0, 4);							//random monster ID that will be created along with the room
		int chance = generateRandomNumber(1, 2);									//50% chance for item to appear 
		int validIDs = generateRandomNumber(2, 7);
		if (randomMonsterID == 0) {													//if NO monster
			isThereMonster = false;													//assign bool variable of checking if theres monster to FALSE
			//Which items can be created. Artifacts(1) not allowed to be found in empty room
			if (chance == 2) {

				AssignRandomItem();												//Else generate item if you got the 50% chance
				isThereItem = true;										     		//Bool variable checking for item to be TRUE
			}
			else {

				isThereItem = false;									     		//if theres no item, bool variable set to FALSE
			}
		}

		else {
			MonsterInRoom = Monster(randomMonsterID, roomNumber);				//Instantiating Monster objects within rooms
			isThereMonster = true;												//bool variable checking for monster set to be TRUE
		}
	}
	else {
		isThereMonster = false;
		isThereItem = false;
	}
};





void Location::UpdateMap() {
	std::vector<char> SNE = { 'S','N','E' };
	std::vector<char> SWE = { 'S','W','E' };
	std::vector<char> SWN = { 'S','W','N' };
	std::vector<char> WNE = { 'W','N','E' };
	charMap.clear();
	if (visibleExits == SNE) {

		if (isThereMonster == false) {

			if (isThereItem == false) {

				std::ifstream fileToRead("Art/Map_Art/Map_SNE_EMPTY.txt");
				if (fileToRead.is_open()) {
					std::string line = "";
					while (!fileToRead.eof()) {
						getline(fileToRead, line);
						charMap.push_back(line);
					}
				}
			}
			else {
				std::ifstream fileToRead("Art/Map_Art/Map_SNE_EMPTY_ITEM.txt");
				if (fileToRead.is_open()) {
					std::string line = "";
					while (!fileToRead.eof()) {
						getline(fileToRead, line);
						charMap.push_back(line);
					}
				}

			};
		}
		else {
			std::ifstream fileToRead("Art/Map_Art/Map_SNE.txt");
			if (fileToRead.is_open()) {
				std::string line = "";
				while (!fileToRead.eof()) {
					getline(fileToRead, line);
					charMap.push_back(line);
				}
			}
		}

	}
	else if (visibleExits == SWE) {

		if (isThereMonster == false) {

			if (isThereItem == false) {

				std::ifstream fileToRead("Art/Map_Art/Map_SWE_EMPTY.txt");
				if (fileToRead.is_open()) {
					std::string line = "";
					while (!fileToRead.eof()) {
						getline(fileToRead, line);
						charMap.push_back(line);
					}
				}
			}
			else {
				std::ifstream fileToRead("Art/Map_Art/Map_SWE_EMPTY_ITEM.txt");
				if (fileToRead.is_open()) {
					std::string line = "";
					while (!fileToRead.eof()) {
						getline(fileToRead, line);
						charMap.push_back(line);
					}
				}
			}
		}
		else {
			std::ifstream fileToRead("Art/Map_Art/Map_SWE.txt");
			if (fileToRead.is_open()) {
				std::string line = "";
				while (!fileToRead.eof()) {
					getline(fileToRead, line);
					charMap.push_back(line);
				}
			}
		}
	}
	else if (visibleExits == SWN) {

		if (isThereMonster == false) {

			if (isThereItem == false) {

				std::ifstream fileToRead("Art/Map_Art/Map_SWN_EMPTY.txt");
				if (fileToRead.is_open()) {
					std::string line = "";
					while (!fileToRead.eof()) {
						getline(fileToRead, line);
						charMap.push_back(line);
					}
				}
			}
			else {
				std::ifstream fileToRead("Art/Map_Art/Map_SWN_EMPTY_ITEM.txt");
				if (fileToRead.is_open()) {
					std::string line = "";
					while (!fileToRead.eof()) {
						getline(fileToRead, line);
						charMap.push_back(line);
					}
				}
			}

		}
		else {
			std::ifstream fileToRead("Art/Map_Art/Map_SWN.txt");
			if (fileToRead.is_open()) {
				std::string line = "";
				while (!fileToRead.eof()) {
					getline(fileToRead, line);
					charMap.push_back(line);
				}
			}
		}


	}
	else if (visibleExits == WNE) {

		if (isThereMonster == false) {

			if (isThereItem == false) {

				std::ifstream fileToRead("Art/Map_Art/Map_WNE_EMPTY.txt");
				if (fileToRead.is_open()) {
					std::string line = "";
					while (!fileToRead.eof()) {
						getline(fileToRead, line);
						charMap.push_back(line);
					}
				}
			}
			else {
				std::ifstream fileToRead("Art/Map_Art/Map_WNE_EMPTY_ITEM.txt");
				if (fileToRead.is_open()) {
					std::string line = "";
					while (!fileToRead.eof()) {
						getline(fileToRead, line);
						charMap.push_back(line);
					}
				}

			}
		}
		else {
			std::ifstream fileToRead("Art/Map_Art/Map_WNE.txt");
			if (fileToRead.is_open()) {
				std::string line = "";
				while (!fileToRead.eof()) {
					getline(fileToRead, line);
					charMap.push_back(line);
				}
			}
		}
	}
}


//a way to create a room with all access to the properties of the class
// 
//mutators

			///////////////GET///////////////

int Location::GetRoomNumber()									//return room no
{
	return roomNumber;
};
std::string Location::GetRoomName()								//return room name
{
	return name;
};
std::string Location::GetDescription()							//return room description
{
	return description;
};
std::vector<char> Location::GetVisibleExits()					//return visible exits
{
	return visibleExits;
};
std::vector<int> Location::listOfConnectingExits() {
	return connectingExits;
}
bool Location::GetIsThereMonster()								//return bool var of whether there is a monster in room
{
	return isThereMonster;
};
bool Location::GetIsThereItem()									//return bool var of whether there is a item in room
{
	return isThereItem;
};
Monster* Location::GetMonsterInRoom()							//return monster object in room
{
	return &MonsterInRoom;
};
Item* Location::GetItemInRoom()									//return item object in room
{
	return &ItemInRoom;
};
std::vector<std::string> Location::Return_charMap() {
	return charMap;
};

int Location::getX() {
	return coordinateX;
};
int Location::getY() {
	return coordinateY;
};



///////////////////////SET/////////////////////

//Room Stats
void Location::SetRoomNumber(int input)							//change a room number
{
	roomNumber = input;
};
void Location::SetRoomName(std::string input)					//access and change room name according to parameter
{
	name = input;
};
void Location::SetDescription(std::string input)				//set the description
{
	description = input;
};
void Location::SetVisibleExits(std::vector<char> input)			//input a possible exits to the room
{
	visibleExits = input;
};
void Location::SetIsThereMonster(bool bool_input)					//Change the bool val if there is a monster
{
	isThereMonster = bool_input;
};
void Location::SetIsThereItem(bool input)						//Change the bool value if there is an item
{
	isThereItem = input;
};



//Removal./Edit of Objects Tied to location
void Location::SetMonsterInRoom(Monster input)					//You can change the monster that was created in constructor of location class
{
	MonsterInRoom = input;
};
void Location::SetItemInRoom(Item input)						//change the item that is in the room when it was created in the constructor of location class
{
	ItemInRoom = input;
};
void Location::removeMonsterInRoom() {
	MonsterInRoom.~Monster();
	isThereMonster = false;

}
void Location::removeItemInRoom() {
	ItemInRoom.~Item();
	isThereItem = false;

}




//cout object properties


//void Location::getDetails() {
//		std::cout << "Room name is " << name << std::endl;
//
//		std::cout << "description: " << description << std::endl;
//
//		std::cout << "visible exits: [" << visibleExits[0] << "] [" << visibleExits[1] << "] [" << visibleExits[2] << "]" << std::endl;
//
//		std::cout << "connecting Rooms: " << connectingExits[0] << " " << connectingExits[1] << " " << connectingExits[2] << " " << std::endl;
//
//		std::cout << std::boolalpha;
//
//		std::cout << "Is there monster?: " << isThereMonster << std::endl;
//		
//		if (isThereMonster == true) {
//
//			std::cout << "The monster is: " << MonsterInRoom.GetMonsterName() << std::endl;
//		}
//		else {
//
//			std::cout << "Is there item?: " << isThereItem << std::endl;
//			if (isThereItem == true) {
//
//				std::cout << "The item is: " << ItemInRoom.GetItemName() << std::endl;
//			}
//
//
//		}
//		
//
//
//
//}


