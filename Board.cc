#include "Board.h"
#include "Player.h"
#include "SLC.h"
#include "AcademicBuilding.h"
#include "Gyms.h"
#include "Residences.h"
#include "DCTims.h"
#include "Fee.h"
#include "GoToTims.h"
#include "GooseNesting.h"
#include "NeedlesHall.h"


// AcademicBuilding(int Id, string &name, int purchaseCost, int improvementCost);
Board::Board(){
    auto osap = make_shared<Fee>(0,"OSAP");
    auto al = make_shared<AcademicBuilding>(1,"AL",40,50);
    auto slc1 = make_shared<SLC>(2);
    auto ml = make_shared<AcademicBuilding>(3,"ML",60,50);
    auto f = make_shared<Fee>(4,"TUITION");
    auto mkv = make_shared<Residences>("MKV");
    auto ech = make_shared<AcademicBuilding>(6,"ECH",100,50);
    auto needle1 = make_shared<NeedlesHall>(7);
    auto pas = make_shared<AcademicBuilding>(8,"PAS",100,50);
    auto hh = make_shared<AcademicBuilding>(9,"HH",100,50);
    auto dc_tims = make_shared<DCTims>();
    auto rch = make_shared<AcademicBuilding>(11,"RCH",140,100);
    auto pac = make_shared<Gym>("PAC");
    auto dwe = make_shared<AcademicBuilding>(13,"DWE",140,100);
    auto cph = make_shared<AcademicBuilding>(14,"CPH",160,100);
    auto uwp = make_shared<Residences>("UWP");
    auto lhi = make_shared<AcademicBuilding>(16,"LHI",180,100);
    auto slc2 = make_shared<SLC>(17);
    auto bmh = make_shared<AcademicBuilding>(18,"BMH",180,100);
    auto opt = make_shared<AcademicBuilding>(19,"OPT",200,100);
    auto goose = make_shared<GooseNesting>();
    auto ev1 = make_shared<AcademicBuilding>(21,"EV1",220,150);
    auto needle2 = make_shared<NeedlesHall>(22);
    auto ev2 = make_shared<AcademicBuilding>(23,"EV2",220,150);
    auto ev3 = make_shared<AcademicBuilding>(24,"EV3",240,150);
    auto v1 = make_shared<Residences>("V1");
    auto phys = make_shared<AcademicBuilding>(26,"PHYS",260,150);
    auto b1 = make_shared<AcademicBuilding>(27,"B1",260,150);
    auto cif = make_shared<Gym>("CIF");
    auto b2 = make_shared<AcademicBuilding>(29,"B2",280,150);
    auto go_to_tims = make_shared<GoToTims>();
    auto eit = make_shared<AcademicBuilding>(31,"EIT",300,200);
    auto esc = make_shared<AcademicBuilding>(32,"ESC",300,200);
    auto slc3 = make_shared<SLC>(33);
    auto c2 = make_shared<AcademicBuilding>(34,"C2",320,200);
    auto rev = make_shared<Residences>("REV");
    auto needle3 = make_shared<NeedlesHall>(36);
    auto mc = make_shared<AcademicBuilding>(37,"MC",350,200);
    auto coop = make_shared<Fee>(38,"COOP");
    auto dc = make_shared<AcademicBuilding>(39,"DC",400,200);
    
    vector<shared_ptr<Gym>> gyms;
    gyms.emplace_back(pac);
    gyms.emplace_back(cif);
    pac->observers = gyms;
    cif->observers = gyms;
    vector<shared_ptr<Residences>> res;
    res.emplace_back(mkv);
    res.emplace_back(uwp);
    res.emplace_back(v1);
    res.emplace_back(rev);
    mkv->observers = res;
    uwp->observers = res;
    v1->observers = res;
    rev->observers = res;
    
    vector<shared_ptr<AcademicBuilding>> arts1;
    arts1.emplace_back(al);
    arts1.emplace_back(ml);
    al->observers = arts1;
    ml->observers = arts1;
    vector<shared_ptr<AcademicBuilding>> arts2;
    arts2.emplace_back(ech);
    arts2.emplace_back(pas);
    arts2.emplace_back(hh);
    ech->observers = arts2;
    pas->observers = arts2;
    hh->observers = arts2;
    vector<shared_ptr<AcademicBuilding>> eng;
    eng.emplace_back(rch);
    eng.emplace_back(dwe);
    eng.emplace_back(cph);
    rch->observers = eng;
    dwe->observers = eng;
    cph->observers = eng;
    vector<shared_ptr<AcademicBuilding>> health;
    health.emplace_back(lhi);
    health.emplace_back(bmh);
    health.emplace_back(opt);
    lhi->observers = health;
    bmh->observers = health;
    opt->observers = health;
    vector<shared_ptr<AcademicBuilding>> env;
    env.emplace_back(ev1);
    env.emplace_back(ev2);
    env.emplace_back(ev3);
    ev1->observers = env;
    ev2->observers = env;
    ev3->observers = env;
    vector<shared_ptr<AcademicBuilding>> sci1;
    sci1.emplace_back(phys);
    sci1.emplace_back(b1);
    sci1.emplace_back(b2);
    phys->observers = sci1;
    b1->observers = sci1;
    b2->observers = sci1;
    vector<shared_ptr<AcademicBuilding>> sci2;
    sci2.emplace_back(eit);
    sci2.emplace_back(esc);
    sci2.emplace_back(c2);
    eit->observers = sci2;
    esc->observers = sci2;
    c2->observers = sci2;
    vector<shared_ptr<AcademicBuilding>> math;
    math.emplace_back(mc);
    math.emplace_back(dc);
    mc->observers = math;
    dc->observers = math;
    
    squares.emplace_back(osap);
    squares.emplace_back(al);
    properties.emplace_back(al);
    squares.emplace_back(slc1);
    squares.emplace_back(ml);
    properties.emplace_back(ml);
    squares.emplace_back(f);
    squares.emplace_back(mkv);
    properties.emplace_back(mkv);
    squares.emplace_back(ech);
    properties.emplace_back(ech);
    squares.emplace_back(needle1);
    properties.emplace_back(pas);
    squares.emplace_back(pas);
    squares.emplace_back(hh);
    properties.emplace_back(hh);
    squares.emplace_back(dc_tims);
    squares.emplace_back(rch);
    properties.emplace_back(rch);
    squares.emplace_back(pac);
    properties.emplace_back(pac);
    squares.emplace_back(dwe);
    properties.emplace_back(dwe);
    squares.emplace_back(cph);
    properties.emplace_back(cph);
    squares.emplace_back(uwp);
    properties.emplace_back(uwp);
    squares.emplace_back(lhi);
    properties.emplace_back(lhi);
    squares.emplace_back(slc2);
    squares.emplace_back(bmh);
    properties.emplace_back(bmh);
    squares.emplace_back(opt);
    properties.emplace_back(opt);
    squares.emplace_back(goose);
    squares.emplace_back(ev1);
    properties.emplace_back(ev1);
    squares.emplace_back(needle2);
    squares.emplace_back(ev2);
    properties.emplace_back(ev2);
    squares.emplace_back(ev3);
    properties.emplace_back(ev3);
    squares.emplace_back(v1);
    properties.emplace_back(v1);
    squares.emplace_back(phys);
    properties.emplace_back(phys);
    squares.emplace_back(b1);
    properties.emplace_back(b1);
    squares.emplace_back(cif);
    properties.emplace_back(cif);
    squares.emplace_back(b2);
    properties.emplace_back(b2);
    squares.emplace_back(go_to_tims);
    squares.emplace_back(eit);
    properties.emplace_back(std::move(eit));
    squares.emplace_back(esc);
    properties.emplace_back(esc);
    squares.emplace_back(slc3);
    squares.emplace_back(c2);
    properties.emplace_back(c2);
    squares.emplace_back(rev);
    properties.emplace_back(rev);
    squares.emplace_back(needle3);
    squares.emplace_back(mc);
    properties.emplace_back(mc);
    squares.emplace_back(coop);
    squares.emplace_back(dc);
    properties.emplace_back(dc);
    
    this->cups = 0;
    
    
}

