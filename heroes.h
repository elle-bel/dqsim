#ifndef _MYHEROES_H_
#define _MYHEROES_H_
#include <string>
#include <vector>

class Weapon;
class Enemy;

class Hero{
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
        void normalAttack(Enemy & e);
        std::string getName() const;
        int getLevel() const;
        std::vector<int> getStats() const;
};
        

#endif