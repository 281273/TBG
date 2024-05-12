#include "BackGround.h"

BackGround::BackGround(const string& filename,float x,float y){
    LoadTexture(filename);
    Init(x,y);
};

void BackGround::LoadTexture(const string& filename){
    if (!texture.loadFromFile("../sprites/"+filename+".png")) {
        std::cerr << "Texture error player \n";
    }
}

void BackGround::Init(float x,float y){
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void BackGround::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

