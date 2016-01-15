#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	public:
		Player() = default;
		Player(int pos):position_(pos) {};

		// change > 0 ==> earn ; change < 0 ==> spend
		// return value ==> trade success or not
		int currentMoney()const { return money_; };
		int getPos()const { return position_; }
		void setPos(int pos) { position_ = pos; };

		Player& operator += ( int money ){
            money_ += money ;
            return *this ;
		}
        Player& operator -= ( int money ){
            if( money_ >= money )
                money_ -= money ;
            return *this ;
		}

		constexpr static int step_ = 6 ;

	private:
		constexpr static int default_money = 150;
		int money_ = default_money;
		int position_ = 0;

};

#endif // PLAYER_H
