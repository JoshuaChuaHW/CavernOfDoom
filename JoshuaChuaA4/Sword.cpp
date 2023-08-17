#include "Sword.h"


Sword::Sword() {
	name = "SWORD";
	itemType = Item_Type::WEAPON_ARMOR;
	itemID = item_ID::SWORD;
	special_Effects = { 0,2,0 };
	statsAdded = false;
}