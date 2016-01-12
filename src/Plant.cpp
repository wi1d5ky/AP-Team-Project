#include "Plant.h"

Plant::Plant(int cost, int fullHP, std::string name):cost_(cost), full_HP_(fullHP), name_(name)
{
	/* NO NEED TO ENTER ANY CODE*/
}

CoinPlant::CoinPlant(int cost, int fullHP, std::string name, int happend, int getmoney)
   :Plant(cost, fullHP, name) ,happend_round_(happend), getmoney_(getmoney)
{
	/* NO NEED TO ENTER ANY CODE*/
};

std::string CoinPlant::display()
{
	return "gives $" + std::to_string(getmoney_)
		+ " every " + std::to_string(happend_round_) + " rounds";
}

BombPlant::BombPlant(int cost,int fullHP, std::string name)
	:Plant(cost,fullHP,name),damage_(fullHP)
{
	/* NO NEED TO ENTER ANY CODE*/
};

HealPlant::HealPlant(int cost,int fullHP, std::string name,int heal)
	:Plant(cost,fullHP,name),heal_(heal)
{
	/* NO NEED TO ENTER ANY CODE*/
};

ShotPlant(int cost,int fullHP, std::string name,int damage):Plant(cost,fullHP,name),damage_(damage)
{
	/* NO NEED TO ENTER ANY CODE*/
};