int Board::get_cups() const{
    return cups;
}



void Board::set_cups(int c){
    this->cups = c;
}

std::shared_ptr<Building>& Board::at(int pos){
    return squares[pos];
}


std::shared_ptr<Property> Board:: find_property(string s){
    for(auto pro : this->properties){
        if(pro->getName() == s){
            return pro;
        }
    }
    return nullptr;
}

void Board::trade(std::string name, std::string &give, std::string &receive){
    try{
        // check if the player's name is valid in main
        std::shared_ptr<Player> with;
        for(auto p : players){
            if(p->get_name() == name){
                with = p;
            }
        }

        if(is_num(give) && is_num(receive)){
            // if both give and receive are money, reject the trade
            cout<<"Your trade offer is rejected"<<endl;
            return;
        }
        cout << "Will " << with->get_name() << " accept or reject this trade?\nEnter <accept> or <reject>." << endl;
        string reply;
        cin >> reply;
        if (reply == "reject") {
            cout <<"Your trade offer is rejected"<< endl;
            return;
        } // else
        if(!is_num(give) && !is_num(receive)){
            // if both give and receive are property
            // check if their names are valid
            if (!curPlayer->asset_contain(give) || !with->asset_contain(receive))  throw Error();
            // now the buildings' names are valid
            // check if the monopoly has improvement
            std::shared_ptr<Property> g = this->find_property(give);
            std::shared_ptr<Property> r = this->find_property(receive);
            if(g->getImprovement() != 0 || r->getImprovement() != 0) throw Error();
            // now the buildings are good to trade
            curPlayer->remove_asset(g);
            with->add_asset(g);
            g->changeOwner(with, (*this));
            curPlayer->add_asset(r);
            with->remove_asset(r);
            r->changeOwner(curPlayer, (*this));

        } else if (is_num(give)){
            // now give is money, receive is building
            // check if the building's name is valid
            int g = to_num(give);
            if(!with->asset_contain(receive)) throw Error();
            std::shared_ptr<Property> r = this->find_property(receive);
            if( r->getImprovement() != 0) throw Error();
            // now the buildings are good to trade
            with->remove_asset(r);
            curPlayer->add_asset(r);
            r->changeOwner(curPlayer, (*this));
            with->setMoney(with->getMoney() - g);
        } else{
            // now give is building, receive is money
            // check if the building's name is valid
            int r = to_num(receive);
            if(!curPlayer->asset_contain(give)) throw Error();
            std::shared_ptr<Property> g = this->find_property(give);
            if(g->getImprovement() != 0) throw Error();
            // now the buildings are good to trade
            with->add_asset(g);
            curPlayer->remove_asset(g);
            g->changeOwner(with, (*this));
            curPlayer->setMoney(curPlayer->getMoney() + r);
            
        }
        cout << "Trade is successful!" << endl;
    } catch(Error &e){
        cout<<e.message()<<endl;
        cout<<"Trade is unsuccessful"<<endl;
    }

}


void Board::addPlayer(Player &p){
    players.emplace_back(std::make_shared<Player>(p));
}

