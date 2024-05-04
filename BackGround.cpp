#include "BackGround.h"

BackGround::BackGround(const string& filename){
    LoadTexture(filename);
    Init();
};

void BackGround::LoadTexture(const string& filename){
    if (!texture.loadFromFile("../sprites/"+filename+".png")) {
        std::cerr << "Texture error player \n";
    }
}

void BackGround::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void BackGround::Init(){
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
}