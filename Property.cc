#include "Player.h"
#include "Property.h"
#include "Board.h"
#include <vector>
using std::vector;

void Property::setOwner(string s, Board &b){
    if(s == "BANK"){
        this->owner = nullptr;
    } else{
        for(auto pl: b.players){
            if(pl->get_name() == s){
                this->owner = pl;
                for(auto pro : b.properties){
                    if(pro->getName()[0] == this->name[0] &&
                       pro->getName()[1] == this->name[1]){
                        pl->add_asset(pro);
                    }
                }
            }
        }
    }
}



void Property::setImprovement(int n){
    this->improvement = n;
}


//string Property::getName(){
//    return this->name;
//}

int Property::get_worth(){
    int result = this->purchase;
    result += this->improvement * improvementCost;
    return result;
}

int Property::get_cost(){
    return this->purchase;
}



string Property::get_owner(){
    if(this->owner == nullptr){
        return "BANK";
    } else{
        return this->owner->get_name();
    }
}

int Property:: getImprovement(){
    if(this->morgaged == true){
        return -1;
    }
    return this->improvement;
}

void Property:: auction(Player &p, Board &b){
    cout <<"Auction of " << this->getName() << " starts!" << endl;
    cout<<"There are "<<b.players.size()<<" player on board"<<endl;
    int bid = this->purchase;
    std::shared_ptr<Player> winner = nullptr;
    vector<bool> valid_player;
    for(int i = 0; i < b.players.size(); i++){
        valid_player.emplace_back(true);
    }
    int active = b.players.size() - 1;
    int broke_player = 0;
    for(int i = 0; i < b.players.size(); i++){
        if(b.players[i]->get_name() == p.get_name()){
            broke_player = i;
            break;
        }
    }
    int i = 0;
    while(active != 0){
        //cout<<"i = "<<i<<endl;
        // if the current player is the broke, skip
        if(i == broke_player) i = (i + 1) % b.players.size();
        //cout<<"i = "<<i<<endl;
        // if the current player has already withdrawed from the auction, skip
        if(valid_player[i] == false) i = (i + 1) % b.players.size();
        // now the buyer is valid
        if(active == 1) {
            // the player is the only active player, then he/she is the winner
            winner = b.players[i];
            break;
        }
        // now there are more than one player are active
        cout<<"the current bid is $"<<bid<<endl;
        //cout<<" i = "<< i <<endl;
        cout<<"the current player is "<<b.players[i]->get_name()<<endl;
        cout<<"if you want to continue, enter a price higher than the current bid,"<<endl;
        cout<<"if you want to quit, enter \"quit\", if you enter any other command, you will withdraw from the auction by default"<<endl;
        string in;
        cin>>in;
        if(is_num(in) && to_num(in) > bid){
            winner = b.players[i];
            bid = to_num(in);
        } else{
            active--;
            valid_player[i] = false;
            cout<<b.players[i]->get_name()<<" withdraws from the auction"<<endl;
        }
        i = (i + 1) % b.players.size();
    }
    // now we get the winner
    cout<<winner->get_name()<<" is the winner of this auction, and need to pay $"<<bid<<endl;
    
    if (winner->getMoney() >= bid){
        winner->setMoney(winner->getMoney() - bid);
        this->changeOwner(winner, b);
        for(auto pro: b.properties){
            if(pro->getName() == this->name){
                winner->add_asset(pro);
            }
        }
    } else {
        cout <<"You do not have enough money! But you must pay if you win an auction!" << endl;
        winner->pay_more_than_have(bid, b, *winner);
    }
}

