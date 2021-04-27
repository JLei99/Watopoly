
#ifndef GYM_H
#define GYM_H
#include "Property.h"
#include <vector>
using namespace std;
class Gym: public Property{
private:
    int dice();
public:
    int sibling; // 0--1
    Gym(string name);
    vector<shared_ptr<Gym>> observers;


    
    // call when you arrive at the gym,
    //  1. if the gym is owmed by yourself
    //  2. if the it is owned by someone else, pay the tuition
    //  3. if the gym is not bought, you can choose to buy the gym
    //  4. if you choose not to buy or cannot afford, it will be auctioned
    void arrive(Player &p, Board & b) override;
    
    // will give the gym to the bank
    void clear() override;
    
    // change the owner of the building
    // notice:
    //     Player::remove_asset and Player::add_asset may need to be called additionally
    void changeOwner(std::shared_ptr<Player> to, Board &b) override;
    
    // update the state of the gym and the other gym
    void update() override;
};


#endif /* Gyms_hpp */
