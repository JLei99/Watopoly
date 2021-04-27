
#include "SLC.h"

SLC::SLC(int id){
    this->ID = id;
    this->name = "SLC";
}

std::string SLC::getName(){
    return this->name;
}

void SLC::arrive(Player &p, Board &b){
    // check if the board has 4 roll up
    if(b.get_cups() == 4){
        // do not have a chance to get a cup, do nothing
    } else{
        int chance;
        chance = rand() % 100;
        if(chance == 0){
            // win a cup
            cout<<"You win a roll up the Rim cup!"<<endl;
            p.add_cup();
            b.set_cups(b.get_cups() + 1);
        }
    }
    // now the chance for cup ends
    int chance;
    chance = rand() % 24 + 1; // 1 to 24
    if(1 <= chance && chance <= 3){ // back 3
        p.set_pos((p.get_pos() - 3 + 40) % 40);
        cout<<"You go back 3 steps"<<endl;
        b.at(p.get_pos())->arrive(p, b);
    } else if(4 <= chance && chance <= 7){ // back 2
        p.set_pos((p.get_pos() - 2 + 40) % 40);
        cout<<"You go back 2 steps"<<endl;
        b.at(p.get_pos())->arrive(p, b);
    } else if(8 <= chance && chance <= 11){ // back 1
        p.set_pos((p.get_pos() - 1 + 40) % 40);
        cout<<"You go back 1 steps"<<endl;
        b.at(p.get_pos())->arrive(p, b);
    } else if(12 <= chance && chance <= 14){ // forward 1
        p.set_pos((p.get_pos() + 1 ) % 40);
        
        cout<<"You go forward 1 steps"<<endl;
        b.at(p.get_pos())->arrive(p, b);
    } else if(15 <= chance && chance <= 18){ // forward 2
        p.set_pos((p.get_pos() + 2 ) % 40);
        cout<<"You go forward 2 steps"<<endl;
        b.at(p.get_pos())->arrive(p, b);
    } else if(19 <= chance && chance <= 22){ // forward 3
        p.set_pos((p.get_pos() + 3 ) % 40);
        cout<<"You go forward 3 steps"<<endl;
        b.at(p.get_pos())->arrive(p, b);
    } else if(chance == 23){ // goes to DC Tims Line
        p.set_pos(10);
        p.DC_Tims_time = 1;
        cout<<"You go to DC Tims Line"<<endl;
    } else if(chance == 24 ){ // goes to OSAP
        p.set_pos(0);
        cout<<"You advance to Collect OSAP"<<endl;
        p.setMoney(p.getMoney() + 200);
    }
}

