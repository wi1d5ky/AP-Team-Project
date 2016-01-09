#ifndef PLANT_H
#define PLANT_H

#include<string>

class Plant
{
    public:
        Plant()=default;
        Plant(int cost):cost_(cost){}
        virtual ~Plant();


		int cost() {return cost_;};
        std::string getName() {return Name_;};
        int getFullHP() {return full_HP_;};
        int getHP() {return HP_;};
        void gotHurt(int hurt) {HP_-=hurt;};


    protected:
        int cost_ ;
        std::string Name_ ;
        int HP_;
        constexpr static int full_HP_;

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
		void Do(Game);
		void Attacked(Game);
	private:
		const static int happendRound_ ;
		int getmoney_ ;
		int visited_;
        //const std::string effect_ = "gives $" + std::to_string(getmoney_) + "every " + std::to_string(happendRound_) + " rounds";
};

class BombPlant:public Plant
{
	public:
		BombPlant()=default;
		bool isNull() {return false;};
		void Attacked(Game);
	private:
		const std::string type_ = "BombPlant";
		int damage_;
		//const std::string effect_ ="gives " + std::to_string(damage_) + " damage points";
};

class HealPlant:public Plant
{
	public:
		HealPlant()=default;
		bool isNull() {return false;};
		void Do(Game);
		void Attacked(Game);
	private:
		const std::string type_ = "HealPlant";
		int heal_;
		//const std::string effect_= "gives all your plants " + std::to_string(heal_) + " Hp back";
};

class ShotPlant:public Plant
{
public:
    ShotPlant()=default;
    bool isNull() {return false;};
    void Attacked(Game);
private:
    const std::string type_ = "ShotPlant";
    int damage_;
    //const std::string effect_ = "gives " + std::to_string(damage_) + " damage points";

};
#endif // PLANT_H
