#pragma once
#include "Item.h"
#include "Character.h"
#include <string>

class AttackBoost : public Item
{
private:
	string name;
	string toolTip;
	int attackIncrease;
	int sellPrice;
	int buyPrice;

public:
	AttackBoost();
	virtual void Use(Character* character) override;
	virtual const std::string& getName() const override { return name; }
	virtual const std::string& getToolTip() const override { return toolTip; }
	virtual const int& getSellPrice() const override { return sellPrice; }
	virtual const int& getBuyPrice() const override { return buyPrice; }
};

