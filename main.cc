#include <iostream>
#include <iomanip>
#include <vector>
#include "luminary.h"
#include "heroes.h"
#include "weapon.h"
#include "enemies.h"
using namespace std;

void battleSeq(Hero *h, Enemy * e){ //currently not based on speed and only works for 1 hero, 1 enemy
    cout << "A " << e->getName() << " draws near!" << endl;
    /*
    vector<Entity *> order;
    if (h->getStats()[2] > e->getStats()[2]){
        order.emplace_back(h);
        order.emplace_back(e);
    } else {
        order.emplace_back(e);
        order.emplace_back(h);
    }

    int orderMax = order.size() - 1;
    */
    while(1){
         
        int enemyHP = h->normalAttack(e);
        if (enemyHP == 0){
            cout << "The " << e->getName() << " is defeated!" << endl;
            break;
        }
        int heroHP = e->normalAttack(h);
        if (heroHP == 0){
            cout << "The party was wiped out!" << endl;
            break;
        }
    }
}

// makefile works with "mingw32-make"
// run dqsim.exe with ".\dqsim.exe"

int main(){
    vector<Hero *> party;
    vector<Weapon *> weapons;
    vector<Enemy *> monsters;
    party.push_back(new Luminary());
    weapons.push_back(new Weapon("Iron Sword", 19));
    monsters.push_back(new Enemy("Slime", 25, 7, 7, 9));

    cout << "Current Party Members:" << endl;
    for (auto p: party){
        cout << setw(12) << left << p->getName() << setw(3) << right << "Level " << p->getLevel() << endl;
    }

    Hero * curhero = party[0];
    curhero->equip(weapons[0]);

    battleSeq(curhero, monsters[0]);
}