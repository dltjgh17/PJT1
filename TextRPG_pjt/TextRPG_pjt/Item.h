#pragma once
#include <string>

enum class ItemCode
{
	ITEM_HEALTH_POTION = 1001,
	ITEM_ATTACK_BOOST = 1002,
};

class Character;
class Item
{
public:
	virtual ~Item() {}
	virtual void Use(Character* character) = 0;
	virtual const std::string& getName() const = 0;
	virtual const std::string& getToolTip() const = 0;
	virtual const ItemCode& getItemCode() const = 0;
	virtual const int& getSellPrice() const = 0;
	virtual const int& getBuyPrice() const = 0;
};