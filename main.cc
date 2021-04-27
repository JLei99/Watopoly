  #include "Board.h"
  #include "Player.h"
  #include <iostream>
  #include <string>
 #include <fstream>
  using namespace std;

 const string playerList [8] = {"Goose","GRT Bus", "Tim Hortons Doughnut", "Professor", "Student", "Money", "Laptop", "Pink tie"};

 bool valid_player_name(string s){
     for(int i = 0; i < 8;  i++){
         if(playerList[i] == s){
             return true;
         }
     }
     return false;
 }

bool player_already_exist(Board &b, string name){
    for(auto n : b.players){
        if(n->get_name() == name){
            return true;
        }
    }
    return false;
}

 vector<string> split_info(vector<string> v){
     if(v[0] == "GRT" || v[0] == "Pink"){
         v[0] = v[0] + " " + v[1];
         v.erase(v.begin() + 1);
     } else if (v[0] == "Tim"){
         v[0] = v[0] + " " + v[1] + " " + v[2];
         v.erase(v.begin() + 2);
         v.erase(v.begin() + 1);
     }
     return v;
 }

vector<string> split_pro(vector<string> v){
    if(v[1] == "GRT" || v[1] == "Pink"){
        v[1] = v[1] + " " + v[2];
        v.erase(v.begin() + 2);
    } else if (v[1] == "Tim"){
        v[1] = v[1] + " " + v[2] + " " + v[3];
        v.erase(v.begin() + 3);
        v.erase(v.begin() + 2);
    }
    return v;
}


