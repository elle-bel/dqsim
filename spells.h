#include <string>
#include <vector>
#include "entity.h"

class Spells{
    std::string spellName;
    int mpRequired;
    public:
        Spells(std::string spellName, int mpRequired);
        std::string getName();
        int getmpRequired();
        //int magicalMightIncrease();
};