#include "Plant.h"
#include "Zombie.h"
#include "Player.h"
#include <iostream>
using namespace std ;

Plant::Plant(string name, int cost, int fullhp)
	:name_(name),cost_(cost),fullhp_(fullhp),hp_(fullhp){}

//Copy Constructor
Plant::Plant(const Plant &plant):name_(name_),cost_(cost_),fullhp_(fullhp_),hp_(hp_){}
/* doThing() return heal point */
/* beAttacked() return whether plant is alive after attack of zombie */

void Plant::display() const {}
int Plant::doThing(Player& py) { return 0 ;}     // Player on plant
int Plant::beAttacked(Zombie& zb) { return 0 ;}  // Zombie on plant


CoinPlant::CoinPlant(string name, int cost, int fullhp, int round, int coin)
    :Plant(name, cost, fullhp) ,round_(round), coin_(coin), visited_(0){}

CoinPlant::CoinPlant(const CoinPlant &coinplant):Plant(coinplant),round_(round_),coin_(coin_),visited_(visited_){}

void CoinPlant::display()const{
	cout << name_ << " $" << cost_ << " HP: " << hp_
        << " - gives $" << coin_ << " every " << round_ << " rounds" << endl ;
}

int CoinPlant::doThing(Player& py) {
    if( ++visited_ >= round_ ){
        py += coin_  ;
        visited_ = 0 ;
    }
    return 0 ;
}
int CoinPlant::beAttacked(Zombie& zb) {
    hp_ -= zb.getAttack() ;
    if( hp_ <= 0 ){         // Plant is died
        hp_ = 0 ;
        return 0 ;
    }
    return 1 ;              // Plant is alive
}

BombPlant::BombPlant(string name, int cost, int fullhp )
:Plant(name, cost, fullhp), damage_(fullhp){}

BombPlant::BombPlant(const BombPlant &bombplant):Plant(bombplant),damage_(damage_){}

void BombPlant::display()const{
	cout << name_ << " $" << cost_ << " HP: " << hp_
            << " - gives " << damage_ << " damage points" << endl ;
}

int BombPlant::doThing(Player& py) {
    /* Nothing happen */
    return 0 ;
}
int BombPlant::beAttacked(Zombie& zb) {
    hp_ = 0 ;
    zb -= damage_ ;

    return 0 ;              // Always die
}

HealPlant::HealPlant( std::string name, int cost, int fullhp, int heal)
	:Plant(name, cost, fullhp),heal_(heal){}

HealPlant::HealPlant(const HealPlant &healplant):Plant(healplant),heal_(heal_){}

void HealPlant::display()const{
	cout << name_ << " $" << cost_ << " HP: " << hp_
            << " - gives all your plants " << heal_ << " HP back." << endl ;
}

int HealPlant::doThing(Player& py) {
    return heal_ ;
}
int HealPlant::beAttacked(Zombie& zb) {
    hp_ -= zb.getAttack() ;
    if( hp_ <= 0 ) return 0 ;
    else return 1 ;
}

ShotPlant::ShotPlant(std::string name, int cost, int fullhp, int damage)
	:Plant(name, cost, fullhp),damage_(damage){}

ShotPlant::ShotPlant(const ShotPlant &shotplant):Plant(shotplant),damage_(damage_){}

void ShotPlant::display()const{
	cout << name_ << " $" << cost_ << " HP: " << hp_
            << " - gives " << damage_ << " damage points" << endl ;
}

int ShotPlant::doThing(Player& py) {
    /* Nothing happen */
    return 0 ;
}
int ShotPlant::beAttacked(Zombie& zb) {
    zb -= damage_ ;
    if( zb.isDied() ) return 1 ;

    hp_ -= zb.getAttack() ;
    if( hp_ <= 0 ) return 0 ;
    else return 1 ;
}
