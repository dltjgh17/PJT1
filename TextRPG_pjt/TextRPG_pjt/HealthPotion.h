#pragma once
#include "Item.h"
#include "Character.h"
#include <string>

class HealthPotion : public Item
{
private:
	string name;
	int healthRestore;

public:
	HealthPotion();
	virtual void Use(Character* character) override;
	virtual const std::string& getName() const override { return name; }
};

