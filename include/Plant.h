#ifndef PLANT_H
#define PLANT_H

#include<string>

class Plant
{
public:
    Plant()=default;
    Plant(int cost, int fullHP, std::string name);

    // hp
    int getFullHP() { return full_HP_; }
    int HP() { return hp_; }
    int hurt( int hurt) { return hp_ -= hurt; }

    // name
    std::string getName() { return name_; }
    void setName(std::string name) { name_ = name; };

    int cost() { return cost_; }
    virtual std::string display() { return "Description of Plant"; }

protected:
    int full_HP_; // not all plants have the same full HP
    int hp_ = 0;
    std::string name_;
    int cost_ = 0;
};

class CoinPlant:public Plant
{
public:
    CoinPlant()=default;
    CoinPlant(int cost,int fullHP, std::string name, int happend, int getmoney);
    virtual std::string display();
    //void Do(Game);
    //void Attacked(Game);
private:
    int happend_round_ = 2; // non static is easier to set
    int getmoney_ ;
    int visited_ = 0;
};

class BombPlant:public Plant
{
public:
    BombPlant()=default;
    BombPlant(int cost, int fullHP, std::string name);

    virtual std::string display() { return "gives " + std::to_string(damage_) + " damage points"; }
    //void Do(Game);
    //void Attacked(Game);
private:
    int damage_;
};

class HealPlant:public Plant
{
public:
    HealPlant()=default;
	HealPlant::HealPlant(int cost,int fullHP, std::string name,int heal);
    virtual std::string display() { return "gives all your plants " + std::to_string(heal_) + " HP back."; }
    //void Do(Game);
    //void Attacked(Game);
private:
    int heal_;
};

class ShotPlant:public Plant
{
public:
    ShotPlant()=default;
    ShotPlant(int cost,int fullHP, std::string name,int damage):Plant(cost,fullHP,name),damage_(damage)
    virtual std::string display() { return "gives " + std::to_string(damage_) + " damage points"; }
	//void Do(Game);
    //void Attacked(Game);
private:
    int damage_;
};

#endif // PLANT_H
