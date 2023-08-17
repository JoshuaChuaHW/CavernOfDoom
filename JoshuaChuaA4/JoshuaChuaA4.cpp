#include <iostream>
#include <windows.h>
#include "Player.h"
#include "Monster.h"
#include "Location.h"
#include "Boss.h"
#include "Item.h"
#include <fstream>
#include <cstdlib>
#include "window_Console.h"
#include "WIN32_VKCODE.h"



//Enum gamestate
enum GameState_ {
	MENU,
	WALKING,
	INITIALIZE,
	TRANSITION,
	ITEM_ENCOUNTERED,
	MONSTER_ENCOUNTERED,
	INVENTORY,
	IN_COMBAT,
	UPDATEMAP,
	GAMEOVER,
	QUITING,
	WON
};
GameState_ Game_State = MENU;




//Map
std::vector<Location> mapVector;								//to store and access the vector of maps



						/////////To compare with each individual map, made it a global for ease of use////////////

std::vector<char> SNE = { 'S','N','E' };
std::vector<char> SWE = { 'S','W','E' };
std::vector<char> SWN = { 'S','W','N' };
std::vector<char> WNE = { 'W','N','E' };


//For Main() default values
std::string playerName = "";
bool Play_Game = false;
bool Obj_Created = false;


//Global Var checking for items in inv
bool InvHasPotions = false;
bool InvHasProvision = false;
bool elixirPresent = false;

//readFile functionality
void readFile(std::string fileName) {

	// open file for reading
	std::ifstream fileToRead(fileName);
	if (fileToRead.is_open()) {
		std::string line = "";
		while (!fileToRead.eof()) {
			getline(fileToRead, line);
			std::cout << line << "\n";
		}
	}
	else {
		std::cout << "\nFile Not Found.\n";
	}
	//close file
	fileToRead.close();
}
Item copyOfItemMonsterOrRoomIsHolding;
Item* global_Ptr_Of_Item = &copyOfItemMonsterOrRoomIsHolding;

///////////////ASCII_ART_READFILE////////////////


//Misc
void renderInventoryGraphic() {
	readFile("Art/Misc/Inventory.txt");
}				//Graphic Inventory
//Render Loading Screen
void render_New_Map_Load() {
	system("cls");
	system("color 0e");

	char a = 177, b = 219;
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Loading New Map....";
	std::cout << "\n\n";
	std::cout << "\t\t\t\t\t";

	for (int i = 0; i <= 30; i++) {
		std::cout << b;
		Sleep(10);
	}
	system("color 0f");
	std::cout << "\n\n\n\n" << std::endl;
	system("cls");


}
//Print possible Exits based on map the player is on
void RenderDirectionOptions(Location place) {

	std::vector<char> exitOptions = place.GetVisibleExits();
	if (exitOptions == SNE) {

		std::cout << "\n            Press Letter Encased To Move  \n";
		for (int x = 0; x < 53; x++) {
			std::cout << "_";
		}
		std::cout << "\n          [S]            [N]           [E]\n";
	}
	else if (exitOptions == SWE) {
		std::cout << "\n            Press Letter Encased To Move  \n";
		for (int x = 0; x < 53; x++) {
			std::cout << "_";
		}
		std::cout << "\n          [S]            [W]           [E]\n";
	}
	else if (exitOptions == SWN) {
		std::cout << "\n            Press Letter Encased To Move  \n";
		for (int x = 0; x < 53; x++) {
			std::cout << "_";
		}
		std::cout << "\n          [S]            [W]           [N]\n";
	}
	else if (exitOptions == WNE) {
		std::cout << "\n            Press Letter Encased To Move  \n";
		for (int x = 0; x < 53; x++) {
			std::cout << "_";
		}
		std::cout << "\n          [W]            [N]           [E]\n";
	}
	for (int x = 0; x < 53; x++) {
		std::cout << "_";
	}
}


//Menu Screen
void render_Load_Bar() {
	system("cls");
	system("color 0e");

	char a = 177, b = 219;
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tLoading Game Objects & Maps....";
	std::cout << "\n\n";
	std::cout << "\t\t\t\t\t";

	for (int i = 0; i <= 30; i++) {
		std::cout << b;
		Sleep(10);
	}
	system("color 0f");
	std::cout << "\n\n\n\n" << std::endl;
	system("pause");
	system("cls");


}
void printVictory() {
	system("cls");
	readFile("Art/Misc/Victory.txt");
	system("pause>nul");
}
void LoadMaps() {
	//create map 20 times from index 0-19
	for (int index = 0; index < 20; index++) {
		mapVector.push_back(Location(index));
	}

}
void ReloadMapExceptForDragon() {
	for (int index = 0; index < 20; index++) {
		mapVector.push_back(Location(index));
	}
	mapVector[17].SetIsThereMonster(false);

}
void RenderLoadingScreen() {
	readFile("Art/Misc/LoadingScreen.txt");
}
void DisplayHelp() {
	system("cls");
	readFile("Art/Misc/Information.txt");								//<--Display information text from information.txt
	system("pause>nul");
}
void PrintStats_Art() {
	system("cls");
	readFile("Art/Misc/Stats.txt");
}

