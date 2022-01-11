#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "luminary.h"
#include "heroes.h"
#include "weapon.h"
#include "enemies.h"
using namespace std;

int partition(vector<Entity *> &ent, int low, int high){
    int pivot = ent[high]->getStats()[2];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++){
        if(ent[j]->getStats()[2] <= pivot){
            i++;
            swap(ent[i], ent[j]);
        }
    }
    swap(ent[i+1], ent[high]);
    return (i+1);
}

void sortSpeed(vector<Entity *> &ent, int low, int high){
    if (low < high){
        int pivot = partition(ent, low, high);
        sortSpeed(ent, low, pivot - 1);
        sortSpeed(ent, pivot + 1, high);
    }

}

void battleSeq(vector<Entity *> h, vector<Entity *> e){ 
    if (e.size() > 1){
        cout << e[0]->getName() << " and friends draw near!" << endl;
    } else {
        cout << "A " << e[0]->getName() << " draws near!" << endl;
    }
    vector<Entity *> tempbattle = h;
    vector<Entity *> tempe = e;
    tempbattle.insert(tempbattle.end(), tempe.begin(), tempe.end());
    sortSpeed(tempbattle, 0, tempbattle.size() - 1);

    int maxind = tempbattle.size() - 1;
    int counter = maxind;
    int enemyCount = e.size();
    int partyCount = h.size();
    while(1){
        int entHP;
        if (count(h.begin(), h.end(), tempbattle[counter]) > 0){
            entHP = tempbattle[counter]->normalAttack(e);
        } else {
            entHP = tempbattle[counter]->normalAttack(h);
        }
        if (entHP == 0){
            if (count(h.begin(), h.end(), tempbattle[counter]) > 0){
                enemyCount--;
            } else {
                partyCount--;
            }
            tempbattle.erase(tempbattle.begin()+counter);
        }
        if (enemyCount == 0){
            cout << "The party is victorious!" << endl;
            break;
        } 
        if (partyCount == 0){
            cout << "The party was wiped out!" << endl;
            break;
        }
        if (counter == 0){
            counter = maxind;
        } else{
            counter--;
        }
    }
    
}


// makefile works with "mingw32-make"
// run dqsim.exe with ".\dqsim.exe"

int main(){
    vector<Entity *> party;
    vector<Weapon *> weapons;
    vector<Entity *> monsters;
    party.push_back(new Luminary());
    weapons.push_back(new Weapon("Iron Sword", 19));
    monsters.push_back(new Enemy("Slime", 25, 7, 7, 9));

    monsters.push_back(new Enemy("Slime2", 25, 7, 7, 12));
    //monsters.push_back(new Enemy("Slime3", 25, 7, 7, 7));
    //monsters.push_back(new Enemy("Slime4", 25, 7, 7, 10));

    cout << "Current Party Members:" << endl;
    for (auto p: party){
        Hero * temp = static_cast<Hero *> (p);
        cout << setw(12) << left << p->getName() << setw(3) << right << "Level " << temp->getLevel() << endl;
    }

    Hero * curhero = static_cast<Hero *>(party[0]);
    curhero->equip(weapons[0]);
    
    battleSeq(party, monsters);
}