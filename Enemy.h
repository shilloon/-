#pragma once
#include "Actor.h"

class Enemy : public Actor {

public:
	Enemy(int hp, int ad, std::string name, bool named);
	bool Named;
	void Damaged(int damage) override;
	void Move(bool front) override;

};