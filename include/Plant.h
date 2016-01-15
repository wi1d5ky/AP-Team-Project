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


    Plant& operator -=(int hurt){
        hp_-=hurt;
        return *this;
    } //operator
    Plant& operator +=(int heal)
    {
        hp_+=heal;
        if(hp_>fullhp_)
            hp_=fullhp_;
        return *this;
    }
    Plant& operator = ( const Plant& plant )
    {
        name_ = plant.name_ ;
        cost_ = plant.cost_ ;
        fullhp_ = plant.fullhp_ ;
        hp_ = plant.hp_ ;
        return *this ;
    }

    virtual Plant* clone() const ;
    virtual void display() const ;
    virtual void displayinfo() const;
    virtual int doThing(Player& py , std::vector<Plant*> plantlist) ;     // Player on plant
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

    CoinPlant& operator = ( const CoinPlant& plant )
    {
        Plant::operator=(plant) ;
        round_ = plant.round_ ;
        coin_ = plant.coin_ ;
        visited_ = plant.visited_ ;
        return *this ;
    }

    virtual Plant* clone() const;
    virtual void display()const ;
    virtual void displayinfo()const;
    virtual int doThing(Player& py , std::vector<Plant*> plantlist) ;
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

    BombPlant& operator = ( const BombPlant& plant )
    {
        Plant::operator=(plant) ;
        damage_ = plant.damage_ ;
        return *this ;
    }

    virtual Plant* clone() const;
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

    HealPlant& operator = ( const HealPlant& plant )
    {
        Plant::operator=(plant) ;
        heal_ = plant.heal_ ;
        return *this ;
    }

    virtual Plant* clone() const;
    virtual void display()const ;
    virtual int doThing(Player& py , std::vector<Plant*> plantlist) ;
    virtual int beAttacked(Zombie& zb) ;

private:
    int heal_= 0 ;

};

class ShotPlant:public Plant{

public:
    ShotPlant()=default;
    ShotPlant(const std::string& name, int cost, int fullhp, int damage);
    ShotPlant(const ShotPlant &shotplant);

    ShotPlant& operator = ( const ShotPlant& plant )
    {
        Plant::operator=(plant) ;
        damage_ = plant.damage_ ;
        return *this ;
    }

    virtual Plant* clone() const;
    virtual void display()const ;
    virtual int beAttacked(Zombie& zb) ;

private:
    int damage_ = 0;

};

#endif // PLANT_H
