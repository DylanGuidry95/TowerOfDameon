#pragma once
#include <imgui.h>
#include "Hero.h"

class newGameClass
{
public:
	newGameClass();

	enum choiceState {noSkill, health, defense, accuracy, strength};

	void draw(aie::Renderer2D* renderer, int timer, aie::Font* font);

	void drawText(aie::Renderer2D* renderer, aie::Font* font);

	Hero StartGame();
};