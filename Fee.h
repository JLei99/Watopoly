#ifndef Fee_hpp
#define Fee_hpp
#include "Building.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
class Building;
using std::cout;
using std::endl;
class Player;
class Board;

class Fee: public Building{
public:
    
    
    Fee(int id, string name);
    
    // call when arrive at the building
    // Fees will be charged
    // if the instantiation is Tuition, player have to choose a way to pay the fee
    void arrive(Player &p, Board &b) override;
    

};

#endif /* Fee_hpp */
