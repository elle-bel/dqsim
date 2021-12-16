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
    party.push_back(new Luminary());

    cout << "Current Party Members:" << endl;
    for (auto p: party){
        cout << setw(12) << left << p->getName() << setw(3) << right << "Level " << p->getLevel() << endl;
    }
}