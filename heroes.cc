#include "heroes.h"
#include "weapon.h"
#include <string>
#include <vector>
#include "enemies.h"

Hero::Hero(std::string name, int level, int maxHP, int attack, int defense, int speed)
: name{name}, level{level}, maxHP{maxHP}, attack{attack}, defense{defense}, speed{speed} {
    curHP = maxHP;
}

Hero::~Hero(){
    delete equippedWeapon;
}

std::string Hero::getName() const{
    return name;
}

int Hero::getLevel() const{
    return level;
}

std::vector<int> Hero::getStats() const{
    std::vector<int> stats = {attack, defense, speed};
    return stats;
}

void Hero::changeStats(int hpup, int atkup, int defup, int spdup){
    maxHP += hpup;
    attack += atkup;
    defense += defup;
    speed += spdup;

    level++;
    curHP = maxHP;
}

//add fluctuations in damage??
void Hero::normalAttack(Enemy & e){
    int atkVal = attack + (attack * (equippedWeapon->getAtk() / 100));
    e.getNormAttack(*this, atkVal);
}
