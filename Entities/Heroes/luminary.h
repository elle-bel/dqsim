#ifndef _LUMINARY_H_
#define _LUMINARY_H_
#include "../heroes.h"

class Luminary: public Hero{ 
    public:
        Luminary();
        void levelUp() override;
        void initspells() override;
};

#endif