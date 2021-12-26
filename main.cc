#include <iostream>
#include <iomanip>
#include <vector>
#include "luminary.h"
#include "heroes.h"
#include "weapon.h"
#include "enemies.h"
using namespace std;

// makefile works with "mingw32-make"

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

    curhero->normalAttack(monsters[0]);
}