#ifndef Property_h
#define Property_h
#include "Building.h"
#include <memory>

class Building;

class Property : public Building {
protected:
  //  int mortgaged;
    std::shared_ptr<Player> owner;
    int tuition;
    int purchase;
    int improvement = 0;
    int improvementCost;
   
public:
    bool morgaged;
    
    /**For load **/
    // set Owner to s
    void setOwner(string s, Board &b);
    // set improvement to n
    void setImprovement(int n);
  
    // auction this building without p participating
    void auction(Player &p, Board &b);
    
    // bank will have the property after calling the function
    virtual void clear(){}; // used in Residence and Gyms
    
    // return the total worth of this Property
    //  that is (price of building + cost of each improvements)
    int get_worth();
    
    // return the purchase cost of the building
    int get_cost();
    
    // change the owner of the building
    // notice:
    //     Player::remove_asset and Player::add_asset may need to be called additionally
    virtual void changeOwner(std::shared_ptr<Player> to, Board &b) = 0;
    
    // return the number of improvement of the building
    // only used in Academic Building
    int getImprovement();
    
    // see AcademicBuilding.cc
    // only use in academic Building
    virtual void sellImprovement(int num = 0){};
    
    // see in AcademicBuilding.cc
    // only use in academic Building
    virtual void buyImprovement(){};
    
    // update the state of the property and properties in the same monopoly block or type
    virtual void update(){};
    
    // call when you arrive at the property,
    //  1. if the property is owmed by yourself
    //  2. if the it is owned by someone else, pay the tuition
    //  3. if the property is not bought, you can choose to buy it
    //  4. if you choose not to buy or cannot afford, it will be auctioned
    virtual void arrive(Player &p, Board &b) override = 0 ;
    
    // return the name of the owner
    string get_owner();
};

#endif /* Property_h */

