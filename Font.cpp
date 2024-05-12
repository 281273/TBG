#include "Font.h"


Font::Font(const std::string& content,float x,float y){
    LoadFont();
    Init(content,x,y);
}

void Font::LoadFont(){
    if(!font.loadFromFile("../font/prstart.ttf")){
        std::cerr << "Font error \n";
    }
}

void Font::Init(const std::string& content,float x,float y){
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(1);
    text.setCharacterSize(24);
    text.setString(content);
    text.setPosition(x,y);
}

void Font::draw(sf::RenderTarget& target) const {
    target.draw(text);
}