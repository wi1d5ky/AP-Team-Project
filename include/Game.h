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

    void DisplayOfPlant()const;
    void DisplayMap()const;
    void DisplayZombieInfo()const;

    bool InitPlants();

    void PlayerAction();
    void PlantAction();
    void ZombieAction();

    int Move(int max);




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

    std::vector<Plant*> plantlist_;
    
    int Choice(std::string input);
    void MinPriceOfPlant();
    bool EnoughMoney(){return player_.currentMoney() > min_price_;}
    int RandZombiePos()const;

};

#endif // GAME_H
