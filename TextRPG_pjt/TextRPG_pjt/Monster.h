#pragma once

//Monster.h
#ifndef Monster_H
#define Monster_H

#include <string>


class Monster
{
public:
	Monster(const std::string& name, int health, int attack);

	std::string GetName() const;
	int GetHealth() const;
	int GetAttack() const;

	void TakeDamage(int damage);

	void SetHealth(int playerLevel);

protected:
	std::string name_;
	int health_;
	int attack_;

};




#endif // !monster_H




