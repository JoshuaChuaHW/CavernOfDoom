#include "Monster.h"


//Random Number Method

int Monster::generateRandomNumber(int min, int max) {
	std::random_device val;
	std::mt19937 gen(val());
	std::uniform_int_distribution<> distr(min, max);
	return distr(gen);
}

//Update Monster stats based on parameters(Items stats)

void Monster::UpdateStats(int Health, int Damage, int Defence) {
	health += Health;
	damage += Damage;
	defence += Defence;
}

void Monster::AssignRandomItem() {
	int idOfItem = generateRandomNumber(2, 7);

	switch (idOfItem)
	{
	case 2:
		ItemMonsterIsCarrying = Gold();
		break;
	case 3:
		ItemMonsterIsCarrying = Lantern();
		break;
	case 4:
		ItemMonsterIsCarrying = Provisions();
		break;
	case 5:
		ItemMonsterIsCarrying = Potion();
		break;
	case 6:
		ItemMonsterIsCarrying = Sword();
		break;
	case 7:
		ItemMonsterIsCarrying = Armour();
		break;
	default:
		break;
	}
}


//////////////////////Constructors//////////////////////


//Default Constructor

Monster::Monster() {

	name = "NULL";
	level = 0;
	attack = 0;
	defence = 0;
	damage = 0;
	itemEquipped = 0;
	location = 0;
	isCarryingItem = false;



}

//Overloaded Constructor for when instantiating rooms

Monster::Monster(int monsterID, int Location) {

	MonsterType typeOfMonster = MonsterType(monsterID);
	name = "No Monster";
	level = 0;
	attack = 0;
	defence = 0;
	damage = 0;
	health = 0;
	itemEquipped = 0;
	isCarryingItem = false;
	location = Location;


	if (typeOfMonster == MonsterType::GOBLIN) {
		std::ifstream fileToRead("Art/Monster_Art/Goblin.txt");
		if (fileToRead.is_open()) {
			std::string line = "";
			while (!fileToRead.eof()) {
				getline(fileToRead, line);
				monster_Art.push_back(line);
			}
		}

	}

	else if (typeOfMonster == MonsterType::HOBOGOBLIN) {
		std::ifstream fileToRead("Art/Monster_Art/Hobogoblin.txt");
		if (fileToRead.is_open()) {
			std::string line = "";
			while (!fileToRead.eof()) {
				getline(fileToRead, line);
				monster_Art.push_back(line);
			}
		}

	}

	else if (typeOfMonster == MonsterType::TROLL) {
		std::ifstream fileToRead("Art/Monster_Art/Troll.txt");
		if (fileToRead.is_open()) {
			std::string line = "";
			while (!fileToRead.eof()) {
				getline(fileToRead, line);
				monster_Art.push_back(line);
			}
		}

	}

	else if (typeOfMonster == MonsterType::OGRE) {
		std::ifstream fileToRead("Art/Monster_Art/Ogre.txt");
		if (fileToRead.is_open()) {
			std::string line = "";
			while (!fileToRead.eof()) {
				getline(fileToRead, line);
				monster_Art.push_back(line);
			}
		}

	}

	else if (typeOfMonster == MonsterType::DRAGON) {
		std::ifstream fileToRead("Art/Monster_Art/Dragon.txt");
		if (fileToRead.is_open()) {
			std::string line = "";
			while (!fileToRead.eof()) {
				getline(fileToRead, line);
				monster_Art.push_back(line);
			}
		}

	}

	//depending on the monster type, initialize the variables accordingly
	switch (typeOfMonster)
	{
		int temp;
	case MonsterType::GOBLIN:
		name = "GOBLIN";
		level = 1;
		health = level * (generateRandomNumber(2, 3));
		attack = level * (generateRandomNumber(1, 3));
		defence = level * (generateRandomNumber(1, 2));
		damage = level;
		typeOfMonster = MonsterType::GOBLIN;

		temp = generateRandomNumber(1, 100);
		if (temp > 60) {												//40% chance
			itemEquipped = (generateRandomNumber(2, 7));				//instantiate a random item between 2 and 7 (Items that are carry-able by this class of monsters
			AssignRandomItem();
			isCarryingItem = true;

		}
		else {
			isCarryingItem = false;
		};



		break;


	case MonsterType::HOBOGOBLIN:

		name = "HOBOGOBLIN";
		level = 2;
		health = level * (generateRandomNumber(3, 5));
		attack = level * (generateRandomNumber(2, 4));
		defence = level * (generateRandomNumber(1, 3));
		damage = level;
		typeOfMonster = MonsterType::HOBOGOBLIN;



		temp = generateRandomNumber(1, 100);
		if (temp > 50) {											//50% chance
			itemEquipped = (generateRandomNumber(2, 7));			//instantiate a random item between 2 and 7 (Items that are carry-able by this class of monsters
			AssignRandomItem();
			isCarryingItem = true;									//updating stats (health,damage,defence)
		}
		else {
			isCarryingItem = false;
		}

		break;


	case MonsterType::OGRE:

		name = "OGRE";
		level = 3;
		health = level * (generateRandomNumber(4, 6));
		attack = level * (generateRandomNumber(3, 5));
		defence = level * (generateRandomNumber(2, 4));
		damage = level;
		typeOfMonster = MonsterType::OGRE;



		temp = generateRandomNumber(1, 100);
		if (temp > 40) {											//60% chance
			itemEquipped = (generateRandomNumber(8, 11));			//artefacts ID as ogres can now carry artefacts
			AssignRandomItem();
			isCarryingItem = true;									//updating stats (health,damage,defence)
		}
		else {
			isCarryingItem = false;
		}

		break;

	case MonsterType::TROLL:

		name = "TROLL";
		level = 4;
		health = level * (generateRandomNumber(5, 7));
		attack = level * (generateRandomNumber(4, 7));
		defence = level * (generateRandomNumber(2, 5));
		damage = level;
		typeOfMonster = MonsterType::TROLL;


		temp = generateRandomNumber(1, 100);
		if (temp > 30) {											//70% chance
			itemEquipped = (generateRandomNumber(8, 11));			//artefacts ID
			AssignRandomItem();
			isCarryingItem = true;
		}
		else {
			isCarryingItem = false;
		}

		break;
	default:
		break;
	}


	//IF the monster is carrying items, add weapons stats to its own, only if its not a consumable or misc item like gold, map or potion or provisions

	if (isCarryingItem == true) {
		if (ItemMonsterIsCarrying.GetItemType() == Item_Type::ARTEFACTS || ItemMonsterIsCarrying.GetItemType() == Item_Type::WEAPON_ARMOR) {
			UpdateStats(ItemMonsterIsCarrying.GetItemHealth(), ItemMonsterIsCarrying.GetItemDamage(), ItemMonsterIsCarrying.GetItemDefence());
		}
	}
}


