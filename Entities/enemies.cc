#include <iostream>
#include <random>
#include "enemies.h"
#include "heroes.h"

Enemy::Enemy(std::string name, int maxHP, int maxMP, int attack, int defense, int speed, int expGiven)
: name{name}, maxHP{maxHP}, maxMP{maxMP}, attack{attack}, defense{defense}, speed{speed}, expGiven{expGiven} {
    curHP = maxHP;
    curMP = maxMP;
}

int Enemy::getType(){
    return 1;
}

int Enemy::getHp(){
    return curHP;
}

int Enemy::getMp(){
    return curMP;
}

int Enemy::giveExp(){
    return expGiven;
}

void Enemy::incExp(int exp){
    // unused
}

int Enemy::getNormAttack(Entity & ent, int atkVal){
    int dmgVal = std::max(atkVal - (int)std::ceil(atkVal * ((float)defense / 100)), 0);
    std::cout << ent.getName() << " did " << dmgVal << " damage to " << name << "!" << std::endl;
    if (curHP - dmgVal < 0){
        curHP = 0;
    } else {
        curHP -= dmgVal;
    }
    if (curHP == 0){
        std::cout << name << " was defeated!" << std::endl;
    }
    return curHP;
}

// fix to account for downed party members
void Enemy::normalAttack(std::vector<Entity *> ent){
    int i = (rand() % ent.size());
    int heroHP = ent[i]->getNormAttack(*this, attack);
}

std::string Enemy::getName(){
    return name;
}

std::vector<int> Enemy::getStats(){
    std::vector<int> stats = {attack, defense, speed, maxHP, maxMP};
    return stats;
}

int Enemy::getFixedAtk(int atk){
    if (curHP - atk < 0){
        curHP = 0;
    } else {
        curHP -= atk;
    }
    if (curHP == 0){
        std::cout << name << " was defeated!" << std::endl;
    }
    return curHP;
}

//first function that gets called when a magic is selected
// returns the proper entity (either the team(1) or the monsters(0)) to be processed on
std::vector<int> Enemy::call(){
    // hi
}


//assume we are being passed the correct entity
void Enemy::cast(std::vector<Entity *> ent, int index){
    // he
}

int Enemy::getHealed(int heal){
    if (curHP + heal > maxHP){
        curHP = maxHP;
    } else {
        curHP += heal;
    }
    return curHP;
}