//Monster.cpp
#include "Monster.h"
#include <iostream>
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
        
	}

	//로그 처리 필요한지?
}


void Monster::SetHealth(int playerLevel)
{
	health_ *= playerLevel;
}
