#include <string>
#include <vector>
#include "entity.h"
#include "spells.h"

class Spells;

class SingleAtk: public Spells{
    int baseDmg;
    public:
        SingleAtk(std::string spellName, int baseDmg, int mpRequired);
        int getbaseDmg();
};

class SingleHeal: public Spells{
    int baseHp;
    public:
        SingleHeal(std::string spellName, int baseHp, int mpRequired);
        int getbaseHp();
};
