#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Zombie.h"
#include "Map.h"
#include "Game.h"

using namespace std;


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
//    for (int i=0; i<50; i++)
//    {
//        cout << endl;
//    }
    system("cls");
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
    srand(time(NULL));

    cout << "-----------------------------" << endl
         << "|     Plants vs. Zombies     |" << endl
         << "-----------------------------" << endl ;
    cout << "Number of lands on the map (1-10, default:8)...>";

    char c ;
    int zombienum = 0 , landnum = 0 ;
    while( c = getchar() , c != '\n' ) {
        landnum *= 10 ;
        landnum += (c-'0') ;
    }
    if( !landnum ) landnum = Game::defaultLand ;

    cout << "Number of zombies on the map (1-10, default:3)...>";
    while( c = getchar() , c != '\n' ) {
        zombienum *= 10 ;
        zombienum += (c-'0') ;
    }
    if( !zombienum ) zombienum = Game::defaultZombie ;


    Game game(landnum,zombienum);
    DisplayRule();


    while(true)
    {
        game.DisplayMap();
        DisplayBar();
        game.DisplayZombieInfo();
        DisplayBar();
        game.DisplayOfPlant();

        cout << endl;
        game.PlayerAction();
        Wait();
        Clear();
        
        game.ZombieAction();
        
        game.NextStep();
    }


    

	return 0;
}


