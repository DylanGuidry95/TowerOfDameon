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
	Hero *player;
	iterator<Enemy> currentenemy;
	void initializeladder();
	const char* speak(int num);
	void draw(aie::Renderer2D * renderer, int state,int timer,aie::Font*);
	Character* ptr;
	int choice;
	enum current { newGame,inShop, inBattle, inContinue,playerturn,enemyturn,viewstats,viewattacks, defending};
	current gamestate;
	current ladderstate = playerturn;

	//the combat:
	void battleladder(Hero*&);
	//linked list:
	unorderedList<Enemy> enemyLadder;
	
};