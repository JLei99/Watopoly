
#ifndef SLC_hpp
#define SLC_hpp

#include "Building.h"
#include "Board.h"
#include "Player.h"

class SLC : public Building{
public:
    SLC(int id);
    
    // return name of the building
    std::string getName() override;
    
    // call when the player arrive at SLC, their piece is randomly moved on the board. 
    void arrive(Player &p, Board & b) override;
};

#endif /* SLC_hpp */
