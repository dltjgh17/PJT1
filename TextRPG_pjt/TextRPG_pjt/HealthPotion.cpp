#include "HealthPotion.h"
#include "Character.h"

HealthPotion::HealthPotion()
{
	this->healthRestore = 50;
	this->name = "Healing Potion";
	this->toolTip = "Restore 50 HP";
	this->sellPrice = 20;
	this->buyPrice  = 50;
}

void HealthPotion::Use(Character* character)
{
	character->heal(healthRestore);
}
