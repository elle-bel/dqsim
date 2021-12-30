#include "enemies.h"
#include <iostream>
#include "heroes.h"

Enemy::Enemy(std::string name, int maxHP, int attack, int defense, int speed)
: name{name}, maxHP{maxHP}, attack{attack}, defense{defense}, speed{speed} {}

int Enemy::getNormAttack(Entity & ent, int atkVal){
    int dmgVal = atkVal - (atkVal * (defense / 100));
    std::cout << ent.getName() << " did " << dmgVal << " damage to " << name << "!" << std::endl;
    if (maxHP - dmgVal < 0){
        maxHP = 0;
    } else {
        maxHP -= dmgVal;
    }
    return maxHP;
}

int Enemy::normalAttack(Entity * ent){
    int heroHP = ent->getNormAttack(*this, attack);
    return heroHP;
}

std::string Enemy::getName(){
    return name;
}

std::vector<int> Enemy::getStats(){
    std::vector<int> stats = {attack, defense, speed};
    return stats;
}