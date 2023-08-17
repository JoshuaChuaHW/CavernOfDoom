#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "ItemTypeEnum.h"
#include "item_ID.h"
#include <random>
#include <vector>
#include <iostream>
class Item
{
protected:
	std::string name;
	Item_Type itemType;
	item_ID itemID;
	int location;
	std::vector<int> special_Effects = { 0,0,0 };								 // 0  is value of health, 1 is value of damage, 2 is value for defence
	//int amount;
	bool statsAdded = false;

public:

	//Declaring Random Method

	//DECLARING constructors

	//random method
	int generateRandomNumber(int min, int max);

	//Constructors
	Item();
	//Item(int itemType, int Location);
	//Item(int Item_ID);
	//Item(std::string Name, Item_Type ItemType, item_ID ItemID, int Location, std::vector<int>Special_Effects, int Amount);

	//Deconstructor

	~Item();



	//Declaring function to cout item properties

	//void GetDetails();











	// Mutators(Get/Set)

	// Get Variables

	std::string GetItemName();

	Item_Type GetItemType();

	item_ID GetItemID();

	virtual int GetItemHealth();

	int GetItemDamage();

	int GetItemDefence();

	virtual int GetAmount();

	bool GetStatsAdded();



	// Set Variables

	void setName(std::string var);

	void SetItemType(int type);

	void SetItemID(int ID);


	void SetItemHealth(int var);

	void SetItemDamage(int var);

	void SetItemDefence(int var);

	void SetStatsAdded(bool input);

	virtual void SetAmount(int var);

	virtual void Consume();

	virtual int ConsumeLantern();

	virtual void UpdatePlayerLocationOnMap(int x, int y);

	virtual void DisplayMapItem();


};
#endif

