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
	int choice = 1;
	while (choice)
	{
		system("cls");
		cout << "============================" << endl;
		cout << "        Item Shop           " << endl;
		cout << "============================" << endl;
		cout << "Gold: " << player->getGold() << "G" << endl;
		cout << "[1] Healing Potion (50G) - Restore 50 HP" << endl;
		cout << "[2] Berserker Tincture (120G) - +10 Attack" << endl;
		cout << "[0] Exit Shop" << endl;

		cout << "\nChoose an item to buy: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			return;
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			cout << "Invalid input. Please try again.";
			break;
		}
	}
}

void Shop::byItem(int slotNum, Character* player)
{
}

void Shop::sellItem(int slotNum, Character* player)
{
}
