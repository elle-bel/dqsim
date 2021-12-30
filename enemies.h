#ifndef _MYENEMIES_H_
#define _MYENEMIES_H_
#include <string>

class Hero;

class Enemy{
    std::string name;
    int maxHP;
    int attack;
    int defense;
    int speed;
    public:
        Enemy(std::string name, int maxHP, int attack, int defense, int speed);
        int getNormAttack(Hero &h, int atkVal);
        std::string getName();
};

#endif