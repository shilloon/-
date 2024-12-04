#include "Character.h"
#include <iostream>

Character::Character(int hp, int ad) : Actor(hp, ad, "���") {

	Healcount = 0;

}

void Character::Damaged(int damage) {

	std::cout << damage << "�� �������� �Ծ���!" << std::endl;
	std::cout << "����ü��" << ((HP - damage) > 0 ? HP - damage : 0) << std::endl;
	Actor::Damaged(damage);

}

void Character::Heal() {

	if (Healcount < 3) {

		HP += HealSlot[Healcount];
		Healcount++;
		std::cout << HealSlot[Healcount - 1] << "�� ȸ���ߴ�! ���� ȸ��Ƚ��" << 3 - Healcount << std::endl;

	}
	else {
		
		std::cout << "ȸ���� �� �� ���ȴ�!" << 3 - Healcount << std::endl;

	}
}