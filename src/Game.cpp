#include <cstring>
#include <cstdlib>
#include <fstream>
#include "Game.h"

using namespace std;

Game::Game(int numOfLand , int numOfZombie )
        :map_(numOfLand),numOfZombie_(numOfZombie), numOfLand_(numOfLand) , player_( RandPos(numOfLand) )
{
    for (int i=0; i<numOfZombie_; i+=1){
        zombies_.push_back(Zombie(RandPos(numOfLand)));
    }
    InitPlants() ;
}
Game::~Game(){
    for( auto& pt : plantTypes_ ){
        delete pt ;
    }
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

int Game::RandPos( int range )const
{
    int pos = rand()%range;
    return pos;
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
            if (zombies_[j].getPos() == i)
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
        cout << "[" << i << "] Damage: " << zombies_[i].getAttack() << " HP:";
        zombies_[i].display();
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
    static int lastmove_ = plantTypes_.size() ;

    if (map_[player_.getPos()].getStood())
    {
        map_[player_.getPos()].getPlant()->doThing( player_ , getPlantList() );
    }
    if ( player_.currentMoney() < min_price_ )
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

    string tmp;
    getline(cin,tmp);
    int choice = atoi(tmp.c_str());
    if ( choice < 0 || choice > plantTypes_.size() || !tmp.size() ) choice = lastmove_ ;
    else lastmove_ = choice ;

    if (choice == plantTypes_.size() )
    {
        cout << "You give up!" << endl;
        return;
    }

    //Plant *newPlant = new Plant(*plantTypes_[choice]);
    //plantlist_.push_back(newPlant);

    if(map_.put( plantTypes_[choice]->clone() , player_.getPos()) )// bool
    {
        player_ -= plantTypes_[choice]->getCost();
        cout << "You have planted " << plantTypes_[choice]->getName() << " at land " << player_.getPos() << " !" << endl;
    }
}

vector<Plant*> Game::getPlantList()
{
    vector<Plant*> plantlist ;

    for( int i = 0 ; i < numOfLand_ ; i+=1 )
    {
        if( map_[i].getPlant() != nullptr )
            plantlist.push_back(map_[i].getPlant()) ;
    }
    return plantlist ;
}

void Game::NextStep()
{
    size_t currentPos = player_.getPos();
    player_.setPos((Move(Player::step_)+currentPos)%numOfLand_);
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
        int ZcurrentPos = zombies_[i].getPos();
        zombies_[i].setPos((ZcurrentPos+Move(Zombie::step_))%numOfLand_);
        int ZPos = (ZcurrentPos+Move(Zombie::step_))%numOfLand_;
        zombies_[i].setPos(ZPos);

        DisplayMap();
        cout << string(50,'-') << endl;//bar
        DisplayZombieInfo();
        cout << string(50,'=') << endl;
        cout << "Zombie [" << i << "] moves to land " << ZPos << "." << endl;
        system("pause");
        system("cls");

        if(map_[zombies_[i].getPos()].getStood() && ! map_[zombies_[i].getPos()].getPlant()->beAttacked(zombies_[i]) )
        {
            map_[zombies_[i].getPos()].recycle();
        }
        if (zombies_[i].isDied())
        {
            zombies_.erase(zombies_.begin()+i);
        }

    }
}

bool Game::isWin()
{
    return (zombies_.size() == 0 && getPlantList().size()>0 && numOfDeadBomb_ <= numOfZombie_) ;
}
bool Game::isLose()
{
    int alivePlant = 0;
    for (int i=0 ; i< numOfLand_; i+=1)
    {
        if ( map_[i].getStood() )
        {
            alivePlant++;
        }
    }
    if (!alivePlant)
    {
        return true ;
    }

    return false ;
}



