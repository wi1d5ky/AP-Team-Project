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

    constexpr static int maxZombie = 10 ;
    constexpr static int maxLand = 10 ;
    constexpr static int defaultZombie = 3 ;
    constexpr static int defaultLand = 8 ;

    void DisplayOfPlant()const;
    void DisplayMap()const;
    void DisplayZombieInfo()const;

    bool InitPlants();

    void PlayerAction();
    void PlantAction();
    void ZombieAction();

    int Move(int max);
    void NextStep();
    bool isWin(){return win_;}
    bool isLose(){return lose_;}
    void WinOrLose();



private:

    int min_price_ = INT32_MAX;
    int numOfDeadBomb_ = 0;
    int numOfZombie_ ;
    int numOfLand_ ;
    int remainZombie_ = numOfZombie_;
    int RandPos( int range )const;
    std::vector<Plant*> getPlantList() ;
    bool lose_ = false ;
    bool win_ = false ;


    Player player_;
    Map map_;
    std::vector<Zombie*> zombies_;
    std::vector<Plant*> plantTypes_;


};

#endif // GAME_H
