#include "Plant.h"
#include "Zombie.h"
#include "Player.h"
#include <iostream>
#include <vector>
using namespace std ;

Plant::Plant(const std::string& name, int cost, int fullhp)
	:name_(name),cost_(cost),fullhp_(fullhp),hp_(fullhp){}

/* doThing() return heal point */
/* beAttacked() return whether plant is alive after attack of zombie */

void Plant::display() const {
    cout << name_ << " $" << cost_ << " HP: " << hp_ ;
}
void Plant::displayinfo() const
{
    cout << name_ << " HP: "<< hp_ ;
}
int Plant::doThing(Player& py , vector<Plant*> plantlist ) { return -1 ;}     // Player on plant
int Plant::beAttacked(Zombie& zb) { return 0 ;}  // Zombie on plant
Plant* Plant::clone() const
{
    Plant* p = new Plant(*this) ;
    return p ;
}

CoinPlant::CoinPlant(const std::string& name, int cost, int fullhp, int round, int coin)
    :Plant(name, cost, fullhp) ,round_(round), coin_(coin), visited_(0){}


void CoinPlant::display()const{
	cout << name_ << " $" << cost_ << " HP: " << hp_
        << " - gives $" << coin_ << " every " << round_ << " rounds" << endl  ;
}

void CoinPlant::displayinfo()const{
    cout<< name_ <<" HP: " << hp_ << " <"<< round_-visited_ <<" more visits>";
}

int CoinPlant::doThing(Player& py , vector<Plant*> plantlist ) {
    if( ++visited_ >= round_ ){
        py += coin_  ;
        visited_ = 0 ;
        return 0 ;
    }
    return round_ - visited_ ;
}
int CoinPlant::beAttacked(Zombie& zb) {
    hp_ -= zb.getAttack() ;
    if( hp_ <= 0 ){         // Plant is died
        hp_ = 0 ;
        return 0 ;
    }
    return 1 ;              // Plant is alive
}
Plant* CoinPlant::clone() const{
    Plant* p = new CoinPlant(*this) ;
    return p ;
}

BombPlant::BombPlant(const std::string& name, int cost, int fullhp )
    :Plant(name, cost, fullhp), damage_(fullhp){}

void BombPlant::display()const{
	cout << name_ << " $" << cost_ << " HP: " << hp_
            << " - gives " << damage_ << " damage points" << endl ;
}

int BombPlant::beAttacked(Zombie& zb) {
    hp_ = 0 ;
    zb -= damage_ ;

    return 0 ;              // Always die
}
Plant* BombPlant::clone() const{
    Plant* p = new BombPlant(*this) ;
    return p ;
}

HealPlant::HealPlant( const std::string& name, int cost, int fullhp, int heal)
	:Plant(name, cost, fullhp),heal_(heal){}

HealPlant::HealPlant(const HealPlant &healplant):Plant(healplant),heal_(healplant.heal_){}

void HealPlant::display()const{
	cout << name_ << " $" << cost_ << " HP: " << hp_
            << " - gives all your plants " << heal_ << " HP back." << endl ;
}


int HealPlant::doThing(Player& py , vector<Plant*> plantlist) {
    for( auto& plant : plantlist ){
        if( plant != nullptr )
            *plant += heal_ ;
    }
    return -1 ;
}
int HealPlant::beAttacked(Zombie& zb) {
    hp_ -= zb.getAttack() ;
    if( hp_ <= 0 ) return 0 ;
    else return 1 ;
}
Plant* HealPlant::clone() const{
    Plant* p = new HealPlant(*this) ;
    return p ;
}

ShotPlant::ShotPlant(const std::string& name, int cost, int fullhp, int damage)
	:Plant(name, cost, fullhp),damage_(damage){}

void ShotPlant::display()const{
	cout << name_ << " $" << cost_ << " HP: " << hp_
            << " - gives " << damage_ << " damage points" << endl ;
}


int ShotPlant::beAttacked(Zombie& zb) {
    zb -= damage_ ;
    if( zb.isDied() ) return 1 ;

    hp_ -= zb.getAttack() ;
    if( hp_ <= 0 ) return 0 ;
    else return 1 ;
}
Plant* ShotPlant::clone() const{
    Plant* p = new ShotPlant(*this) ;
    return p ;
}
