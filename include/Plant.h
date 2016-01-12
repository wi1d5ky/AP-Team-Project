#ifndef PLANT_H
#define PLANT_H

#include<string>

struct Effect {
    int coin   = 0 ,
        heal   = 0 ,
        damage = 0 ;
};

class Plant{

public:
    Plant()=default;
    Plant( std::string name, int cost, int fullhp );

    int getFullHP() const{
        return fullhp_;
    }
    int gethp() const{
        return hp_;
    }
    int getCost() const{
        return cost_;
    }
    std::string getName() const{
        return name_ ;
    }
    void setName(std::string name) {
        name_ = name;
    }

    int hurt( int hurt) {
        return hp_ -= hurt;
    }


    virtual void display()const {}
    virtual Effect doThing() {}     // Player on plant
    virtual Effect beAttacked() {}  // Zombie on plant


protected:
    std::string name_ = "";
    int cost_ = 0;
    int fullhp_ = 0;
    int hp_ = 0;

};

class CoinPlant:public Plant{

public:
    CoinPlant()=default;
    CoinPlant( std::string name, int cost, int fullhp, int round, int coin );

    virtual void display()const ;
    virtual Effect doThing() ;
    virtual Effect beAttacked() ;

private:
    int round_ = 0 ; // non static is easier to set
    int coin_ = 0 ;
    int visited_ = 0 ;

};

class BombPlant:public Plant{

public:
    BombPlant()=default;
    BombPlant( std::string name, int cost, int fullhp );

    virtual void display()const ;
    virtual Effect doThing() ;
    virtual Effect beAttacked() ;

};

class HealPlant:public Plant{

public:
    HealPlant()=default;
	HealPlant(std::string name, int cost, int fullhp);

    virtual void display()const ;
    virtual Effect doThing() ;
    virtual Effect beAttacked() ;

private:
    int heal_=0;

};

class ShotPlant:public Plant{

public:
    ShotPlant()=default;
    ShotPlant(std::string name, int cost, int fullhp);

    virtual void display()const ;
    virtual Effect doThing() ;
    virtual Effect beAttacked() ;

private:
    int damage_=0;

};

#endif // PLANT_H
