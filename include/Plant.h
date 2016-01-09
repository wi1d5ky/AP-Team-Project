#ifndef PLANT_H
#define PLANT_H

#include<string>

class Plant
{
    public:
        Plant()=default;
        Plant(int cost):cost_(cost){}
        virtual ~Plant();

		std::string getType() {return type_;};
		int spend() {return cost_;};
        std::string getName() {return Name_;};
        int getFullHP() {return full_HP_;};
        int getHP() {return HP_;};
        void gotHurt(int hurt) {HP_-=hurt;};
        std::string effect() {return effect_;};

    protected:

		const std::string type_ = "Plant";
        int cost_;
        std::string Name_ = "Plant Name";
        int HP_;
        int full_HP_;
        const std::string effect_ = "this is a plant";
};

class nilPlant:public Plant
{
	public:
		bool isNull() { return isNull_; };
	private:
		const bool isNull_ = true;
};

class CoinPlant:public Plant
{
	public:
		CoinPlant()=default;
		bool isNull() {return false;};
	private:
		const std::string type_ = "CoinPlant";
		const static int happendRound_ = 2;
		int getmoney_ = 100;
		int visited_;
        const std::string effect_ = "gives $" + std::to_string(getmoney_) + "every " + std::to_string(happendRound_) + " rounds";
};

class BombPlant:public Plant
{
	public:
		BombPlant()=default;
		bool isNull() {return false;};
	private:
		const std::string type_ = "BombPlant";
		int damage_;
};

class HealPlant:public Plant
{
	public:
		HealPlant()=default;
		bool isNull() {return false;};
	private:
		const std::string type_ = "HealPlant";
		int heal_;
};

#endif // PLANT_H
