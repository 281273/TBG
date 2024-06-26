#include "Game.h"

Game::Game(){
    CreateUnits();
    activePc = 3;       //Active Pc unit 1-3 Saber , Lancer, Archer
    activeUser = 0;     //Active User unit at the moment
    manuUp = true;      //Menu state
    over = false;       //Game over state
    userTurn = true;    //Checks whos turn is it User or not (pc)
    score = 0;
}

void Game::GameLoop() {
    //Ini
    //Creating the main window and setting its properties
    sf::RenderWindow window(sf::VideoMode(1050,540),"Turn-Based Game");
    window.setFramerateLimit(120);

    //Main game loop working while game is open
    while(window.isOpen()){
        sf::Event event{};
        //Closing the window by pressing button X
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
        }

        //Update
        Update(window);
        //Render
        //If all player units died, display game over screen
        if(over){
            RenderOver(window);
        }else{
            //If Menu state display menu screen
            if(manuUp){
                RenderMenu(window);
            //If Menu is not active display game screen
            }else{
                RenderGame(window);
            }
        }
    }
}

void Game::Update(sf::RenderWindow& window){ //potem usunac parametr
    //Mouse info update
    UpadateMousePosition(window);

    //Inputs
    //Press space to go from Menu to Game state
    if(manuUp and sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
        manuUp = false;
    }
    //Press Escape to close game id in Menu state
    else if(manuUp and sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
        window.close();
    }
    //Press Escape to go back to Menu if in Game state
    else if (!manuUp) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            manuUp = true;
        }
        //Changes from User to Pc turn after 1 action is done
        if(userTurn){
            UserTurn(window);

        }else{
            PcTurn(window);

        }
    }
}

//Gives mouse position in window
void Game::UpadateMousePosition(sf::RenderWindow& window){
    //cout<<sf::Mouse::getPosition(window).x <<" "<<sf::Mouse::getPosition(window).y<<"\n";
    mousePosWindow = sf::Mouse::getPosition(window);
}

//Displays everything on screen in Menu state
void Game::RenderMenu(sf::RenderWindow& window){
    window.clear(sf::Color::Blue);

    //Draw here
    BackGround("MENU",0,0).draw(window);
    Font("Press Space",430,440).draw(window);

    window.display();
}

//Displays everything on screen in Game state
void Game::RenderGame(sf::RenderWindow& window){
    int myhp = UnitsTab[activeUser]->GetHp();
    int enemyhp = UnitsTab[activePc]->GetHp();
    std::string myname = UnitsTab[activeUser]->getName();
    std::string enemyname = UnitsTab[activePc]->getName();

    window.clear(sf::Color::Blue);

    //Draw here V
    BackGround("BG",0,0).draw(window);
    BackGround("MANUAL",770,287).draw(window);

    //score
    std::string scoreinfo = "Score: "+std::to_string(score);
    Font(scoreinfo,10,10).draw(window);

    //Displays Pc Unit png,  name and hp
    UnitsTab[activePc]->draw(window);
    std::string playerinfo = (myname+": "+std::to_string(myhp));
    Font(playerinfo,260, 280).draw(window);

    //Displays Player Unit png,  name and hp
    UnitsTab[activeUser]->draw(window);
    std::string enemyinfo = (enemyname+": "+std::to_string(enemyhp));
    Font(enemyinfo,630, 130).draw(window);

    window.display();
}

void Game::RenderQTE(sf::RenderWindow& window,const std::string& eventinfo,float x,float y){
    Font(eventinfo,x, y).draw(window);

    window.display();
}


//Displays ,,game over" screen
void Game::RenderOver(sf::RenderWindow& window){
    window.clear(sf::Color::Blue);
    //Draw here
    BackGround("OVER",0,0).draw(window);

    window.display();
}

//Adds playable Units to vector
void Game::CreateUnits(){
    UnitsTab.push_back(std::make_shared<UserUnit>("SABER"));         //0
    UnitsTab.push_back(std::make_shared<UserUnit>("LANCER"));        //1
    UnitsTab.push_back(std::make_shared<UserUnit>("ARCHER"));        //2

    UnitsTab.push_back(std::make_shared<PcUnit>("LANCER"));          //3
}

double Game::Decide(double a, double b){
    std::random_device random_device;
    std::mt19937 random_engine{random_device()};
    std::uniform_real_distribution distribution{a,b};
    return distribution(random_engine);
}




