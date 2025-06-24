//Monster.cpp
#include "Monster.h"
#include <iostream>
#include "UI.h"

Monster::Monster(const std::string& name, int health, int attack) : name_(name), health_(health), attack_(attack)
{

}


std::string Monster::GetName() const
{
	return name_;
}
int Monster::GetHealth() const
{
	return health_;
}
int Monster::GetAttack() const
{
	return attack_;
}

void Monster::TakeDamage(int damage)
{
	UI* InterFace = UI::getInstance();
	health_ -= damage;
	if (health_ > 0)
	{
		InterFace->AddBattleLog(name_ + " : [체력]: " + to_string(damage) + " : 감소했습니다!");
		InterFace->AddBattleLog(name_ + " : [체력] : " + to_string(health_) + " : 남았습니다! ");
	}
	if (health_ <= 0)
	{
		health_ = 0;
		InterFace->AddBattleLog(name_ + " : [체력] : 0 : 남았습니다! ");
		InterFace->AddBattleLog(GetName() + " 죽었습니다!");
	}
}

//레벨당 체력 공격력 조정 (플레이어 레벨)
void Monster::SetHealth(int playerLevel)
{

	health_ = health_ * (playerLevel);
	attack_ = attack_ * (playerLevel);

}
//레벨당 체력 공격력 조정 (플레이어 레벨 + 적용 퍼센트)
void Monster::SetHealth(int playerLevel, int randomPer)
{
	health_ = (health_*(playerLevel))* randomPer;
	attack_ = (attack_ * (playerLevel)) * randomPer;
}

//레벨당 체력 공격력 조정 (플레이어 레벨 + 적용 퍼센트Hp + 적용 퍼센트 Atk)
void Monster::SetHealth(int playerLevel, float  randomPerHp, float  randomPerAtk)
{
	health_ = (health_ * (playerLevel)) * randomPerHp;
	attack_ = (attack_ * (playerLevel)) * randomPerAtk;
}
