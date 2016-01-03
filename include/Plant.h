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
    private:
        int cost_;
        std::string Name_;
        int HP_;
        int full_HP_; // SUGGEST TO CHANGE TO COST

        /* NEED: Name, HP, full_HP */
};
class CoinPlant:public Plant
{
public:
    CoinPlant()=default;
    CoinPlant(int cost, int getmoney):Plant(cost), getmoney_(getmoney){}
private:
    int getmoney_;

};
class BombPlant:public Plant
{
public:
    BombPlant()=default;
};

#endif // PLANT_H
