#pragma once
#include <string>

class Character
{
private:
	int health;
	int attack;
public:
	void heal(int amount) {};
	void takeDamage(int amount) {};
};

using namespace std;

class Item
{
public:
	virtual ~Item() {}
	virtual void Use(Character* character) = 0;
	virtual const string& getName() const = 0;
};