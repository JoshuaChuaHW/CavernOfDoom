#include "Provisions.h"


Provisions::Provisions() {
	name = "PROVISIONS";
	itemType = Item_Type::CONSUMABLE;
	itemID = item_ID::PROVISIONS;
	special_Effects = { 0,0,0 };
	amount = generateRandomNumber(2, 4);
}

void Provisions::SetAmount(int var) {
	amount = var;
}

void Provisions::Consume() {
	amount -= 1;
}

int Provisions::GetAmount() {
	return amount;
}

int Provisions::GetItemHealth() {
	special_Effects[0] = generateRandomNumber(5, 10);
	return special_Effects[0];

}