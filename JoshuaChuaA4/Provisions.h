#ifndef PROVISIONS_H
#define PROVISIONS_H


#include "Item.h"
class Provisions :
    public Item
{
public:
    Provisions();
    void Consume()override;
    int GetAmount()override;
    void SetAmount(int var)override;
    int GetItemHealth() override;
private:
    int amount;
};




#endif // !PROVISIONS_H