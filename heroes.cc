#include "heroes.h"
#include "weapon.h"
#include "spells.h"
#include <string>
#include <vector>
#include <iostream> 
#include <sstream>
#include "enemies.h"

Hero::Hero(std::string name, int level, int maxHP, int maxMP, int attack, int magicalmight, int magicalmending, int defense, int speed)
: name{name}, level{level}, maxHP{maxHP}, maxMP{maxMP}, attack{attack}, magicalmight{magicalmight},
magicalmending{magicalmending}, defense{defense}, speed{speed} {
    curHP = maxHP;
    curMP = maxMP;
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

//wont happen for a while but use decorator pattern for atk/spd/def buffs/debuffs
//will need to make a "calc atk/calc def" function for entities, instead of the atkVal we use..?

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
    std::string input;
    int response;
    while (getline(std::cin, input)){
        std::istringstream ss (input);
        if (ss >> response){
            if (response < 1 || response >= len) {
                std::cout << "Invalid Input" << std::endl;
            } else{
                int enemyHP = ent[response - 1]->getNormAttack(*this, atkVal);
                return enemyHP;
            }
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


//eventually add group spells
int Hero::cast(std::vector<Entity *> ent){
    int magicLen = magic.size();
    std::cout << "Select a an option (Type number eg: 1, 2, 3,...)" << std::endl;
    for (int i = 0; i < magicLen; i++){
        std::cout << i+1 << ": " << magic[i]->getName() << std::endl;
    }
    std::string input;
    int response;
    int len = ent.size();
    while (getline(std::cin, input)){
        std::istringstream ss (input);
        if (ss >> response){
            if (response < 1 || response >= magicLen){
                std::cout << "Invalid Input" << std::endl;
            } else if (curMP >= magic[response-1]->getmpRequired()){
                int magindx = response - 1;
                std::cout << "Who should " << name << " target? (Type number eg: 1, 2, 3...)" << std::endl;
                for (int i = 0; i < len; i++){
                    if(ent[i]->getStats()[3] > 0){
                        std::cout << i+1 << ": " << ent[i]->getName() << std::endl;
                    }
                }

                while (getline(std::cin, input)){
                    std::istringstream ss (input);
                    if (ss >> response){
                        //this is wrong but we will fix later
                        int dmg = magic[magindx]->getbaseDmg() + (magic[magindx]->getbaseDmg() * (magicalmight/100));
                        int enemyHP = ent[response-1]->getFixedAtk(dmg);
                        curMP -= magic[magindx]->getmpRequired();
                        return enemyHP;
                    }
                }
            } else {
                std::cout << "You don't have enough MP!" << std::endl;
            }
        }
    }
}

int Hero::getFixedAtk(int atk){
    curHP -= atk;
    return curHP;
}
