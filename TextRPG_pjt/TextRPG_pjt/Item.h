#pragma once
#include <string>

class Character;
class Item
{
public:
	virtual ~Item() {}
	virtual void Use(Character* character) = 0;
	virtual const std::string& getName() const = 0;
	virtual const std::string& getToolTip() const = 0;
	virtual const int& getSellPrice() const = 0;
	virtual const int& getBuyPrice() const = 0;
};