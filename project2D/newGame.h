#pragma once
#include <imgui.h>
#include "Hero.h"

class newGameClass
{
private:
	int count = 0;
public:
	newGameClass();

	void draw(aie::Renderer2D* renderer, int timer, aie::Font* font);

	void drawText(aie::Renderer2D* renderer, aie::Font* font);

	Hero StartGame(int&);
};