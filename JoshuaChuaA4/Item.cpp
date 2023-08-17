#include "Item.h"

//Method to get truly random numbers

int Item::generateRandomNumber(int min, int max) {
	std::random_device val;
	std::mt19937 gen(val());
	std::uniform_int_distribution<> distr(min, max);
	return distr(gen);
}


//Constructors

//Default Constructor
Item::Item() {

}

//Destructor
Item::~Item() {

}


//For Instantiating in backpack
// 
//Overloaded Constructor Instantiating whilst Instantiating Rooms

//Item::Item(int ItemType, int location) {
//
//	itemType = Item_Type(ItemType);
//	amount = NULL;
//	int randomItemID;
//	int posOrNeg;
//	special_Effects = { 0,0,0 };
//	int healAmount;
//	int hurtAmount;
//	switch (itemType)
//	{
//	case Item_Type::ARTEFACT:
//		randomItemID = generateRandomNumber(8, 12);
//		itemID = item_ID(randomItemID);
//
//		switch (itemID)
//		{
//		case item_ID::KRANGS_BATTLE_AXE:
//
//			name = "KRANG'S BATTLE AXE";
//			special_Effects = { 0,8,0 };
//			break;
//
//		case item_ID::KRANGS_CHAINMAIL:
//			name = "KRANG'S CHAINMAIL";
//			special_Effects = { 0,0,12 };
//			break;
//
//		case item_ID::BOOTS_OF_SPEED:
//			name = "BOOTS OF SPEED";
//			special_Effects = { 0,0,6 };
//			break;
//		case item_ID::ELIXIR_MAXIMA:
//			name = "ELIXIR MAXIMA";
//			itemType = Item_Type::ARTEFACT;
//			break;
//
//
//		case item_ID::BALTHAZARS_SPELL_TOME:
//			name = "BALTHAZAR'S SPELL TOME";
//			itemType = Item_Type::ARTEFACT;
//			break;
//		};
//
//	case Item_Type::POTION:
//
//		name = "POTION FLASK";
//		itemID = item_ID::POTION_FLASK;
//		posOrNeg = generateRandomNumber(1, 100);
//		healAmount = generateRandomNumber(2, 4);
//		hurtAmount = healAmount * (-1);
//
//		if (posOrNeg > 50) {
//			special_Effects = { healAmount, 0 , 0 };
//		}
//		else {
//			special_Effects={hurtAmount, 0 , 0 };
//		}
//		amount = generateRandomNumber(2, 4);
//
//		break;
//
//	case Item_Type::WEAPON:
//		name = "SWORD";
//		itemID = item_ID::SWORD;
//		special_Effects = { 0,2,0};
//		break;
//
//	case Item_Type::ARMOR:
//		name = "LEATHER ARMOUR";
//		itemID = item_ID::LEATHER_AMOUR;
//		special_Effects = { 0,0,4 };
//		break;
//
//	case Item_Type::ITEM:
//
//		randomItemID = generateRandomNumber(1, 4);
//		itemID = item_ID(randomItemID);
//		healAmount = generateRandomNumber(5, 10);
//
//		switch (itemID)
//		{
//		case item_ID::MAP:
//			name = "MAP";
//			amount = NULL;
//			break;
//		case item_ID::LANTERN:
//			name = "LANTERN";
//			amount = generateRandomNumber(5,10);
//			break;
//		case item_ID::PROVISIONS:
//			name = "PROVISIONS";
//			amount = generateRandomNumber(2, 4);
//			special_Effects = {healAmount,0,0};
//			break;
//		case item_ID::GOLD:
//			name = "GOLD";
//			amount = generateRandomNumber(6, 12);
//			break;
//		}
//		break;
//
//	};
//
//
//
//}




//Overloaded Constructor of creating an item from scratch
//Item::Item(std::string Name,Item_Type ItemType,item_ID ItemID,int Location,std::vector<int>Special_Effects,int Amount){
//	name = Name;
//	itemType = ItemType;
//	itemID = ItemID;
//	special_Effects = Special_Effects;
//	amount = Amount;
//}


//COUT Item Details (Properties)

//void Item::GetDetails() {
//	std::cout << "Name: " << GetItemName() << std::endl;
//	std::cout << "Damage: " << GetItemDamage() << std::endl;
//	std::cout << "Health: " << GetItemHealth() << std::endl;
//	std::cout << "Defence: " << GetItemDefence() << std::endl;
//	std::cout << "Amount: " << GetAmount() << std::endl;
//
//}



//Getters


std::string Item::GetItemName() {
	return name;
}

Item_Type Item::GetItemType() {
	return itemType;
}

item_ID Item::GetItemID() {
	return  itemID;
}


int Item::GetItemHealth() {

	return special_Effects[0];
}

int Item::GetItemDamage() {
	int Damage = special_Effects[1];
	return Damage;
}

int Item::GetItemDefence() {
	int Defence = special_Effects[2];
	return Defence;
}


bool Item::GetStatsAdded() {
	return statsAdded;
}



//Setters

void Item::setName(std::string var) {
	name = var;
}

void Item::SetItemType(int type) {
	itemType = Item_Type(type);
}

void Item::SetItemID(int ID) {
	itemID = item_ID(ID);
}


void Item::SetItemHealth(int var) {
	special_Effects[0] = var;
}

void Item::SetItemDamage(int var) {
	special_Effects[1] = var;
}

void Item::SetItemDefence(int var) {
	special_Effects[2] = var;
}

void Item::SetAmount(int var) {}

void Item::SetStatsAdded(bool input) {
	statsAdded = input;
}

void Item::Consume() {}

int Item::GetAmount() {
	return 5000;
}

int Item::ConsumeLantern() {
	return 10000;
};


void Item::UpdatePlayerLocationOnMap(int x, int y) {};

void Item::DisplayMapItem() {};






