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
	~Shop();
	void displayItems(Character* player);
	void displayBuyMenu(Character* player);
	void displaySellMenu(Character* player);
	void showMain(Character* player);
	void showSell(Character* player);
	void showBuy(Character* player);

	void buyItem(const int& slotNum, Character* player);
	void sellItem(const int& slotNum, Character* player);
	Item* createItemType(const ItemCode& code);
};

