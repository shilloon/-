#pragma once
#include <string>

class Actor {

public:
	Actor(int hp, int ad, std::string name);
	void SetPosition(int Postion);
	int GetPosition();
	int GetHP();
	virtual void Damaged(int damage);
	virtual void Attack(Actor* hit);
	virtual void Move(bool front);
	~Actor();
protected:
	std::string Name;
	int HP;
	int AD;
	int Position;
};