#include "Continue.h"

bool Continue::subtractGold(Hero * player)
{
	if (player->viewgold() >= 500)
	{
		player->viewgold() - 500;
		return true;
	}
	else
	{
		return false;
	}
}

void Continue::draw(aie::Renderer2D *renderer, int timer, aie::Font *font, Hero * player, int& state)
{
	renderer->drawSprite(continueStage, 600, 450, 500, 583);
	renderer->drawSprite(hero, 600, 400, 57, 92);

	drawtext(renderer, font, player, state);
}

void Continue::drawtext(aie::Renderer2D * renderer, aie::Font *font, Hero * player, int& state)
{
	switch (choice)
	{
	case start:
	{
		if (ImGui::Button("Hell Yeah!!", ImVec2(100, 100)))
		{
			choice = play;
			break;
		}
		if (ImGui::Button("Nah", ImVec2(100, 100)))
		{
			choice = end;
			break;
		}
	}
	case(play):
	{
		if (subtractGold(player))
		{
			if (ImGui::Button("I need to buy some stuff..", ImVec2(100, 100)))
			{
				choice = shop;
				break;
			}
			if (ImGui::Button("I want to fight!", ImVec2(100, 100)))
			{
				choice = battle;
				break;
			}
		}
		else if (subtractGold(player) == false)
		{
			renderer->drawText(font, "You do not have enough gold to continue", 300, 100, 100);
			choice = end;
			break;
		}
	}
	case(shop):
	{
		state = 1;
	}
	case(battle):
	{
		state = 2;
	}
	case(end):
	{

	}
	}
}


