#include <cstring>
#include <cstdlib>
#include <fstream>
#include "Game.h"

using namespace std;

vector<Plant*> Game::plantTypes_;
int Game::min_price_;

Game::Game(int numOfLand, int numOfZombie) :map_(numOfLand),numOfZombie_(numOfZombie), numOfLand_(numOfLand)
{
    for (int i=0; i<numOfZombie_; i+=1)
    {
        Zombie *temp = new Zombie(InitZombiePos());
        zombies_.push_back(temp);
    }
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
    Clear();
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
            CoinPlant* plant = new CoinPlant(name,cost,fullHP,round,getmoney);
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
            ShotPlant* plant = new ShotPlant(name,cost,fullHP,damage);
            plantTypes_.push_back(plant);
        }
        else if(input == "B")//bomb plant
        {
            f >> name;
            f >> cost_str;
            cost_str.erase(cost_str.begin()+0);// erase $ symbol
            cost = atoi(cost_str.c_str());// change 100 to int
            f >> fullHP;
            BombPlant* plant = new BombPlant(name,cost,fullHP);
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
            HealPlant* plant = new HealPlant(name,cost,fullHP,heal);
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
        plantTypes_[i]->display();
    }
}

int Game::InitZombiePos()const
{
    int pos = rand()%numOfLand_;
    cout <<pos;
    return pos;
}

void Game::MinPriceOfPlant()
{
    min_price_ = INT32_MAX;
    for (unsigned int i=0; i<plantTypes_.size(); i+=1)
    {
        if (min_price_ > plantTypes_[i]->getCost())
        {
            min_price_ = plantTypes_[i]->getCost();
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

void Game::Clear()const
{
    for (int i=0; i<50; i++)
    {
        cout << endl;
    }
}

int Game::Choice(char input)
{
    int choice = atoi(&input);
    if (choice < 1 || choice > (int) plantTypes_.size())
    {
        return lastmove_;
    }
    return choice;
}

void Game::PutMenu()
{
    if (map_[player_.getPos()].getStood())
    {
        Wait();
        return;
    }
    if (!EnoughMoney())
    {
        cout << "You do not have enough money to plant anything!" << endl;
        Wait();
        return;
    }
    cout << "Player $" << player_.currentMoney() << ":    Enter your choice (4 to give up, default: " << lastmove_ << ")...>";
    int choice = Choice(cin.get());
    lastmove_ = choice;
    if (choice == 4)
    {
        cout << "You give up!" << endl;
        Wait();
        return;
    }
    map_.put(*plantTypes_[choice], player_.getPos()); // bool
    cout << "You have planted " << plantTypes_[choice]->getName() << " at land " << player_.getPos() << " !" << endl;
    Wait();
    Clear();
}

void Game::DisplayMap()const
{
    for (int i=0; i<numOfLand_; i+=1)
    {
        cout << "[" << i << "]{" ;
        if (player_.getPos() == i)
        {
            cout << "*";
        }
        else
        {
            cout << " ";
        }

        for (int j=0; j<remainZombie_; j+=1)
        {
            if (zombies_[j]->getPos() == i)
            {
                cout << j;
            }
            else
            {
                cout << " ";
            }
        }
        cout << "}";
        if (!map_[i].getStood())
        {
            cout << "Empty";
        }
        else
        {

        }
        cout << endl;
    }
    DisplayBar();
    cout << "Zombie information:" << endl;
    for (int i=0; i<numOfZombie_; i+=1)
    {
        cout << "[" << i << "] Damage: " << zombies_[i]->getAttack() << " HP:";
        //zombie.display
        cout << endl;
    }
    DisplayBar();
}
