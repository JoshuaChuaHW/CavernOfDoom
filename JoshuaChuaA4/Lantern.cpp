#include "Lantern.h"


Lantern::Lantern() {

	name = "LANTERN";
	itemType = Item_Type::CONSUMABLE;
	itemID = item_ID::LANTERN;
	fuel = generateRandomNumber(5, 10);

}
int Lantern::ConsumeLantern() {

	int fuelused = generateRandomNumber(2, 5);
	fuel -= fuelused;

	return fuelused;
}

void Lantern::Consume() {

	fuel -= 1;

}

int Lantern::GetAmount() {

	return fuel;

}


void Lantern::SetAmount(int var) {
	fuel = var;
}