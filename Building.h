#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include <string>
#include <cstdlib>

class Player;
class Board;

using std::string;
using std::cout;
using std::endl;

const std::string own[22] = {"AL","ML","ECH","PAS","HH","RCH","DWE","CPH","LHI","BMH","OPT","EV1","EV2","EV3","PHYS","B1","B2","EIT","ESC","C2","MC","DC"};


class Building{
    
protected:
    std::string name;
    int ID;
public:
    Building(){}
    virtual std::string getName();
    virtual void arrive(Player &p, Board &b) = 0;
};

#endif /* BUILDING_H */
