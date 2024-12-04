#include "Character.h"
#include "Enemy.h"
#include <iostream>

void main() {

	Character* character = new Character(20, 3);

	for (int i = 0; i < 3; i++) {

		Enemy* enemy = nullptr;
		switch (i) {

			case 0:
				enemy = new Enemy(3, 1, "���", false);
				std::cout << "����� �������ϴ�." << std::endl;
				break;
			case 1:
				enemy = new Enemy(5, 3, "����Ʈ", true);
				std::cout << "����Ʈ�� �������ϴ�." << std::endl;
				break;
			case 2:
				enemy = new Enemy(5, 6, "����", true);
				std::cout << "������ �������ϴ�." << std::endl;
				break;

		}

		enemy->SetPosition(5);

		character->SetPosition(0);

		while (enemy != nullptr) {

			std::cout << "�� ��ġ: " << character->GetPosition() << "�� ��ġ: " << enemy->GetPosition() << std::endl;

			char input;
			std::cout << "�ൿ�� �������ּ���" << std::endl;

			std::cin >> input;

			if (input == 'e') {

				std::cout << "�����ƽ��ϴ�" << std::endl;
				break;

			}

			else if (input == 'a') {

				if (enemy->GetPosition() == character->GetPosition() + 1) {

					character->Attack(enemy);
			
				}
				else {

					std::cout << "������ ������ ���� �ʽ��ϴ�." << std::endl;

				}
			}

			else if (input == 'f') {

				if (enemy->GetPosition() > character->GetPosition() + 1) {

					character->Move(true);

				}
				else {

					std::cout << "���� ���θ����ֽ��ϴ�" << std::endl;

				}

			}

			else if (input == 'b') {

				if (0 < character->GetPosition()) {

					character->Move(false);

				}
				else {

					std::cout << "���ٸ� ����Դϴ�." << std::endl;

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
	std::cout << "���� ��" << std::endl;
}