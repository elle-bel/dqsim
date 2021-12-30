#ifndef _MYENTITY_H_
#define _MYENTITY_H_

class Entity{
    public:
    virtual std::string getName() = 0;
    virtual int normalAttack(Entity * ent) = 0;
    virtual int getNormAttack(Entity & ent, int atkVal) = 0;
    virtual ~Entity() {};
};


#endif