//All actions possible for player while its his turn. After 1 action its Pcs turn
void Game::UserTurn(sf::RenderWindow& window){
    int myhp = UnitsTab[activeUser]->GetHp();
    int enemyhp = UnitsTab[activePc]->GetHp();
    int dmgmulti = UnitsTab[activeUser]->GetDmgMulti();
    std::string myname = UnitsTab[activeUser]->getName();
    std::string enemyname = UnitsTab[activePc]->getName();
    std::string info;
    float myX = 390; float myY = 350;
    float enemyX = 520; float enemyY = 210;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)){
        //attack
        int dmg=(4+score/3);
        if((myname == "Saber" && enemyname=="Lancer") or (myname == "Lancer" && enemyname=="Archer") or (myname == "Archer" && enemyname=="Saber")){
            dmg = dmg + dmgmulti;
        }else if((myname == "Lancer" && enemyname=="Saber")or(myname == "Archer" && enemyname=="Lancer")or(myname == "Saber" && enemyname=="Archer")) {
            dmg = dmg - dmgmulti;
        }else{

        }
        enemyhp-=dmg;

        //Display the information that enemy lost hp
        info = "-"+std::to_string(dmg)+"hp";
        RenderQTE(window,info,enemyX,enemyY);

        UnitsTab[activePc]->SetHp(enemyhp);

        Sleep(500);
        userTurn=false;

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        //heal/overheal
        int heal = (2+score/3);
        UnitsTab[activeUser]->SetHp(myhp+heal);

        //How much healed
        info = "+"+std::to_string(heal)+"hp";
        RenderQTE(window,info,myX-210,myY);

        Sleep(500);
        userTurn=false;

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)){   //hold
        //changeunit - not working untill hold fix
        info = "Changing Unit...";
        RenderQTE(window,info,myX,myY+100);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1) and (UnitsTab[0]->GetHp())>0){
            //SABER
            activeUser=0;

            //Prompt that u succesfully changed your unit to saber
//            info = "Unit Changed to SABER";
//            RenderQTE(window,info,myX,myY);
            Sleep(500);
            userTurn=false;
        }else if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) and (UnitsTab[1]->GetHp())>0){
            //LANCER
            activeUser=1;
            //
//            info = "Unit Changed to LANCER";
//            RenderQTE(window,info,myX,myY);
            Sleep(500);
            userTurn=false;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3) and (UnitsTab[2]->GetHp())>0){
            //ARCHER
            activeUser=2;
            //
//            info = "Unit Changed to ARCHER";
//            RenderQTE(window,info,myX,myY);
            Sleep(500);
            userTurn=false;
        }else{
//            info = "Can't do that";
//            RenderQTE(window,info,myX,myY);
        }
    }

    //koniuec player turn ----------------------------------------------------------------------------------------------
}
void Game::PcTurn(sf::RenderWindow& window){

    int myhp = UnitsTab[activePc]->GetHp();
    int enemyhp = UnitsTab[activeUser]->GetHp();
    int dmgmulti = UnitsTab[activePc]->GetDmgMulti();
    std::string myname = UnitsTab[activePc]->getName();
    std::string enemyname = UnitsTab[activeUser]->getName();
    std::string info;
    float enemyX = 390; float enemyY = 350;
    float myX = 760; float myY = 210;


    //after pc unit is defeated , create a new random one
    if(myhp<=0){
        double unit = int(Decide(1.0,4.0));
        UnitsTab.erase (UnitsTab.begin()+3);
        score+=1;

        //Heal after kill to whole party. can revive
        for(int i=0;i<3;i++){
            int currUhp = UnitsTab[i]->GetHp();
            UnitsTab[i]->SetHp(currUhp+2+(score/5));
        }

        //Info about pc death
        info = "Unit Died!";
        RenderQTE(window,info,myX,myY);

        //Bonus stats based on score
        if(unit==1){
            UnitsTab.push_back(std::make_shared<PcUnit>("SABER"));
        }else if(unit==2){
            UnitsTab.push_back(std::make_shared<PcUnit>("LANCER"));
        }else{
            UnitsTab.push_back(std::make_shared<PcUnit>("ARCHER"));
        }
        int currPhp = UnitsTab[3]->GetHp();
        UnitsTab[3]->SetHp(currPhp+score);

        Sleep(500);
        userTurn=true;
    }else{
        //action decided by random numbers, border to choose between action based on the rolled number
        double border = 25.0;
        double action = Decide(1.0,101.0);
        //IF hp is low chance to heal is higher
        if(myhp<(15)){
            border+=25.0;
        }

        if(action<=border){
            //heal
            int heal = (2+score/3);
            UnitsTab[activePc]->SetHp(myhp+heal);

            //Amount of p healed info
            info = "+"+std::to_string(heal)+"hp";
            RenderQTE(window,info,myX,myY);

            Sleep(500);
            userTurn = true;

        }else{
            //attack
            int dmg=(4+score/2);
            if((myname == "Saber" && enemyname=="Lancer") or (myname == "Lancer" && enemyname=="Archer") or (myname == "Archer" && enemyname=="Saber")){
                dmg = dmg + dmgmulti;
            }else if((myname == "Lancer" && enemyname=="Saber")or(myname == "Archer" && enemyname=="Lancer")or(myname == "Saber" && enemyname=="Archer")) {
                dmg = dmg - dmgmulti;
            }else{

            }
            enemyhp-=dmg;

            //Amount of p healed info
            info = "-"+std::to_string(dmg)+"hp";
            RenderQTE(window,info,enemyX,enemyY);

            UnitsTab[activeUser]->SetHp(enemyhp);

            Sleep(500);
            userTurn = true;
        }

        //If all players units are killed , its game over
        if(enemyhp<=0){
            //Info that u died
            info = "Your active unit died";
            RenderQTE(window,info,enemyX-200,enemyY+100);
            Sleep(1000);
            //Selecting anew unit based on hp of others if no options game over
            if(UnitsTab[0]->GetHp()>0){
                activeUser=0;
            }else if(UnitsTab[1]->GetHp()>0){
                activeUser=1;
            }else if(UnitsTab[2]->GetHp()>0){
                activeUser=2;
            }else{
                //game over state
//            cout<<"over";
                over = true;
            }

        }

        //Koniec not dead else
    }
}


