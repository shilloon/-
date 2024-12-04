#include "Character.h"
#include <iostream>

Character::Character(int hp, int ad) : Actor(hp, ad, "용사") {

	Healcount = 0;

}

void Character::Damaged(int damage) {

	std::cout << damage << "의 데미지를 입었다!" << std::endl;
	std::cout << "남은체력" << ((HP - damage) > 0 ? HP - damage : 0) << std::endl;
	Actor::Damaged(damage);

}

void Character::Heal() {

	if (Healcount < 3) {

		HP += HealSlot[Healcount];
		Healcount++;
		std::cout << HealSlot[Healcount - 1] << "를 회복했다! 남은 회복횟수" << 3 - Healcount << std::endl;

	}
	else {
		
		std::cout << "회복을 다 써 버렸다!" << 3 - Healcount << std::endl;

	}
}