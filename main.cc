#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include "Entities/Heroes/luminary.h"
#include "Entities/heroes.h"
#include "weapon.h"
#include "Entities/enemies.h"
#include "BattleActions/spells.h"
using namespace std;

int partition(vector<Entity *> &ent, int low, int high){
    //pivot is the last element
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

// using quickSort
void sortSpeed(vector<Entity *> &ent, int low, int high){
    if (low < high){
        int pivot = partition(ent, low, high);
        sortSpeed(ent, low, pivot - 1);
        sortSpeed(ent, pivot + 1, high);
    }

}

// need to define a "group" - either between enemies or the party (all 4)

void battleSeq(vector<Entity *> h, vector<Entity *> e){ 
    if (e.size() > 1){
        cout << e[0]->getName() << " and friends draw near!" << endl;
    } else {
        cout << "A " << e[0]->getName() << " draws near!" << endl;
    }
    vector<Entity *> tempbattle = h;
    tempbattle.insert(tempbattle.end(), e.begin(), e.end());
    sortSpeed(tempbattle, 0, tempbattle.size() - 1);

    int maxind = tempbattle.size() - 1;
    int counter = maxind;
    int givenExp = 0;
    int enemyCount = e.size();
    int partyCount = h.size();
    while(1){
        bool end = false;
        //determines if the entity going first is a hero or an enemy
        // battle action occurs
        if (tempbattle[counter]->getType() == 0){
            std::cout << "What do you want to do? \n1. Attack\n2. Magic\n3. Check Party Stats\n4. Flee!" << std::endl;
            std::string input;
            int response;
            while (getline(std::cin, input)){
                std::istringstream ss (input);
                if (ss >> response){
                    if (response == 1){
                        tempbattle[counter]->normalAttack(e);
                    } else if (response == 2){
                        std::vector<int> magicDetails = tempbattle[counter]->call();
                        if (magicDetails[0] == 0){
                            tempbattle[counter]->cast(h, magicDetails[1]);
                        } else if (magicDetails[0] == 1){
                            tempbattle[counter]->cast(e, magicDetails[1]);
                        } else{
                            std::cout << "error" << std::endl;
                        }
                    } else if (response == 3){
                        for (auto hero : h){
                            auto stats = hero->getStats();
                            cout << setw(12) << left << hero->getName() << endl;
                            cout << setw(12) << left << "Health " << setw(5) << right << hero->getHp() << "/" << stats[3] << endl;
                            cout << setw(12) << left << "Mana " << setw(5) << right << hero->getMp() << "/" << stats[4] << endl;
                        }
                        cout << endl;
                        std::cout << "What do you want to do? \n1. Attack\n2. Magic\n3. Check Party Stats\n4. Flee!" << std::endl;
                        continue;
                    } else if (response == 4){
                        end = true;
                    } else{
                        std::cout << "Invalid Input" << std::endl;
                    }
                    break;
                }
            }
            if (end == true){
                std::cout << "The party fled! [Exiting Game]" << std::endl;
                break;
            }
        } else {
            tempbattle[counter]->normalAttack(h);
        }

        // cleaning up battle list
        for (auto ents: tempbattle){
            if (ents->getHp() == 0){
                if (ents->getType() == 0){
                    partyCount--;
                } else {
                    enemyCount--;
                    givenExp += ents->giveExp();
                }
                auto it = std::find(tempbattle.begin(), tempbattle.end(), ents);
                tempbattle.erase(it);
            }
        }
        if (enemyCount == 0){
            cout << "The party is victorious!" << endl;
            for (auto hero: h){
                hero->incExp(givenExp/(h.size()));
            }
            cout << "The party received " << givenExp/h.size() << " exp each!" << endl;
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
// clean via "mingw32-make clean"
// run dqsim.exe with ".\dqsim.exe"

/*
Task List:
3. implement healing / buff spells?
*/

int main(){
    vector<Entity *> party;
    vector<Weapon *> weapons;
    vector<Entity *> monsters;
    party.push_back(new Luminary());
    weapons.push_back(new Weapon("Iron Sword", 19));
    monsters.push_back(new Enemy("Slime", 25, 2, 7, 7, 9,5));

    monsters.push_back(new Enemy("Slime2", 25, 2, 7, 7, 12,5));
    //monsters.push_back(new Enemy("Slime3", 25, 2, 7, 7, 7,5));
    //monsters.push_back(new Enemy("Slime4", 25, 2, 7, 7, 10,5));

    cout << "Current Party Members:" << endl;
    for (auto p: party){
        Hero * temp = static_cast<Hero *> (p);
        cout << setw(12) << left << p->getName() << setw(3) << right << "Level " << temp->getLevel() << endl;
    }

    Hero * curhero = static_cast<Hero *>(party[0]);
    curhero->equip(weapons[0]);
    curhero->initspells();
    
    battleSeq(party, monsters);
}