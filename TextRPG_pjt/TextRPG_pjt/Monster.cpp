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
	health_ -= damage;
	if (health_ < 0)
	{
		health_ = 0;

		UI* ui = UI::getInstance();
		std::vector<std::string>* BattleLogPtr = ui->GetBattleLogPtr();
		ui->AddFullLog(GetName() + "이(가) " + "죽었습니다!");
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
void Monster::SetHealth(int playerLevel, int randomPerHp, int randomPerAtk)
{
	health_ = (health_ * (playerLevel)) * randomPerHp;
	attack_ = (attack_ * (playerLevel)) * randomPerAtk;
}
