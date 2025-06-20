#pragma once
#include <vector>
#include "Item.h"
class Shop
{
private:
	vector<Item*> availableItems;

public:
	Shop();
	void displayItems(Character* player);
	void byItem(int slotNum, Character* player);
	void sellItem(int slotNum, Character* player);
};