//Combat Print
void PrintLoot() {
	readFile("Art/Misc/Loot.txt");
}
void PrintTakeOrDrop() {
	std::cout << "\n	        [T]ake\n\n";
	std::cout << "	           or\n\n";
	std::cout << "	        [D]rop";
}
void PrintFight() {
	readFile("Art/Misc/Fight.txt");
}
void RenderAskToFight(Monster input) {
	std::cout << "                You've encountered a Monster!" << "    Monster: " << input.GetMonsterName() << "\n\n";
	for (int x = 0; x < 100; x++) {
		std::cout << "_";
	}
	std::cout << "\n";
	input.renderGraphics();
	for (int x = 0; x < 100; x++) {
		std::cout << "_";
	}
	std::cout << std::endl;
	std::cout << "                          [F]ight? or Attempt to [R]un?\n";
}
void RenderMonster(Monster input, Player playerInput) {
	for (int x = 0; x < 100; x++) {
		std::cout << "_";
	}
	std::cout << "\n";
	input.renderGraphics();
	for (int x = 0; x < 100; x++) {
		std::cout << "_";
	}
	std::cout << "\n\n";
	std::cout << "                          " << "Your Health:" << playerInput.GetPlayerHealth() << "   " << input.GetMonsterName() << " Health:" << input.GetMonsterHealth() << std::endl;
	for (int x = 0; x < 100; x++) {
		std::cout << "_";
	}
}
void RenderOption() {
	std::cout << "\n";
	for (int x = 0; x < 100; x++) {
		std::cout << "_";
	}
	std::cout << std::endl;
	std::cout << "\n                              [A]ttack      [F]lee     " << std::endl;
	for (int x = 0; x < 100; x++) {
		std::cout << "_";
	}
}


//Map Printing
void printPlayerDetails_Walking() {

	for (int x = 0; x < 53; x++) {
		std::cout << "_";
	}
	std::cout << "\n";
	std::cout << "   [M]ap   [H]elp   [I]nventory  S[T]ats   [Q]uit " << std::endl;
	for (int x = 0; x < 53; x++) {
		std::cout << "_";
	}
	std::cout << "\n   Use Arrow Keys To Move Character Within The Map";

}
void printFightPrequel(Monster mon, Player me) {

	system("cls");
	PrintFight();
	std::cout << "                Monster: " << mon.GetMonsterName() << "       Item equipped: " << mon.GetItemMonsterIsCarrying_ptr()->GetItemName() << std::endl;
	RenderMonster(mon, me);

}


//Display Map
void renderMap(std::vector<std::string> input) {
	for (int i = 0; i < input.size(); i++) {
		for (int z = 0; z < 54; z++) {
			std::cout << map[i][z];
		}
	}

}




///////////////GAME_FUNFCTIONS////////////////

////////////////Menu////////////////
void Menu() {
	system("cls");
	char option_Chosen = NULL;
	bool* gameState_ptr = &Play_Game;
	RenderLoadingScreen();
	while (*gameState_ptr == false) {

		if (GetAsyncKeyState(VK_KEY_P) & 0x8000) {
			*gameState_ptr = true;
			Game_State = WALKING;
			Play_Game = true;
			render_Load_Bar();
		}
		else if (GetAsyncKeyState(VK_KEY_I) & 0x8000) {
			DisplayHelp();
			Menu();
		}
		else if (GetAsyncKeyState(VK_KEY_Q) & 0x8000) {
			exit(0);
		}
	}



}
void GetPlayerName() {
	std::string* input = &playerName;
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tWho Stumbles Into My Home?";
	std::cout << "\n\n";
	std::cout << "\t\t\t\t\t";
	std::cout << "Enter your Name:";
	std::cin >> *input;
	system("cls");

}
void ShowStats(Player player) {
	std::cout << "\t\n\n\n                         Name: " << player.GetPlayerName() << std::endl << std::endl;
	std::cout << "\t\n\n\n                  Health: " << player.GetPlayerHealth() << "         Defence: " << player.GetPlayerDefence() << std::endl << std::endl;
	std::cout << "\t\n\n\n                  Attack: " << player.GetPlayerAttack() << "          Damage : " << player.GetPlayerDamage() << std::endl << std::endl;
	std::cout << "\t\n\n                             Luck: " << player.GetPlayerLuck();

	system("pause>nul");
}



