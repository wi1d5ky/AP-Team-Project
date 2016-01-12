#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	public:
		Player() = default;

		// change > 0 ==> earn ; change < 0 ==> spend
		// return value ==> trade success or not
		bool trade(int change);
		int currentMoney() { return money_; };

	private:
		constexpr static int default_money = 150;
		int money_ = default_money;
};

#endif // PLAYER_H
