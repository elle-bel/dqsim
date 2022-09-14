#include <string>
#include <vector>
#include "spells.h"
#include "spelltypes.h"

SingleAtk::SingleAtk(std::string spellName, int baseDmg, int mpRequired): Spells{spellName, mpRequired}, baseDmg{baseDmg} {}

int SingleAtk::getbaseDmg(){
    return baseDmg;
}

SingleHeal::SingleHeal(std::string spellName, int baseHp, int mpRequired): Spells{spellName, mpRequired}, baseHp{baseHp} {}

int SingleHeal::getbaseHp(){
    return baseHp;
}