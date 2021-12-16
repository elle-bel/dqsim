#include "weapon.h"
#include <string>

Weapon::Weapon(std::string name, int attack): name{name}, attack{attack} {}

int Weapon::getAtk(){
    return attack;
}