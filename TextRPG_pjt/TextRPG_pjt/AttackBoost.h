#pragma once
#include "Item.h"
class AttackBoost : public Item
{
private:
	string name;
	int attackIncrease;
public:
	virtual void Use() override;
	virtual const string& getName() const override { return name; };
};

