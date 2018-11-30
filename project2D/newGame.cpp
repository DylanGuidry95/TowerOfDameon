#include "newGame.h"

newGameClass::newGameClass()
{
}

void newGameClass::draw(aie::Renderer2D* renderer, int timer, aie::Font* font)
{
}

void newGameClass::drawText(aie::Renderer2D* renderer, aie::Font* font)
{
	int count = 0;

	renderer->drawText(font, "Hello Hero, to start off i'm going to give you 2 free skill points.", 320, 720 - 64, 0);
	renderer->drawText(font, "You can use them however you want, or don't use them at all.", 320, 720 - 126, 0);

	if (count == 0)
	{
		renderer->drawText(font, "2 Skill points left to use", 320, 720 - 188, 0);
		count++;
	}

	if (count == 1)
	{
		renderer->drawText(font, "1 Skill point left to use", 320, 720 - 188, 0);
	}
}

Hero newGameClass::StartGame()
{
	Hero* Player = new Hero;

	Player->initalizeHero();

	if (ImGui::Button("No Upgrade", ImVec2(100, 100)))
	{
		Player->AssignStartingPoints(0);
	}

	if (ImGui::Button("Upgrade Health", ImVec2(100, 100)))
	{
		Player->AssignStartingPoints(1);
	}

	if (ImGui::Button("Upgrade Defense", ImVec2(100, 100)))
	{
		Player->AssignStartingPoints(2);
	}

	if (ImGui::Button("Upgrade Accuracy", ImVec2(100, 100)))
	{
		Player->AssignStartingPoints(3);
	}

	if (ImGui::Button("Upgrade Strength", ImVec2(100, 100)))
	{
		Player->AssignStartingPoints(4);
	}
	
	return *Player;
}
