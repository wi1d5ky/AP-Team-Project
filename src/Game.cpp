#include <cstring>
#include <cstdlib>
#include <fstream>
#include "Game.h"

using namespace std;

Game::Game(int numOfLand , int numOfZombie ) :map_(numOfLand),numOfZombie_(numOfZombie), numOfLand_(numOfLand)
{
    for (int i=0; i<numOfZombie_; i+=1)
    {
        Zombie *temp = new Zombie(RandZombiePos());
        zombies_.push_back(temp);
    }
    InitPlants() ;
}

bool Game::InitPlants() // process file plants.txt
{
    fstream f("plants.txt");

    if (!f)
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
            f >> name >> cost_str ;
            cost_str.erase(cost_str.begin()+0);// erase $ symbol
            cost = atoi(cost_str.c_str());// change 100 to int
            f >> fullHP;
            int round,getmoney;
            f >> round >> getmoney ;
            CoinPlant* plant = new CoinPlant(name,cost,fullHP,round,getmoney);
            plantTypes_.push_back(plant);
        }
        else if(input == "S")//horn plant or shoot plant
        {
            f >> name >> cost_str ;
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
            f >> name >> cost_str ;
            cost_str.erase(cost_str.begin()+0);// erase $ symbol
            cost = atoi(cost_str.c_str());// change 100 to int
            f >> fullHP;
            BombPlant* plant = new BombPlant(name,cost,fullHP);
            plantTypes_.push_back(plant);
        }
        else if(input == "H")//heal plant
        {
            f >> name >> cost_str ;
            cost_str.erase(cost_str.begin()+0);// erase $ symbol
            cost = atoi(cost_str.c_str());// change 100 to int
            int heal;
            f >> fullHP >> heal;
            HealPlant* plant = new HealPlant(name,cost,fullHP,heal);
            plantTypes_.push_back(plant);
        }

        if( min_price_ > plantTypes_.back()->getCost() )
            min_price_ = plantTypes_.back()->getCost();
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

int Game::RandZombiePos()const
{
    int pos = rand()%numOfLand_;
    return pos;
}


int Game::Choice(string input)
{
    int choice = atoi(input.c_str());
    if (choice < 0 || choice > (int) plantTypes_.size())
    {
        return lastmove_;
    }
    return choice;
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

        for (int j=0; j<zombies_.size(); j+=1)
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
        if ( !map_[i].getStood() )
        {
            cout << "Empty";
        }
        else
        {
            map_[i].getPlant()->displayinfo();
        }
        cout << endl;
    }
}

void Game::DisplayZombieInfo()const
{
    cout << "Zombie information:" << endl;
    for (int i=0; i<zombies_.size(); i+=1)
    {
        cout << "[" << i << "] Damage: " << zombies_[i]->getAttack() << " HP:";
        zombies_[i]->display();
        cout << endl;
    }
}

int Game::Move(int max)
{
    int move = rand()%max;
    return move+1;
}

void Game::PlayerAction()
{
    if (map_[player_.getPos()].getStood())
    {
        map_[player_.getPos()].getPlant()->doThing( player_ , getPlantList() );
    }
    if (!EnoughMoney())
    {
        cout << "You do not have enough money to plant anything!" << endl;
        return;
    }
    if (map_[player_.getPos()].getStood())
    {
        cout << "Already planted!" << endl;
        return;
    }
    cout << "Player $" << player_.currentMoney() << ":    Enter your choice (4 to give up, default: " << lastmove_ << ")...>";
    string tempstr;
    getline(cin,tempstr);
    int choice = Choice(tempstr);
    lastmove_ = choice;
    if (choice == plantTypes_.size() )
    {
        cout << "You give up!" << endl;
        return;
    }

    //Plant *newPlant = new Plant(*plantTypes_[choice]);
    //plantlist_.push_back(newPlant);

    if(map_.put( plantTypes_[choice]->clone() , player_.getPos()) )// bool
    {
        //player_ -= plantTypes_[choice]->getCost(); //扣錢
        cout << "You have planted " << plantTypes_[choice]->getName() << " at land " << player_.getPos() << " !" << endl;
    }
}

vector<Plant*> Game::getPlantList()
{
    vector<Plant*> plantlist ;

    for( int i = 0 ; i < numOfLand_ ; i+=1 )
    {
        plantlist.push_back(map_[i].getPlant()) ;
    }
    return plantlist ;
}

void Game::NextStep()
{
    size_t currentPos = player_.getPos();
    player_.setPos((Move(6)+currentPos)%numOfLand_);
}

void Game::PlantAction()
{
    for (int i=0; i<numOfLand_; i+=1)
    {
        if (map_[i].getStood())
        {
            if(map_[i].getPlant()->doThing(player_,getPlantList()) == 0)
                cout << "You have get coin!" << endl;
        }
    }
}

void Game::ZombieAction()
{

    for (int i=0; i<zombies_.size(); i+=1)
    {
        
        int ZcurrentPos = zombies_[i]->getPos();
        zombies_[i]->setPos((ZcurrentPos+Move(3))%numOfLand_);
        if(map_[zombies_[i]->getPos()].getStood() && ! map_[zombies_[i]->getPos()].getPlant()->beAttacked(*zombies_[i]) )
        {
            map_[zombies_[i]->getPos()].recycle();
        }
        if (zombies_[i]->getHP()<=0)
        {
            zombies_.erase(zombies_.begin()+i);
        }
        
    }
    
}
