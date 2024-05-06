#include "Game.h"

Game::Game(){
    //View& _view,Model& _model,KeyBinding& _keybinding):view(_view),model(_model),keybinding(_keybinding){

    CreateUnits();
    MainLoop();
    activePc=1;
    activeUser=1;
}

void Game::MainLoop() {
    sf::RenderWindow window(sf::VideoMode(1050,540),"Turn-Based Game");
    window.setFramerateLimit(120);

    int game=1;
    int exit=2;
    int a;
    //Main menu
    while(window.isOpen()){
        sf::Event event{};

        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
            window.clear(sf::Color::Blue);
            BackGround("MENU").draw(window);
            window.display();

//                cout<<"podaj a";
//                cin>>a;
//                if(a==game){
//                    GameLoop(window);
//                }else if(a==exit){
//                    window.close();
//                }else {
//                    cout<<"wrong input";
//                }
            GameLoop(window);


            //cout<<UnitsTab[0]->GetHp()<<" ";

        }
    }
}


void Game::Update(sf::RenderWindow& window){ //potem usunac parametr
    //Mouse
    UpadateMousePosition(window);
}

void Game::UpadateMousePosition(sf::RenderWindow& window){
    cout<<sf::Mouse::getPosition(window).x <<" "<<sf::Mouse::getPosition(window).y<<"\n";
    mousePosWindow = sf::Mouse::getPosition(window);

}

void Game::Render(sf::RenderWindow& window){
    window.clear(sf::Color::Blue);
    //Draw here
    BackGround("BG").draw(window);
    UnitsTab[0]->draw(window);
    UnitsTab[activeUser]->draw(window);

    window.display();
}

void Game::CreateUnits(){
    UnitsTab.push_back(make_shared<PcUnit>("LANCER",true));     //0

    UnitsTab.push_back(make_shared<UserUnit>("SABER",true));     //1
    UnitsTab.push_back(make_shared<UserUnit>("LANCER",false));    //2
    UnitsTab.push_back(make_shared<UserUnit>("ARCHER",false));   //3
}

enum class GameState {
    Menu,
    RunningGame,
    EndGame
};

void Game::GameLoop(sf::RenderWindow &window) {
    Update(window);
    Render(window);
}

