#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	this->name = "Berserker Tincture";
	this->attackIncrease = 10;
}

void AttackBoost::Use(Character* character)
{
	character->takeDamage(attackIncrease);
}