///////////////Combat////////////
void Combat(Player& playerObj, Monster& monsterObj) {

	//obj Stats

	//player stats
	int player_Randomized_Attack = playerObj.getRandomizedAttackValue();
	int player_Defence = playerObj.GetPlayerDefence();
	int player_Damage = playerObj.GetPlayerDamage();
	int player_Current_Health = playerObj.GetPlayerHealth();

	//monster stats
	int monster_Current_Health = monsterObj.GetMonsterHealth();
	int monster_Randomized_Attack = monsterObj.getRandomizedAttack();
	int monster_Defence = monsterObj.GetDefence();
	int monster_Damage = monsterObj.GetMonsterDamage();
	std::string nameOfMonster = monsterObj.GetMonsterName();

	//Resulting results
	int damage_Inflicted;
	int resulting_Health;
	bool specialAttackUsed = false;

	if (monsterObj.GetMonsterType() == MonsterType::DRAGON) {
		if (monsterObj.GetIfSpecialAttackused() == true) {
			specialAttackUsed = true;
		}
	}

	//if player's attack is > monster's
	if (player_Randomized_Attack > monster_Randomized_Attack) {

		damage_Inflicted = player_Damage - monster_Defence;
		// if damage is less than 1, so it dosent ADD to the monster's health or if 0 fight never ends
		if (damage_Inflicted < 1) {

			damage_Inflicted = 1;
		}
		resulting_Health = monster_Current_Health - damage_Inflicted;
		monsterObj.SetMonsterHealth(resulting_Health);
		printFightPrequel(monsterObj, playerObj);
		std::cout << "\n\n\n                       You attacked the " << nameOfMonster << " for " << damage_Inflicted << " damage!";
		std::cout << "\n\n                                     " << monster_Current_Health << "-----> " << resulting_Health;
	}
	//if monster attack > player's attack
	else if (monster_Randomized_Attack > player_Randomized_Attack) {

		if (monsterObj.GetMonsterType() == MonsterType::DRAGON && specialAttackUsed == false) {
			monster_Damage = monsterObj.SpecialAttack();
		}

		damage_Inflicted = monster_Damage - player_Defence;
		if (damage_Inflicted < 1) {
			damage_Inflicted = 1;
		}
		resulting_Health = player_Current_Health - damage_Inflicted;
		playerObj.SetPlayerHealth(resulting_Health);
		printFightPrequel(monsterObj, playerObj);
		std::cout << "\n\n\n                          " << nameOfMonster << " attacked you for " << damage_Inflicted << " damage!";;
		std::cout << "\n\n                                     " << player_Current_Health << "-----> " << resulting_Health;
	}
	//else if player attack == monster attack 

	else
	{
		printFightPrequel(monsterObj, playerObj);
		std::cout << "\n\n                             Both " << nameOfMonster << " and you are equally skilled" << std::endl;
		std::cout << "                                         You exchange blows but neither take damage" << std::endl;


	}
}
void FleeSequence(Player& person, Monster& mon) {
	system("cls");
	int initalPlayerHealth = person.GetPlayerHealth();
	int damage_inflicted = mon.GetMonsterDamage() - person.GetPlayerDefence();
	if (damage_inflicted < 0) {
		damage_inflicted = 1;
	}
	int resulting_Health = initalPlayerHealth - damage_inflicted;
	person.SetPlayerHealth(resulting_Health);

	printFightPrequel(mon, person);

	std::cout << "\n\n                         " << mon.GetMonsterName() << "attacked you for " << damage_inflicted << " while fleeing!";
	std::cout << "\n\n                                    " << initalPlayerHealth << "-----> " << resulting_Health;

	system("pause>nul");
}
void checkWhoWon(Player& player_, Monster& monster_, GameState_& stateOfGame, Location& CurrentRoom) {
	bool monsterDied = false;
	bool playerDied = false;
	int player_Health = player_.GetPlayerHealth();
	int monster_Health = monster_.GetMonsterHealth();
	if (player_Health <= 0) {
		playerDied = true;
	}
	if (monster_Health <= 0) {
		monsterDied = true;
	}
	if (playerDied == true) {
		stateOfGame = GAMEOVER;
	}
	else if (playerDied == false && monsterDied == true) {
		CurrentRoom.SetIsThereMonster(false);
		CurrentRoom.UpdateMap();
		system("pause>nul");
		printVictory();

		if (monster_.GetIsCarryingItem() == true) {

			bool option_chosen = false;
			bool item_In_Inventory = false;
			while (option_chosen == false) {
				system("cls");
				std::cout << "\n\n       Item Dropped: " << monster_.GetItemMonsterIsCarrying_ptr()->GetItemName() << "\n";
				PrintLoot();
				PrintTakeOrDrop();
				system("pause>nul");
				if (GetAsyncKeyState(VK_KEY_T) & 0x8000) {
					copyOfItemMonsterOrRoomIsHolding = *(monster_.GetItemMonsterIsCarrying_ptr());
					std::string itemName = global_Ptr_Of_Item->GetItemName();
					std::vector<Item*>* inventory_ptr = player_.GetPlayerInventory_Ptr();
					int indexItemLookingFor;
					for (int i = 0; i < player_.getSizeOfInventory(); i++) {
						if (itemName == (*inventory_ptr)[i]->GetItemName()) {
							item_In_Inventory = true;
							indexItemLookingFor = i;
						}
					}
					if (item_In_Inventory == true) {
						if (monster_.GetItemMonsterIsCarrying_ptr()->GetItemType() == Item_Type::CONSUMABLE || monster_.GetItemMonsterIsCarrying_ptr()->GetItemType() == Item_Type::MISC) {
							int amountNow = (*inventory_ptr)[indexItemLookingFor]->GetAmount();
							int amountToAdd = copyOfItemMonsterOrRoomIsHolding.GetAmount();
							int finalAmount = amountNow + amountToAdd;

							(*inventory_ptr)[indexItemLookingFor]->SetAmount(finalAmount);

							system("cls");
							std::cout << "\n\n\n\n\n\n                 Item Added To Inventory!";
							system("pause>nul");
							option_chosen = true;

						}
						else {
							system("cls");
							std::cout << "\n\n\n\n\n\n    You Already Have That Item In Your Inventory! ";
							system("pause>nul");
							option_chosen = true;
						}
					}
					else {
						player_.addItemToInventory(global_Ptr_Of_Item);
						system("cls");
						std::cout << "\n\n\n\n\n\n                 Item Added To Inventory!";
						system("pause>nul");
						option_chosen = true;
					}
				}
				if (GetAsyncKeyState(VK_KEY_D) & 0x8000) {
					option_chosen = true;
				}
			}

		}
		monster_.~Monster();
		stateOfGame = UPDATEMAP;
	}
	else {
		stateOfGame = IN_COMBAT;
	}

}
void printUpdatedFight(Monster monster, Player player) {
	printFightPrequel(monster, player);
	Combat(player, monster);
}


