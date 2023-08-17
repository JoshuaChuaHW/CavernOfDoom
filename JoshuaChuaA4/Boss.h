#ifndef BOSS_H
#define BOSS_H
#include"Monster.h"



class Boss :public Monster

{

private:
	int specialDamage;
	bool specialAttackUsed;

public:


	Boss(int Location);
	Boss();
	~Boss();
	int SpecialAttack()override;

	bool GetIfSpecialAttackused() override;
};

#endif // !BOSS_H
