#pragma once
#include <string>
struct Attack
{
	const char*name;
	float mDamage;
	int usage;
	Attack()
	{

	}
	Attack(const char* othername, float damage,int usagenum)
	{
		name = othername;
		mDamage = damage;
		usage = usagenum;
	}
};