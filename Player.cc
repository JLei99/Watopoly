
 #include "Player.h"

void Player::set_cup(int n){
    this->roll_up = n;
}

 bool Player::asset_contain(string s){
     for(auto p : this->assets){
         if(p->getName() == s){
             return true;
         }
     }
     return false;
 }

char Player::get_char(){
    return this->ch;
}

int Player::get_cup(){
    return this->roll_up;
}

 std::shared_ptr<Property> Player::find_asset(string s){
     for(auto pro : this->assets){
         if(pro->getName() == s){
             return pro;
         }
     }
     return nullptr;
 }


 Player::Player(string name){
     this->name = name;
     this->money = 1500;
     this->roll_up = 0;
     this->bank_rupt = false;
     this->position = 0;
     this->DC_Tims_time = 0;
     if(name == "Goose"){
         this->ch = 'G';
     } else if(name == "GRT Bus"){
         this->ch = 'B';
     } else if(name == "Tim Hortons Doughnut"){
         this->ch = 'D';
     } else if(name == "Professor"){
         this->ch = 'P';
     } else if(name == "Student"){
         this->ch = 'S';
     } else if(name == "Money"){
         this->ch = '$';
     } else if(name == "Laptop"){
         this->ch = 'L';
     } else { // pink tie
         this->ch = 'T';
     }
 }

 void Player::remove_asset(std::shared_ptr<Property> pro){
     int i;
     for(i = 0; i < this->assets.size(); i++){
         if(assets[i]->getName() == pro->getName()){
             break;
         }
     }
     this->assets.erase(this->assets.begin() + i);
 }


 void Player::add_asset(std::shared_ptr<Property> p){
     assets.push_back(p);
 }

 vector<string> split(const string& s){
     vector<string> tokens;
     string token;
     std::istringstream tokenStream(s);
     while (std::getline(tokenStream, token, ' '))
     {
         tokens.push_back(token);
         
     }
     return tokens;
 }

 int Player::get_pos(){
     return this->position;
 }

 void Player::set_pos(int n){
     this->position = n;
 }

 void Player::setMoney(int new_money){
     this->money = new_money;
     std::cout << "Now "<< this->name <<" have $" << money << std::endl;
 }

 int Player::getMoney(){
     return money;
 }

 void Player::add_cup(){
     this->roll_up++;
 }

 int Player::getTotalWorth(){
     int worth = this->money;
     for(auto build : this->assets){
         worth += build->get_worth();
     }
     return worth;
 }

 string Player::get_name(){
     if(this == nullptr) return "BANK";
     return this->name;
 }


 bool Player::roll(int * step_num){
     int dice1 = rand() % 6 + 1;
     int dice2 = rand() % 6 + 1;
     cout<<"dice1: "<<dice1<<endl;
     cout<<"dice2: "<<dice2<<endl;
     *(step_num) += dice1 + dice2;
     if(dice1 == dice2){
         cout<<"roll double!"<<endl;
         return true;
     }
     return false;
 }

