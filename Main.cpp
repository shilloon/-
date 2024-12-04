#include "Character.h"
#include "Enemy.h"
#include <iostream>

void main() {

	Character* character = new Character(20, 3);

	for (int i = 0; i < 3; i++) {

		Enemy* enemy = nullptr;
		switch (i) {

			case 0:
				enemy = new Enemy(3, 1, "잡몹", false);
				std::cout << "잡몹을 만났습니다." << std::endl;
				break;
			case 1:
				enemy = new Enemy(5, 3, "엘리트", true);
				std::cout << "엘리트를 만났습니다." << std::endl;
				break;
			case 2:
				enemy = new Enemy(5, 6, "보스", true);
				std::cout << "보스를 만났습니다." << std::endl;
				break;

		}

		enemy->SetPosition(5);

		character->SetPosition(0);

		while (enemy != nullptr) {

			std::cout << "내 위치: " << character->GetPosition() << "적 위치: " << enemy->GetPosition() << std::endl;

			char input;
			std::cout << "행동을 선택해주세요" << std::endl;

			std::cin >> input;

			if (input == 'e') {

				std::cout << "도망쳤습니다" << std::endl;
				break;

			}

			else if (input == 'a') {

				if (enemy->GetPosition() == character->GetPosition() + 1) {

					character->Attack(enemy);
			
				}
				else {

					std::cout << "공격을 했으나 닿지 않습니다." << std::endl;

				}
			}

			else if (input == 'f') {

				if (enemy->GetPosition() > character->GetPosition() + 1) {

					character->Move(true);

				}
				else {

					std::cout << "적이 가로막고있습니다" << std::endl;

				}

			}

			else if (input == 'b') {

				if (0 < character->GetPosition()) {

					character->Move(false);

				}
				else {

					std::cout << "막다른 골목입니다." << std::endl;

				}
			}

			else if (input == 'h') {

				character->Heal();

			}

			if (enemy->GetHP() <= 0) {

				delete(enemy);
				enemy = nullptr;

			}

			if (enemy == nullptr) {

				break;

			}

			if (enemy->GetPosition() == character->GetPosition() + 1) {

				enemy->Attack(character);

			}
			else {

				enemy->Move(true);

			}

			if (character->GetHP() <= 0) {

				delete(character);
				character = nullptr;

			}

			if (character == nullptr) {

				break;

			}

		}

		if (character == nullptr) {

			break;

		}

	}
	std::cout << "게임 끝" << std::endl;
}