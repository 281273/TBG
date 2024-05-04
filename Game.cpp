#include "Game.h"

Game::Game(){
    //View& _view,Model& _model,KeyBinding& _keybinding):view(_view),model(_model),keybinding(_keybinding){
    CreateUnits();
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
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
        window.clear(sf::Color::Blue);
        //Draw here
        BackGround("MENU").draw(window);
        UnitsTab[3]->draw(window);
        cout<<UnitsTab[0]->GetHp()<<" ";
        window.display();
        }

    }
}

void Game::Update(){

}

void Game::Render(){

}

void Game::CreateUnits(){


    UnitsTab.push_back(make_shared<PcUnit>("LANCER","Lancer",15,1.5,true));     //0

    UnitsTab.push_back(make_shared<UserUnit>("SABER","Saber",20,1.25,true));     //1
    UnitsTab.push_back(make_shared<UserUnit>("LANCER","Lancer",15,1.5,false));    //2
    UnitsTab.push_back(make_shared<UserUnit>("ARCHER","Archer",10,1.75,false));   //3

}