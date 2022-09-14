#ifndef _MYHEROES_H_
#define _MYHEROES_H_
#include <string>
#include <vector>
#include <iostream>
#include "entity.h"

class Weapon;
class Enemy;
class Spells;

class Hero: public Entity{
    std::string name;
    int level;
    int maxHP;
    int curHP;
    int maxMP;
    int curMP;
    int attack;
    int magicalmight;
    int magicalmending;
    int defense;
    int speed;
    Weapon * equippedWeapon;

    //share the same base class since they both do the same thing, but abilities are special to the Hero, magic is not
    std::vector<Spells *> magic;
    std::vector<Spells *> abilities;
    public:
        Hero(std::string name, int level, int maxHP, int maxMP, int attack, int magicalmight, int magicalmending, int defense, int speed);
        ~Hero();
        virtual void levelUp() = 0;
        void changeStats(int hpup, int atkup, int defup, int spdup);
        int normalAttack(std::vector<Entity *> ent) override;
        std::string getName() override;
        int getLevel();
        std::vector<int> getStats() override;
        void equip(Weapon * w);
        int getNormAttack(Entity &ent, int atkVal) override;
        int cast(std::vector<Entity *> ent) override;
        int getFixedAtk(int atk) override;
};
        

#endif