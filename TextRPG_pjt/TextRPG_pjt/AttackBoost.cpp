#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	this->name = "Berserker Tincture";
	this->toolTip = "+10 Attack";
	this->attackIncrease = 10;
	this->buyPrice = 120;
	this->sellPrice = 60;
}

void AttackBoost::Use(Character* character)
{
	character->increaseAtk(attackIncrease);
}