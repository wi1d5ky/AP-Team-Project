#include "Player.h"

Player::Player()
{
	choice_[0] = new CoinPlant();
	choice_[1] = new BombPlant();
	choice_[2] = new HealPlant();
}

std::vector<std::string> Player::store()
{
	std::vector<std::string> menu;
	for(int i = 0 ; i < plant_num_ ; ++i)
	{
		std::string info = choice_[i]->getType();
		info += " $" + std::to_string(choice_[i]->spend());
		info += " HP: " + std::to_string(choice_[i]->getFullHP());
		info += " - " + choice_[i]->effect();
		menu.push_back(info);
	}
	return menu;
}

bool Player::canBuy()
{
    for(int i = 0 ; i < plant_num_ ; ++i)
		if(choice_[i]->spend() <= money_)
			return true;
	return false;
}

#include<iostream>

Plant Player::buy(int i)
{
	if(money_ - choice_[i]->spend() < 0)
		return *(new nilPlant);
	money_ -= choice_[i]->spend();
	return *choice_[i];
}

