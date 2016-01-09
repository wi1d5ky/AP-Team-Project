#define TESTMODE 1

#include <iostream>
#include <algorithm>
#include <vector>
#include "Player.h"
#include "Zombie.h"
#include "Map.h"

using namespace std;

#if TESTMODE

void StartMenu()
{
    cout << "-----------------------------" << endl << "|     Plants vs. Zombies     |" << endl << "-----------------------------" << endl ;
}

int main()
{
    StartMenu();

    cout << "Number of lands on the map (1-10, default:8)...>" << endl;
    //int land_num = 8;

    ///////////////////////////////////////////////////////////

	Map * game_map = new Map(8);
	Player player;
	vector<string> menu = player.store();

	cout << "Player has $" << player.currentMoney() << endl;
	cout << "There are " << game_map->size() <<  " planet(s) on the map:" << endl;

	for(int i = 0 ; i < game_map->size() ; ++i)
		cout << game_map->land(i) << endl;

	for(unsigned int i = 0 ; i < menu.size() ; ++i)
		cout << "[" + to_string(i) + "] " + menu[i] << endl;

	return 0;
}

#else
int main( int argc , char* argv[] )
{
	cout << "Hello, world." << endl ;
	return 0 ;
}
#endif // TESTMODE
