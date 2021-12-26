#ifndef _MYWEAPON_H_
#define _MYWEAPON_H_
#include <string>

class Weapon{
    std::string name;
    int attack;
    public:
        int getAtk();
        std::string getName();
        Weapon(std::string name, int attack);
};

#endif