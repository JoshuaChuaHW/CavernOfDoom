#include "Gold.h"

Gold::Gold() {
	name = "GOLD";
	itemType = Item_Type::MISC;
	itemID = item_ID::GOLD;
	amount = generateRandomNumber(6, 12);

}