#include "Hero.h"
#include<iostream>
#include <time.h>

void Hero::takeDamage(float damageTaken)
{
	if (playerstate == Defending)
	{
		mDefense = mDefense + 30;
		damageTaken = damageTaken - mDefense;
		mDefense -= 30;
	}
	else
	{
		damageTaken = damageTaken - mDefense;
	}
	

	//checks if the total damage output is less than or equal to zero if so hero recieves no damage
	if (damageTaken <= 0)
	{

		playerstate = blocked;
	}

	if (mHealth > 0)
	{
		mHealth = mHealth - damageTaken;
	}
}

void Hero::fight(Character&foe, int attack)
{
	float damageTaken;

	srand(time(NULL));

	//Creates a random value used to measure accuracy
	int Accuracy_Value = 40;//rand() % 100;

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

	//if the random accuracy value is more than the max value required to land a hit the player's damage is doubled
	else if (Accuracy_Value > mAccuracy.max)
	{
		damageTaken = (listofattacks[attack].mDamage + (listofattacks[attack].mDamage * mStrength) * 2);

		foe.takeDamage(damageTaken);
	}
}

void Hero::viewStats()
{
	std::cout << name << "'s stats" << std::endl;
	std::cout << "Health: " << mHealth << std::endl;
	std::cout << "Defense: " << mDefense << std::endl;
	std::cout << "Strength: " << mStrength << std::endl;
	std::cout << "Accuracy: " << mAccuracy.min << " - " << mAccuracy.max << std::endl;
}

void Hero::defend()
{
	int protection = 20;
	mDefense = mDefense + protection;
}

Hero::Hero()
{
}

//Takes the choice variable and uses it to access an index in the armorbag and then add the stats to the current stats
void Hero::equipArmor(int choice)
{
	mArmor = armorBag.at(choice);
	mDefense = mDefense + mArmor.defenseBoost;
	mHealth = mHealth + mArmor.health_Value;
	mStrength = mStrength + mArmor.strength_Value;
}

//removes current armor stats by subtracting the values
void Hero::unequipArmor()
{
	mDefense = mDefense - mArmor.defenseBoost;
	mHealth = mHealth - mArmor.health_Value;
	mStrength = mStrength - mArmor.strength_Value;
}

void Hero::buy_Attack(Shop& store, int choice)
{
	AttackItem item_Bought = store.sellattack(choice);
	mGold = mGold - item_Bought.mCost;
	attackBag.push_back(item_Bought.newattack);
}
//choice 1 is the item they want to equip choice two is what item are they replacing
void Hero::equipAttack(int choice1, int choice2)
{
	Attack* temp = new Attack;
	*temp = listofattacks[choice2];
	listofattacks[choice2] = attackBag.at(choice1);
	attackBag.at(choice1) = *temp;
	delete temp;
}

void Hero::unequipAttack(int choice)
{
	attackBag.push_back(listofattacks[choice]);
	Attack*ptr = new Attack;
	listofattacks[choice] = *ptr;
	delete ptr;
}

//needs to be looked at
void Hero::initalizeHero()
{
	mGold = 4;
	mHealth = 100;
	mDefense = 5;
	mStrength = .05f;
	mAccuracy.min = 30;
	mAccuracy.max = 90;
	Attack starter1("Flail", 5, 10);
	Attack starter2("Quick Attack", 10, 5);
	Attack starter3("Fury Rush", 30, 2);
	listofattacks[0] = starter1;
	listofattacks[1] = starter2;
	listofattacks[2] = starter3;
}

void Hero::AssignStartingPoints(int op)
{
	switch (op)
	{
	case (0):
	{
		return;
	}

	case (1):
	{
			healthLVL++;

			if (healthLVL == 1)
			{
				mHealth = 150;
			}

			if (healthLVL == 2)
			{
				mHealth = 200;
			}

			break;
	}

	case (2):
	{
			defenseLVL++;

			if (defenseLVL == 1)
			{
				mDefense = 10;
			}

			if (defenseLVL == 2)
			{
				mDefense = 15;
			}

			break;
	}

	case (3):
	{
	
			accLVL++;

			if (accLVL == 1)
			{
				mAccuracy.min = 26;
				mAccuracy.max = 88;
			}

			if (accLVL == 2)
			{
				mAccuracy.min = 22;
				mAccuracy.max = 86;
			}

			break;


	}

	case (4):
	{
			strengthLVL++;

			if (strengthLVL == 1)
			{
				mStrength = .10f;
			}

			if (strengthLVL == 2)
			{
				mStrength = .15f;
			}

			break;
	}
	}
}

bool Hero::upgrade(int pchoice)
{
	switch (pchoice)
	{
		case(1):
		{
			if (healthLVL == 5)
				return false;
			else
			mHealth += 100;
			mGold -= 500;
		}
		case (2):
		{
			if (defenseLVL == 5)
				return false;
			else
			mDefense += 5;
			mGold -= 500;
		}
		case(3):
		{
			if (strengthLVL == 5)
				return false;
			else
			mStrength += .05;
			mGold -= 500;
		}
		case(4):
		{
			if (accLVL == 5)
				return false;
			else
			mAccuracy.max -= 2;
			mAccuracy.min -= 4;
			mGold -= 500;
		}
	}
	return true;
}

int Hero::viewgold()
{
	return mGold;
}

const char * Hero::getAttackName(int num)
{
	const char* ptr;
	switch(num)
	{
		case 0:
		{
			return ptr = listofattacks[0].name; 
		}
		case 1:
		{
			return ptr = listofattacks[1].name;
		}
		case 2:
		{
			return ptr = listofattacks[2].name;
		}
	}
}

std::string Hero::getName()
{
	return name;
}

//Can't initialize values in constructor. A possible solution would be to copy the argument list into initialize hero function and ask for name in assign skill point function
//Hero::Hero()
//{
//	//mHealth = 100;
//	//mDefense = 5;
//	//mStrength = .05f;
//	//mAccuracy.min = 30;
//	//mAccuracy.max = 90;
//}

//calls the sell function for the store to remove the item from its inventory and then adds it to to the players inventory
void Hero::buy_Armor(Shop& store, int choice)
{
	DefenseItem item_Bought = store.selldefense(choice);
	mGold = mGold - item_Bought.mCost;
	armorBag.push_back(item_Bought.suit);
}

void Hero::drawtext(aie::Renderer2D *renderer, aie::Font*font,int choice)
{
	switch (playerstate)
	{
	case Attacking:
	{
		renderer->drawText(font, "You used", 300, 100, 100);
		renderer->drawText(font, listofattacks[choice].name, 400, 100, 100);
		break;
	}
	case Defending:
	{
		renderer->drawText(font, "You raised your gaurd!", 300, 100, 100);
		break;
	}
	case blocked:
	{
		renderer->drawText(font, "You blocked their attack!", 300, 100, 100);
		break;
	}

	}
}

void Hero::drawsprite(aie::Renderer2D * renderer, int timer, aie::Font * font)
{
}

void Hero::draw(aie::Renderer2D*renderer, int timer, aie::Font* font,int choice)
{
	/*renderer->setUVRect(0.f, 0.f, 1, 1);
	renderer->drawSprite(shop, 600, 450, 500, 583);

	renderer->drawSprite(hero, 600, 400, 57, 92);*/


	drawtext(renderer, font,choice);
	drawsprite(renderer, timer, font);
	//, 300, 100, 100);

}
