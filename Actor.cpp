#include "Actor.h"
#include <iostream>

Actor::Actor(int hp, int ad, std::string name) {

	HP = hp;
	AD = ad;
	Name = name;
	Position = 0;
}

void Actor::SetPosition(int position) {

	Position = position;

}

int Actor::GetPosition() {

	return Position;

}

int Actor::GetHP() {

	return HP;

}

void Actor::Damaged(int damage) {

	HP -= damage;

}

void Actor::Attack(Actor* hit) {

	hit->Damaged(AD);

}

void Actor::Move(bool front) {

	if (front) {

		Position += 1;

	}
	else {

		Position -= 1;

	}
}

Actor::~Actor() {
	std::cout << Name << "ав╢ы" << std::endl;
}