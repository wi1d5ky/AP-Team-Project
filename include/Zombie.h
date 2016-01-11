#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Plant.h"

class Zombie
{
	public:
		Zombie(int pos);

		int getHP() { return HP_; };
		void setPos(int i) {pos_ = i;};
		int position() { return pos_;};
		int attack() { return power_; };
		int getFullHP() {return full_HP_;};

	protected:

	private:
		int pos_;
		int HP_ = full_HP_; // current HP
		constexpr static int power_ = 15;
		constexpr static int full_HP_ = 40;
		constexpr static int max_num = 10;
};

#endif // ZOMBIE_H
