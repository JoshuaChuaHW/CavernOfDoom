#ifndef LANTERN_H
#define LANTERN_H
#include "Item.h"

class Lantern :
    public Item
{
public:
    Lantern();
    int ConsumeLantern()override;
    void Consume()override;
    int GetAmount()override;
    void SetAmount(int var)override;
private:
    int fuel;
};

#endif // !LANTERN_H
