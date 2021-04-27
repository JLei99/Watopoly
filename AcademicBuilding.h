 #ifndef AcademicBuilding_h
 #define AcademicBuilding_h

 #include "Property.h"
 #include <map>
 #include <vector>
#include <memory>
 using namespace std;

 class tuitionTable {
     map<string, map<int, int>> table;
 public:
     tuitionTable();
     int getTuition(const string &name, int improvement);
 };



 class AcademicBuilding : public Property {
     friend class Board;
     bool monopoly;
     tuitionTable table;
     vector<shared_ptr<AcademicBuilding>> observers; // include this
     
     // set the state to monopoly_now and change the tuition accordingly
     void setState(bool monopopy_now);
     
     // buys the property
     // pay money, add property to assets,
     // change owner, notify observers
     // require: money >= purchaseCost
     virtual void buy(Player &to, Board &b);
 public:
     
     AcademicBuilding(int ID, const string &name, int purchaseCost, int improvementCost);
     
     // When arrives the AcademicBuilding, you will
     // 1. pay tuition if it is owned by someone else
     // 2. choose to buy the building if the bank owns it
     // 3. auction if you choose not to buy it
     virtual void arrive(Player &p, Board &b) override;
     
     
     // update the state of the academic building including:
     //     1. if forms monopoly
     //     2. change the tuition if monopoly state changes
     // called when:
     //     1. load a file at the beginning
     //     2. change owner
     virtual void update() override;
     
     // change the owner of the building
     // notice:
     //     Player::remove_asset and Player::add_asset may need to be called additionally
     virtual void changeOwner(std::shared_ptr<Player> to, Board &b) override;
     
     // sell all the improvement by default or sell one improvement if num is one
     // sell one improvement if the player choose to sell, and sell all if the
     //      player is trying to raise money.
     virtual void sellImprovement(int num) override;
     
     // buy one improvement
     // Error message may be display if the player do not form a monopoly or cannot afford
     virtual void buyImprovement() override;
     
    
 };




 #endif /* AcademicBuilding_h */


