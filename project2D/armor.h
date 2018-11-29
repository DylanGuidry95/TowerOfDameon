#pragma once
#include "Character.h"
#include <string>
struct Armor
{
	const char* name;
	float defenseBoost;
	float health_Value;
	float strength_Value;
	Armor();
	Armor(const char* name,float defense, float health, float strength);
};