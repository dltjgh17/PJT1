#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "Healing Potion";
	healthRestore = 50;
}

void HealthPotion::Use(Character* character)
{
	character->heal(healthRestore);
}
