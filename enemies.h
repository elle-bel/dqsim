#ifndef _MYENEMIES_H_
#define _MYENEMIES_H_
#include <string>
#include <vector>
#include "entity.h"

class Hero;

class Enemy: public Entity{
    std::string name;
    int maxHP;
    int attack;
    int defense;
    int speed;
    public:
        Enemy(std::string name, int maxHP, int attack, int defense, int speed);
        int getNormAttack(Entity & ent, int atkVal) override;
        std::string getName() override;
        int normalAttack(std::vector<Entity *> ent) override;
        std::vector<int> getStats() override;
        int cast(std::vector<Entity *> ent);
        int getFixedAtk(int atk) override;
};

#endif