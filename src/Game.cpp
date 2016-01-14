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

void Game::DisplayBar()const
{
    for (int i=0; i<77; i+=1)
    {
        cout << "=" ;
    }
    cout << endl ;
}

void Game::DisplayRule()const
{
    DisplayBar();
    cout << "Plants vs. Zombies Rule:" << endl << endl
         << "How to win:" << endl
         << "  (1) All zombies are dead." << endl
         << "  (2) At least one plant is live." << endl
         << "  (3) The number of dead bomb plants cannot exceed the number of zombies." << endl << endl
         << "How to lose:" << endl
         << "  All plants are dead." << endl;
    DisplayBar();
    cout << "Press any key to continue...";
    cin.get();
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


