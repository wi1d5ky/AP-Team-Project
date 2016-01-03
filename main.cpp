#define TESTMODE 1

#include <iostream>
#include "Player.h"
#include "Map.h"

using namespace std;

#if TESTMODE

int main()
{
	Player player;
	Map * a = new Map(10);

	cout << "Player has $" << player.currentMoney() << endl;
	cout << "There are " << a->size() <<  " planet(s) on the map:" << endl;
	for(int i = 0 ; i < a->size() ; ++i)
		cout << a->list()[0].getPlantName() << endl;
	return 0;
}

#else
int main( int argc , char* argv[] )
{
	cout << "Hello, world." << endl ;
	return 0 ;
}
#endif // TESTMODE
