#include <iostream>
#include <iomanip>
#include <vector>
#include "luminary.h"
#include "heroes.h"
#include "weapon.h"
#include "enemies.h"
using namespace std;

void battleSeq(Hero *h, Enemy * e){
    cout << "A " << e->getName() << " draws near!" << endl;
    while(1){
        int enemyHP = h->normalAttack(e);
        if (enemyHP == 0){
            cout << "The " << e->getName() << " is defeated!" << endl;
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