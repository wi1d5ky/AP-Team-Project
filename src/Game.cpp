#include <cstring>
#include <cstdlib>
#include <fstream>
#include "Game.h"

using namespace std;

Game::Game(int numofland , int numofzombie )
        :map_(numofland),numofzombie_(numofzombie), numofland_(numofland) ,player_( RandPos(numofland) )
{
    if( numofzombie_ > Zombie::maxZombie ) numofzombie_ = Zombie::maxZombie ;
    else if( numofzombie_ <= 0 ) numofzombie_ = Game::defaultZombie ;

    for (int i=0; i<numofzombie_; i+=1){
        zombies_.push_back(Zombie(RandPos(numofland),i));
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
    for (unsigned int i=0; i < plantTypes_.size(); i+=1){
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
    for (int i=0; i<numofland_; i+=1){
        cout << "[" << i << "]{" ;
        if (player_.getPos() == i) cout << "*";
        else cout << " ";

        for (int j=0; j<zombies_.size(); j+=1){
            if (zombies_[j].getPos() == i)
                cout << zombies_[j].getId() ;
            else
                cout << " ";
        }
        cout << "}";
        if ( !map_[i].getStood() ) cout << "Empty";
        else map_[i].getPlant()->displayinfo();

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

    if (map_[player_.getPos()].getStood()){
        if( map_[player_.getPos()].getPlant()->doThing(player_,map_.getPlantList()) == 0)
                cout << "You have get coin!" << endl;

        cout << "Already planted!" << endl;
        return;
    }

    if ( player_.currentMoney() < min_price_ ){
        cout << "You do not have enough money to plant anything!" << endl;
        return;
    }

    cout << "Player $" << player_.currentMoney() << ":    Enter your choice (" << plantTypes_.size()
                                                        << " to give up, default: " << lastmove_ << ")...>";
    string tmp;
    getline(cin,tmp);
    int choice = atoi(tmp.c_str());
    if ( choice < 0 || choice > plantTypes_.size() || !tmp.size() ) choice = lastmove_ ;
    else lastmove_ = choice ;

    if (choice == plantTypes_.size() ){
        cout << "You give up!" << endl;
    }
    else if( map_.put( plantTypes_[choice]->clone() , player_.getPos()) ){
        player_ -= plantTypes_[choice]->getCost();
        cout << "You have planted " << plantTypes_[choice]->getName() << " at land " << player_.getPos() << " !" << endl;
    }
}

void Game::NextStep(){
    size_t currentPos = player_.getPos();
    player_.setPos((Move(Player::step_)+currentPos)%numofland_);
}

void Game::ZombieAction()
{
    for (int i=0; i<zombies_.size(); i+=1)
    {
        int ZcurrentPos = zombies_[i].getPos();
        zombies_[i].setPos((ZcurrentPos+Move(Zombie::step_))%numofland_);
        int ZPos = (ZcurrentPos+Move(Zombie::step_))%numofland_;
        zombies_[i].setPos(ZPos);

        DisplayMap();
        cout << string(50,'-') << endl;//bar
        DisplayZombieInfo();
        cout << string(50,'=') << endl;
        cout << "Zombie [" << i << "] moves to land " << ZPos << "." << endl;


        if( map_[zombies_[i].getPos()].getStood() )
        {
            int damage = map_[zombies_[i].getPos()].getPlant()->beAttacked(zombies_[i]) ;

            if( damage > 0 ){
                cout << map_[zombies_[i].getPos()].getPlant()->getName() << " gives "
                                            <<  damage << " damage to the zombie!" << endl ;
            }
            if (zombies_[i].isDied()){
                cout << "Zombie is killed!" << endl ;
                zombies_.erase(zombies_.begin()+i);
            }
            else{
                cout << "Zombie eats plant " << map_[zombies_[i].getPos()].getPlant()->getName()
                                        << " and causes damage "  << zombies_[i].getAttack() << "." << endl ;
            }
            if( map_[zombies_[i].getPos()].getPlant()->isDied() )
            {
                cout << map_[zombies_[i].getPos()].getPlant()->getName() << " is dead!" << endl ;
                if( damage == map_[zombies_[i].getPos()].getPlant()->getFullhp() )
                    numofdeadbomb_ += 1 ;

                map_[zombies_[i].getPos()].recycle();
            }
        }

        system("pause");
        system("cls");
    }
}

bool Game::isWin()
{
    return (zombies_.size() == 0 && !isLose() && !deadTooMany() ) ;
}
bool Game::isLose()
{
    return ( map_.getPlantList().size() == 0 ) ;
}
bool Game::deadTooMany()
{
    return numofdeadbomb_ > numofzombie_/2 ;
}


