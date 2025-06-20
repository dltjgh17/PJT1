#pragma once
#include "Item.h"
#include "Character.h"
#include <string>

class HealthPotion : public Item
{
private:
	string name;
	string toolTip;
	int healthRestore;
	int sellPrice;
	int buyPrice;


public:
	HealthPotion();
	virtual void Use(Character* character) override;
	virtual const std::string& getName() const override { return name; }
	virtual const std::string& getToolTip() const override { return toolTip; }
	virtual const int& getSellPrice() const override { return sellPrice; }
	virtual const int& getBuyPrice() const override { return buyPrice; }
};

