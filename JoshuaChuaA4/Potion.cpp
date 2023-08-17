#include "Potion.h"

Potion::Potion() {
	name = "POTION FLASK";
	itemType = Item_Type::CONSUMABLE;
	itemID = item_ID::POTION_FLASK;
	amount = generateRandomNumber(1, 2);
	special_Effects = { 0,0,0 };
}

void Potion::Consume() {
	amount -= 1;
}

int Potion::GetAmount() {
	return amount;
}

void Potion::SetAmount(int var) {
	amount = var;
}

int Potion::GetItemHealth() {
	int healOrHurt = generateRandomNumber(1, 2);
	int healAmount = generateRandomNumber(2, 4);
	const int negative = -1;
	if (healOrHurt == 1) {
		special_Effects[0] = healOrHurt * negative;
	}
	else {
		special_Effects[0] = healOrHurt;
	}
	return special_Effects[0];
}