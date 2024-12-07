#ifndef _MYSPELLS_H_
#define _MYSPELLS_H_

#include <string>
#include <vector>
#include "../Entities/entity.h"

class Spells{
    std::string spellName;
    int mpRequired;
    public:
        Spells(std::string spellName, int mpRequired);
        virtual ~Spells();
        std::string getName();
        int getmpRequired();
        virtual int getBaseDmgorHeal() = 0;
        //int magicalMightIncrease();
        virtual void target(std::vector<Entity *> ent, int might, int mending) = 0;
        virtual int getEntType() = 0;
        
};

#endif