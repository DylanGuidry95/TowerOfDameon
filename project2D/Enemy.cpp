#include "Enemy.h"
#include<iostream>
#include <time.h>

void Enemy::takeDamage(float damageTaken)
{
	damageTaken = damageTaken - mDefense;

	//checks if the total damage output is less than or equal to zero if so enemy recieves no damage
	if (damageTaken <= 0)
	{

		std::cout << name << " blocked!" << std::endl;
	}

	else if (mHealth > 0 && damageTaken >= 0)
	{
		mHealth = mHealth - damageTaken;
	}
}


void Enemy::fight(Character& foe, int attack)
{
	float damageTaken;

	srand(time(NULL));

	//Creates a random value used to measure accuracy
	int Accuracy_Value = rand() % 100;

	//if the random accuracy value is less than the min required to land a hit no damage is dealt
	if (Accuracy_Value < mAccuracy.min)
	{
		std::cout << "You missed!" << std::endl;
	}

	//if the random accuracy value is more than the min required to land a hit and less than the maximum value required base damage is dealt
	else if (Accuracy_Value > mAccuracy.min && Accuracy_Value < mAccuracy.max)
	{
		damageTaken = listofattacks[attack].mDamage + (listofattacks[attack].mDamage * mStrength);

		foe.takeDamage(damageTaken);
	}

	//if the random accuracy value is more than the max value required to land a hit the enemy's damage is doubled
	else if (Accuracy_Value > mAccuracy.max)
	{
		damageTaken = (listofattacks[attack].mDamage + (listofattacks[attack].mDamage * mStrength) * 2);

		foe.takeDamage(damageTaken);
	}
}


void Enemy::defend()
{
	int protection = 20;
	mDefense = mDefense + protection;
}


Enemy::Enemy()
{
}



Enemy::Enemy(const char* name, Attack otherlistofattacks[3], aie::Texture*othertexture, float health, float def, float str, int minAcc, int maxAcc)
{
	//(Stats:.. Can be changed later)
	mHealth = health;
	mDefense = def;
	mStrength = str;
	mAccuracy.min = minAcc;
	mAccuracy.max = maxAcc;
	charTexture = othertexture;
	this->name = name;
	for (int i = 0; i <= 2; i++)
	{
		listofattacks[i] = otherlistofattacks[i];
	}

}

bool Enemy::operator!=(Enemy rhs)
{
	return this->name != rhs.name;
}

bool Enemy::operator==(Enemy rhs)
{
	return this->name == rhs.name;
}

void Enemy::draw(aie::Renderer2D*renderer,int timer,aie::Font*font,int choice)
{
	renderer->drawSprite(charTexture, 650, 350, 116, 106);
	drawtext(renderer, font,choice);
}

void Enemy::drawtext(aie::Renderer2D*renderer,aie::Font*font,int choice)
{
	switch (enemystate)
	{
	case attacking:
	{
		renderer->drawText(font, "The monster used", 300, 100, 100);
		renderer->drawText(font, listofattacks[choice].name, 400, 100, 100);
		break;
	}
	case defending:
	{
		renderer->drawText(font, "The monster raised its gaurd!", 300, 100, 100);
		break;
	}
	case blocked:
	{
		renderer->drawText(font, "It blocked your attack!", 300, 100, 100);
		break;
	}

	}
}
