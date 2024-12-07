#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include "spells.h"
#include "spelltypes.h"

SingleAtk::SingleAtk(std::string spellName, int baseDmg, int mpRequired): Spells{spellName, mpRequired}, baseDmg{baseDmg} {}

// 0 means team
// 1 means monsters
int SingleAtk::getEntType(){
    return 1;
}

int SingleAtk::getBaseDmgorHeal(){
    return baseDmg;
}

void SingleAtk::target(std::vector<Entity *> ent, int might, int mending){
    //ask who (single target) to attack
    int len = ent.size();
    for (int i = 0; i < len; i++){
        if(ent[i]->getHp() > 0){
            std::cout << i+1 << ": " << ent[i]->getName() << std::endl;
        }
    }
    std::string input;
    int response;
    while (getline(std::cin, input)){
        std::istringstream ss (input);
        if (ss >> response){
            if (response < 1 || response > len) {
                std::cout << "Invalid Input" << std::endl;
                continue;
            } else{
                int dmg = getBaseDmgorHeal() + std::ceil(getBaseDmgorHeal() * ((float)might/100));
                std::cout << getName() << " did " << dmg << " damage to " << ent[response-1]->getName() << std::endl;
                int enemyHP = ent[response - 1]->getFixedAtk(dmg);
                break;
            }
        }
    }
}

SingleHeal::SingleHeal(std::string spellName, int baseHp, int mpRequired): Spells{spellName, mpRequired}, baseHp{baseHp} {}

int SingleHeal::getEntType(){
    return 0;
}

int SingleHeal::getBaseDmgorHeal(){
    return baseHp;
}

void SingleHeal::target(std::vector<Entity *> ent, int might, int mending){
    int len = ent.size();
    for (int i = 0; i < len; i++){
        if(ent[i]->getHp() > 0){
            std::cout << i+1 << ": " << ent[i]->getName() << std::endl;
        }
    }

    std::string input;
    int response;
    while (getline(std::cin, input)){
        std::istringstream ss (input);
        if (ss >> response){
            if (response < 1 || response > len) {
                std::cout << "Invalid Input" << std::endl;
                continue;
            } else{
                int heal = getBaseDmgorHeal() + std::ceil(getBaseDmgorHeal() * ((float)mending/100));
                int heroHP = ent[response - 1]->getHealed(heal);
                std::cout << getName() << " healed " << ent[response - 1]->getName() << " for " << heal << "HP" << std::endl;
                break;
            }
        }
    }

}