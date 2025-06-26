#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	this->name = "공격력 증가 포션";
	this->toolTip = "공격력 10증가";
	this->attackIncrease = 10;
	this->buyPrice = 120;
	this->sellPrice = 60;
	this->itemCode = static_cast<int>(ItemCode::ITEM_ATTACK_BOOST);
}

void AttackBoost::Use(Character* character)
{
	character->increaseAtk(attackIncrease);
}