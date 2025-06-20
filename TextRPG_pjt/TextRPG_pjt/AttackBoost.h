#pragma once
#include "Item.h"

class AttackBoost : public Item
{
private:
	string name;
	int attackIncrease;
public:
	AttackBoost();
	virtual void Use(Character* character) override;
	virtual const string& getName() const override { return name; };
};

