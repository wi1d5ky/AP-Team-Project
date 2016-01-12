#include "Plant.h"
#include <iostream>
using namespace std ;

Plant::Plant(string name, int cost, int fullhp)
	:name_(name),cost_(cost),fullhp_(fullhp),hp_(fullhp){}

CoinPlant::CoinPlant(string name, int cost, int fullhp, int round, int coin)
    :Plant(name, cost, fullhp) ,round_(round), coin_(coin){}

void CoinPlant::display(){
	cout << name_ << " $" << cost_ << " HP: " << hp_
        << " - gives $" << coin_ << " every " << round_ << " rounds" << endl ;
}

BombPlant( std::string name, int cost, int fullhp, int damage )
	:Plant(name, cost, fullhp), damage_(fullhp){}

void BombPlant::display(){
	cout << name_ << " $" << cost_ << " HP: " << hp_
            << " - gives" << damage_ << " damage points" << endl ;
}

HealPlant::HealPlant( std::string name, int cost, int fullhp, int heal)
	:Plant(name, cost, fullhp),heal_(heal){}

void HealPlant::display(){
	cout << name_ << " $" << cost_ << " HP: " << hp_
            << " - gives all your plants " << heal_ << " HP back" << endl ;
}

ShotPlant::ShotPlant(std::string name, int cost, int fullhp, int damage)
	:Plant(name, cost, fullhp),damage_(damage){}

void ShotPlant::display(){
	cout << name_ << " $" << cost_ << " HP: " << hp_
            << " - gives" << damage_ << " damage points" << endl ;
}
