#ifndef POTION_H
#define POTION_H

#include "Item.h"
class Potion :
    public Item
{
public:
    Potion();
    void Consume()override;
    int GetAmount()override;
    void SetAmount(int var)override;
    int GetItemHealth() override;
private:
    int amount;
};


#endif // !POTION_H