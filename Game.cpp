#include "Game.h"

//Game::Game(UserUnit& _userunit,PcUnit& _pcunit,Input& _input):userunit(_userunit),pcunit(_pcunit),input(_input){
Game::Game(){
    //View& _view,Model& _model,KeyBinding& _keybinding):view(_view),model(_model),keybinding(_keybinding){
    CreateUnits();
    activePc = 3;
    activeUser = 0;
    manuUp = true;
    over = false;
    userTurn = true;
}

void Game::GameLoop() {
    //Ini
    //sf::Time second = sf::seconds(0.5);   //sekundy

    sf::RenderWindow window(sf::VideoMode(1050,540),"Turn-Based Game");
    window.setFramerateLimit(120);

    //Main game loop
    while(window.isOpen()){
        sf::Event event{};
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
        }

        //Update
        Update(window);
        //Render

        if(over){
            RenderOver(window);
        }else{
            if(manuUp){
                RenderMenu(window);
            }else{
                RenderGame(window);
            }
        }
    }
}

void Game::Update(sf::RenderWindow& window){ //potem usunac parametr
    //Mouse
    UpadateMousePosition(window);

    //Inputs
    if(manuUp and sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
        manuUp = false;
    }
    else if(manuUp and sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
        window.close();
    }
    else if (!manuUp) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            manuUp = true;
        }

        if(userTurn){
            UserTurn(window);
        }else{
            PcTurn(window);
        }
    }
}

void Game::UpadateMousePosition(sf::RenderWindow& window){
    cout<<sf::Mouse::getPosition(window).x <<" "<<sf::Mouse::getPosition(window).y<<"\n";
    mousePosWindow = sf::Mouse::getPosition(window);
}

void Game::RenderMenu(sf::RenderWindow& window){
    window.clear(sf::Color::Blue);
    //Draw here
    BackGround("MENU",0,0).draw(window);
    Font("Press Space",450,440).draw(window);
//    UnitsTab[activePc]->draw(window);
//    UnitsTab[activeUser]->draw(window);
    window.display();
}

void Game::RenderGame(sf::RenderWindow& window){
    float myhp = UnitsTab[activeUser]->GetHp();
    float enemyhp = UnitsTab[activePc]->GetHp();
    std::string myname = UnitsTab[activeUser]->getName();
    std::string enemyname = UnitsTab[activePc]->getName();

    window.clear(sf::Color::Blue);

    //Draw here
    BackGround("BG",0,0).draw(window);
    BackGround("MANUAL",770,287).draw(window);

    UnitsTab[activePc]->draw(window);
    std::string playerinfo = (myname+"\n\t "+to_string(int(myhp)));
    Font(playerinfo,290, 260).draw(window);

    UnitsTab[activeUser]->draw(window);
    std::string enemyinfo = (enemyname+"\n\t "+to_string(int(enemyhp)));
    Font(enemyinfo,660, 110).draw(window);

    window.display();
}

void Game::RenderOver(sf::RenderWindow& window){
    window.clear(sf::Color::Blue);
    //Draw here
    BackGround("OVER",0,0).draw(window);
//    UnitsTab[activePc]->draw(window);
//    UnitsTab[activeUser]->draw(window);
    window.display();
}

//void Game::RenderText(sf::RenderTarget& target){
//    Font().draw(target);
//}




void Game::CreateUnits(){
    UnitsTab.push_back(make_shared<UserUnit>("SABER"));     //0
    UnitsTab.push_back(make_shared<UserUnit>("LANCER"));    //1
    UnitsTab.push_back(make_shared<UserUnit>("ARCHER"));   //2

    UnitsTab.push_back(make_shared<PcUnit>("LANCER"));     //3
}


