#include <string>
#include <vector>
#include <iostream> 
#include <sstream>
#include <cmath>
#include "heroes.h"
#include "../weapon.h"
#include "../BattleActions/spells.h"
#include "enemies.h"
#include "../BattleActions/spelltypes.h"

Hero::Hero(std::string name, int level, int maxHP, int maxMP, int attack, int magicalmight, int magicalmending, int defense, int speed)
: name{name}, level{level}, maxHP{maxHP}, maxMP{maxMP}, attack{attack}, magicalmight{magicalmight},
magicalmending{magicalmending}, defense{defense}, speed{speed} {
    curHP = maxHP;
    curMP = maxMP;
    curExp = 0;
    int x = ceil((level,1.5)*20+10*(level));
    expToNext = x + 10-(x % 10);
}

Hero::~Hero(){
    delete equippedWeapon;
}

std::string Hero::getName() {
    return name;
}

int Hero::getHp(){
    return curHP;
}

int Hero::getMp(){
    return curMP;
}

int Hero::getLevel() {
    return level;
}

std::vector<int> Hero::getStats() {
    std::vector<int> stats = {attack, defense, speed, maxHP, maxMP, magicalmending, magicalmight};
    return stats;
}

// used ONLY as a level up function btw!!
void Hero::changeStats(int hpup, int atkup, int defup, int spdup, int mmightup, int mmendup){
    std::cout << name << " levelled up!" << std::endl;
    maxHP += hpup;
    attack += atkup;
    defense += defup;
    speed += spdup;
    magicalmending += mmendup;
    magicalmight += mmightup;

    level++;
    int x = ceil((level,1.5)*20+10*(level));
    expToNext = x + 10-(x % 10);
    // exp = ?
    curHP = maxHP;
}

void Hero::incExp(int exp){
    if (curExp + exp > expToNext){
        this->levelUp();
        curExp = ((curExp + exp) - expToNext);
    } else {
        curExp += exp;
    }
}

int Hero::giveExp(){
    // unused
    return 0;
}

int Hero::getType(){
    return 0;
}

//wont happen for a while but use decorator pattern for atk/spd/def buffs/debuffs
//will need to make a "calc atk/calc def" function for entities, instead of the atkVal we use..?

//add fluctuations in damage??
void Hero::normalAttack(std::vector<Entity *> ent){
    int atkVal = attack + std::ceil(attack * ((float)equippedWeapon->getAtk() / 100));
    int len = ent.size();
    std::cout << "Who should " << name << " attack? (Type number eg: 1, 2, 3...)" << std::endl;
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
                int enemyHP = ent[response - 1]->getNormAttack(*this, atkVal);
                break;
            }
        }
    }

}

int Hero::getNormAttack(Entity &ent, int atkVal){
    int dmgVal = std::max(atkVal - (int)std::ceil(atkVal * ((float)defense / 100)), 0);
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

void Hero::updateMagic(std::vector<Spells *> newMagic){
    if (magic.size() == 0){
        magic = newMagic;
    }
    else {
        magic.insert(magic.end(), newMagic.begin(), newMagic.end());
    }
}

//first function that gets called when a magic is selected
// returns the proper TYPE of entity (either the team(1) or the monsters(0)) to be processed on
std::vector<int> Hero::call(){
    int magicLen = magic.size();
    std::cout << "Select an option (Type number eg: 1, 2, 3,...)" << std::endl;
    for (int i = 0; i < magicLen; i++){
        std::cout << i+1 << ": " << magic[i]->getName() << std::endl;
    }
    std::string input;
    int response;
    int entTargetType;
    while (getline(std::cin, input)){
        std::istringstream ss (input);
        if (ss >> response){
            if (response < 1 || response > magicLen){
                std::cout << "Invalid Input" << std::endl;
                continue;
            } else{
                entTargetType = magic[response - 1]->getEntType();
                break;
            }
        }
    }
    std::vector<int> retvect{entTargetType, response};
    return retvect; 
}


//takes a vector of entities & what magic we are casting
void Hero::cast(std::vector<Entity *> ent, int index){
    int ind = index - 1;
    if (curMP >= magic[ind]->getmpRequired()){
        std::cout << "Who should " << name << " target? (Type number eg: 1, 2, 3...)" << std::endl;
        Spells* spell = magic[ind];

        // going to need to fix this when we are able to attack multiple entities at once! going to need to fix the whole thing actually...
        magic[ind]->target(ent, magicalmight, magicalmending);
        curMP -= spell->getmpRequired();
            
    } else {
        std::cout << "You don't have enough MP!" << std::endl;
    }
}

int Hero::getFixedAtk(int atk){
    if (curHP - atk < 0){
        curHP = 0;
    } else {
        curHP -= atk;
    }
    if (curHP == 0){
        std::cout << name << " was wiped out!" << std::endl;
    }
    return curHP;
}

int Hero::getHealed(int heal){
    if (curHP + heal > maxHP){
        curHP = maxHP;
    } else {
        curHP += heal;
    }
    return curHP;
}
