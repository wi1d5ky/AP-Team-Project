#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Zombie.h"

class Game
{
public:
    Game(int numOfLand , int numOfZombie );
    ~Game() ;

    constexpr static int defaultZombie = 3 ;
    constexpr static int defaultLand = 8 ;

    void DisplayOfPlant()const;
    void DisplayMap()const;
    void DisplayZombieInfo()const;

    void PlayerAction();
    void ZombieAction();

    int Move(int max);
    void NextStep();
    bool isWin();
    bool isLose();
    bool deadTooMany();

private:

    int min_price_ = INT32_MAX;
    int numofdeadbomb_ = 0;
    int numofzombie_ ;
    int numofland_ ;

    bool InitPlants();
    int RandPos( int range )const;

    Player player_;
    Map map_;
    std::vector<Zombie> zombies_;
    std::vector<Plant*> plantTypes_;

};

#endif // GAME_H
