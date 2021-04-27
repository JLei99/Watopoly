
#include "Gyms.h"
#include "Player.h"


Gym::Gym(string resi_name){
    this->name = resi_name;
    this->owner = nullptr;
    this->purchase = 150;
    this->tuition = 0; // doesn't matter
    if(this->name == "PAC"){
        this->ID = 12;
    } else if(this->name == "CIF"){
        this->ID = 28;
    }
    this->sibling = 0;
    this->improvement = 0;
    this->improvementCost = 0;
    this->morgaged = false;
}


void Gym::update(){
    if(this->observers[0]->owner->get_name() == this->observers[1]->owner->get_name()){
        observers[0]->sibling = 1;
        observers[1]->sibling = 1;
    } else{
        observers[0]->sibling = 0;
        observers[1]->sibling = 0;
    }
}

void Gym:: changeOwner(std::shared_ptr<Player> to, Board &b){
    this->owner = to;
    update();
}

void Gym::clear(){
    this->owner = nullptr;
    this->sibling = 0;
}




int Gym:: dice(){
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    cout<<"dice1: "<<dice1<<endl;
    cout<<"dice2: "<<dice2<<endl;
    return dice1 + dice2;
}

void Gym::arrive(Player &p, Board &b){
    cout<<"You are landing on Gym "<<this->name<<endl;
    
    // if this Gym has been bought
    if(this->owner != nullptr){
        // if the gym is owned by player p
        if(this->owner->get_name() == p.get_name()){
               cout<<"You are the owner of this Gym, you do not need to pay the fee"<<endl;
               return;
        }
        
        // if this gym is mortgaged
        if(this->morgaged == true){
            cout<<"This gym has been mortgaged, you do not need to pay fee"<<endl;
            return;
        }
        cout<<"This gym "<<this->name<<" has been bought by player "<<p.get_name()<<endl;\
        cout<<"You roll the dices"<<endl;
        int gym_fee = dice();
        if(this->sibling == 0){
            this->tuition = gym_fee * 4;
        } else if(this->sibling == 1){
            this->tuition = gym_fee * 10;
        }
        cout<<"You needs to pay gym fee $"<<this->tuition<<" to "<<this->owner->get_name()<<endl;
        if(p.getMoney() >= this->tuition){
            p.setMoney(p.getMoney() - this->tuition);
            // the owner gets the fee
            this->owner->setMoney(this->owner->getMoney() + this->tuition);
        
        } else{ // if they can't afford the gym_fee
            p.pay_more_than_have(this->tuition, b, *(this->owner));
            cout<<"Now you have $"<<p.getMoney()<<endl;
            return;
        }
    } else{ // if the gym belongs to bank, the player has enough money, and he/she decides to buy
        if(p.getMoney() >= 150){
            cout<<"You have enough money, do you want to buy this gym?"<<endl;
            cout<<"Please enter \"Yes\" or \"No\", if you enter other command, you'll buy this gym by default"<<endl;
            string in;
            cin>>in;
            // if they choose to buy the Gym
            if(in != "No"){
                cout<<"You bought this Gym"<<endl;
                cout<<"money - $150"<<endl;
                p.setMoney(p.getMoney() - 150);
                this->owner = std::make_shared<Player>(p);
                // add this gym to the player's asset
                for(auto pro: b.properties){
                    if(pro->getName() == this->name){
                        p.add_asset(pro);
                    }
                }
                this->update();
                return;
            }
            
        } else{
            cout<<"You can't buy this gym because you do not have enough money"<<endl;
        }
        // if the player do not have enough money to buy, or the player doesn't want to buy the residence: auction
            // first roll the dices and try to pay the gym_fee
        cout<<"Now you roll the dices and pay the gym fee"<<endl;
        cout<<"You roll the dices"<<endl;
        int gym_fee = dice();
        tuition = gym_fee;
        cout<<"You need to pay gym fee $"<<this->tuition<<endl;
        if(p.getMoney() >= this->tuition){
            p.setMoney(p.getMoney() - this->tuition);
        } else{ // if they can't afford the gym_fee
            p.pay_more_than_have(tuition, b, p);
        }
        cout<<"Now you have $"<<p.getMoney()<<endl;
            
        // auction
        cout<<"This gym "<<this->name<<" hasn't been bought"<<endl;
        cout<<"The gym "<<this->name<<" will be auctioned"<<endl;
        
        this->auction(p, b);
    }
}
