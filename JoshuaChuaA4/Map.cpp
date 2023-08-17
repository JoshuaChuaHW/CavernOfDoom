#include "Map.h"


Map::Map() {

	itemID = item_ID::MAP;
	itemType = Item_Type::MAP;
	name = "MAP";
	map_ShowCase_Vector = {};

	std::ifstream fileToRead("Art/Misc/MapShowcase.txt");
	if (fileToRead.is_open()) {
		std::string line = "";
		while (!fileToRead.eof()) {
			getline(fileToRead, line);
			map_ShowCase_Vector.push_back(line);
		}
	}
	else {
		std::cout << "\nFile Not Found.\n";
	}
	//close file
	fileToRead.close();



	for (int row = 0; row < 34; row++) {
		std::string line = map_ShowCase_Vector[row];
		for (int column = 0; column < 120; column++) {
			map_Showcase[row][column] = line[column];
		}
	}
}








void Map::UpdatePlayerLocationOnMap(int x, int y) {
	for (int row = 0; row < 34; row++) {
		for (int column = 0; column < 120; column++) {
			map_Showcase_Updated[row][column] = map_Showcase[row][column];
		}
	}
	map_Showcase_Updated[y][x] = char(1);
}

void Map::DisplayMapItem() {
	for (int i = 0; i < 34; i++) {
		std::cout << map_Showcase_Updated[i] << std::endl;
	}
}