#define TESTMODE 1

#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include "Player.h"
#include "Zombie.h"
#include "Map.h"
#include "Game.h"

using namespace std;

#if TESTMODE

constexpr static int MAX = 10;// lands and zombies

int ReadChoice(string input)
{
    int choice = atoi(input.c_str());
    if (choice < 1 || choice > MAX)
    {
        return -1;
    }
    return choice;
}

void DisplayBar()
{
    cout << string(77,'=') ;
    cout << endl ;
}

void Wait()
{
    cout << "Press any key to continue...";
    cin.get();
    cout << endl;
}

void Clear()
{
    for (int i=0; i<50; i++)
    {
        cout << endl;
    }
}

void DisplayRule()
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

void DisplayWin()
{
    cout << endl << endl << endl << "Congratulations! You have killed all zombies!" << endl;
    Wait();
}

void DisplayLose()
{
    cout << endl << endl << endl << "Oh no... You have no plant on the map ...." << endl;
    Wait();
    
}

int main()
{
    srand(static_cast<unsigned>(time(0)));
    
    cout << "-----------------------------" << endl
         << "|     Plants vs. Zombies     |" << endl
         << "-----------------------------" << endl ;
    cout << "Number of lands on the map (1-10, default:8)...>";
    string landstr,zombiestr;
    getline(cin,landstr);
    int numOfLands = ReadChoice(landstr);
    if (numOfLands == -1)
    {
        numOfLands = 8;
    }
    cout << "Number of zombies on the map (1-10, default:3)...>";
    getline(cin,zombiestr);
    int numOfZombies = ReadChoice(zombiestr);
    if (numOfZombies == -1)
    {
        numOfZombies = 3;
    }
    Game game(numOfLands,numOfZombies);

    game.InitPlants();
    DisplayRule();
    
    game.DisplayMap();
    DisplayBar();
    game.DisplayZombieInfo();
    DisplayBar();
    
    cout << endl;
    game.PlayerAction();
    Wait();
    Clear();
    
    game.DisplayMap();
    DisplayBar();
    game.DisplayZombieInfo();
    DisplayBar();
    

    /*
    int land_num = 8;
    ///////////////////////////////////////////////////////////

	constexpr int zombie_num = 3;
    Zombie * zombies[zombie_num] = {};
    // Should set position
    zombies[0] = new Zombie(4);
    zombies[1] = new Zombie(5);
    zombies[2] = new Zombie(6);

    for(int i = 0 ; i < 3 ; ++i)
	{
		cout << "[" + to_string(i) + "] Damage: " + to_string(zombies[i]->attack()) + " HP:";
		for(int j = 0 ; j < zombies[i]->getFullHP(); ++j)
			cout << "*";
		cout << endl;
	}

    ///////////////////////////////////////////////////////////

	Map * game_map = new Map(land_num);
	Player player;

	cout << "Player has $" << player.currentMoney() << endl;
	cout << "There are " << game_map->size() <<  " planet(s) on the map:" << endl;

	for(int i = 0 ; i < game_map->size() ; ++i)
		cout << game_map->land(i) << endl;

	///////////////////////////////////////////////////////////

	int stand = 7;
	Plant first_plant = player.buy(1);
	Plant second_plant = player.buy(2);
	game_map->put(first_plant, stand);
	if(game_map->put(second_plant, stand))
	{
		// put plant success
	}
	else
	{
		// the place has been stood, choose another
		game_map->put(second_plant, 6);
	}

    for(int i = 0 ; i < game_map->size() ; ++i)
		cout << game_map->land(i) << endl;

	///////////////////////////////////////////////////////////

	cout << "////// Zombie Position /////" << endl;
	for(int i = 0 ; i < zombie_num ; ++i)
		cout << "[" + to_string(i) +"] " << zombies[i]->position() << endl;

	cout << endl;

	zombies[0]->setPos(1);
	zombies[1]->setPos(2);
	zombies[2]->setPos(3);

	for(int i = 0 ; i < zombie_num ; ++i)
		cout << "[" + to_string(i) +"] " << zombies[i]->position() << endl;

	///////////////////////////

	cout << player.currentMoney() << endl;
	cout << (player.canBuy() ? "Can Buy!" : "Can't Buy") << endl;

	Plant first_plant = player.buy(1);

	cout << player.currentMoney() << endl;
	cout << (player.canBuy() ? "Can Buy!" : "Can't Buy") << endl;

	*/


	return 0;
}

#else
int main( int argc , char* argv[] )
{
	cout << "Hello, world." << endl ;
	return 0 ;
}
#endif // TESTMODE
