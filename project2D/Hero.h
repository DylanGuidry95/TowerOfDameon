#pragma once
#include "Character.h"
#include "Enemy.h"
#include"item.h"
#include "defenseitem.h"
#include "attackitem.h"
#include <vector>
#include "armor.h"
#include "Shop.h"
#include "list.h"

class Hero : public Character
{
private:
	//mGold is the total amount of money the player has accumulated 
	int mGold;
	Armor mArmor;
	int healthLVL = 0;
	int defenseLVL = 0;
	int accLVL = 0;
	int strengthLVL = 0;
public:
	//The player has two lists that store their previously bought attacks and armor for later use
	std::vector<Armor> armorBag;
	std::vector<Attack> attackBag;
	enum current {Attacking,Defending,stats,blocked};
	current playerstate;
	void drawtext(aie::Renderer2D*,aie::Font*,int);
	void drawsprite(aie::Renderer2D*renderer,int timer,aie::Font* font);
	void draw(aie::Renderer2D*renderer, int timer, aie::Font* font,int choice = 0);

	//The takeDamage function is called in the fight function and is only used to 
	//decrement the enemy's health
	void takeDamage(float) override;

	//The fight function calculates the total damage output of the enemy that is about to attack and then calls the take damage function with that value as its argument
	void fight(Character&, int attack) override;

	//Prints the player's current statistics (accuracy, health, strength, defense) to the window
	void viewStats();
	
	//Increases the player's defense by 20
	void defend();

	Hero();

	//Takes a defense item from the shop, removes it, places it in the players armorbag list, and decrements their gold value by the cost of the item 
	void buy_Armor(Shop& store, int choice);

	//Allows the player to choose which armor to use or remove
	void equipArmor(int);
	void unequipArmor();

	//Takes an attack item from the shop, removes it, places it in the players attackbag list, and decrements their gold value by the cost of the item 
	void buy_Attack(Shop& store, int choice);

	//Allows the player to choose which attack to use or remove
	void equipAttack(int choice1, int choice2);
	void unequipAttack(int);
	
	//Initializes hero with base stats
	void initalizeHero();
	void AssignStartingPoints(std::string othername);

	bool upgrade(int pchoice);

	int viewgold();
	const char* getAttackName(int num);
	
	aie::Texture*       idletexture = new aie::Texture("./textures/idle.png");
	aie::Texture*       welcometexture = new aie::Texture("./textures/welcome.png");
	aie::Texture*       tower = new aie::Texture("./textures/tower.png");
	aie::Texture*       hero = new aie::Texture("./textures/HeroSprites/Hero1Back.png");
	aie::Texture*       shopkeep;

	std::string getName();
};