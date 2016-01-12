#include <string>
#include <fstream>
#include "Game.h"


using namespace std;

void Game::StartMenu()
{
    cout << "-----------------------------" << endl
         << "|     Plants vs. Zombies    |" << endl
         << "-----------------------------" << endl ;
}

bool Game::InitPlants() // process file plants.txt
{
    fstream f;
    f.open("plants.txt");
    if (!f.is_open())
    {
        cout << "Can't find plants.txt!" << endl;
        return false;
    }
    while (!f.eof())
    {
        string input,name,cost_str;
        int cost = 0;
        int fullHP = 0;

        //getline(f,input);
        f >> input;

        if (input == "C")//coin plant
        {
            f >> name;
            f >> cost_str;
            cost_str.erase(cost_str.begin()+0);// erase $ symbol
            cost = atoi(cost_str.c_str());// change 100 to int
            f >> fullHP;
            int happen,getmoney;
            f >> happen;
            f >> getmoney;
            CoinPlant *plant = new CoinPlant(cost,fullHP,name,happen,getmoney);
            plantTypes_.push_back(plant);
        }
        else if(input == "S")//horn plant or shoot plant
        {
            f >> name;
            f >> cost_str;
            cost_str.erase(cost_str.begin()+0);// erase $ symbol
            cost = atoi(cost_str.c_str());// change 100 to int
            f >> fullHP;
            int damage;
            f >> damage;
            ShotPlant *plant = new ShotPlant(cost,fullHP,name,damage);
            plantTypes_.push_back(plant);
        }
        else if(input == "B")//bomb plant
        {
            f >> name;
            f >> cost_str;
            cost_str.erase(cost_str.begin()+0);// erase $ symbol
            cost = atoi(cost_str.c_str());// change 100 to int
            f >> fullHP;
            BombPlant *plant = new BombPlant(cost,fullHP,name);
            plantTypes_.push_back(plant);
        }
        else if(input == "H")//heal plant
        {
            f >> name;
            f >> cost_str;
            cost_str.erase(cost_str.begin()+0);// erase $ symbol
            cost = atoi(cost_str.c_str());// change 100 to int
            f >> fullHP;
            int heal;
            f >> heal;
            HealPlant *plant = new HealPlant(cost,fullHP,name,heal);
            plantTypes_.push_back(plant);
        }
        else
        {

        }
    }

    f.close();
    return true;
}

vector<Plant*> Game::plantTypes_;
void Game::DisplayOfPlant()
{
    for (unsigned int i=0; i < plantTypes_.size(); i+=1)
    {
        cout << "[" << to_string(i) << "] " << plantTypes_[i]->getName() << " $" << plantTypes_[i]->cost() << " HP: " << plantTypes_[i]->getFullHP() << " - " << plantTypes_[i]->display() << endl;
    }
}

void Game::InitZombie()
{
    for (int i=0; i < numOfZombie_; i+=1)
    {
        int pos = rand()%numOfLand_;
        zombies_[i] = new Zombie(pos);
    }
}
