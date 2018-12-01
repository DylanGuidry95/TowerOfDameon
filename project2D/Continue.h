#pragma once
#include "Game.h"

class Continue
{
public:
	enum choicestate {play, end, shop, battle, start};
	choicestate choice=start;
	void draw(aie::Renderer2D*, int timer, aie::Font*, Hero* player, int& state);
	void drawtext(aie::Renderer2D * renderer, aie::Font*, Hero* player, int& state);
	bool subtractGold(Hero* hero);

	aie::Texture*       continueStage = new aie::Texture("./textures/continue.png");
	aie::Texture*       hero = new aie::Texture("./textures/HeroSprites/Hero1Back.png");
};