#include <cstring>
#include <cstdlib>
#include <fstream>
#include "Game.h"

using namespace std;

int ReadChoice(char input)
{
    int choice = atoi(&input);
    if (choice < 1 && choice > 10)
    {
        return -1;
    }
    return choice;
}

//===================================================

vector<Plant> Game::plantTypes_;
int Game::min_price_;

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
    Wait();
}

void Game::DisplayWin()const
{
    cout << endl << endl << endl << "Congratulations! You have killed all zombies!" << endl;
    Wait();
}

void Game::DisplayLose()const
{
    cout << endl << endl << endl << "Oh no... You have no plant on the map ...." << endl;
    Wait();

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

void Game::MinPriceOfPlant()
{
    min_price_ = INT32_MAX;
    for (int i=0; i<plantTypes_.size(); i+=1)
    {
        if (min_price_ > plantTypes_[i].getCost())
        {
            min_price_ = plantTypes_[i].getCost();
        }
    }
    //return min_price_;
}

void Game::Wait()const
{
    cout << "Press any key to continue...";
    cin.get();
    cout << endl;
}

int Game::Choice(char input)
{
    int choice = atoi(&input);
    if (choice < 1 && choice >= plantTypes_.size())
    {
        return -1;
    }
    return choice;
}

void Game::PutMenu()
{
    if (!EnoughMoney())
    {
        cout << "You do not have enough money to plant anything!" << endl;
        Wait();
        return;
    }
    cout << "Player $" << player_.currentMoney() << ":    Enter your choice (4 to give up, default:4)...>";
    int choice = Choice(cin.get());

}
