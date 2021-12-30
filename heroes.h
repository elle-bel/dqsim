#ifndef _MYHEROES_H_
#define _MYHEROES_H_
#include <string>
#include <vector>
#include <iostream>
#include "entity.h"

class Weapon;
class Enemy;

class Hero: public Entity{
    std::string name;
    int level;
    int maxHP;
    int curHP;
    int attack;
    int defense;
    int speed;
    Weapon * equippedWeapon;
    public:
        Hero(std::string name, int level, int maxHP, int attack, int defense, int speed);
        ~Hero();
        virtual void levelUp() = 0;
        void changeStats(int hpup, int atkup, int defup, int spdup);
        int normalAttack(Entity * ent) override;
        std::string getName() override;
        int getLevel() const;
        std::vector<int> getStats() const;
        void equip(Weapon * w);
        int getNormAttack(Entity &ent, int atkVal) override;
};
        

#endif