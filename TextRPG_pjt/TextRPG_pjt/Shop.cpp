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
		cout << "        Item Shop           " << endl;
		cout << "============================" << endl;
		cout << "Gold: " << player->getGold() << "G" << endl;
		cout << "[1] Buy" << endl;
		cout << "[2] Sell" << endl;
		cout << "[0] Exit Shop" << endl;

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
		cout << "       Item Shop(Buy)       " << endl;
		cout << "============================" << endl;
		cout << "Gold: " << player->getGold() << "G" << endl;
		for (int i = 0; i < availableItems.size(); i++)
		{
			cout << "[" << i + 1 << "] " << availableItems[i]->getName() << " (" << availableItems[i]->getBuyPrice() << ") - " << availableItems[i]->getToolTip() << endl;
		}
		cout << "[0] Back to main menu" << endl;

		cout << "\nChoose an item to buy: ";
		cin >> choice;

		// ���͸� ������ ��� ����
		cout << "\nPress Enter to Continue...";
		cin.ignore();
		cin.get();
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
		cout << "       Item Shop(Sell)      " << endl;
		cout << "============================" << endl;
		cout << "          Inventory         " << endl;
		cout << "============================" << endl;
		cout << "Gold: " << player->getGold() << "G" << endl;
		if (!inven.size()) // �κ��� �� ���
		{
			cout << "Your inventory is empty." << endl;
		}
		else 
		{
			for (int i = 0; i < inven.size(); i++)
			{
				cout << "[" << i + 1 << "] " << inven[i]->getName() << " (" << inven[i]->getSellPrice() << ") - " << inven[i]->getToolTip() << endl;
			}
		}
		cout << "[0] Back to main menu" << endl;
		cout << "\nChoose an item to Sell: ";
		cin >> choice;

		// ������ �ε����� ������ �Ǹ� �Լ� ȣ��
		if (choice > 0 && 0 < inven.size() && choice <= inven.size()) // �κ��丮�� ������� ��� �κ��丮�� ���� ���ϵ��� ����ó��
		{
			player->addGold(inven[choice - 1]->getSellPrice()); // �ǸŽ� ��� ����
			sellItem(choice - 1, player); // �κ��丮���� ����
		}
		// ���͸� ������ ��� ����
		cout << "\nPress Enter to Continue...";
		cin.ignore();
		cin.get();
	}
}

void Shop::byItem(const int& slotNum, Character* player)
{
	Item* item = new HealthPotion();
	player->addItem(item);
	player->addGold(-50);
}

void Shop::sellItem(const int& slotNum, Character* player)
{
	if (!player->getInventory().empty()) // �κ��丮�� �� ������ �ƴѰ��
	{
		player->removeItem(slotNum); // �ε��� ��ġ�� ������ ���� �Լ� ȣ��
	}
}