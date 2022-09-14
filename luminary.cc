#include "luminary.h"
#include <string>

Luminary::Luminary(): Hero{"Luminary", 5, 33, 17, 17, 13, 15, 9, 16} {}

void Luminary::levelUp(){
    changeStats(4, 3, 3, 4);
}