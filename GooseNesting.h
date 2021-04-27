
#ifndef GooseNesting_h
#define GooseNesting_h

#include <iostream>
#include "Building.h"
#include "Board.h"
#include "Player.h"

class GooseNesting : public Building{
public:
    GooseNesting();
    

    // call when arrive at the building
    // simply display a meaasge
    void arrive(Player &p, Board &b) override;
};

#endif /* GooseNesting_h */
