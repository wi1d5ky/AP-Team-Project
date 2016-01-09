#ifndef PLAYER_H
#define PLAYER_H

#include "Plant.h"
#include <vector>

class Player
{
	public:
		Player();
		int currentMoney() { return money_; };

		std::vector<std::string> store();
		Plant buy(int i);

	protected:

	private:
		constexpr static int plant_num_ = 3;
		constexpr static int default_money = 150;
		Plant * choice_[plant_num_];
		int money_ = default_money;
};

#endif // PLAYER_H
