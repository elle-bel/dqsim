#include "enemies.h"
#include <iostream>
#include <random>
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
    if (maxHP == 0){
        std::cout << name << " was defeated!" << std::endl;
    }
    return maxHP;
}

int Enemy::normalAttack(std::vector<Entity *> ent){
    int i = (rand() % ent.size());
    int heroHP = ent[i]->getNormAttack(*this, attack);
    return heroHP;
}

std::string Enemy::getName(){
    return name;
}

std::vector<int> Enemy::getStats(){
    std::vector<int> stats = {attack, defense, speed, maxHP};
    return stats;
}