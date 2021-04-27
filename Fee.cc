
#include "Fee.h"

Fee::Fee(int id, string name){
    this->ID = id;
    this->name = name;
}
 



void Fee::arrive(Player &p, Board &b){
    if(p.get_pos() == 4){ // if landing on tuition
        int choice;
        cout<<"Press 1 if you choose to pay $300 tuition"<<endl;
        cout<<"Press 2 if you choose to pay 10% of your total worth"<<endl;
        cout<<"If you enter other command, you will pay $300 by default"<<endl;
        cin>>choice;
        if(choice == 1){
            cout<<"You choose to pay $300 for tuition fee"<<endl;
            if(300 > p.getMoney()){ // money is not enough for paying the tuition
                p.pay_more_than_have(300,b,p);
            } else{ // money is enough to pay the tuition
                p.setMoney(p.getMoney() - 300);
            }
        } else if(choice == 2){
            cout<<"You choose to pay 10% of total worth for tuition fee"<<endl;
            int tuition = 0.1 * p.getTotalWorth();
            cout<<"Your tuition fee is $"<<tuition<<endl;
            if(tuition > p.getMoney()){ // money is not enough for paying tuition
                p.pay_more_than_have(tuition,b,p);
            } else{ // money is enough to pay the tuition fee
                p.setMoney(p.getMoney() - tuition);
            }
        } else{
            cout<<"Invalid command! You are supposed to choose either 0 or 1, now you are paying $300 by default"<<endl;
            if(300 > p.getMoney()){ // money is not enough for paying the tuition
                p.pay_more_than_have(300,b,p);
            } else{ // money is enough to pay the tuition fee
                p.setMoney(p.getMoney() - 300);
            }
        }
    } else if(p.get_pos() == 38){ // landing on coop
        cout<<"You will pay $150"<<endl;
        if(150 > p.getMoney()){ // money is not enough for paying the coop
            p.pay_more_than_have(150,b,p);
        } else{ // money is enough to pay the coop
            p.setMoney(p.getMoney() - 150);
        }
    } else if(p.get_pos() == 0){ // landing on OSAP
        cout<<"You are landing on Collect OSAP and you collect $200!"<<endl;
        p.setMoney(p.getMoney() + 200);
    }
}