string readName(){
    string word;
    cin >> word;
    if (word == playerList[0] || word == playerList[3] || word == playerList[4] || word == playerList[5] || word == playerList[6]){
        return word;
    }
    if (word == "GRT"  ){
        cin >> word;
        if (word == "Bus") return "GRT Bus";
    }
    if (word == "Tim") {
        cin >> word;
        if (word == "Hortons") {
            cin >> word;
            if (word == "Doughnut") return "Tim Hortons Doughnut";
        }
    }
    if (word == "Pink") {
        cin >> word;
        if (word == "tie") return "Pink tie";
    }
    return "";
}

  int main(int argc, char * argv[]) {
      cout << "Welcome to Watopoly!" << endl;
      Board watopoly{};
      bool testMode = false;
      int file_count = 0;
      //char *inputfile = new char;
      int file_pos = 0;
      for(int i = 1; i < argc; i++){
          if(argv[i][0] == '-' && argv[i][1] == 't'){
              testMode = true; // turn on the test mode
          } else{
              //inputfile = argv[i];
              file_count++;
              file_pos = i;
          }
      }
      
      if(file_count!= 0){ // there is a load file
          std::ifstream infile = std::ifstream{ argv[file_pos] };
          // if infile is unreadable
          if ( !infile.is_open() || infile.fail() ) {
              std::cout << "ERROR: " << argv[file_pos] << "cannot be opened for input"<<endl;
              return 1;
          }
          // now the infile is readable, load the game line by line
          cout<<"Loading the game from file "<<argv[file_pos]<<endl;
          std::string line;
              // get the first line(number of players)
          std::getline( infile, line );
          int num_player = to_num(line);
          cout<<"the number of player is "<<num_player<<endl;
          for(int i = 0; i < num_player; i++){
              // load the player
              std::getline( infile, line );
              vector<string> player_info = split_info(split(line));
              Player p{player_info[0]};
              p.set_cup(to_num(player_info[2]));
              p.setMoney(to_num(player_info[3]));
              p.set_pos(to_num(player_info[4]));
              cout<<"loading player "<<player_info[0]<<"..."<<endl;
              cout<<"player's cup = "<<to_num(player_info[2])<<endl;
              cout<<"player's Money = $"<<to_num(player_info[3])<<endl;
              cout<<"player's position is "<<to_num(player_info[4])<<endl;
              if(player_info.size() == 6){ // pass by DC Tims
                  p.DC_Tims_time = 0;
                  cout<<"player currently doesn't get stuck in DC Tims Line"<<endl;
              }
              if(player_info.size() == 7){ // stuck in DC Tims
                  p.DC_Tims_time = to_num(player_info[6]) + 1;
                  cout<<"player currently gets stuck in DC Tims Line"<<endl;
              }
              
              watopoly.addPlayer(p);
          }
          cout<<"All players are loaded"<<endl;
          cout<<"Now loading properties"<<endl;
          // now load the status of the properties
          while (std::getline( infile, line )) {
               
              // load the game
              vector<string> pro_info = split_pro(split(line));
              for(auto pro : watopoly.properties){
                  // we find the certain property to update
                  // set the owner
                  if(pro->getName() == pro_info[0]){
                      pro->setOwner(pro_info[1], watopoly);
                      int improve_num = to_num(pro_info[pro_info.size() - 1]);
                      pro->setImprovement(improve_num);
                      cout<<"Loading property "<<pro->getName()<<"..."<<endl;
                      cout<<"property's number of improvement is: "<<improve_num<<endl;
                  }
                 
              }
              
          }
          // update all properties
          for(auto pro : watopoly.properties){
              pro->update();
          }
          
         cout<<"Loading finished"<<endl;
              // Closes the I/O files. Don't delete if standard input or output, though.
     
          
      } else{
          // if there is no input file, select the new players
          cout<<"Start a new game"<<endl;
          cout << "How many players?\nPlease enter a number between 6 and 8" << endl;
          int num_player;
          while (cin >> num_player){
              if (  num_player >= 6 && num_player <= 8) {
                  break;
              } else {
                  cout << "Please enter a number between 6 and 8." << endl;
              }
          }
          cout<<"Please choose "<< num_player << " players from the following list: "<<endl;
          for(int i = 0; i < 8; i++){
              cout<<playerList[i]<<endl;;
          }
          string name;
          string cmd;
          cout << "To create a new player: enter <name> <char>" << endl;
          while(num_player-- > 0){
              name = readName();
              if(valid_player_name(name)){
                  // check if the player has been added
                  if(player_already_exist(watopoly, name)) {
                      cout << "Player already exists! Pick another one!" << endl;
                      cin>>cmd;
                      num_player++;
                      continue;
                  }
                  Player p{name};
                  cin >> cmd;
                  if (p.get_char() != (*(cmd.c_str()))){
                      cout << "Please enter the right player name with right char" << endl;
                      num_player++;
                  } else {
                      watopoly.addPlayer(p);
                  }
              } else{
                  cin >> cmd;
                  cout<<"Invalid player name, try another name"<<endl;
                  num_player++;
              }
              
              cout << "To create a new player: enter <name> <char>" << endl;
          }
      }
      // now check if the test mode is on
      if(testMode){
          testMode = true;
      }
      
      string cmd;
      bool rolled = false;
      int cplayer = 0;
      watopoly.curPlayer = watopoly.players.at(cplayer);
      cout << "Let's start the game!\n" <<watopoly.curPlayer->get_name() << "'s turn now!" << endl;
      while(cin >> cmd){
          if (cmd == "roll"){
              if (rolled) {
                      cout << "You have rolled! Choose another command!" << endl;
                      continue;
                  }
                  int steps = 0;
                  bool test_roll_again = false;
                  if (testMode){
                      int step1 = 0;
                      int step2 = 0;
                      cin>>step1;
                      cin>>step2;
                      steps = step1 + step2;
                      if(step1 == step2) test_roll_again = true;
                  }
                  watopoly.curPlayer->takeStep(watopoly, steps, testMode, test_roll_again);
                  rolled = true;
              } else if (cmd == "next"){
                  if (!rolled){
                      cout <<"You have not rolled yet. Please roll!" << endl;
                      continue;
                  }
                  watopoly.curPlayer = watopoly.players.at(++cplayer % watopoly.players.size());
                  cout << "Now, it is " << watopoly.curPlayer->get_name() <<
                  "'s turn!" <<endl;
                  rolled = false;
          } else if (cmd == "trade"){
              string name = readName();
              string give;
              cin >> give;
              string receive;
              cin >> receive;
              watopoly.trade(name, give, receive);
          } else if (cmd == "improve"){
              string property;
              cin >> property;
              cin >> cmd;
              if (cmd == "sell"){
                  watopoly.curPlayer->improve(property, false);
              } else {
                  watopoly.curPlayer->improve(property, true);
              }
          } else if (cmd == "mortgage"){
              string property;
              cin >> property;
              watopoly.curPlayer->mortgage(property);
          } else if (cmd == "unmortgage"){
              string property;
              cin >> property;
              watopoly.curPlayer->unmortgage(property);
          } else if (cmd == "assets"){
              watopoly.curPlayer->asset();
          } else if (cmd  == "all") {
              for (auto p : watopoly.players){
                  p->asset();
              }
          } else if (cmd == "-testing"){
              testMode = !testMode;
          } else if (cmd == "save") {
              string file;
              cin>>file;
              std::ofstream outfile{ file };
              outfile << watopoly.players.size() << std::endl;
              for(auto pl : watopoly.players){
                  outfile<<pl->get_name()<<" "<<pl->get_char()<<" "<<pl->get_cup()<<" "<<pl->getMoney()<<" "<<pl->get_pos()<<" ";
                  if(pl->DC_Tims_time == 0){
                      outfile<<"0"<<endl;
                  } else{
                      outfile<<"1 "<<pl->DC_Tims_time - 1<<endl;
                  }
              }
              for(int i = 0; i < watopoly.properties.size() - 1; i++){
                  outfile<<watopoly.properties[i]->getName()<<" "<<watopoly.properties[i]->get_owner()<<" "<<watopoly.properties[i]->getImprovement()<<endl;
              }
              outfile<<watopoly.properties[watopoly.properties.size() - 1]->getName()<<" "<<watopoly.properties[watopoly.properties.size() - 1]->get_owner()<<" "<<watopoly.properties[watopoly.properties.size() - 1]->getImprovement();
              cout<<"You've saved the game to file "<<file<<endl;
          } else if (cmd == "quit"){
              break;
          } else {
              cout << "Please enter a valid command!" << endl;
          }
          
          
      }
  }





