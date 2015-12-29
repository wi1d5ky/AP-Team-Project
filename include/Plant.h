#ifndef PLANT_H
#define PLANT_H


class Plant
{
    public:
        Plant()=default;
        Plant(int spend):spend_(spend){}
        virtual ~Plant();
    protected:
    private:
        int spend_;
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
