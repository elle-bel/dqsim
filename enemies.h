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
        void getNormAttack(Hero &h, int atkVal);
};

#endif