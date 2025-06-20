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
	// 구매 상점
	int choice = 1;
	while (choice)
	{
		system("cls");
		cout << "============================" << endl;
		cout << "        Item Shop           " << endl;
		cout << "============================" << endl;
		cout << "Gold: " << player->getGold() << "G" << endl;
		for (int i = 0; i < availableItems.size(); i++)
		{
			cout << "[" << i + 1 << "] " << availableItems[i]->getName() << " (" << availableItems[i]->getBuyPrice() << ") - " << availableItems[i]->getToolTip() << endl;
		}
		cout << "[0] Exit Shop" << endl;

		cout << "\nChoose an item to buy: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			return;

		case 1:
			if (50 <= player->getGold())
			{
				Item* item = new HealthPotion();
				player->addItem(item);
				player->addGold(-50);
			}
			else
			{
				cout << "Not enough gold." << endl;
			}
			break;

		case 2:
			if (120 <= player->getGold())
			{
				Item* item = new AttackBoost();
				player->addItem(item);
				player->addGold(-120);
			}
			else
			{
				cout << "Not enough gold." << endl;
			}
			break;

		default:
			cout << "Invalid input. Please try again." << endl;
			break;
		}

		// 엔터를 누르면 계속 진행
		cout << "\nPress Enter to Continue...";
		cin.ignore();
		cin.get();
	}
}

void Shop::byItem(int slotNum, Character* player)
{
}

void Shop::sellItem(int slotNum, Character* player)
{
}
