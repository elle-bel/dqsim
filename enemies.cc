#include "enemies.h"
#include <iostream>
#include "heroes.h"

Enemy::Enemy(std::string name, int maxHP, int attack, int defense, int speed)
: name{name}, maxHP{maxHP}, attack{attack}, defense{defense}, speed{speed} {}

int Enemy::getNormAttack(Hero &h, int atkVal){
    int dmgVal = atkVal - (atkVal * (defense / 100));
    std::cout << h.getName() << " did " << dmgVal << " damage to " << name << "!" << std::endl;
    if (maxHP - dmgVal < 0){
        maxHP = 0;
    } else {
        maxHP -= dmgVal;
    }
    return maxHP;
}

std::string Enemy::getName(){
    return name;
}