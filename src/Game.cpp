#include <cstring>
#include <cstdlib>
#include <fstream>
#include "Game.h"


using namespace std;

vector<Plant> Game::plantTypes_;

void Game::StartMenu()const
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
            int round,getmoney;
            f >> round;
            f >> getmoney;
            CoinPlant plant(name,cost,fullHP,round,getmoney);
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
            ShotPlant plant(name,cost,fullHP,damage);
            plantTypes_.push_back(plant);
        }
        else if(input == "B")//bomb plant
        {
            f >> name;
            f >> cost_str;
            cost_str.erase(cost_str.begin()+0);// erase $ symbol
            cost = atoi(cost_str.c_str());// change 100 to int
            f >> fullHP;
            BombPlant plant(name,cost,fullHP);
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
            HealPlant plant(name,cost,fullHP,heal);
            plantTypes_.push_back(plant);
        }
        else
        {

        }
    }

    f.close();
    return true;
}

void Game::DisplayOfPlant()const
{
    for (unsigned int i=0; i < plantTypes_.size(); i+=1)
    {
        cout << "[" << i << "] ";
        plantTypes_[i].display();
        cout << endl;
    }
}

void Game::InitZombie()
{
    for (int i=0; i < numOfZombie_; i+=1)
    {
        int pos = rand()%numOfLand_;
        zombies_[i] = Zombie(pos);
    }
}
