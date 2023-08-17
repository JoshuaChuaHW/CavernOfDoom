#include "Armour.h"



Armour::Armour() {
	name = "LEATHER ARMOUR";
	itemType = Item_Type::WEAPON_ARMOR;
	itemID = item_ID::LEATHER_AMOUR;
	special_Effects = { 0,0,4 };
	statsAdded = false;
}