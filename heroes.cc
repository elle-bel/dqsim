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

std::string Hero::getName() {
    return name;
}

int Hero::getLevel() {
    return level;
}

std::vector<int> Hero::getStats() {
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
int Hero::normalAttack(std::vector<Entity *> ent){
    int atkVal = attack + (attack * (equippedWeapon->getAtk() / 100));
    int len = ent.size();
    std::cout << "Who should " << name << " attack? (Type number eg: 1, 2, 3...)" << std::endl;
    for (int i = 0; i < len; i++){
        if(ent[i]->getStats()[3] > 0){
            std::cout << i+1 << ": " << ent[i]->getName() << std::endl;
        }
    }
    int response;
    while (std::cin){
        if (std::cin >> response){
            int enemyHP = ent[response - 1]->getNormAttack(*this, atkVal);
            return enemyHP;
        }
    }

}

int Hero::getNormAttack(Entity &ent, int atkVal){
    int dmgVal = atkVal - (atkVal * (defense / 100));
    std::cout << ent.getName() << " did " << dmgVal << " damage to " << name << std::endl; 
    if (curHP - dmgVal < 0){
        curHP = 0;
    } else {
        curHP -= dmgVal;
    }
    if (curHP == 0){
        std::cout << name << " was wiped out!" << std::endl;
    }
    return curHP;
}

void Hero::equip(Weapon * w){
    equippedWeapon = w;
    std::cout << name << " equipped " << w->getName() << std::endl;
}
