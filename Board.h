#ifndef Board_h
#define Board_h

#include <vector>
#include <string>
#include <memory>

using std::vector;
using std::string;

class Building;
class Player;
class Property;

class Board {
    std::vector<std::shared_ptr<Building>> squares; // 40 squares
    int cups; // 0 ~ 4
    std::shared_ptr<Property> find_property(string s);
    
    
public:
    std::shared_ptr<Player> curPlayer;
    vector<std::shared_ptr<Player>> players;
    vector<std::shared_ptr<Property>> properties;
    Board();
    
    // add Player to the game
    // require: must from the PlayerList and no repetition
    void addPlayer(Player &p);
    
    // get the pointer of the building at pos
    std::shared_ptr<Building>& at(int pos);
    
    // change the number of cups in the game
    void set_cups(int c);
    
    // get the number of cups in the game
    int get_cups() const;
    
 
    // curPlayer trade with Player named name
    // require: give or receive can either be property or money
    void trade(std::string name, std::string &give, std::string &receive);
    
};


#endif /* Board_h */

