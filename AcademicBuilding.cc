 
#include "AcademicBuilding.h"
#include "Player.h"
#include "Error.h"

using namespace std;
#include <algorithm>

AcademicBuilding::AcademicBuilding(int ID,const string &name, int purchaseCost, int improvementCost){
    this->ID = ID;
    Building::name = name;
    this->purchase = purchaseCost;
    this->improvementCost = improvementCost;
    improvement = 0;
    monopoly = false;
    tuition = table.getTuition(this->getName(), 0);
    this->morgaged = false;
    this->owner = nullptr;
    
}

void AcademicBuilding::buyImprovement(){
    if (monopoly == false){
        cout << "Not monopoly! Unable to buy improvement!" << endl;
        return;
    }
    if (morgaged) {
        cout << "Mortgaged! Unable to buy improvement!" << endl;
        return;
    }
    if(improvementCost <= owner->getMoney()){
        owner->setMoney(owner->getMoney() - improvementCost);
        improvement++;
        tuition = table.getTuition(this->getName(), improvement);
    } else {
        cout<<"Failed! You do not have enough money!" <<endl;
    }
}

tuitionTable::tuitionTable(){
    map<int, int> m;
    m.emplace(make_pair(0, 2));
    m.emplace(make_pair(1, 10));
    m.emplace(make_pair(2, 30));
    m.emplace(make_pair(3, 90));
    m.emplace(make_pair(4, 160));
    m.emplace(make_pair(5, 250));
    table.emplace(make_pair("AL", m));
    m.clear();
    m.emplace(make_pair(0, 4));
    m.emplace(make_pair(1, 20));
    m.emplace(make_pair(2, 60));
    m.emplace(make_pair(3, 180));
    m.emplace(make_pair(4, 320));
    m.emplace(make_pair(5, 450));
    table.emplace(make_pair("ML", m));
    m.clear();
    m.emplace(make_pair(0, 6));
    m.emplace(make_pair(1, 30));
    m.emplace(make_pair(2, 90));
    m.emplace(make_pair(3, 270));
    m.emplace(make_pair(4, 400));
    m.emplace(make_pair(5, 550));
    table.emplace(make_pair("ECH", m));
    table.emplace(make_pair("PAS", m));
    m.clear();
    m.emplace(make_pair(0, 8));
    m.emplace(make_pair(1, 40));
    m.emplace(make_pair(2, 100));
    m.emplace(make_pair(3, 300));
    m.emplace(make_pair(4, 450));
    m.emplace(make_pair(5, 600));
    table.emplace(make_pair("HH", m));
    m.clear();
    m.emplace(make_pair(0, 10));
    m.emplace(make_pair(1, 50));
    m.emplace(make_pair(2, 150));
    m.emplace(make_pair(3, 450));
    m.emplace(make_pair(4, 625));
    m.emplace(make_pair(5, 750));
    table.emplace(make_pair("RCH", m));
    table.emplace(make_pair("DWE", m));
    m.clear();
    m.emplace(make_pair(0, 12));
    m.emplace(make_pair(1, 60));
    m.emplace(make_pair(2, 180));
    m.emplace(make_pair(3, 500));
    m.emplace(make_pair(4, 700));
    m.emplace(make_pair(5, 900));
    table.emplace(make_pair("CPH", m));
    m.clear();
    m.emplace(make_pair(0, 14));
    m.emplace(make_pair(1, 70));
    m.emplace(make_pair(2, 200));
    m.emplace(make_pair(3, 550));
    m.emplace(make_pair(4, 750));
    m.emplace(make_pair(5, 950));
    table.emplace(make_pair("LHI", m));
    table.emplace(make_pair("BMH", m));
    m.clear();
    m.emplace(make_pair(0, 16));
    m.emplace(make_pair(1, 80));
    m.emplace(make_pair(2, 220));
    m.emplace(make_pair(3, 600));
    m.emplace(make_pair(4, 800));
    m.emplace(make_pair(5, 10000));
    table.emplace(make_pair("OPT", m));
    m.clear();
    m.emplace(make_pair(0, 18));
    m.emplace(make_pair(1, 90));
    m.emplace(make_pair(2, 250));
    m.emplace(make_pair(3, 700));
    m.emplace(make_pair(4, 875));
    m.emplace(make_pair(5, 1050));
    table.emplace(make_pair("EV1", m));
    table.emplace(make_pair("EV2", m));
    m.clear();
    m.emplace(make_pair(0, 20));
    m.emplace(make_pair(1, 100));
    m.emplace(make_pair(2, 300));
    m.emplace(make_pair(3, 750));
    m.emplace(make_pair(4, 925));
    m.emplace(make_pair(5, 1100));
    table.emplace(make_pair("EV3", m));
    m.clear();
    m.emplace(make_pair(0, 22));
    m.emplace(make_pair(1, 110));
    m.emplace(make_pair(2, 330));
    m.emplace(make_pair(3, 800));
    m.emplace(make_pair(4, 975));
    m.emplace(make_pair(5, 1150));
    table.emplace(make_pair("PHYS", m));
    table.emplace(make_pair("B1", m));
    m.clear();
    m.emplace(make_pair(0, 24));
    m.emplace(make_pair(1, 120));
    m.emplace(make_pair(2, 360));
    m.emplace(make_pair(3, 850));
    m.emplace(make_pair(4, 1025));
    m.emplace(make_pair(5, 1200));
    table.emplace(make_pair("B2", m));
    m.clear();
    m.emplace(make_pair(0, 26));
    m.emplace(make_pair(1, 130));
    m.emplace(make_pair(2, 390));
    m.emplace(make_pair(3, 900));
    m.emplace(make_pair(4, 1100));
    m.emplace(make_pair(5, 1275));
    table.emplace(make_pair("EIT", m));
    table.emplace(make_pair("ESC", m));
    m.clear();
    m.emplace(make_pair(0, 28));
    m.emplace(make_pair(1, 150));
    m.emplace(make_pair(2, 450));
    m.emplace(make_pair(3, 1000));
    m.emplace(make_pair(4, 1200));
    m.emplace(make_pair(5, 1400));
    table.emplace(make_pair("C2", m));
    m.clear();
    m.emplace(make_pair(0, 35));
    m.emplace(make_pair(1, 175));
    m.emplace(make_pair(2, 500));
    m.emplace(make_pair(3, 1100));
    m.emplace(make_pair(4, 1300));
    m.emplace(make_pair(5, 1500));
    table.emplace(make_pair("MC", m));
    m.clear();
    m.emplace(make_pair(0, 50));
    m.emplace(make_pair(1, 200));
    m.emplace(make_pair(2, 600));
    m.emplace(make_pair(3, 1400));
    m.emplace(make_pair(4, 1700));
    m.emplace(make_pair(5, 2000));
    table.emplace(make_pair("DC", m));
}