//Destructor
Monster::~Monster() {

}



//For creating Monster based on ID given in the parameter

Monster::Monster(int monsterID) {

	attack = 0;
	defence = 0;
	damage = 0;
	health = 0;
	itemEquipped = 0;
	level = 0;

	//Assign the monster type
	MonsterType typeOfMonster = MonsterType(monsterID);
	location;
	isCarryingItem = false;
	//default values

	switch (typeOfMonster)
	{
		int temp;
	case MonsterType::GOBLIN:
		name = "GOBLIN";
		level = 1;
		health = level * (generateRandomNumber(2, 3));
		attack = level * (generateRandomNumber(1, 3));
		attack = level * (generateRandomNumber(1, 2));
		damage = level;

		temp = generateRandomNumber(1, 100);
		if (temp > 60) {												//40% chance to carry an item
			itemEquipped = (generateRandomNumber(2, 7));				//Random item between ID 2-7. possible items they can carry
			AssignRandomItem();											//UpdateStats(ItemMonsterIsCarrying.GetItemHealth(), ItemMonsterIsCarrying.GetItemDamage(), ItemMonsterIsCarrying.GetItemDefence());
			isCarryingItem = true;										//Assign proper boolean values to bool var
		}
		else {
			isCarryingItem = false;
		}

		break;


	case MonsterType::HOBOGOBLIN:

		name = "HOBOGOBLIN";
		level = 2;
		health = level * (generateRandomNumber(3, 5));
		attack = level * (generateRandomNumber(2, 4));
		attack = level * (generateRandomNumber(1, 3));
		damage = level;


		temp = generateRandomNumber(1, 100);
		if (temp > 50) {
			itemEquipped = (generateRandomNumber(2, 7));				//50% chance, create random item
			AssignRandomItem();											//UpdateStats(ItemMonsterIsCarrying.GetItemHealth(), ItemMonsterIsCarrying.GetItemDamage(), ItemMonsterIsCarrying.GetItemDefence());
			isCarryingItem = true;
			//getDetails();
			//un comment on top to prove the update stats is working
			//UpdateStats(ItemMonsterIsCarrying.GetItemHealth(), ItemMonsterIsCarrying.GetItemDamage(), ItemMonsterIsCarrying.GetItemDefence());
		}
		else {
			isCarryingItem = false;
		}

		break;


	case MonsterType::OGRE:

		name = "OGRE";
		level = 3;
		health = level * (generateRandomNumber(4, 6));
		attack = level * (generateRandomNumber(3, 5));
		attack = level * (generateRandomNumber(2, 4));
		damage = level;


		temp = generateRandomNumber(1, 100);
		if (temp > 40) {												//60% chance
			itemEquipped = generateRandomNumber(8, 11);				//random number 8-11 artefacts xcept dragon item
			AssignRandomItem();											//UpdateStats(ItemMonsterIsCarrying.GetItemHealth(), ItemMonsterIsCarrying.GetItemDamage(), ItemMonsterIsCarrying.GetItemDefence());
			//UpdateStats(ItemMonsterIsCarrying.GetItemHealth(), ItemMonsterIsCarrying.GetItemDamage(), ItemMonsterIsCarrying.GetItemDefence());
			isCarryingItem = true;										//bool value
		}
		else {
			isCarryingItem = false;
		}

		break;

	case MonsterType::TROLL:

		name = "TROLL";
		level = 4;
		health = level * (generateRandomNumber(5, 7));
		attack = level * (generateRandomNumber(4, 7));
		attack = level * (generateRandomNumber(2, 5));
		damage = level;


		temp = generateRandomNumber(1, 100);
		if (temp > 30) {												//70% chance
			itemEquipped = generateRandomNumber(8, 11);					//random 8-11, artefacts ID
			AssignRandomItem();											//UpdateStats(ItemMonsterIsCarrying.GetItemHealth(), ItemMonsterIsCarrying.GetItemDamage(), ItemMonsterIsCarrying.GetItemDefence());
			//UpdateStats(ItemMonsterIsCarrying.GetItemHealth(), ItemMonsterIsCarrying.GetItemDamage(), ItemMonsterIsCarrying.GetItemDefence());
			isCarryingItem = true;										//bool var
		}
		else {
			isCarryingItem = false;
		}

		break;
		break;
	}

}



