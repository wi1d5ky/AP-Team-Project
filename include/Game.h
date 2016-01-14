#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Zombie.h"

class Game
{
public:
    Game(int numOfLand = 8, int numOfZombie = 3) :map_(numOfLand),numOfZombie_(numOfZombie), numOfLand_(numOfLand) {}

    void StartMenu()const;
    void DisplayBar()const;
    void DisplayRule()const;
    void DisplayOfPlant()const;
    void DisplayWin()const;
    void DisplayLose()const;
    void Wait()const;
    
    void InitZombie();
    bool InitPlants();
    
    void MinPriceOfPlant();
    bool EnoughMoney(){return player_.currentMoney() > min_price_;}
    
    void PutMenu();
    int Choice(char input);
    //bool PutPlant(int pos, Plant plant);
    


private:
    static std::vector<Plant> plantTypes_;
    static int min_price_;

    Map map_;
    int numOfZombie_ = 3;
    int numOfLand_ = 8;
    
    int remainZombie_ = numOfZombie_;
    int numOfDeadBomb_ = 0;

    Player player_;

    std::vector<Zombie> zombies_;
};

int ReadChoice(char input[]);

#endif // GAME_H
