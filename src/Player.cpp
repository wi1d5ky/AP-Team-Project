#include <typeinfo>
#include <iostream>
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
	for(Plant* p : choice_)
		menu.push_back(p->display());
	return menu;
}

bool Player::canBuy()
{
    for(int i = 0 ; i < plant_num_ ; ++i)
		if(choice_[i]->cost() <= money_)
			return true;
	return false;
}

#include<iostream>

Plant Player::buy(int i)
{
	if(money_ - choice_[i]->cost() < 0)
		return *(new nilPlant);
	money_ -= choice_[i]->cost();
	return *choice_[i];
}

