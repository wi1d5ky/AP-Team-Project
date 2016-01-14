#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Zombie.h"

class Game
{
public:
    Game(int numOfLand, int numOfZombie);

    void DisplayBar()const;
    void DisplayRule()const;
    void DisplayOfPlant()const;
    
    void DisplayWin()const;
    void DisplayLose()const;
    void Wait()const;
    void Clear()const;
    
    int InitZombiePos()const;
    bool InitPlants();
    
    void MinPriceOfPlant();
    bool EnoughMoney(){return player_.currentMoney() > min_price_;}
    
    void PutMenu();
    int Choice(char input);
    
    void DisplayMap()const;


private:
    static std::vector<Plant*> plantTypes_;
    static int min_price_;

    Map map_;
    int numOfZombie_ = 3;
    int numOfLand_ = 8;
    
    int remainZombie_ = numOfZombie_;
    int numOfDeadBomb_ = 0;
    
    int lastmove_ = 4;

    Player player_;

    std::vector<Zombie*> zombies_;
};

#endif // GAME_H
