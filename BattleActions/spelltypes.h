#include <string>
#include <vector>
#include "../Entities/entity.h"
#include "spells.h"

class Spells;

class SingleAtk: public Spells{
    int baseDmg;
    public:
        SingleAtk(std::string spellName, int baseDmg, int mpRequired);
        void target(std::vector<Entity *> ent, int might, int mending) override;
        int getEntType() override;
        int getBaseDmgorHeal() override;

};


class SingleHeal: public Spells{
    int baseHp;
    public:
        SingleHeal(std::string spellName, int baseHp, int mpRequired);
        int getEntType() override;
        int getBaseDmgorHeal() override;
        void target(std::vector<Entity *> ent, int might, int mending) override;
};