int tuitionTable::getTuition(const string &name, int improvement){
    return table.at(name).at(improvement);
}


void AcademicBuilding::arrive(Player &p, Board &b) {
    if (this->owner->get_name() == p.get_name()) {
        cout << "This is your AcademicBuilding!" << endl;
    } else if(this->owner != nullptr){
        //1. if owner is not bank and not player itself
        //     give tuition
        if (this->morgaged) {
            cout << "The building is mortgaged, you do not have to pay the fee :)" << endl;
            return;
        }
        if (p.getMoney() >= tuition){
            cout << "This is " << this->owner->get_name() << "'s property!\nYou will pay $"<< this->tuition <<endl;
            p.setMoney(p.getMoney() - tuition);
            owner->setMoney(owner->getMoney() + tuition);
            
        } else {
            p.pay_more_than_have(tuition, b, *(this->owner));
        }
    } else {
        //2. if owner is bank
        //     decide but or not
        cout << "Do you want to buy " << this->name << "?\nType <Yes> or <No>" <<endl;
        string cmd;
        if (cin >> cmd){
            if (cmd == "Yes"){
                if (p.getMoney() >= this->purchase){
                    this->buy(p, b);
                    cout << this->name << " has been bought successfully!" <<endl;
                } else {
                    cout << "Error! Not enough money!"<< endl;
                    //  p.pay_more_than_have(tuition, b, *(this->owner));
                    this->auction(p, b);
                  //  throw Error();
                }
            } else if (cmd == "No") {// decide not buying -> auction
                this->auction(p, b);
            } else {
                cout << "Invalid command! "<< this->getName()<< " will be auctioned!"<< endl;
                this->auction(p, b);
            }
        }
    }
    
}

// buys the property
// pay money, add property to assets,
// change owner, notify observers
// require: money >= purchaseCost
void AcademicBuilding::buy(Player &to, Board &b){
    to.setMoney(to.getMoney() - this->purchase);
    owner = std::make_shared<Player>(to);
    for(auto pro: b.properties){
        if(pro->getName() == this->name){
            to.add_asset(pro);
            break;
        }
    }
    update();
}



// update the state and set to new state
void AcademicBuilding::update(){
    bool newState = true;
    for(auto it = observers.begin(); it != observers.end(); it++){
        if ((*it)->owner == nullptr || (*it)->owner->get_name() != this->owner->get_name()){
            newState = false;
            break;
        }
    }
    if(newState != monopoly){
        //for(auto it = observers.begin(); it != observers.end(); it++){
            this->setState(newState);
      //  }
    }
    
}


// set the state to monopoly_now
void AcademicBuilding::setState(bool monopopy_now){
    for(auto it = observers.begin(); it != observers.end(); it++){
        if(monopopy_now){ // change to monopoly
            (*it)->monopoly = monopopy_now;
            (*it)->tuition = table.getTuition((*it)->getName(), 0) * 2;
            (*it)->improvement = 0;
        } else {
            if ((*it)->improvement != 0) {
                // sell improvement
                (*it)->owner->setMoney((*it)->owner->getMoney() + (*it)->improvementCost * improvement);
                (*it)->improvement = 0;
                (*it)->tuition = table.getTuition((*it)->getName(), 0);
            }
        }
    }
}


void AcademicBuilding::changeOwner(std::shared_ptr<Player> to, Board &b) {
    if (improvement > 0 ){
        cout << "You have to sell improvements first!" << endl;
        return;
    }
    this->owner = to;
    this->update();
}



void AcademicBuilding::sellImprovement(int num = 0) {
    if (num == 0 || num > improvement){
        // sell all
        this->owner->setMoney(owner->getMoney() + improvementCost * improvement / 2);
        improvement = 0;
        tuition = table.getTuition(this->getName(), improvement);
    } else if (improvement > 0){ // sell one improvement
        this->owner->setMoney(owner->getMoney() + improvementCost / 2);
        improvement -= 1;
        tuition = table.getTuition(this->getName(), improvement);
    } else {
        cout << "You do not have any improvement to sell!" << endl;
    }
}


