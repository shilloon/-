#include <iostream>
#include "Enemy.h"

Enemy::Enemy(int hp, int ad, std::string name, bool named) : Actor(hp, ad, name) {

	Named = named;

}

void Enemy::Damaged(int damage) {

	if (Named) {

		std::cout << "울부짖으며," << std::endl;

	}
	std::cout << "감히 나를 때렸겠다?" << std::endl;

	Actor::Damaged(damage);

}

void Enemy::Move(bool front) {

	if (front) {

		Position--;

	}
	else {

		Position++;

	}
}