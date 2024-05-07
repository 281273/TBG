#include "Game.h"

//Game::Game(UserUnit& _userunit,PcUnit& _pcunit,Input& _input):userunit(_userunit),pcunit(_pcunit),input(_input){
Game::Game(){
    //View& _view,Model& _model,KeyBinding& _keybinding):view(_view),model(_model),keybinding(_keybinding){
    CreateUnits();
    activePc = 0;
    activeUser = 1;
    manuUp = true;
    userTurn = true;
}



void Game::GameLoop() {
    //Ini

    sf::RenderWindow window(sf::VideoMode(1050,540),"Turn-Based Game");
    window.setFramerateLimit(120);

    //Main game loop
    while(window.isOpen()){
        sf::Event event{};
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }

            //Update
            Update(window);
            //Render
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
    }else if (!manuUp) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            manuUp = true;
        }

        if(!userTurn){
            PcTurn();
        }else{
            UserTurn();
        }
    }
}

void Game::UpadateMousePosition(sf::RenderWindow& window){
    //cout<<sf::Mouse::getPosition(window).x <<" "<<sf::Mouse::getPosition(window).y<<"\n";
    mousePosWindow = sf::Mouse::getPosition(window);
}

void Game::RenderMenu(sf::RenderWindow& window){
    window.clear(sf::Color::Blue);
    //Draw here
    BackGround("MENU").draw(window);
//    UnitsTab[activePc]->draw(window);
//    UnitsTab[activeUser]->draw(window);
    window.display();
}

void Game::RenderGame(sf::RenderWindow& window){
    window.clear(sf::Color::Blue);
    //Draw here
    BackGround("BG").draw(window);
    UnitsTab[activePc]->draw(window);
    UnitsTab[activeUser]->draw(window);

    window.display();
}

void Game::CreateUnits(){
    UnitsTab.push_back(make_shared<PcUnit>("LANCER"));     //0

    UnitsTab.push_back(make_shared<UserUnit>("SABER"));     //1
    UnitsTab.push_back(make_shared<UserUnit>("LANCER"));    //2
    UnitsTab.push_back(make_shared<UserUnit>("ARCHER"));   //3
}

void Game::UserTurn(){
    float myhp = UnitsTab[activeUser]->GetHp();
    float enemyhp = UnitsTab[activePc]->GetHp();
    float dmgmulti = UnitsTab[activeUser]->GetDmgMulti();
    string myname = UnitsTab[activeUser]->getName();
    string enemyname = UnitsTab[activePc]->getName();

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
        cout<<"Player"<<myname<<enemyname<<enemyhp<<" ";  //do wywalenia
        UnitsTab[activePc]->SetHp(enemyhp);

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        //heal/overheal
        UnitsTab[activeUser]->SetHp(myhp+2);
        cout<<"Player"<<UnitsTab[activeUser]->GetHp()<<" "; //do wywalenia

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)){   //hold
        //changeunit
        cout<<"1-3 ";
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)){
            activeUser=1;
            cout<<activeUser<<" ";
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)){
            activeUser=2;
            cout<<activeUser<<" ";
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)){
            activeUser=3;
            cout<<activeUser<<" ";
        }

    }
    userTurn=false;
}

void Game::PcTurn(){
    float myhp = UnitsTab[activePc]->GetHp();
    float enemyhp = UnitsTab[activeUser]->GetHp();
    float dmgmulti = UnitsTab[activePc]->GetDmgMulti();
    string myname = UnitsTab[activePc]->getName();
    string enemyname = UnitsTab[activeUser]->getName();
    //action
    double border = 25.0;
    double action = Decide(1.0,101.0);
    double unit = int(Decide(1.0,4.0));
    int i=0;
    if(myhp<10){
        border+=25.0;
    }

    if(action<=border){
        //heal
        UnitsTab[activePc]->SetHp(myhp+3);
        cout<<"Pc"<<UnitsTab[activePc]->GetHp()<<" "; //do wywalenia

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
        cout<<"Pc"<<myname<<enemyname<<enemyhp<<" ";  //do wywalenia
        UnitsTab[activeUser]->SetHp(enemyhp);
    }
    cout<<action<<" "<<unit<<"\n";
    //changeuit
    if(myhp<=0){
        i+=1;
        if(unit==1){
            //UnitsTab[activePc];
        }else if(unit==2){

        }else{

        }
    }

    userTurn = true;
}

double Game::Decide(double a, double b){
    random_device random_device;
    mt19937 random_engine{random_device()};
    uniform_real_distribution distribution{a,b};
    return distribution(random_engine);
}