//cout MonsterDetails


void Monster::getDetails() {

	std::cout << "Name : " << name << std::endl;
	std::cout << std::endl;
	std::cout << "Level : " << level << std::endl;
	std::cout << std::endl;
	std::cout << "Health : " << health << std::endl;
	std::cout << std::endl;
	std::cout << "Attack : " << attack << std::endl;
	std::cout << std::endl;
	std::cout << "Defence : " << defence << std::endl;
	std::cout << std::endl;
	std::cout << "Damage: " << damage << std::endl;
	std::cout << std::endl;
	std::cout << "Location : " << location << std::endl;
	std::cout << std::endl;
	std::cout << "Is Carrying Item? : " << std::boolalpha << isCarryingItem << std::endl;

	if (isCarryingItem == true) {
		std::cout << "Item ID equipped: " << itemEquipped << std::endl;
		std::cout << "Item carried: " << ItemMonsterIsCarrying.GetItemName() << std::endl;
		std::cout << std::endl;
	};
}


//get
// 
//open code to see comments

//getting carried item properties

std::string Monster::getCarriedItemName()								//name of the item carried
{
	return ItemMonsterIsCarrying.GetItemName();
}

MonsterType Monster::GetMonsterType() {
	return typeOfMonster;
}

int Monster::getCarriedItemHealth()										//health of the item carried	
{
	return ItemMonsterIsCarrying.GetItemHealth();
};
int Monster::getCarriedItemDamage() {						//Damage of carried item

	return ItemMonsterIsCarrying.GetItemDamage();

};
int Monster::getCarriedItemDefence() {						//defence of item carried

	return ItemMonsterIsCarrying.GetItemDefence();
};
int Monster::getRandomizedAttack() {
	int temp = generateRandomNumber(2, 10);
	int attackVal = attack + temp;
	return attackVal;
};
int Monster::GetDefence() {
	return defence;
}

//getting Monster properties

std::string Monster::GetMonsterName()				//get Monster name
{
	return name;
}
int Monster::GetMonsterHealth()						//get Monster Health
{
	return health;
}
int Monster::GetMonsterDamage()						//get Monster Damage
{
	return damage;
}
int Monster::GetLocation()							//get Location
{
	return location;
}
bool Monster::GetIsCarryingItem()					//get bool val of is carrying item?
{
	return isCarryingItem;
}
Item* Monster::GetItemMonsterIsCarrying_ptr() {			//return the item that the monster is carrying
	return &ItemMonsterIsCarrying;
}
std::vector<std::string> Monster::getArt() {
	return monster_Art;
}

bool Monster::GetIfSpecialAttackused() {
	return false;
};

int Monster::SpecialAttack() {
	return 0;
}

//setting monster properties

void Monster::SetMonsterName(std::string var)
{
	name = var;
}
void Monster::SetMonsterHealth(int var)
{
	health = var;
}
void Monster::SetMonsterDamage(int var)
{
	damage = var;
}
void Monster::SetLocation(int var)
{
	location = var;
}
void Monster::SetisCarryingItem(bool var)
{
	isCarryingItem = var;
}
void Monster::renderGraphics() {

	for (int i = 0; i < monster_Art.size(); i++) {
		std::cout << monster_Art[i] << std::endl;
	}

}