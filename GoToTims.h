
#ifndef GoToTims_hpp
#define GoToTims_hpp
#include "Building.h"
#include "Board.h"
#include "Player.h"

class GoToTims : public Building{
private:
public:
    GoToTims();
    

    
    // the player will be sent to DC Tims Line and will not be able to get out unless they pay $50, or use cups rim
    void arrive(Player &p, Board &b) override;
    
};

#endif /* GoToTims_hpp */
