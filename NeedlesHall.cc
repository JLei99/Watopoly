
#include "NeedlesHall.h"

NeedlesHall::NeedlesHall(int id){
    this->ID = id;
    this->name = "Needles Hall";
}


void  NeedlesHall::arrive(Player &p, Board &b){
    cout<<"You are landing on Needles Hall"<<endl;
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
    chance = rand() % 18 + 1; // 1 to 18
    
    if(chance == 1){ // - 200
        if(p.getMoney() < 200){ // doesn't have enough money
            p.pay_more_than_have(200, b, p);
        } else{
            p.setMoney(p.getMoney() - 200);
        }
        cout<<"You lose $200"<<endl;
        cout<<"Now you have $"<<p.getMoney()<<endl;
    } else if(2 <= chance && chance <= 3){ // - 100
        if(p.getMoney() < 100){ // doesn't have enough money
            p.pay_more_than_have(100, b, p);
        } else{
            p.setMoney(p.getMoney() - 100);
        }
        cout<<"You lose $100"<<endl;
        cout<<"Now you have $"<<p.getMoney()<<endl;
    } else if(4 <= chance && chance <= 6){ // - 50
        if(p.getMoney() < 50){ // doesn't have enough money
           p.pay_more_than_have(50, b, p);
        } else{
            cout<<"You lose $50"<<endl;
            p.setMoney(p.getMoney() - 50);
        }
    } else if(7 <= chance && chance <= 12){ // + 25
        cout<<"You win $25"<<endl;
        p.setMoney(p.getMoney() + 25);
    } else if(13 <= chance && chance <= 15){ // +50
        cout<<"You win $50"<<endl;
        p.setMoney(p.getMoney() + 50);
    } else if(16 <= chance && chance <= 17){ // +100
        cout<<"You win $100"<<endl;
        p.setMoney(p.getMoney() + 100);
    } else if(chance == 18){ // + 200
        cout<<"You win $200"<<endl;
        p.setMoney(p.getMoney() + 200);
    }
    
}
