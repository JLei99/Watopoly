#include "GoToTims.h"
GoToTims::GoToTims(){
    this->ID = 30;
    this->name = "GOToTims";
}




void GoToTims::arrive(Player &p, Board &b){
    cout<<"You are landing on GoToTims"<<endl;
    p.set_pos(10);
    p.DC_Tims_time = 1;
    cout<<"You are now sent to DC Tims Line"<<endl;
}
