#include "item.h"

Item::Item()
{
}

Item::Item(const char* nameofitem,  int costofitem)
{
	name = nameofitem;
	mCost = costofitem;
}
