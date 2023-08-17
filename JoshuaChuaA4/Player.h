#ifndef PLAYER_H
#define PLAYER_H


#include "Item.h"
#include "Location.h"
#include "Monster.h"
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

class Player
{


	friend class Item;


private:
	std::string name;
	int health;
	int attack;
	int defence;
	int damage;
	float luck;
	int currentLocation = 0;
	Location current_Location;
	std::vector<Item*> inventory = {};



public:
	//Constructors
	Player(std::string Name);
	Player();

	//Destructor
	~Player();


	//display details abt obj

	void getDetails();
	int generateRandomNumber(int min, int max);


	//update obj stats

	void updateStats(int health, int attack, int defence, float luck);

	//mutators
	//get

	std::string GetPlayerName();

	int GetPlayerHealth();

	int GetPlayerAttack();

	int GetPlayerDefence();

	int GetPlayerDamage();

	float GetPlayerLuck();

	int getRandomizedAttackValue();

	Location* GetPlayerCurrentLocation();

	std::vector<Item*>* GetPlayerInventory_Ptr();
	void addItemToInventory(Item* item);
	int getSizeOfInventory();



	//setters

	void SetPlayerName(std::string var);

	void SetPlayerHealth(int var);

	void SetPlayerAttack(int var);

	void SetPlayerDefence(int var);

	void SetPlayerDamage(int var);

	void SetPlayerLuck(int var);

	void SetPlayerCurrentLocation(Location roomassigned);

	void updateStats();

protected:;
};

















#endif // !PLAYER_H