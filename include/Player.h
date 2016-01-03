#ifndef PLAYER_H
#define PLAYER_H


class Player
{
	public:
		int currentMoney() { return money_; };

	protected:

	private:
		int money_ = default_money;
		constexpr static int default_money = 150;
};

#endif // PLAYER_H
