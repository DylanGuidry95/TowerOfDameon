#include "armor.h"

Armor::Armor()
{
}

Armor::Armor(const char* othername, float defense, float health, float strength)
{
	name = othername;
	defenseBoost = defense;
	health_Value = health;
	strength_Value = strength;
}
