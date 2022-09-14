#include <string>
#include "spells.h"


Spells::Spells(std::string spellName, int mpRequired): spellName{spellName}, mpRequired{mpRequired} {}

std::string Spells::getName(){
    return spellName;
}

int Spells::getmpRequired(){
    return mpRequired;
}
