#ifndef PLANT_H
#define PLANT_H

#include<string>

class Plant
{
    public:
        Plant()=default;
        Plant(int cost):cost_(cost){}
        virtual ~Plant();

        std::string getName() {return Name_;};
        int getHP() {return HP_;};
        void gotHurt(int hurt) {HP_-=hurt;};

    protected:
        int cost_;
        std::string Name_;
        int HP_;
        int full_HP_;
};
class CoinPlant:public Plant
{
public:
    CoinPlant()=default;
private:
    int getmoney_;
    int round_;

};
class BombPlant:public Plant
{
public:
    BombPlant()=default;
private:
    int damage_;
};
class HealPlant:public Plant
{
public:
    HealPlant();
private:
    int heal_;
};

#endif // PLANT_H
