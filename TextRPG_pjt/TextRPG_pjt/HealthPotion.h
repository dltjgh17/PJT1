#pragma once
#include "Item.h"
// #include "Character.h"
#include <string>

class HealthPotion : public Item
{
private:
	string name;
	int healthRestore;

public:
	virtual ~Item() {}
	virtual void Use() override;
	virtual const string& getName() const override { return name; };
};

