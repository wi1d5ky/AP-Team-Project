#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <cstring>

class Zombie
{
	public:
		Zombie(int pos,int id):position_(pos),id_(id) {}

		int getPos()const { return position_; }
        int getAttack()const { return power_; }
        int getId()const { return id_ ; }
		void setPos(int i) { position_ = i; }
		bool isDied()const { return hp_ <= 0 ;}
        void display()const { std::cout << std::string(hp_, '*'); };

		Zombie& operator += ( int life ){
            hp_ += life ;
            if( hp_ > full_hp_ ) hp_ = full_hp_ ;
            return *this ;
		}
        Zombie& operator -= ( int hurt ){
            hp_ -= hurt ;
            if( hp_ < 0 ) hp_ = 0 ;
            return *this ;
		}

        constexpr static int step_ = 4 ;
        constexpr static int maxZombie = 10 ;

	private:
		int position_;
		int hp_ = full_hp_;
		int id_ ;
		constexpr static int power_ = 15;
		constexpr static int full_hp_ = 40;

};

#endif // ZOMBIE_H
