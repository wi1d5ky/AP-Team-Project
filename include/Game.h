#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Zombie.h"

class Game
{
public:
    Game(int numOfLand = 8, int numOfZombie = 3) :map_(numOfLand),numOfZombie_(numOfZombie), numOfLand_(numOfLand) {};

    void StartMenu();
    void InitZombie();
    bool InitPlants();
    void DisplayOfPlant();

private:
    static std::vector<Plant*> plantTypes_;

    Map map_;
    int numOfZombie_ = 3;
    int numOfLand_ = 8;

    Player player_;

    std::vector<Zombie*> zombies_;
};

#endif // GAME_H
