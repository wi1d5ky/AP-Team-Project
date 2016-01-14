#ifndef PLANT_H
#define PLANT_H

#include<string>
#include<vector>

class Player ;
class Zombie ;

class Plant{

public:
    Plant()=default;
    Plant( const std::string& name, int cost, int fullhp );
    Plant( const Plant &plant );

    int getFullHP() const{
        return fullhp_;
    }
    int gethp() const{
        return hp_;
    }
    int getCost() const{
        return cost_;
    }
    const std::string& getName() const{
        return name_ ;
    }

    void setName( const std::string& name ) {
        name_ = name;
    }

    int hurt( int hurt) {
        return hp_ -= hurt;
    }

    void operator -=(int hurt){hp_-=hurt;} //operator
    void operator +=(int heal){hp_+=heal;}


    virtual void display() const ;
    virtual int doThing(Player& py , std::vector<Plant*>& plantlist) ;     // Player on plant
    virtual int beAttacked(Zombie& zb) ;  // Zombie on plant

protected:
    std::string name_ = "";
    int cost_ = 0;
    int fullhp_ = 0;
    int hp_ = 0;

};

class CoinPlant:public Plant{

public:
    CoinPlant()=default;
    CoinPlant( const std::string& name, int cost, int fullhp, int round, int coin );
    CoinPlant(const CoinPlant &coinplant);

    virtual void display()const ;
    virtual int doThing(Player& py , std::vector<Plant*>& plantlist) ;
    virtual int beAttacked(Zombie& zb) ;

private:
    int round_ = 0 ; // non static is easier to set
    int coin_ = 0 ;
    int visited_ = 0 ;

};

class BombPlant:public Plant{

public:
    BombPlant()=default;
    BombPlant( const std::string& name, int cost, int fullhp );
    BombPlant(const BombPlant &bombplant);

    virtual void display()const ;
    virtual int beAttacked(Zombie& zb) ;

private:
    int damage_ = 0 ;

};

class HealPlant:public Plant{

public:
    HealPlant()=default;
	HealPlant(const std::string& name, int cost, int fullhp, int heal);
	HealPlant(const HealPlant &healplant);

    virtual void display()const ;
    virtual int doThing(Player& py , std::vector<Plant*>& plantlist) ;
    virtual int beAttacked(Zombie& zb) ;

private:
    int heal_= 0 ;

};

class ShotPlant:public Plant{

public:
    ShotPlant()=default;
    ShotPlant(const std::string& name, int cost, int fullhp, int damage);
    ShotPlant(const ShotPlant &shotplant);

    virtual void display()const ;
    virtual int beAttacked(Zombie& zb) ;

private:
    int damage_ = 0;

};

#endif // PLANT_H
