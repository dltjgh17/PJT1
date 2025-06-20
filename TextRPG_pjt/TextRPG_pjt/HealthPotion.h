#pragma once
#include "Item.h"

class HealthPotion : public Item
{
private:
	string name;
	int healthRestore;

public:
	HealthPotion();
	virtual void Use(Character* character) override;
	virtual const string& getName() const override { return name; };
};

