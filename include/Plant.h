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
        virtual std::string display() {return "Plant";}


    protected:
        int cost_ ;
        std::string Name_ ;
        int HP_;
        constexpr static int full_HP_ = 75; // not all plants have the same full HP!

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
		virtual std::string display() {return "CoinPlant gives $" + std::to_string(getmoney_) + " every " + std::to_string(happendRound_) + " rounds";}
		//void Do(Game);
		//void Attacked(Game);
	private:
		const static int happendRound_ = 2;
		int getmoney_ ;
		int visited_;
};

class BombPlant:public Plant
{
	public:
		BombPlant()=default;
		bool isNull() {return false;};
		virtual std::string display() {return "BombPlant gives " + std::to_string(damage_) + " damage points";}
		//void Attacked(Game);
	private:
		int damage_;
};

class HealPlant:public Plant
{
	public:
		HealPlant()=default;
		bool isNull() {return false;};
		virtual std::string display() {return "HealPlant gives all your plants " + std::to_string(heal_) + " Hp back";}
		//void Do(Game);
		//void Attacked(Game);
	private:
		int heal_;
};

class ShotPlant:public Plant
{
	public:
		ShotPlant()=default;
		bool isNull() {return false;};
		virtual std::string display() {return "ShotPlant gives " + std::to_string(damage_) + " damage points";}

		//void Attacked(Game);
	private:
		int damage_;

};
#endif // PLANT_H
