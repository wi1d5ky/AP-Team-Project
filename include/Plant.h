#ifndef PLANT_H
#define PLANT_H


class Plant
{
    public:
        Plant();
        virtual ~Plant();
    protected:
    private:
};
class CoinPlant
{
public:
    Plant(int getmoney, int spend):getmoney_(getmoney),spend_(spend){}
private:
    int getmoney_;
    int spend_;
};

#endif // PLANT_H
