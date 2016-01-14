#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	public:
		Player() = default;
		Player(int pos):position_(pos) {};

		// change > 0 ==> earn ; change < 0 ==> spend
		// return value ==> trade success or not
		bool trade(int change);
		int currentMoney() { return money_; };
		int getPos()const { return position_; }
		void setPos(int pos) { position_ = pos; };

	private:
		constexpr static int default_money = 150;
		int money_ = default_money;
		int position_;
};

#endif // PLAYER_H