/////////////Inventory///////////
void DisplayInventory(std::vector<Item*> inv) {																			//display inventory dependingf on items in it and switch globval flags
	std::string rovisions = "ROVISIONS";
	std::string tions = "TIONS";
	std::cout << "\n\n                 no.      |    Item Name    |     Amount\n";
	for (int i = 0; i < inv.size(); i++) {

		if (inv[i]->GetItemID() == item_ID::ELIXIR_MAXIMA) {
			std::cout << "\n\n                  " << i + 1 << ".      |   [E]LIXIR MAXIMA  =       " << inv[i]->GetAmount() << std::endl;
			elixirPresent = true;
		}
		if (inv[i]->GetItemID() == item_ID::PROVISIONS) {
			std::cout << "\n\n                  " << i + 1 << ".      |   [P]" << rovisions << "  =       " << inv[i]->GetAmount() << std::endl;
			InvHasProvision = true;
		}
		else if (inv[i]->GetItemID() == item_ID::POTION_FLASK) {
			std::cout << "\n\n                  " << i + 1 << ".      |   P[O]" << tions << "     =       " << inv[i]->GetAmount() << std::endl;
			InvHasPotions = true;
		}
		else if (inv[i]->GetItemID() == item_ID::LANTERN) {
			std::cout << "\n\n                  " << i + 1 << ".      |   LANTERN       =       " << inv[i]->GetAmount() << std::endl;
		}
		else if (inv[i]->GetItemID() == item_ID::GOLD) {
			std::cout << "\n\n                  " << i + 1 << ".      |   GOLD          =       " << inv[i]->GetAmount() << std::endl;
		}
		else {
			std::cout << "\n\n                  " << i + 1 << ".      |   " << inv[i]->GetItemName() << std::endl;
		}
	}
	if (elixirPresent == true) {
		std::cout << "\n\n\n\n\n                      Press [E] to use ELIXIR";
	}
	if (InvHasProvision == true && InvHasPotions == false) {
		std::cout << "\n\n\n\n\n                    Press [P] to use Provisions";
		std::cout << "\n\n                   Or Any Other Button To Return";

	}
	else if (InvHasProvision == false && InvHasPotions == true) {
		std::cout << "\n\n\n\n\n                    Press [O] to use P[O]tions";
		std::cout << "\n\n                   Or Any Other Button To Return";

	}
	else if (InvHasProvision == true && InvHasPotions == true) {
		std::cout << "\n\n\n\n\n            Press [P] for Provisions and [O] for Potions";
		std::cout << "\n\n                   Or Any Other Button To Return";

	}
	else {
		std::cout << "\n\n                     Press Any Button To Return";
	}
}
void RemoveFromInv(std::vector<Item*>& inv_, Item& ItemToRemove) {
	int item_Index = 0;
	for (int y = 0; y < inv_.size(); y++) {
		if (inv_[y]->GetItemID() == ItemToRemove.GetItemID()) {
			item_Index = y;
		}
	}

	if (inv_[item_Index]->GetAmount() == 0 && inv_[item_Index]->GetItemID() != item_ID::MAP) {
		inv_.erase(inv_.begin() + item_Index);
	}

}
Item* Get_Item_Ptr(std::vector<Item*>& inv_, item_ID itemID) {
	for (int i = 0; i < inv_.size(); i++) {
		if (inv_[i]->GetItemID() == itemID) {
			return inv_[i];
		}
	}
	return nullptr;
}
void UseConsumable(Item& consumable, Player& player_Used) {

	int healthRestored = consumable.GetItemHealth();
	int currentHealth = player_Used.GetPlayerHealth();
	int restoredHealth = currentHealth + healthRestored;

	if (consumable.GetItemID() == item_ID::PROVISIONS || consumable.GetItemID() == item_ID::POTION_FLASK) {

		consumable.Consume();
		system("cls");

		std::cout << "\n\n\n\n               You consumed a " << consumable.GetItemName();
		std::cout << "\n\n\n\n                 " << healthRestored << "  health restored!\n";
		std::cout << "\n\n\n\n                      " << currentHealth << "---> " << restoredHealth;
		player_Used.SetPlayerHealth(restoredHealth);
		system("pause>nul");
		system("cls");

		if (consumable.GetAmount() == 0) {

			std::cout << "\n\n\n\n               You Ran Out Of " << consumable.GetItemName();
			system("pause>nul");

		}
	}

}
bool Check_If_Empty(Item* consumable) {
	if (consumable->GetAmount() == 0) {
		return true;
	}
	else {
		return false;
	}
}

