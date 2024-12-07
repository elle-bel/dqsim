#include <string>
#include <vector>
#include "luminary.h"
#include "../../BattleActions/spells.h"
#include "../../BattleActions/spelltypes.h"

//std::string name, int level, int maxHP, int maxMP, int attack, int magicalmight, int magicalmending, int defense, int speed
Luminary::Luminary(): Hero{"Luminary", 5, 33, 17, 17, 13, 15, 9, 16} {}

void Luminary::levelUp(){
    changeStats(4, 3, 3, 4, 2, 2);
}

void Luminary::initspells(){
    std::vector<Spells*> startingSpells;
    startingSpells.push_back(new SingleAtk("Frizz", 10, 2));
    startingSpells.push_back(new SingleHeal("Heal", 20, 5));
    updateMagic(startingSpells);
}