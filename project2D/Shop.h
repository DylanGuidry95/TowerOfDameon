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
	void viewAttacks();
	void viewArmor();
	void draw(aie::Renderer2D*,int timer,aie::Font*);
	const char* speak(int num);
	int talk;
	enum storestate {welcome,sell,viewItems,viewDefenseItems,viewAttackItems,viewUpgrades};
	storestate shopstate = welcome;	

	aie::Texture*       shop= new aie::Texture("./textures/shop.png");
	aie::Texture*       shopkeep= new aie::Texture("./textures/sell.png");
	aie::Texture*       hero = new aie::Texture("./textures/sprites/Hero1Back.png");
};