#pragma once
#include "Item.h"
#include "Character.h"
#include <string>

class AttackBoost : public Item
{
private:
	string name;
	int attackIncrease;
public:
	AttackBoost();
	virtual void Use(Character* character) override;
	virtual const std::string& getName() const override { return name; }
};

