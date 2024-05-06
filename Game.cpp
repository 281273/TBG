#include "Game.h"

Game::Game(){
    //View& _view,Model& _model,KeyBinding& _keybinding):view(_view),model(_model),keybinding(_keybinding){
    CreateUnits();
    activePc=1;
    activeUser=1;
}



void Game::GameLoop() {
    //Ini
    sf::RenderWindow window(sf::VideoMode(1050,540),"Turn-Based Game");
    window.setFramerateLimit(120);

//    sf::Texture texture;
//    texture.loadFromFile("../sprites/SABER.png");
//    sf::Sprite player = sf::Sprite(texture);

    //Main game loop
    while(window.isOpen()){
        sf::Event event{};
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
            Game::Update(window);
            Game::Render(window);
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