void Player::takeStep(Board &b, int steps, bool test, bool test_roll_again){
    cout<<"Now it's turn for player "<<this->name<<endl;
    cout<<"You currently have $"<<this->money<<endl;
    int step_num = steps;
    bool roll_again = false;
    // first roll the dices
    if (steps == 0){
        roll_again = roll(&step_num);
    }
    
    if(this->position == 10 && this->DC_Tims_time == 3){
        cout<<"This is your third turn being in the DC Tims Line, you must leave the DC Tims Line"<<endl;
        this->DC_Tims_time = 0;
        if(this->roll_up != 0){
            string use;
            cout<<"Choose to use a Roll up the Rim cup?"<<endl;
            cout<<"Please enter \"Yes\" or \"No\", if you enter other command, you will ues the Roll up the Rim cup by default"<<endl;
            cin>>use;
            if(use != "No"){
              cout<<"You chose to use a Roll up the Rim cup, now you leave the DC Tims Line!"<<endl;
                roll_up -= 1;
            }
        } else{
            cout<<"You now have to pay $50 to leave"<<endl;
            if(this->money > 50){
                this->money -= 50;
            } else{
                this->pay_more_than_have(50, b, *this);
            }
        }
    }
    if(this->position == 10 && this->DC_Tims_time != 0 && (roll_again ||  test_roll_again)){
        cout<<"roll double! You can leave Tims Line now:)"<<endl;
        DC_Tims_time = 0;
    }
    
    
    // check if the player is in DCTims Line and doesn't roll double
    if(this->position == 10 && this->DC_Tims_time != 0 && !roll_again && ! test_roll_again){
        cout<<"You are currently stuck in DC Tims Line and you didn't roll double"<<endl;
        if(this->roll_up != 0){
            string use;
            cout<<"Choose to use a Roll up the Rim cup?"<<endl;
            cout<<"Please enter \"Yes\" or \"No\", if you enter other command, you will not use the Roll up the Rim cup by default"<<endl;
            cin>>use;
            if(use == "Yes"){ // if the player choose to use
                cout<<"You chose to use a Roll up the Rim cup, now you leave the DC Tims Line!"<<endl;
                roll_up -= 1;
                this->DC_Tims_time = 0;
            }
        } else{
            cout<<"You currently have no Roll up the Rim cup"<<endl;
            cout<<"Choose to pay $50 to leave the DC Tims Line?"<<endl;
            cout<<"Please enter \"Yes\" or \"No\", if you enter other command, you will not pay $50 by default"<<endl;
            string use;
            cin>>use;
            if(use == "Yes"){
                cout<<"You chose pay $50, now you leave the DC Tims Line!"<<endl;
                if(this->money > 50){
                    this->money -= 50;
                } else{
                    this->pay_more_than_have(50, b, *this);
                }
                this->DC_Tims_time = 0;
            } else{
                cout<<"Oops! You are still stuck in DC Tims Line:("<<endl;
                DC_Tims_time++;
                return;
            }
        }
    }
    
    // if the testMode is on (note that the roll_again for testMode is allways off)
    if(test == true){
        int times = 1;
        while(true){
            if(test_roll_again == false){
                break;
            }
            if(times == 3){
                this->position = 10;
                this->DC_Tims_time = 1;
                cout<<"Ops! You are sent to the DC Tims Line"<<endl;
                return;
            }
            // now it means the roll again
            times++;
            cout<<"You roll double, please roll again, follow the format \"roll\" <num1> <num2>"<<endl;
            string r,num1, num2;
            cin>>r;
            cin>>num1;
            cin>>num2;
            while(!(r == "roll" && is_num(num1) && is_num(num2))){
                cout<<"Invalid command! Please follow the format\"roll\" <num1> <num2>"<<endl;
                cin>>r;
                cin>>num1;
                cin>>num2;
            }
            step_num += to_num(num1) + to_num(num2);
            test_roll_again = (num1 == num2);
        }
    }
    
    // if the player is not currently stuck in DC Tims Line
    // for the first time the dices have the same number
    if(roll_again){
        roll_again = roll(&step_num);
    }
    // for the second time they roll again
    if(roll_again){
        roll_again = roll(&step_num);
    }
    // for the third time the dices have the same number, the player is sent to the TimsLine
    if(roll_again){
        // send to TimsLine directly
        this->position = 10;
        this->DC_Tims_time = 1;
        cout<<"Oops! You are sent to the DC Tims Line"<<endl;
        return;
    }
    // now we get the number of steps to move
    int pre_pos = this->position;
    // update the player's position
    this->position = (this->position + step_num) % 40;
    // if the player passes over OSAP
    if(pre_pos + step_num > 40){
        this->money += 200;
        cout<<"You pass over Collect OSAP and get $200!"<<endl;
    }
    // now the player lands on a perticular place, and we call the function
    std::shared_ptr<Building>& place = b.at(this->position);
    cout << "You are now at " << place->getName() << "!"<<endl;
    place->arrive(*this, b);
}





 bool is_num(string s){
     size_t len = s.length();
     for(int i = 0; i < len ; i++){
         if(!('0' <= s[i] && s[i] <='9'))
             return false;
     }
     return true;
 }

 int to_num(string s){
     int result = 0;
     size_t len = s.length();
     for(int i = 0; i < len ; i++){
         result = result * 10 + s[i] - '0';
     }
     return result;
 }



 void Player::improve(std::string property, bool buy){
     try{
         // check if the property name is valid
         bool valid = false;
         for(auto item: own){
             if(item == property) valid = true;
         }
         if(!valid) throw Error();
         // now buy or sell the improvement of property
         std::shared_ptr<Property> prop = find_asset(property);
         if(buy){
             prop->buyImprovement();
         } else {
             prop->sellImprovement(1);
         }
         
     } catch(Error &e){
         cout<<e.message()<<endl;
         cout<<"improve unsuccessfully"<<endl;
     }
 }


 void Player::mortgage(std::string property){
     try{
         // now buy or sell the improvement property
         std::shared_ptr<Property> prop = find_asset(property);
         if (prop == nullptr || prop->morgaged) throw Error();
         if (prop ->getImprovement() > 0) prop->sellImprovement();
         // change status
         prop->morgaged = true;
        // this->money += this->find_asset(property)->get_cost() * 0.5;
         this->setMoney(money + prop->get_cost() * 0.5);
     } catch(Error &e){
         cout<<e.message()<<endl;
         cout<<"mortgage unsuccessfully"<<endl;
     }
 }
 void Player::unmortgage(std::string property){
     try{
         // check if the property name is valid
         // now buy or sell the improvement property
         std::shared_ptr<Property> prop = find_asset(property);
         if (prop == nullptr || !prop->morgaged) throw Error();
         // change status
         prop->morgaged = false;
         //this->money -= this->find_asset(property)->get_cost() * 0.6;
         this->setMoney(this->money - prop->get_cost() * 0.6);
     } catch(Error &e){
         cout<<e.message()<<endl;
         cout<<"unmortgage unsuccessfully"<<endl;
     }
 }


 void Player::bankrupt(Player &p, Board &b){
     cout<<this->name<<" is declaring bankruptcy"<<endl;
     this->bank_rupt = true;
     // if the player owe money to other player
     
     if(p.get_name() != this->name){
         // destroy the cups
         b.set_cups(b.get_cups() - this->roll_up);
         // update all Property
         for(auto prop : assets){
             prop->changeOwner(make_shared<Player>(p), b);
             prop->update();
         }
         // transfer all assets
         for(auto pro: this->assets){
             p.add_asset(std::move(pro));
         }
         
     } else{ // if this player owe money to bank
         // destroy the cups
         b.set_cups(b.get_cups() - this->roll_up);
         for(auto pro : assets){
             // clear the properties
             pro->morgaged = false;
             pro->setImprovement(0);
             pro->changeOwner(nullptr, b);
         }
         assets.clear();
     }
         // update active players on board
         for(int i = 0; i < b.players.size(); i++){
             if(b.players[i]->get_name() == this->name){
                 b.players.erase(b.players.begin() + i);
             }
         }
     if(b.players.size() == 1){
         cout << (*(b.players.begin()))->name << " is the only player left! You win! Congragulations!" << endl;
     }
 }

 void Player::asset(){
     cout<<this->name<<": ";
     for(auto b : this->assets){
         cout<<b->getName()<<" ";
     }
     cout<<endl;
 }


 //At any time when a player must pay more money than they currently have, they have the option to drop out (declare bankruptcy) or attempt to trade, mortgage buildings and sell improvements to gather the required money.
 void Player::pay_more_than_have(int pay, Board &b, Player &p){
     cout << "You are unable to pay the fee!\nChoose an option from:\nDeclare bankrupt<bankrupt>(Default)\nMortgage<mortgage><property>\nSell improvement<improvement><property>\nOr trade<trade><name><give><receive>" << endl;
     string cmd;
     string arg;
  //   bool try_to_raise = true;
     while (cin >> cmd){
         if (cmd == "bankrupt"){
             this->bankrupt(p, b);
             return;
       //      try_to_raise = false;
         } else if (cmd == "mortgage") {
             cin >> arg;
             this->mortgage(arg);
         } else if (cmd == "improvement"){
             cin >> arg;
             this->improve(arg, false);
         } else if (cmd == "trade"){
             string name;
             cin >> name;
             string give;
             cin >> give;
             string receive;
             cin >> receive;
             b.trade(name, give, receive);
         } else {
             cout << "Invalid Command! You will declare bankrupt by default!"<< endl;
             this->bankrupt(p, b);
             return;
     //        try_to_raise = false;
         }
         if (this->money >= pay) {
             cout << "You have raised enough money! $" << pay << " is paid."<< endl;
             this->setMoney(money - pay);
             return;
         }
         cout << "You are still unable to pay the fee!\nChoose an option from:\nDeclare bankrupt<bankrupt>(Default)\nMortgage<mortgage><property>\nSell improvement<improvement><property>\nOr trade<trade><name><give><receive>" << endl;
     }
 }
