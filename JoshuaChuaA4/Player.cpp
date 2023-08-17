#include "Player.h"

//constructors

Player::Player(std::string Name) {



	name = Name;
	health = generateRandomNumber(4, 12) + 12;
	attack = health / 6;
	defence = attack / 2;
	damage = (attack / 3) + 4;
	luck = generateRandomNumber(2, 6) + 6;
	inventory = {};
	currentLocation = 0;

}

Player::Player() {
	name = "Player";
	health = generateRandomNumber(4, 12) + 12;
	attack = health / 6;
	defence = attack / 2;
	damage = (attack / 3) + 4;
	luck = generateRandomNumber(2, 6) + 6;
	inventory = {};
	currentLocation = 0;

};

//deconstructor
Player::~Player() {

}




//cout Player Details




void Player::getDetails() {
	std::cout << name << std::endl;
	std::cout << health << std::endl;;
	std::cout << attack << std::endl;;
	std::cout << defence << std::endl;;
	std::cout << luck << std::endl;;
	std::cout << currentLocation << std::endl;

	for (int i = 0; i < inventory.size(); i++) {
		std::cout << "Slot" << i << ": " << inventory[i]->GetItemName() << std::endl;
	}
}




//random number



int Player::generateRandomNumber(int min, int max) {
	std::random_device val;
	std::mt19937 gen(val());
	std::uniform_int_distribution<> distr(min, max);
	return distr(gen);
}


//update player stats based on parameter
void Player::updateStats(int Health, int Attack, int Defence, float Luck) {

	health += Health;

	attack += Attack;

	defence += Defence;

	luck += Luck;

}



//Get


std::string Player::GetPlayerName()													//return player name
{
	return name;
}
int Player::GetPlayerHealth()														//get health value of player
{
	return health;
}
int Player::GetPlayerAttack()														//get attack value of player
{
	return attack;
}
int Player::GetPlayerDefence()														//get defence value of player
{
	return defence;
}
int Player::GetPlayerDamage()														//get damage value of player
{
	return damage;
}
float Player::GetPlayerLuck()															//get luck value of player	
{
	return luck;

}
Location* Player::GetPlayerCurrentLocation()												//get currentlocation of player
{
	return &current_Location;
}

std::vector<Item*>* Player::GetPlayerInventory_Ptr() {									//return the vector of item objects
	return &inventory;
}

int Player::getRandomizedAttackValue() {
	int temp = generateRandomNumber(2, 10);
	int randAtt = attack + temp;
	return randAtt;
}

int Player::getSizeOfInventory() {
	int size = 0;
	for (int i = 0; i < inventory.size(); i++) {
		size += 1;
	}
	return size;
};
void Player::addItemToInventory(Item* item) {
	inventory.push_back(item);
}



//setters



void Player::SetPlayerName(std::string var)											//set new assigned name provided in parameter
{
	name = var;
};
void Player::SetPlayerHealth(int var)												//set new health value
{
	health = var;
};
void Player::SetPlayerAttack(int var)												//set new attack values
{
	attack = var;
};
void Player::SetPlayerDefence(int var)												//new defence values
{
	defence = var;
};
void Player::SetPlayerDamage(int var)												//damage values
{
	damage = var;
};
void Player::SetPlayerLuck(int var)													//luck values
{
	luck = var;
};
void Player::SetPlayerCurrentLocation(Location roomassigned)										//set the currentlocation of player obj
{
	current_Location = roomassigned;
};

void Player::updateStats() {

	for (int i = 0; i < inventory.size(); i++) {

		if (inventory[i]->GetItemType() == Item_Type::ARTEFACTS || inventory[i]->GetItemType() == Item_Type::WEAPON_ARMOR) {
			if (inventory[i]->GetStatsAdded() == false) {
				health += inventory[i]->GetItemHealth();
				damage += inventory[i]->GetItemDamage();
				defence += inventory[i]->GetItemDefence();
				inventory[i]->SetStatsAdded(true);
			}
		}
	}
	attack = health / 6;
}