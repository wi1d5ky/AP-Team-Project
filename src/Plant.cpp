#include "Plant.h"
#include "Zombie.h"
#include "Player.h"
#include <iostream>
using namespace std ;

Plant::Plant(string name, int cost, int fullhp)
	:name_(name),cost_(cost),fullhp_(fullhp),hp_(fullhp){}

void Plant::display() const {}
int Plant::doThing(Player py) {}     // Player on plant
int Plant::beAttacked(Zombie zb) {}  // Zombie on plant

CoinPlant::CoinPlant(string name, int cost, int fullhp, int round, int coin)
    :Plant(name, cost, fullhp) ,round_(round), coin_(coin){}

void CoinPlant::display()const{
	cout << name_ << " $" << cost_ << " HP: " << hp_
        << " - gives $" << coin_ << " every " << round_ << " rounds" << endl ;
}

int CoinPlant::doThing(Player) {

}
int CoinPlant::beAttacked(Zombie) {

}

BombPlant::BombPlant(string name, int cost, int fullhp )
:Plant(name, cost, fullhp), damage_(fullhp){}

void BombPlant::display()const{
	cout << name_ << " $" << cost_ << " HP: " << hp_
            << " - gives" << damage_ << " damage points" << endl ;
}

int BombPlant::doThing(Player) {

}
int BombPlant::beAttacked(Zombie) {

}

HealPlant::HealPlant( std::string name, int cost, int fullhp, int heal)
	:Plant(name, cost, fullhp),heal_(heal){}

void HealPlant::display()const{
	cout << name_ << " $" << cost_ << " HP: " << hp_
            << " - gives all your plants " << heal_ << " HP back" << endl ;
}

int HealPlant::doThing(Player) {

}
int HealPlant::beAttacked(Zombie) {

}

ShotPlant::ShotPlant(std::string name, int cost, int fullhp, int damage)
	:Plant(name, cost, fullhp),damage_(damage){}

void ShotPlant::display()const{
	cout << name_ << " $" << cost_ << " HP: " << hp_
            << " - gives" << damage_ << " damage points" << endl ;
}

int ShotPlant::doThing(Player) {

}
int ShotPlant::beAttacked(Zombie) {

}
