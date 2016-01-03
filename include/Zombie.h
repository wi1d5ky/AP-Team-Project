#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <Plant.h>

class Zombie
{
	public:
		int getHP() { return HP_; };
		int attack() { return power_; };

	protected:

	private:
		int HP_ = full_HP_; // current HP
		constexpr static int power_ = 15;
		constexpr static int full_HP_ = 40;
};

#endif // ZOMBIE_H
