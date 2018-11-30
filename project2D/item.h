#pragma once
#include <string>
#include "Attack.h"
struct Item
{
	const char* name;
	int mCost;
	Item();
	Item(const char* nameofitem, int costofitem);
};