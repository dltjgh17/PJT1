#include "HealthPotion.h"
#include "Character.h"

HealthPotion::HealthPotion()
{
	this->healthRestore = 50;
	this->name = "체력 회복 포션";
	this->toolTip = "체력 50 회복";
	this->sellPrice = 20;
	this->buyPrice  = 50;
}

void HealthPotion::Use(Character* character)
{
	character->heal(healthRestore);
}
	