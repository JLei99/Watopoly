 #ifndef DCTims_hpp
 #define DCTims_hpp

 #include "Building.h"
 #include "Board.h"
 #include "Player.h"


class DCTims: public Building{
public:
     DCTims();

     
     // call when arrives at the building
     // simply print a message
     void arrive(Player &p, Board &b) override;
 };

 #endif /* DCTims_hpp */

