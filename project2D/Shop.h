#pragma once
#include "item.h"
#include <vector>
#include "defenseitem.h"
#include "attackitem.h"
#include <imgui.h>
#include "Renderer2D.h"
#include "Font.h"
#include"Texture.h"
class Shop
{
private:
	//A store has two lists:one to hold defense items called armor stock and one to hold attack items called attackstock
	std::vector<DefenseItem> armorstock;
	std::vector<AttackItem> attackstock;
public:
	Shop();
	Shop(std::vector<DefenseItem>armor, std::vector<AttackItem>attack);
	//Returns an item at the index of the choice argument then deletes it from the list
	AttackItem sellattack(int choice);
	DefenseItem selldefense(int choice);
	
	const char* viewAttacks(int num);
	const char*viewArmor(int num);

	void draw(aie::Renderer2D*,int timer,aie::Font*);
	void drawtext(aie::Renderer2D * renderer, aie::Font*);
	void drawsprite(aie::Renderer2D*, int timer, aie::Font*);

	int currentGold;

	enum storestate {welcome,sell,viewItems,viewDefenseItems,viewAttackItems,viewUpgrades,bought,wait};
	storestate shopstate=welcome;	
	enum sellstate {idle,sold,greet};
	sellstate spritestate;

	aie::Texture*       idletexture = new aie::Texture("./textures/idle.png");
	aie::Texture*       welcometexture = new aie::Texture("./textures/welcome.png");
	aie::Texture*       selltexture = new aie::Texture("./textures/sell.png");
	aie::Texture*       shop= new aie::Texture("./textures/shop.png");
	aie::Texture*       hero = new aie::Texture("./textures/sprites/Hero1Back.png");
	aie::Texture*       shopkeep;
	
};