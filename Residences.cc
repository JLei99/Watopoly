
#include "Residences.h"
#include "Player.h"

void Residences::clear(){
    this->tuition = 25;
    this->owner = nullptr;
}

Residences::Residences (string resi_name){
    this->name = resi_name;
    this->owner = nullptr;
    this->purchase = 200;
    this->tuition = 25;
    if(this->name == "MKV"){
        this->ID = 5;
    } else if(this->name == "UWP"){
        this->ID = 15;
    } else if(this->name == "V1"){
        this->ID = 25;
    } else if(this->name == "REV"){
        this->ID = 35;
    }
    this->improvement = 0;
    this->improvementCost = 0;
    this->morgaged = false;
}



void Residences::update(){
    for(auto re : this->observers){
        int same = 0;
        string own = re->owner->get_name();
        for(auto other : this->observers){
            if(other != re && other->owner->get_name() == own){
                same++;
            }
        }
        int rent = 25;
        for(int i = 0; i < same; i++){
            rent = rent * 2;
        }
        re->tuition = rent;
    }
}

void Residences:: changeOwner(std::shared_ptr<Player> to, Board &b){
    this->owner = to;
    this->update();
}





void Residences::arrive(Player &p, Board &b){
    
    // if this residence has been bought
    if(this->owner != nullptr){
        // if this residences is bought by player p
        if(this->owner->get_name() == p.get_name()){
            cout<<"You are the owner of this Residence, you do not need to pay the rent"<<endl;
            return;
        }
        
        
        // if the residence is mortgaged
        if(this->morgaged == true){
            cout<<"This residence has been mortgaged, you do not need to pay rent :)"<<endl;
            return;
        }
        
        cout<<"This residence "<<this->name<<"has been bought by player "<<this->owner->get_name()<<endl;
        cout<<p.get_name()<<" needs to pay rent $"<<this->tuition<<" to "<<this->owner->get_name()<<endl;
        if(p.getMoney() >= this->tuition){ // if the player can afford the rent
            p.setMoney(p.getMoney() - this->tuition);
            this->owner->setMoney(this->owner->getMoney() + this->tuition);
        } else{ // if they can't afford the rent
            p.pay_more_than_have(this->tuition, b, *(this->owner));
            return;
        }
    } else{ // if the residences belongs to bank, the player has enough money, and he/she decides to buy
        if(p.getMoney() >= 200){
            cout<<"You have enough money, do you want to buy this residence?"<<endl;
            cout<<"Please enter <Yes> or <No>, if you enter other command, you'll buy this residence by default"<<endl;
            string in;
            cin>>in;
            // if they choose to buy the residence
            if(in != "No"){
                cout<<"You choose to buy this residence"<<endl;
                cout<<"You need to pay $200"<<endl;
                this->owner = std::make_shared<Player>(p);
                p.setMoney(p.getMoney() - 200);
                // add the asset to p's assets
                for(auto pro: b.properties){
                    if(pro->getName() == this->name){
                        p.add_asset(pro);
                    }
                }
                this->update();
                return;
            }
        } else{
            cout<<"You can't buy this residence because you do not have enough money"<<endl;
        }
        // if the player do not have enough money, or the player doesn't want to buy the residence: auction
            // auction
            cout<<"This residence "<<this->name<<" hasn't been bought"<<endl;
            cout<<"The residence "<<this->name<<" will be auctioned"<<endl;
            
            this->auction(p, b);
    }
    
}
