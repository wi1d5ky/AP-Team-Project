#ifndef PLANT_H
#define PLANT_H

#include<string>

class Plant
{
    public:
        Plant()=default;
        Plant(int cost,int fullHP,std::string name):cost_(cost),full_HP_(fullHP),Name_(name){}
        virtual ~Plant();


		int cost() {return cost_;};
        std::string getName() {return Name_;};
        int getFullHP() {return full_HP_;};
        int getHP() {return HP_;};
        void gotHurt(int hurt) {HP_-=hurt;};
        virtual std::string display() {return "Plant";}
    
        //not implement yet
    void SetName(std::string name){};
    


    protected:
        int cost_ = 0;
        std::string Name_ ;
        int HP_ = 0;
        int full_HP_ = 75; // not all plants have the same full HP!

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
        CoinPlant(int cost,int fullHP, std::string name, int happend, int getmoney):Plant(cost,fullHP,name),happendRound_(happend),getmoney_(getmoney){};
		bool isNull() {return false;};
		virtual std::string display() {return "gives $" + std::to_string(getmoney_) + " every " + std::to_string(happendRound_) + " rounds";}
		//void Do(Game);
		//void Attacked(Game);
	private:
        int happendRound_ = 2;//non static is more easy to set
		int getmoney_ ;
		int visited_ = 0;
};


class BombPlant:public Plant
{
	public:
		BombPlant()=default;
        BombPlant(int cost,int fullHP, std::string name):Plant(cost,fullHP,name),damage_(fullHP){};
    
		bool isNull() {return false;};
		virtual std::string display() {return "gives " + std::to_string(damage_) + " damage points";}
		//void Attacked(Game);
	private:
		int damage_;
};

class HealPlant:public Plant
{
	public:
		HealPlant()=default;
        HealPlant(int cost,int fullHP, std::string name,int heal):Plant(cost,fullHP,name),heal_(heal){};
    
		bool isNull() {return false;};
		virtual std::string display() {return "gives all your plants " + std::to_string(heal_) + " HP back.";}
		//void Do(Game);
		//void Attacked(Game);
	private:
		int heal_;
};

class ShotPlant:public Plant
{
	public:
		ShotPlant()=default;
        ShotPlant(int cost,int fullHP, std::string name,int damage):Plant(cost,fullHP,name),damage_(damage){};
    
		bool isNull() {return false;};
		virtual std::string display() {return "gives " + std::to_string(damage_) + " damage points";}

		//void Attacked(Game);
	private:
		int damage_;

};
#endif // PLANT_H
