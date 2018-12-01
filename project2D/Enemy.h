#pragma once
#include "Hero.h"
#include "Renderer2D.h"

class Enemy : public Character
{
public:
	//The takeDamage function is called in the fight function and is only used to 
	//decrement the hero's health
	void takeDamage(float) override;

	//The fight function calculates the total damage output of the enemy that is about to attack and then calls the take damage function with that value as its argument
	void fight(Character&, int attack) override;

	//Raises the enemy's defense by 20
	void defend();

	Enemy();

	Enemy(const char* name, Attack otherlistofattacks[3],aie::Texture*, float health, float def, float str, int minAcc, int maxAcc);
	bool operator <= (Enemy rhs);
	bool operator != (Enemy rhs);
	bool operator == (Enemy rhs);
	aie::Texture* enemyTexture;
	enum current{idle,attacking,hurt,defending,blocked};
	current enemystate;
	void draw(aie::Renderer2D*, int timer, aie::Font*font,int choice);
	void drawtext(aie::Renderer2D*,aie::Font*,int choice);
	const Enemy & Enemy::operator=(Character & otherenemy)
	{
		this->mHealth = otherenemy.getHealth();
		return *this;
	}
};