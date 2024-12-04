#pragma once
#include "Actor.h"

class Character : public Actor
{
public:
	Character(int hp, int ad);
	void Damaged(int damamge) override;
	void Heal();

private:
	int Healcount;
	int HealSlot[3] = { 3, 2, 1 };
};