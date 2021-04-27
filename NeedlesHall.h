
#ifndef NeedlesHall_hpp
#define NeedlesHall_hpp
#include "Building.h"
#include "Board.h"
#include "Player.h"
#include <stdexcept>

class NeedlesHall : public Building{
public:
    NeedlesHall(int id);
    

    
    // when the player arrives at the place, it either gains or loses
    // money. They may lose 200 with probability 1/18, lose 100 with
    // probability 1/9, lose 50 with probalibity 1/6, gain 25 with
    // probability 1/3, gain 50 with probability 1/6, gain 100 with
    // probability 1/9, gain 200 with probability 1/18.
    void arrive(Player &p, Board & b) override;
};

#endif /* NeedlesHall_hpp */
