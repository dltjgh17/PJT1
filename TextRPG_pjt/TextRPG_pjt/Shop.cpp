#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

#include <iostream>

using namespace std;

Shop::Shop()
{
	Item* slot1 = new HealthPotion;
	Item* slot2 = new AttackBoost;
	availableItems.push_back(slot1);
	availableItems.push_back(slot2);
}

void Shop::displayItems(Character* player)
{
	// ���� ����
	int choice = 1;
	while (choice)
	{
		system("cls");
		cout << "============================" << endl;
		cout << "             ����            " << endl;
		cout << "============================" << endl;
		cout << "���� ���� ��� : " << player->getGold() << "G" << endl;
		cout << "[1] ���" << endl;
		cout << "[2] �ȱ�" << endl;
		cout << "[0] ���� ������" << endl;

		cin >> choice;

		if (choice == 1)
		{
			displayBuyMenu(player);
		}
		else if (choice == 2)
		{
			displaySellMenu(player);
		}
	}
}

void Shop::displayBuyMenu(Character* player)
{
	int choice = 1;
	while (choice)
	{
		system("cls");
		cout << "============================" << endl;
		cout << "      ���� ������ ����â      " << endl;
		cout << "============================" << endl;
		cout << "���� ���� ��� : " << player->getGold() << "G" << endl;
		for (int i = 0; i < availableItems.size(); i++)
		{
			cout << "[" << i + 1 << "] " << availableItems[i]->getName() << " (" << availableItems[i]->getBuyPrice() << "G) - " << availableItems[i]->getToolTip() << endl;
		}
		cout << "[0] ���� �޴��� ���ư���" << endl;

		cout << "\n ������ �������� �����ϼ��� : ";
		cin >> choice;

		//�����۱���ó��//
		if (0 < choice && choice <= availableItems.size())
		{
			if (player->getGold() >= availableItems[choice - 1]->getBuyPrice())
			{
				buyItem(choice - 1, player);
			}
			else
			{
				cout << "��尡 �����մϴ�!" << endl;
			}
			// ���͸� ������ ��� ����
			cout << "\n �ƹ� Ű�� ���� ��� �����ϼ���...";
			cin.ignore();
			cin.get();
		}
	}
}


void Shop::displaySellMenu(Character* player)
{
	int choice = 1;
	while (choice)
	{
		vector<Item*> inven = player->getInventory();
		system("cls");
		cout << "============================" << endl;
		cout << "         ������ �Ǹ�â       " << endl;
		cout << "============================" << endl;
		cout << "          �� �κ��丮        " << endl;
		cout << "============================" << endl;
		cout << "���� ���� ��� : " << player->getGold() << "G" << endl;

		if (!inven.size()) // �κ��� �� ���
		{
			cout << "������ �ִ� �������� �����ϴ�." << endl;
		}
		else 
		{
			for (int i = 0; i < inven.size(); i++)
			{
				cout << "[" << i + 1 << "] " << inven[i]->getName() << " (" << inven[i]->getSellPrice() << "G) - " << inven[i]->getToolTip() << endl;
			}
		}
		cout << "[0] ���� �޴��� ���ư���" << endl;
		cout << "\n�Ǹ��� �������� ������ : ";
		cin >> choice;

		// ������ �ε����� ������ �Ǹ� �Լ� ȣ��
		if (choice > 0 && 0 < inven.size() && choice <= inven.size()) // �κ��丮�� ������� ��� �κ��丮�� ���� ���ϵ��� ����ó��
		{
			player->addGold(inven[choice - 1]->getSellPrice()); // �ǸŽ� ��� ����
			sellItem(choice, player); // �κ��丮���� ����
		}
		// ���͸� ������ ��� ����
		cout << "\n�ƹ� Ű�� ������ ��� �����ϼ���...";
		cin.ignore();
		cin.get();
	}
}

void Shop::buyItem(const int& slotNum, Character* player)
{
	Item* item = createItemType(availableItems[slotNum]->getItemCode());

	player->addGold(-availableItems[slotNum]->getBuyPrice());
	player->addItem(item);
}

void Shop::sellItem(const int& slotNum, Character* player)
{
	if (!player->getInventory().empty()) // �κ��丮�� �� ������ �ƴѰ��
	{
		player->removeItem(slotNum); // �ε��� ��ġ�� ������ ���� �Լ� ȣ��
	}
}

Item* Shop::createItemType(const ItemCode& code)
{
	switch (code)
	{
	case ItemCode::ITEM_HEALTH_POTION: return new HealthPotion();
	case ItemCode::ITEM_ATTACK_BOOST: return new AttackBoost();
	// ��� �߰�
	default: return nullptr;
	}
	return nullptr;
}