//misc
void useLantern(Item* ptrOfLantern) {
	int fuelNow = ptrOfLantern->GetAmount();
	int fuelUsed = ptrOfLantern->ConsumeLantern();
	int fuelAfter = ptrOfLantern->GetAmount();
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n                                   You Consumed " << fuelUsed << " fuel!";
	std::cout << "\n\n\n\n                                      " << fuelNow << " -----> " << fuelAfter;
	system("pause>nul");

}
//visual feedback of lantern being used




int main()
{

	///////////////Declaring of Variables & Pointers//////////////////

//Objects
	window_Console console;
	Player You;

	bool player_Exit = false;

	//Pointing to Addr of Room obj player is currently in
	Location* ptr_currentRoom_Location = You.GetPlayerCurrentLocation();


	//Player's attributes
	std::vector<Item*>* ptr_player_Inventory = You.GetPlayerInventory_Ptr();
	int playerLocation = 0; //entrance



	//Pointing to Addr or Item and Monster Objs In current room obj
	Monster* ptr_monsterInRoom = ptr_currentRoom_Location->GetMonsterInRoom();
	Item* ptr_itemInRoom = ptr_currentRoom_Location->GetItemInRoom();


	//Room Attributes
	std::vector<char> currentRoom_VisibleExits;
	bool is_There_Item_In_Room;
	bool is_There_Monster_In_Room;
	std::vector<std::string> Current_Room_Map;

	while (player_Exit == false) {

		Menu();


		//create starting inventory Items
		Map map_Item = Map();
		Lantern lantern = Lantern();
		Provisions provisions = Provisions();
		Sword sword = Sword();
		Potion potion = Potion();
		lantern.SetAmount(100);

		//Assign them to pointers since inventory is vector expecting base class
		Item* map_Ptr = &map_Item;
		Item* lantern_Ptr = &lantern;
		Item* provisions_Ptr = &provisions;
		Item* sword_Ptr = &sword;
		Item* potion_Ptr = &potion;
		bool legacyMoving = false;

		while (Play_Game == true) {

			//create new objects for new game
			if (Obj_Created == false) {


				system("cls");
				LoadMaps();
				GetPlayerName();
				You = Player(playerName);
				Obj_Created = true;
				Game_State = UPDATEMAP;
				playerLocation = 0;


				You.addItemToInventory(map_Ptr);
				You.addItemToInventory(lantern_Ptr);
				You.addItemToInventory(provisions_Ptr);
				You.addItemToInventory(sword_Ptr);
				You.addItemToInventory(potion_Ptr);
				///// End of adding items to inventory

			}

			//Pointer pointing to lantern and mnap objects address
			Item* lantern_Ptr = Get_Item_Ptr(*ptr_player_Inventory, item_ID::LANTERN);
			Item* map_Item_Ptr = Get_Item_Ptr(*ptr_player_Inventory, item_ID::MAP);


			while (Game_State == UPDATEMAP) {  
				
				//this game state is updating the map when leaving abattle or changing maps 

				//determine new room entered
				Location* map_ptr = &mapVector[playerLocation];

				//set player's current location the map in question
				You.SetPlayerCurrentLocation(*map_ptr);

				//pointer pointing to the obj, calls onto updatemap function()
				ptr_currentRoom_Location->UpdateMap();

				//make a copy of current room vector of MAP ART to print
				Current_Room_Map = ptr_currentRoom_Location->Return_charMap();

				//bool value if there is monster in room obj
				is_There_Monster_In_Room = ptr_currentRoom_Location->GetIsThereMonster();

				//bool value if there is item in room obj
				is_There_Item_In_Room = ptr_currentRoom_Location->GetIsThereItem();

				//visible exits for room obj
				currentRoom_VisibleExits = ptr_currentRoom_Location->GetVisibleExits();

				//setting the starting point in the room
				console.setX(27);
				console.setY(11);

				//updating the map
				console.updateMap(Current_Room_Map);
				map[11][27] = char(1);

				//resetting map variables
				console.setMonster_Encountr(false);
				console.set_exiting(false);
				console.setItem_Encounter(false);

				//update stats of player depending on item in inventory
				You.updateStats();

				//set the Gamestate to WALKING
				Game_State = WALKING;

			}
			while (Game_State == WALKING) {

				//update stats based on items in inventory
				You.updateStats();

				//check for any events happening (changing Map/Monster or item encounter)
				bool monster_Encountered = console.checkForEvent();
				bool item_Encountered = console.checkForItemFound();
				bool changingMap = console.checkForChangingMap();

				// if none of them are triggered than proceed with rendering the map
				if (changingMap == false) {

					if (monster_Encountered == false && item_Encountered == false) {

						system("cls");
						std::cout << "\n\n\t           Fuel: " << lantern_Ptr->GetAmount() << std::endl;
						std::cout << "\n\t     Location: " << ptr_currentRoom_Location->GetRoomName() << std::endl;
						std::cout << ptr_currentRoom_Location->GetDescription() << std::endl << std::endl;

						for (int i = 0; i < 23; i++) {
							std::cout << map[i] << std::endl;
						}
						//print player options

						printPlayerDetails_Walking();

						//if player wants to use nsew to move rather than moving one coord at a time
						if (legacyMoving == true) {
							RenderDirectionOptions(*ptr_currentRoom_Location);
						}
						else {
							std::cout << "\nPress [Y] if you woul like to use [N][S][E][W] to move";
						}
						system("pause>nul");
						if (GetAsyncKeyState(VK_UP) & 0x8000) { //if up arrow key is used
							console.Move(-1, 0);
						}
						if (GetAsyncKeyState(VK_DOWN) & 0x8000) { // if down arrow key is used
							console.Move(1, 0);
						}
						if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {  // if right arrow key is used
							console.Move(0, 1);
						}
						if (GetAsyncKeyState(VK_LEFT) & 0x8000) {  // if left arrow key is used
							console.Move(0, -1);
						}
						if (GetAsyncKeyState(VK_KEY_H) & 0x8000) {  //h used
							system("cls");
							DisplayHelp();
							std::cout << "\n\n\n Press any button to go back";
							system("pause>nul");
						}
						if (GetAsyncKeyState(VK_KEY_M) & 0x8000) {  // m used
							system("cls");
							std::cout << ptr_currentRoom_Location->getY();											//get x and y coordinates to update map item
							std::cout << ptr_currentRoom_Location->getX();
							map_Item_Ptr->UpdatePlayerLocationOnMap(ptr_currentRoom_Location->getX(), ptr_currentRoom_Location->getY());
							map_Item_Ptr->DisplayMapItem();															//showcase current location on the map
							system("pause>nul");
						}
						if (GetAsyncKeyState(VK_KEY_Q) & 0x8000) {													//quit to go back to main menu
							system("cls");
							std::cout << "game over!";
							Game_State = GAMEOVER;
							Play_Game = false;
							system("pause>nul");
						};
						if (GetAsyncKeyState(VK_KEY_I) & 0x8000) {													//change game state to inventory 
							Game_State = INVENTORY;
						}
						if (GetAsyncKeyState(VK_KEY_T) & 0x8000) {
							PrintStats_Art();																		//show stats of player
							ShowStats(You);
						}
						if (GetAsyncKeyState(VK_KEY_Y) & 0x8000)													// change movement to legacy type nsew
						{
							legacyMoving = true;
						}


											/////////////////////////////if legacy mode is chosen for movement///////////////////////////

						if (GetAsyncKeyState(VK_KEY_N) & 0x8000) {													

							if (legacyMoving == true) {

								if (ptr_currentRoom_Location->GetVisibleExits() != SWE) {
									console.set_exiting(true);
									console.set_exitingExit('N');
									Game_State = TRANSITION;
								}

							}
						}
						if (GetAsyncKeyState(VK_KEY_S) & 0x8000) {

							if (legacyMoving == true) {

								if (ptr_currentRoom_Location->GetVisibleExits() != WNE) {
									console.set_exiting(true);
									console.set_exitingExit('S');
									Game_State = TRANSITION;
								}

							}
						}
						if (GetAsyncKeyState(VK_KEY_E) & 0x8000) {

							if (legacyMoving == true) {

								if (ptr_currentRoom_Location->GetVisibleExits() != SWN) {
									console.set_exiting(true);
									console.set_exitingExit('E');
									Game_State = TRANSITION;
								}

							}
						}
						if (GetAsyncKeyState(VK_KEY_W) & 0x8000) {

							if (legacyMoving == true) {

								if (ptr_currentRoom_Location->GetVisibleExits() != SNE) {
									console.set_exiting(true);
									console.set_exitingExit('W');
									Game_State = TRANSITION;
								}

							}
						}


														////////set exit chosen and change the game state to transition///////

					}
					else if (monster_Encountered == true) {

						Game_State = MONSTER_ENCOUNTERED;
					}
					else if (item_Encountered == true) {
						Game_State = ITEM_ENCOUNTERED;
					}
				}
				else {
					Game_State = TRANSITION;

				}
			}
			while (Game_State == MONSTER_ENCOUNTERED) {

				bool option_Chosen = false;

				while (option_Chosen == false) {

					system("cls");
					RenderAskToFight(*ptr_monsterInRoom);
					system("pause>nul");

					if (GetAsyncKeyState(VK_KEY_F) & 0x8000) {
						option_Chosen = true;
						Game_State = IN_COMBAT;
					}
					if (GetAsyncKeyState(VK_KEY_R) & 0x8000) {
						option_Chosen = true;
						FleeSequence(You, *ptr_monsterInRoom);
						Game_State = UPDATEMAP;
					}

				}
			}
			while (Game_State == ITEM_ENCOUNTERED) {

				bool option_chosen = false;
				bool item_In_Inventory = false;
				std::string itemName = ptr_itemInRoom->GetItemName();
				std::vector<Item*>* inventory_ptr = You.GetPlayerInventory_Ptr();
				for (int i = 0; i < You.getSizeOfInventory(); i++) {
					if (itemName == (*inventory_ptr)[i]->GetItemName()) {
						item_In_Inventory = true;
					}
				}



				while (option_chosen == false) {
					system("cls");
					std::cout << "\n\n               Item: " << itemName << "\n";
					PrintLoot();
					PrintTakeOrDrop();
					system("pause>nul");
					if (GetAsyncKeyState(VK_KEY_T) & 0x8000) {

						if (item_In_Inventory == true) {

							if (ptr_itemInRoom->GetItemType() == Item_Type::MISC || ptr_itemInRoom->GetItemType() == Item_Type::CONSUMABLE) {

								int Item_Looking_For = 0;

								for (int index = 0; index < You.getSizeOfInventory(); index++) {
									if (itemName == (*inventory_ptr)[index]->GetItemName()) {
										Item_Looking_For = index;
									}
								}

								int AmountOfUsesNow = (*inventory_ptr)[Item_Looking_For]->GetAmount();
								int AmountToAdd = ptr_itemInRoom->GetAmount();
								int ResultingAmount = AmountOfUsesNow + AmountToAdd;
								(*You.GetPlayerInventory_Ptr())[Item_Looking_For]->SetAmount(ResultingAmount);

								ptr_itemInRoom->~Item();
								system("cls");
								std::cout << "\n\n\n\n\n\n              " << AmountToAdd << " " << itemName << "Added To Inventory!";
								system("pause>nul");

							}
							else {
								system("cls");
								std::cout << "\n\n\n\n\n\n    You Already Have That Item In Your Inventory! ";
								system("pause>nul");
							}
						}
						else {
							You.addItemToInventory(ptr_itemInRoom);
							ptr_itemInRoom->~Item();
							system("cls");
							std::cout << "\n\n\n\n\n\n                 Item Added To Inventory!";
							system("pause>nul");


						}

						mapVector[playerLocation].SetIsThereItem(false);
						option_chosen = true;

					}
					if (GetAsyncKeyState(VK_KEY_D) & 0x8000) {

						option_chosen = true;
						mapVector[playerLocation].SetIsThereItem(true);
					}

				}
				system("cls");
				Game_State = UPDATEMAP;

			}
			while (Game_State == INVENTORY) {
				system("cls");
				renderInventoryGraphic();
				DisplayInventory(*ptr_player_Inventory);
				Game_State = WALKING;
				system("pause>nul");
				if (GetAsyncKeyState(VK_KEY_E) & 0x8000) {
					if (elixirPresent == true) {
						Game_State == GAMEOVER;
					}
				}
				if (GetAsyncKeyState(VK_KEY_P) & 0x8000) {
					if (InvHasProvision == true) {

						Item* provision_Ptr = Get_Item_Ptr(*ptr_player_Inventory, item_ID::PROVISIONS);
						UseConsumable(*provision_Ptr, You);
						bool RanOutOfProvisions = Check_If_Empty(provision_Ptr);
						if (RanOutOfProvisions == true) {
							RemoveFromInv(*ptr_player_Inventory, *provision_Ptr);
							InvHasProvision = false;
							system("cls");
						}
						Game_State = INVENTORY;


					}
				}
				if (GetAsyncKeyState(VK_KEY_O) & 0x8000) {
					if (InvHasPotions == true) {

						Item* potion_Ptr = Get_Item_Ptr(*ptr_player_Inventory, item_ID::POTION_FLASK);
						UseConsumable(*potion_Ptr, You);
						bool RanOutOfPotions = Check_If_Empty(potion_Ptr);
						if (RanOutOfPotions == true) {
							RemoveFromInv(*ptr_player_Inventory, *potion_Ptr);
							InvHasPotions = false;
						}
						Game_State = INVENTORY;
					}

				}
				system("cls");
			}
			while (Game_State == IN_COMBAT) {

				printFightPrequel(*ptr_monsterInRoom, You);
				RenderOption();
				system("pause>nul");

				if (GetAsyncKeyState(VK_KEY_A) & 0x8000) {
					printFightPrequel(*ptr_monsterInRoom, You);
					Combat(You, *ptr_monsterInRoom);
					checkWhoWon(You, *ptr_monsterInRoom, Game_State, *ptr_currentRoom_Location);
					system("pause>nul");
				}

				if (GetAsyncKeyState(VK_KEY_F)) {
					FleeSequence(You, *ptr_monsterInRoom);
					Game_State = UPDATEMAP;
				}

				if (ptr_currentRoom_Location->GetIsThereMonster() == false) {
					mapVector[playerLocation].SetIsThereMonster(false);
				}
				system("cls");

			}
			while (Game_State == TRANSITION) {
				useLantern(lantern_Ptr);
				render_New_Map_Load();
				char exitChosen = console.ReturnExiting_Exit();
				for (int i = 0; i < ptr_currentRoom_Location->GetVisibleExits().size(); i++) {
					if (exitChosen == ptr_currentRoom_Location->GetVisibleExits()[i]) {
						playerLocation = ptr_currentRoom_Location->listOfConnectingExits()[i];
					}
				}
				Game_State = UPDATEMAP;

				bool haveAllArtefacts = false;
				Item* tome_Ptr = Get_Item_Ptr(*ptr_player_Inventory,item_ID::BALTHAZARS_SPELL_TOME);
				Item* battleAxe_Ptr = Get_Item_Ptr(*ptr_player_Inventory, item_ID::KRANGS_BATTLE_AXE);
				Item* chainMail_Ptr = Get_Item_Ptr(*ptr_player_Inventory, item_ID::KRANGS_CHAINMAIL);
				Item* speedBoots_Ptr = Get_Item_Ptr(*ptr_player_Inventory, item_ID::BOOTS_OF_SPEED);
				Item* elixir_Ptr = Get_Item_Ptr(*ptr_player_Inventory, item_ID::ELIXIR_MAXIMA);

				if (tome_Ptr != nullptr && battleAxe_Ptr != nullptr && chainMail_Ptr != nullptr && speedBoots_Ptr != nullptr && elixir_Ptr != nullptr) {
					haveAllArtefacts = true;
				}
				//must have all items

				bool AreThereStillMonsters = false;
				bool dragonDeafeated = false;

				if (mapVector[17].GetIsThereMonster() == false) {
					dragonDeafeated = true;
				}
				for (int i = 0; i < mapVector.size(); i++) {
					if (mapVector[i].GetIsThereMonster() == true) {
						AreThereStillMonsters = true;
					}
				}
				//if not complete artefacts and no more monsters reload map
				if (haveAllArtefacts == false && AreThereStillMonsters == false) {
					if (dragonDeafeated == false) {
						mapVector.clear();
						LoadMaps();
					}
					else {
						mapVector.clear();
						ReloadMapExceptForDragon();
					}
				}
				//win condition
				if (haveAllArtefacts == true && playerLocation == 0) {
					Game_State = WON;
				}

				//once collect all, set to 40 so they have to rush out as the cave will tubmle
				if (haveAllArtefacts == true) {
					lantern_Ptr->SetAmount(40);
				}




			}
			if (Game_State == GAMEOVER) {
				readFile("Art/Misc/Gameover.txt");
				Play_Game = false;
				Game_State = MENU;
				Obj_Created = false;
				system("pause>nul");
			}
			if (Game_State == WON) {
				system("cls");
				std::cout << "You Won!";
				Game_State = MENU;
				Obj_Created = false;
				system("pause>nul");
			}
			if (Game_State == QUITING) {
				exit(0);
			}

		}
	}
}