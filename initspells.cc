#include "spells.h"
#include "spelltypes.h"
#include <map>
#include <string>

//a map ...? with the spell name as the key, and the spell object as the value. all the "magic" and "abilities" stuff, what gets inserted is a pointer to
// the value

std::map<std::string, Spells*>* initSpellsLuminary(){
    std::map<std::string, Spells*> *retSpells;

    retSpells->insert(std::make_pair("Frizz", new SingleAtk("Frizz", 10, 2)));
    retSpells->insert(std::make_pair("Heal", new SingleHeal("Heal", 25, 3)));

    return retSpells;
}