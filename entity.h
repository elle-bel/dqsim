#ifndef _MYENTITY_H_
#define _MYENTITY_H_

class Weapon;

class Entity{
    public:
    virtual std::string getName() = 0;
    virtual int normalAttack(std::vector<Entity *> ent) = 0;
    virtual int getNormAttack(Entity & ent, int atkVal) = 0;
    virtual std::vector<int> getStats() = 0;
    virtual ~Entity() {};
    virtual int cast(std::vector<Entity *> ent) = 0;
    virtual int getFixedAtk(int atk) = 0;
};


#endif