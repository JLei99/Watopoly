#ifndef Player_h
#define Player_h
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include "Fee.h"
#include "Error.h"
#include "Board.h"
#include "Property.h"
using std::vector;
using std::string;
using std::shared_ptr;
using std::cin;
class Property;
class Board;
#include "AcademicBuilding.h"

class Player {
    std::string name;
    char ch;
    int money;
    int position; // currenct position on the board
    int roll_up;
    std::vector<std::shared_ptr<Property>> assets;
    bool bank_rupt;
    bool roll(int * step_num);
    friend class AcademicBuilding;
public:
    int DC_Tims_time;
    Player(const string name);
    
    // return char of the player
    char get_char();
    
    // return the asset with name s and nullptr if the player does not have the property
    std::shared_ptr<Property> find_asset(string s);
    
    // return true if the player have asset s
    bool asset_contain(string s);
    
    // remove asset
    // require: the asset belongs to the player
    void remove_asset(std::shared_ptr<Property>);
    
    // add asset
    // require: the asset does not belong to the player
    void add_asset(std::shared_ptr<Property>);
    
    // call when the player is asked to pay more than they have
    void pay_more_than_have(int pay, Board &b, Player &p);
    
    // return name of the player
    string get_name();
    
    // add cup rim to the player
    void add_cup();
    
    // return the number of cup rim the player currently have
    int get_cup();
    
    // set the number of cup rim the player have
    void set_cup(int n);
    
    // return the position of the player
    int get_pos();
    
    // set the position of the player to n
    void set_pos(int n);
    
    //  set the saving of the player to new_money
    void setMoney(int new_money);
    
    // return the saving the player have
    int getMoney();
    
    // calculate and return the total value of all assets and savings the player have
    int getTotalWorth();
    
    // the player rolls (also support testing mode)
    // roll again if roll double
    // if roll double for three time, send to DC Tims Line
    void takeStep(Board &b, int steps, bool test, bool test_roll_again);
    
    // buy or sell improvement
    void improve(std::string property, bool buy = true);
    
    // mortgage property and raise fund
    void mortgage(std::string property);
    
    // unmortgage property
    void unmortgage(std::string property);
    
    // declare bankrupt
    // the player p is the person this owns to, give all property to p
    // if p is this, this owns money to the bank, auction all the property
    void bankrupt(Player & p, Board &b);
    
    // print all assets they have
    void asset();
    
};

// return true if the string represent a number
bool is_num(string s);

// convert s to an integer
int to_num(string s);

// split a string into a vector of string separated by <space>
vector<string> split(const string& s);
#endif /* Player_h */

