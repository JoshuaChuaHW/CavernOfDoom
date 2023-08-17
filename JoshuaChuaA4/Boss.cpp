#include "Boss.h"

//Constructor




Boss::Boss() {

	name = "Dragon";
	level = 5;
	health = level * (generateRandomNumber(6, 8));
	std::cout << "health" << std::endl;
	attack = level + (generateRandomNumber(6, 10));
	defence = level + (generateRandomNumber(6, 12));
	damage = level + (generateRandomNumber(4, 6));

	isCarryingItem = true;
	ItemMonsterIsCarrying = Balthazar();							//istantiate a item (only one item possible)
	location = NULL;
	typeOfMonster = MonsterType::DRAGON;


	std::ifstream fileToRead("Art/Monster_Art/Dragon.txt");
	if (fileToRead.is_open()) {
		std::string line = "";
		while (!fileToRead.eof()) {
			getline(fileToRead, line);
			monster_Art.push_back(line);
		}
	}

}
Boss::Boss(int Location) {

	name = "Dragon";
	level = 5;
	health = level * (generateRandomNumber(6, 8));
	attack = level + (generateRandomNumber(6, 10));
	defence = level + (generateRandomNumber(6, 12));
	damage = level + (generateRandomNumber(4, 6));
	isCarryingItem = true;
	ItemMonsterIsCarrying = Balthazar();							//istantiate a item (only one item possible)
	location = Location;
	specialAttackUsed = false;
	specialDamage = level * (generateRandomNumber(2, 3));

	std::ifstream fileToRead("Art/Monster_Art/Dragon.txt");
	if (fileToRead.is_open()) {
		std::string line = "";
		while (!fileToRead.eof()) {
			getline(fileToRead, line);
			monster_Art.push_back(line);
		}
	}
}



//Destructor

bool Boss::GetIfSpecialAttackused() {
	return specialAttackUsed;
}

Boss::~Boss() {

}


int Boss::SpecialAttack() {
	std::cout << " The Dragon Charges Up His Breath And Unleash Fire Everywhere\n";
	return specialDamage;
}



