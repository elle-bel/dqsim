#ifndef _MYENEMIES_H_
#define _MYENEMIES_H_
#include <string>
#include <vector>
#include "entity.h"

class Hero;

class Enemy: public Entity{
    std::string name;
    int maxHP;
    int curHP;
    int maxMP;
    int curMP;
    int attack;
    int defense;
    int speed;
    int expGiven;
    public:
        Enemy(std::string name, int maxHP, int maxMP, int attack, int defense, int speed, int expGiven);
        int getHp() override;
        int getMp() override;
        int getType() override;
        int giveExp() override;
        int getNormAttack(Entity & ent, int atkVal) override;
        std::string getName() override;
        void normalAttack(std::vector<Entity *> ent) override;
        std::vector<int> getStats() override;
        void cast(std::vector<Entity *> ent, int index) override;
        std::vector<int> call() override;
        void incExp(int exp) override;
        int getFixedAtk(int atk) override;
        int getHealed(int heal) override;
};

#endif