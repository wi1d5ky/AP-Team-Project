#define TESTMODE 1

#include <iostream>
#include "Map.h"

using namespace std;

#if TESTMODE

int main()
{
	Map * a = new Map(10);
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
