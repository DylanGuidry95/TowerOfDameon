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

AttackItem Shop::sellattack(int choice)
{
	AttackItem item_Sold = attackstock.at(choice);
	attackstock.erase(attackstock.begin() + choice);
	attackstock.resize(attackstock.size() - 1);
	return item_Sold;
}

DefenseItem Shop::selldefense(int choice)
{
	DefenseItem item_Sold = armorstock.at(choice);
	armorstock.erase(armorstock.begin() + choice);
	armorstock.resize(armorstock.size() - 1);
	return item_Sold;
}

const char* Shop::viewAttacks(int num)
{
	const char* say;
	if (attackstock.size() <= num)
	{
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
	if (armorstock.size() - 1 < num)
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

int Shop::getstocksize(int choice)
{
	switch (choice)
	{
	case 1:
	{
		return attackstock.size();
	}
	case 2:
	{
		return armorstock.size();
	}
	}
}

void Shop::draw(aie::Renderer2D*renderer, int timer, aie::Font* font)
{
	renderer->setUVRect(0.f, 0.f, 1, 1);
	renderer->drawSprite(shop, 600, 450, 500, 583);

	renderer->drawSprite(hero, 600, 400, 57, 92);


	drawtext(renderer, font);
	drawsprite(renderer, timer, font);
	//, 300, 100, 100);

}

void Shop::drawtext(aie::Renderer2D * renderer, aie::Font *font)
{
	const char pgold = currentGold;
	const char* ptr = &pgold;
	renderer->drawText(font, ptr, 0, 720 - 32);
	renderer->drawText(font, "Gold: ", 0, 720 - 64);
	switch (shopstate)
	{
	case(welcome):
	{
		spritestate = greet;
		renderer->drawText(font, "Asher: Ah! Well if it isn't the warrior who dare challanges Dameon. How may I aid you today?", 300, 100, 100);
		return;
	}
	case wait:
	{
		spritestate = idle;
		renderer->drawText(font, "Asher: What can I get for you my friend?", 300, 100, 100);
		return;
	}
	case(viewAttackItems):
	{
		spritestate = idle;
		renderer->drawText(font, "Asher: Need a new move eh? I guess spamming the attack button wasn't enough?", 300, 100, 100);
		return;
	}
	case(viewDefenseItems):
	{
		spritestate = idle;
		renderer->drawText(font, "Asher: Please enjoy one of our mostly legal premium performance enhancing elixers.", 300, 100, 100);
		return;
	}
	case(viewUpgrades):
	{
		spritestate = idle;
		renderer->drawText(font, "Asher: So you need to get more physically fit? Hehe, why workout when you can pay me?", 300, 100, 100);
		return;
	}
	case(sell):
	{
		spritestate = sold;
		renderer->drawText(font, "Asher: Thank you,thank you! A fine choice my friend. Will you be buying more?", 300, 100, 100);
		return;
	}
	case bought:
	{
		spritestate = sold;
		renderer->drawText(font, "Asher: Im all out of that right now. ", 300, 100, 100);
		return;
	}
	}
}

void Shop::drawsprite(aie::Renderer2D *renderer, int timer, aie::Font *)
{
	switch (spritestate)
	{
	case idle:
	{
		shopkeep = idletexture;
		renderer->setUVRect(0, 0.f, .9, 1);
		renderer->drawSprite(shopkeep, 595, 720 - 70, 38, 54);
		break;
	}
	case greet:
	{
		shopkeep = welcometexture;
		renderer->setUVRect(int(timer * 10) % 3 / 2.f, 0.f, .50, 1);
		renderer->drawSprite(shopkeep, 600, 720 - 70, 38, 54);
		break;
	}
	case sold:
	{
		shopkeep = selltexture;
		renderer->setUVRect(int(timer * 10) % 3 / 2.9f, 0.f, .33, 1);
		renderer->drawSprite(shopkeep, 600, 720 - 70, 38, 54);
		break;
	}
	break;
	}
}
