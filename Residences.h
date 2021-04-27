
#ifndef RESIDENCES_H
#define RESIDENCES_H

#include "Property.h"
#include <vector>
#include <memory>
using namespace std;

class Residences: public Property{
public:
    Residences(string name);
    vector<shared_ptr<Residences>> observers;
    
//    // return name of the building
//    std::string getName() override;
    
    // call when you arrive at the gym,
    //  1. if the gym is owmed by yourself
    //  2. if the it is owned by someone else, pay the tuition
    //  3. if the gym is not bought, you can choose to buy the gym
    //  4. if you choose not to buy or cannot afford, it will be auctioned
    void arrive(Player &p, Board & b) override;
    
    // will give the residence to the bank
    void clear() override;
    
    // see property.h
    void changeOwner(std::shared_ptr<Player> to, Board &b) override;
     
    // see property.h
    void update() override;
};

#endif /* Residences_hpp */
