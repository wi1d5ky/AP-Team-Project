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

bool Game::InitPlants()
{
    fstream f;
    f.open("plants.txt");
    return true;
}

vector<Plant> Game::plantTypes_;
void Game::DisplayOfPlant()
{
    for (int i=0; i < plantTypes_.size(); i+=1)
    {
        cout << "[" << to_string(i) << "] " << plantTypes_[i].getName() << " $" << plantTypes_[i].cost() << " HP: " << plantTypes_[i].getFullHP() << " - " << plantTypes_[i].display();
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