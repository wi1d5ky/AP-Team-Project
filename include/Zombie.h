#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie
{
	public:
		Zombie(int pos):position_(pos) {}

		int getFullHP() { return full_hp_; }
		int getHP() { return hp_; }
		int hurt(int cost) { return hp_ -= cost; }
		int getPos() { return position_; }
		void setPos(int i) { position_ = i; }
		int attack() { return power_; }
		bool isDied(){ return hp_ <= 0 ;}

	private:
		int position_;
		int hp_ = full_hp_;
		constexpr static int power_ = 15;
		constexpr static int full_hp_ = 40;
};

#endif // ZOMBIE_H
