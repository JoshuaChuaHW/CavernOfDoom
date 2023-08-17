#ifndef MAP_H
#define MAP_H
#include "Item.h"
#include <fstream>


class Map :
    public Item
{
public:
    Map();
    void UpdatePlayerLocationOnMap(int x, int y) override;
    void DisplayMapItem() override;



private:
    char map_Showcase[35][121];
    std::vector<std::string> map_ShowCase_Vector;
    char map_Showcase_Updated[35][121];


};

#endif // !MAP_H
