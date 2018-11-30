#pragma once
#include "Shop.h"
#include "Hero.h"
#include "Enemy.h"
#include "Character.h"
#include"item.h"
#include "iterator.h"
#include "list.h"
#include "nodetype.h"
#include"unorderedlist.h"
#include "Renderer2D.h"
class Game 
{


public:
	Game();
	void shop(Hero*&);
	void initializeshop();
	Shop item_Shop;
	void initializeladder();
	const char* speak(int num);
	void draw(aie::Renderer2D * renderer, int state,int timer,aie::Font*);
	
	enum current { newGame,inShop, inBattle, inContinue };
	current gamestate;
	void text(const char*);
	//the combat:
	void battleladder();
	//linked list:
	/*unorderedList<Enemy> enemyLadder;
	Game(unorderedList<Enemy>);*/
};