void Game::UserTurn(sf::RenderWindow& window){
    float myhp = UnitsTab[activeUser]->GetHp();
    float enemyhp = UnitsTab[activePc]->GetHp();
    float dmgmulti = UnitsTab[activeUser]->GetDmgMulti();
    std::string myname = UnitsTab[activeUser]->getName();
    std::string enemyname = UnitsTab[activePc]->getName();
    int score=0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)){
        //attack
        float dmg=4;
        if((myname == "Saber" && enemyname=="Lancer") or (myname == "Lancer" && enemyname=="Archer") or (myname == "Archer" && enemyname=="Saber")){
            dmg = dmg + (dmg * dmgmulti);
        }else if((myname == "Lancer" && enemyname=="Saber")or(myname == "Archer" && enemyname=="Lancer")or(myname == "Saber" && enemyname=="Archer")) {
            dmg = dmg - (dmg * dmgmulti);
        }else{

        }
        enemyhp-=dmg;
        cout<<"Player atk "<<myname<<" "<<myhp<<"-"<<enemyname<<" "<<enemyhp<<"\n";  //do wywalenia-------------------------------------------------------------
        UnitsTab[activePc]->SetHp(enemyhp);
        userTurn=false;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        //heal/overheal
        UnitsTab[activeUser]->SetHp(myhp+2);
        cout<<"Player heal "<<UnitsTab[activeUser]->GetHp()<<"\n"; //do wywalenia -----------------------------------------------------
        userTurn=false;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)){   //hold
        //changeunit
        //cout<<"1-3 ";
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1) and (UnitsTab[0]->GetHp())>0){
            //SABER
            activeUser=0;
            cout<<"Player change to"<<activeUser<<"\n";
            userTurn=false;
        }else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) and (UnitsTab[1]->GetHp())>0){
            //LANCER
            activeUser=1;
            cout<<"Player change to"<<activeUser<<"\n";
            userTurn=false;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3) and (UnitsTab[2]->GetHp())>0){
            //ARCHER
            activeUser=2;
            cout<<"Player change to"<<activeUser<<"\n";
            userTurn=false;
        }else{
            cout<<" cant do that ";
        }

    }
    //changeuit dead pc
    if(enemyhp<=0){
        double unit = int(Decide(1.0,4.0));
        UnitsTab.erase (UnitsTab.begin()+3);
        score+=1;
        cout<<" "<<enemyname<<" umrzal-score "<<score<<" ";
        if(unit==1){
            UnitsTab.push_back(make_shared<PcUnit>("SABER"));
        }else if(unit==2){
            UnitsTab.push_back(make_shared<PcUnit>("LANCER"));
        }else{
            UnitsTab.push_back(make_shared<PcUnit>("ARCHER"));
        }
    }

    //koniuec player turn ----------------------------------------------------------------------------------------------
}


void Game::PcTurn(sf::RenderWindow& window){
    float myhp = UnitsTab[activePc]->GetHp();
    float enemyhp = UnitsTab[activeUser]->GetHp();
    float dmgmulti = UnitsTab[activePc]->GetDmgMulti();
    std::string myname = UnitsTab[activePc]->getName();
    std::string enemyname = UnitsTab[activeUser]->getName();
    //action
    double border = 25.0;
    double action = Decide(1.0,101.0);

    if(myhp<10){
        border+=25.0;
    }

    if(action<=border){
        //heal
        UnitsTab[activePc]->SetHp(myhp+3);
        cout<<"Pc heal "<<UnitsTab[activePc]->GetHp()<<"\n-------------------------new turn-----------------------\n"; //do wywalenia
        userTurn = true;
    }else{
        //attack
        float dmg=4;
        if((myname == "Saber" && enemyname=="Lancer") or (myname == "Lancer" && enemyname=="Archer") or (myname == "Archer" && enemyname=="Saber")){
            dmg = dmg + (dmg * dmgmulti);
        }else if((myname == "Lancer" && enemyname=="Saber")or(myname == "Archer" && enemyname=="Lancer")or(myname == "Saber" && enemyname=="Archer")) {
            dmg = dmg - (dmg * dmgmulti);
        }else{

        }
        enemyhp-=dmg;
        cout<<"Pc atk "<<myname<<" "<<myhp<<"-"<<enemyname<<" "<<enemyhp<<"\n--------------new turn-------------\n";  //do wywalenia ---------------------------------
        UnitsTab[activeUser]->SetHp(enemyhp);
        userTurn = true;
    }
    //Dead units - game over
    if(enemyhp<=0){
        if(UnitsTab[0]->GetHp()>0){
            activeUser=0;
        }else if(UnitsTab[1]->GetHp()>0){
            activeUser=1;
        }else if(UnitsTab[2]->GetHp()>0){
            activeUser=2;
        }else{
            //game over
            cout<<"over";
            over = true;
        }
    }

}

double Game::Decide(double a, double b){
    random_device random_device;
    mt19937 random_engine{random_device()};
    uniform_real_distribution distribution{a,b};
    return distribution(random_engine);
}