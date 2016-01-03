#ifndef PLANT_H
#define PLANT_H

#include<string>

class Plant
{
    public:
        Plant()=default;
        Plant(int spend):spend_(spend){}
        virtual ~Plant();

        std::string getName() {/* NOT IMPLEMENT */};
        int getHP() {/* NOT IMPLEMENT */};
        void gotHurt(int hurt) {/* NOT IMPLEMENT */};

    protected:
    private:
        int spend_; // SUGGEST TO CHANGE TO COST

        /* NEED: Name, HP, full_HP */
};
class CoinPlant:public Plant
{
public:
    CoinPlant()=default;
    CoinPlant(int spend, int getmoney):Plant(spend), getmoney_(getmoney){}
private:
    int getmoney_;

};

#endif // PLANT_H
