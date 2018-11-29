#include "Shop.h"
#include <vector>
#include <iostream>
Shop::Shop()
{
}

Shop::Shop(std::vector<DefenseItem> armor, std::vector<AttackItem> attack)
{
	armorstock = armor;
	attackstock = attack;
}

const char * Shop::speak(int num)
{
	const char* say;
	switch (shopstate)
	{
	case(welcome):
	{
		say = "Asher: Ah! Well if it isn't the warrior who dare challanges Dameon. How may I aid you today my suicidal friend?";
		return say;
	}
	case(viewAttackItems):
	{
		say = "Asher: Need a new move eh? I guess spamming the attack button wasn't enough?";
		return say;
	}
	case(viewDefenseItems):
	{
		say = "Asher: Please enjoy one of our mostly legal premium performance enhancing elixers.";
		return say;
	}
	case(viewUpgrades):
	{
		say = "Asher: So you need to get more physically fit? Hehe, why workout when you can pay me?";
		return say;
	}
	case(sell):
	{
		say = "Asher: Thank you,thank you! A fine choice my friend. Will you be buying more?";
		return say;
	}
	}
}

AttackItem Shop::sellattack(int choice)
{
	AttackItem item_Sold = attackstock.at(choice);
	item_Sold = nullitem;
	//attackstock.erase(attackstock.begin() + choice);
	return item_Sold;
}

DefenseItem Shop::selldefense(int choice)
{
	DefenseItem item_Sold = armorstock.at(choice);
	armorstock.erase(armorstock.begin() + choice);
	return item_Sold;
}

const char* Shop::viewAttacks(int num)
{
	const char* say;
	if (attackstock.at(num) == nullitem)
	{
		shopstate = bought;
		say = "Sold Out";
		return say;
	}
	else
	{
		say = attackstock.at(num).name;
		return say;
	}
}

const char* Shop::viewArmor(int num)
{
	const char* say;
	if (num > armorstock.size())
	{
		say = "Sold Out";
		return say;
	}
	else
	{
		say = armorstock.at(num).name;
		return say;
	}
}

void Shop::draw(aie::Renderer2D*renderer, int timer,aie::Font* font)
{
	renderer->setUVRect(0.f, 0.f, 1, 1);
	renderer->drawSprite(shop, 600, 450, 500, 583);

	renderer->drawSprite(hero, 600, 400, 57, 92);

	renderer->setUVRect(int(timer * 10) % 3 / 2.9f, 0.f, .33, 1);
	renderer->drawSprite(shopkeep, 600, 720 - 70, 38, 54);
	//, 300, 100, 100);
	switch (shopstate)
	{
	case(welcome):
	{
		renderer->drawText(font,"Asher: Ah! Well if it isn't the warrior who dare challanges Dameon. How may I aid you today?", 300, 100, 100);
		return;
	}
	case(viewAttackItems):
	{
		renderer->drawText(font, "Asher: Need a new move eh? I guess spamming the attack button wasn't enough?", 300, 100, 100);
		return;
	}
	case(viewDefenseItems):
	{
		renderer->drawText(font, "Asher: Please enjoy one of our mostly legal premium performance enhancing elixers.", 300, 100, 100);
		return;
	}
	case(viewUpgrades):
	{
		renderer->drawText(font, "Asher: So you need to get more physically fit? Hehe, why workout when you can pay me?", 300, 100, 100);
		return;
	}
	case(sell):
	{
		renderer->drawText(font, "Asher: Thank you,thank you! A fine choice my friend. Will you be buying more?", 300, 100, 100);
		return;
	}
	case bought:
	{
		renderer->drawText(font, "Asher: Im all out of that right now. ", 300, 100, 100);
		return;
	}
	}
}


