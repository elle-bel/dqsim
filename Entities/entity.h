#ifndef _MYENTITY_H_
#define _MYENTITY_H_

class Weapon;

class Entity{
    public:
    virtual std::string getName() = 0;
    virtual int getHp() = 0;
    virtual int getMp() = 0;
    virtual int getType() = 0;
    virtual void normalAttack(std::vector<Entity *> ent) = 0;
    virtual int getNormAttack(Entity & ent, int atkVal) = 0;
    virtual std::vector<int> getStats() = 0;
    virtual ~Entity() {};
    virtual void cast(std::vector<Entity *> ent, int index) = 0;
    virtual std::vector<int> call() = 0;
    virtual int getFixedAtk(int atk) = 0;
    virtual int getHealed(int heal) = 0;
    virtual int giveExp() = 0;
    virtual void incExp(int exp) = 0;
};


#endif