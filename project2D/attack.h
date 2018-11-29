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
	Attack(const char* othername, float number,int usagenum)
	{
		name = othername;
		mDamage = number;
		usage = usagenum;
	}
};