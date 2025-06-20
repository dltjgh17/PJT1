#pragma once
#include "Item.h"
#include "Character.h"
#include <vector>
class Shop
{
private:
	vector<Item*> availableItems;

public:
	Shop();
	void displayItems(Character* player);
	void displayBuyMenu(Character* player);
	void displaySellMenu(Character* player);

	void byItem(const int& slotNum, Character* player);
	void sellItem(const int& slotNum, Character* player);

};

