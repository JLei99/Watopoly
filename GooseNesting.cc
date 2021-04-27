
#include "GooseNesting.h"
GooseNesting::GooseNesting(){
    this->ID = 20;
    this->name = "Goose Nesting";
}


void GooseNesting::arrive(Player &p, Board &b){
    cout<<"You are landing on GooseNesting"<<endl;
    cout<<"You are attacked by a group of geese! :("<<endl;
}
