#ifndef MONSTER_H
#define MONSTER_H
#include "MonsterTypeEnum.h"
#include "Item.h"
#include <fstream>
#include <iostream>
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

class Monster
{
protected:
	std::string name;
	int level;
	int health;
	int attack;
	int defence;
	int damage;
	int itemEquipped;
	int location;
	bool isCarryingItem;
	Item ItemMonsterIsCarrying;
	std::vector<std::string> monster_Art;
	MonsterType typeOfMonster;


public:
	//Random Number Method
	int generateRandomNumber(int min, int max);

	//Constructors//

	//default constructor
	Monster();

	//Overloaded Constructor
	Monster(int monsterID);
	Monster(int monsterID, int location);

	//destructor
	~Monster();


	//Update Monster Stats depending on Item stats it is carrying

	void UpdateStats(int Health, int Damage, int Defence);
	void renderGraphics();


	// To access the object(item) that is created within the constructor of the monster Class

	std::string getCarriedItemName();			//Get Item name

	int getCarriedItemHealth();					//get item health

	int getCarriedItemDamage();					//get item damage

	int getCarriedItemDefence();				//get item defence



	//Mutators

	//get
	std::string GetMonsterName();				//get Monster name

	int GetMonsterHealth();						//monster health

	int GetMonsterDamage();						//monster damage

	int GetLocation();							//monster location

	bool GetIsCarryingItem();					//true or false whethere is carrying item

	Item* GetItemMonsterIsCarrying_ptr();			//return object of item if carrying

	int getRandomizedAttack();

	int GetDefence();

	void AssignRandomItem();
	
	MonsterType GetMonsterType();

	virtual int SpecialAttack();


	virtual bool GetIfSpecialAttackused();
	//set

	void SetMonsterName(std::string var);
	void SetMonsterHealth(int var);
	void SetMonsterDamage(int var);
	void SetLocation(int var);
	void SetisCarryingItem(bool var);


	//cout Details
	void getDetails();							//cout all details of created monster
	std::vector<std::string>  getArt();
};






#endif // !MONSTER_H